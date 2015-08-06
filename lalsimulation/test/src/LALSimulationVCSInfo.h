/*
 * LALSimulationVCSInfo.h - LALSimulation VCS Information
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

#ifndef _LALSIMULATIONVCSINFO_H
#define _LALSIMULATIONVCSINFO_H

#include <lal/LALVCSInfoType.h>

#ifdef __cplusplus
extern "C" {
#endif

/* global variables for vcs information */
extern const char *const lalSimulationVCSVersion;
extern const char *const lalSimulationVCSId;
extern const char *const lalSimulationVCSDate;
extern const char *const lalSimulationVCSBranch;
extern const char *const lalSimulationVCSTag;
extern const char *const lalSimulationVCSAuthor;
extern const char *const lalSimulationVCSCommitter;
extern const char *const lalSimulationVCSStatus;

/* global variables for vcs information - identable */
extern const char *const lalSimulationVCSIdentId;
extern const char *const lalSimulationVCSIdentDate;
extern const char *const lalSimulationVCSIdentBranch;
extern const char *const lalSimulationVCSIdentTag;
extern const char *const lalSimulationVCSIdentAuthor;
extern const char *const lalSimulationVCSIdentCommitter;
extern const char *const lalSimulationVCSIdentStatus;

/* library vcs information structure */
extern const struct tagLALVCSInfo lalSimulationVCSInfo;

/* configure arguments */
extern const char *const lalSimulationConfigureArgs;

/* configure date */
extern const char *const lalSimulationConfigureDate;

/* build date */
extern const char *const lalSimulationBuildDate;

#ifdef __cplusplus
}
#endif

#endif /* _LALSIMULATIONVCSINFO_H */

/*
 * vim: tw=0 ts=2 et
 */
