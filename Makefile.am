ACLOCAL_AMFLAGS = -I lal/misc
SUBDIRS = @subdirs@
MAINTAINERCLEANFILES = lalsuite.spec
vcs-clean: cvs-clean
cvs-clean: maintainer-clean
	rm -f Makefile.in
	rm -f configure
	rm -f aclocal.m4
	rm -f config.cache
	rm -f config.status
	rm -f config.log