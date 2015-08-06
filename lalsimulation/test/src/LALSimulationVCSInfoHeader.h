/*
 * LALSimulationVCSInfo.h - LALSimulation VCS Information Header
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with with program; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Copyright (C) 2009-2013 Adam Mercer
 * Copyright (C) 2014 Karl Wette
 */

#ifndef _LALSIMULATIONVCSINFOHEADER_H
#define _LALSIMULATIONVCSINFOHEADER_H

#include <lal/LALVCSInfoType.h>
#include <lal/LALSimulationVCSInfo.h>
#include <lal/LALSimulationConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

/* vcs information defines */
#define LALSIMULATION_NAME "LALSimulation"
#define LALSIMULATION_VCS_ID "30c4fb7f13900ee2ddd327af812855748c3e6834"
#define LALSIMULATION_VCS_DATE "2015-07-7 01:31:54 +0000"
#define LALSIMULATION_VCS_BRANCH "master"
#define LALSIMULATION_VCS_TAG "None"
#define LALSIMULATION_VCS_AUTHOR "Reed Essick <reed.essick@ligo.org>"
#define LALSIMULATION_VCS_COMMITTER "Reed Essick <reed.essick@ligo.org>"
#define LALSIMULATION_VCS_STATUS "UNCLEAN: Modified working tree"

/* vcs information defines - identable*/
#define LALSIMULATION_VCS_IDENT_ID "$" "LALSimulationId: 30c4fb7f13900ee2ddd327af812855748c3e6834 " "$"
#define LALSIMULATION_VCS_IDENT_DATE "$" "LALSimulationDate: 2015-07-7 01:31:54 +0000 " "$"
#define LALSIMULATION_VCS_IDENT_BRANCH "$" "LALSimulationBranch: master " "$"
#define LALSIMULATION_VCS_IDENT_TAG "$" "LALSimulationTag: None " "$"
#define LALSIMULATION_VCS_IDENT_AUTHOR "$" "LALSimulationAuthor: Reed Essick <reed.essick@ligo.org> " "$"
#define LALSIMULATION_VCS_IDENT_COMMITTER "$" "LALSimulationCommitter: Reed Essick <reed.essick@ligo.org> " "$"
#define LALSIMULATION_VCS_IDENT_STATUS "$" "LALSimulationStatus: UNCLEAN: Modified working tree " "$"

/* header vcs information structure */
static const struct tagLALVCSInfo lalSimulationVCSInfoHeader = { \
  LALSIMULATION_NAME, \
  LALSIMULATION_VERSION, \
  LALSIMULATION_VCS_ID, \
  LALSIMULATION_VCS_DATE, \
  LALSIMULATION_VCS_BRANCH, \
  LALSIMULATION_VCS_TAG, \
  LALSIMULATION_VCS_AUTHOR, \
  LALSIMULATION_VCS_COMMITTER, \
  LALSIMULATION_VCS_STATUS \
};

#ifdef __cplusplus
}
#endif

#endif /* _LALSIMULATIONVCSINFOHEADER_H */

/*
 * vim: tw=0 ts=2 et
 */
