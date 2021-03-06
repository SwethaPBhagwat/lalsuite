#
# Copyright (C) 2013  Leo Singer
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
# Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
"""
Listen for new events from LVAlert and perform sky localization.

`bayestar_localize_lvalert` supports two modes of operation. You can explicitly
specify the GraceDb ID on the command line, as in:

    $ bayestar_localize_lvalert T90713

Or, `bayetar_localize_lvalert` can accept an LVAlert XML packet read from
stdin. This is handy for quickly setting up automatic processing of events in
response to LVAlert notifications. To do this, first subscribe to events of
types that you are interested in (probably `cbc_lowmass` or `test_lowmass`):

    $ lvalert_admin --username albert.einstein --password supersecret --subscribe --node cbc_lowmass
    $ lvalert_admin --username albert.einstein --password supersecret --subscribe --node test_lowmass

Create a configuration file that will tell `lvalert_listen` what to do in
response to those event types. For example, you might create a file called
`lvalert_listen.ini` with the following contents:

    [test_lowmass]
    executable = bayestar_localize_lvalert
    [cbc_lowmass]
    executable = bayestar_localize_lvalert

Finally, start `lvalert_listen`:

    $ lvalert_listen  --username albert.einstein --password supersecret --config-file lvalert_listen.ini
"""
__author__ = "Leo Singer <leo.singer@ligo.org>"


#
# Command line interface
#

from optparse import Option, OptionParser
from lalinference.bayestar import command
import logging
import ligo.lvalert.utils
import sys

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger('BAYESTAR')

parser = OptionParser(
    formatter=command.NewlinePreservingHelpFormatter(),
    description=__doc__,
    usage="%prog [options] [GRACEID]"
)
opts, args = parser.parse_args()

if len(args) == 0:
    # No command line arguments; read LVAlert data from stdin
    lvadata = ligo.lvalert.utils.get_LVAdata_from_stdin(sys.stdin, as_dict=True)
    log.info("received lvalert event of type='%s' for uid='%s' and file='%s'",
        lvadata['alert_type'], lvadata['uid'], lvadata['file'])
    if lvadata['alert_type'] == 'update' and lvadata['file'] == 'psd.xml.gz':
        graceid = lvadata['uid']
    else:
        log.info('ignoring')
        raise SystemExit
elif len(args) == 1:
    # One command line argument; manual start from GraceDB id
    graceid, = args
else:
    # Too many command line arguments
    parser.error("expected at most one command line argument")


#
# Hook logging into GraceDb
#

import ligo.gracedb.logging
import ligo.gracedb.rest

# Fire up a GraceDb client
gracedb = ligo.gracedb.rest.GraceDb()

# Send log messages to GraceDb too
handler = ligo.gracedb.logging.GraceDbLogHandler(gracedb, graceid)
handler.setLevel(logging.INFO)
logging.root.addHandler(handler)


#
# Perform sky localization
#

import os
import shutil
import tempfile
from lalinference.bayestar.ligolw_sky_map import gracedb_sky_map
from lalinference import fits

# A little bit of Cylon humor
log.info('by your command...')

try:
    # download coinc.xml
    coinc_file = gracedb.files(graceid, "coinc.xml")

    # download psd.xml.gz
    psd_file = gracedb.files(graceid, "psd.xml.gz")

    # perform sky localization
    log.info("starting sky localization")
    sky_map, epoch, elapsed_time, instruments = gracedb_sky_map(
        coinc_file, psd_file, "TaylorF2threePointFivePN", 10)
    log.info("sky localization complete")

    # upload FITS file
    fitsdir = tempfile.mkdtemp()
    try:
        fitspath = os.path.join(fitsdir, "skymap.fits.gz")
        fits.write_sky_map(fitspath, sky_map, gps_time=float(epoch),
            creator=parser.get_prog_name(), objid=str(graceid),
            url='https://gracedb.ligo.org/events/{0}'.format(graceid),
            runtime=elapsed_time, instruments=instruments,
            origin='LIGO/Virgo', nest=True)
        gracedb.writeLog(graceid, "INFO:BAYESTAR:uploaded sky map",
            filename=fitspath, tagname="sky_loc")
    finally:
        shutil.rmtree(fitsdir)
except:
    # Produce log message for any otherwise uncaught exception
    log.exception("sky localization failed")
    # Then re-raise the exception
    raise
