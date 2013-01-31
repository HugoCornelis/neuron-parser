dnl -*- autoconf -*-
dnl
dnl The neurospaces project : modeling tools for computational
dnl neuroscience.
dnl

dnl ##########################################################################
dnl 
dnl The neurospaces project
dnl 
dnl Copyright (C) 2007-2008 Hugo Cornelis
dnl 
dnl Hugo Cornelis, hugo.cornelis@gmail.com
dnl 
dnl ##########################################################################

# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)

# $Format: "AC_INIT(${package}, ${major}.${minor}.${micro}-${label}, ${email})"$
AC_INIT(neuron-parser, 0.0.0-alpha, bampasakis@gmail.com)



AC_MSG_CHECKING(whether we build universal binaries.)
AC_ARG_WITH(universal,
[AS_HELP_STRING([--with-universal],
              [Build universal binaries on Mac OS X.])],
[ case "$val" in
  no)

    AC_MSG_RESULT(no)
    OSX_UNIVERSAL="no"

    ;;
  *)

    AC_MSG_RESULT(yes)
    OSX_UNIVERSAL="yes"

    ;;
  esac ],
  AC_MSG_RESULT(no)
  OSX_UNIVERSAL="no"
)
AC_SUBST(OSX_UNIVERSAL)



AC_CONFIG_SRCDIR([Makefile.am])

dnl dnl all subdirs
dnl See also http://stackoverflow.com/questions/12624021/can-automake-include-multiple-makefile-am-together

AC_CONFIG_SUBDIRS([nrn-7.2])

# $Format: "AM_INIT_AUTOMAKE(${package}, ${major}.${minor}.${micro}-${label})"$
AM_INIT_AUTOMAKE(neuron-parser, 0.0.0-alpha)

PERL_MODULES=`(cd perl && find . -name "*.pm" | perl -pe 's/\n/ /g')`
AC_SUBST(PERL_MODULES)

PERL_DATA=`(cd perl && find . -name "numbers-7x11.txt" | perl -pe 's/\n/ /g')`
AC_SUBST(PERL_DATA)

# Checks for programs.

#   need to have this bail out when MTN = NULL
#   since it's required. 
AC_CHECK_PROGS([MTN],mtn monotone,[NULL])

#   check for packaging programs for debian and red hat.
#   no need to bail out if these are missing since they're optional. 
AC_CHECK_PROGS([DPKG_BUILDPACKAGE],dpkg-buildpackage,[NULL])
AC_CHECK_PROGS([DH],dh,[NULL])
AC_CHECK_PROGS([RPMBUILD],rpmbuild,[NULL])

dnl Check for Python and it's headers
AM_PATH_PYTHON(,[],[
   echo "Python is not installed."
   exit -1
])

AC_MSG_CHECKING([Python prefix is ])
  AC_MSG_RESULT(['$PYTHON_PREFIX'])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# determine the test library to install

TEST_SPECIFICATION_FILES=`/bin/echo -n "tests/introduction.html " && find tests/specifications -name "*.t" | perl -pe 's/\n/ /g' && find tests/specifications/strings -name "*.txt" | perl -pe 's/\n/ /g' && find tests/data -name "*.yml" | perl -pe 's/\n/ /g'`
AC_SUBST(TEST_SPECIFICATION_FILES)


dnl AC_CONFIG_HEADERS([nrn-7.2/nmodlconf.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/nrnconf.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/nrnoc/nrnconfigargs.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/oc/nrnmpiuse.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/oc/nrnrtuse.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/oc/nrnpthread.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/parallel/bbsconf.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/nrnjava/njconf.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/nrncvode/nrnneosm.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/ivos/ivstream.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/sundials/sundials_config.h])
dnl AC_CONFIG_HEADERS([nrn-7.2/src/nrnpython/nrnpython_config.h])

AC_CONFIG_FILES([Makefile])
dnl 		 perl/Makefile
dnl 		 python/Makefile])


dnl 	nrn-7.2/Makefile
dnl 	nrn-7.2/src/Makefile
dnl 	nrn-7.2/src/e_editor/Makefile
dnl 	nrn-7.2/src/modlunit/Makefile
dnl 	nrn-7.2/src/nmodl/Makefile
dnl 	nrn-7.2/nrnrpm.spec
dnl 	nrn-7.2/src/sundials/Makefile
dnl 	nrn-7.2/src/sundials/shared/Makefile
dnl 	nrn-7.2/src/sundials/cvodes/Makefile
dnl 	nrn-7.2/src/sundials/ida/Makefile
dnl 	nrn-7.2/src/sparse/Makefile
dnl 	nrn-7.2/src/memacs/Makefile
dnl 	nrn-7.2/src/readline/Makefile
dnl 	nrn-7.2/src/sparse13/Makefile
dnl 	nrn-7.2/src/oc/Makefile	src/scopmath/Makefile
dnl 	nrn-7.2/src/nrnoc/Makefile
dnl 	nrn-7.2/src/gnu/Makefile
dnl 	nrn-7.2/src/uxnrnbbs/Makefile
dnl 	nrn-7.2/src/mesch/Makefile
dnl 	nrn-7.2/src/uxnrnbbs/mos2nrn.h
dnl 	nrn-7.2/src/nrnmpi/Makefile
dnl 	nrn-7.2/src/ivoc/Makefile
dnl 	nrn-7.2/src/nrncvode/Makefile
dnl 	nrn-7.2/src/parallel/Makefile
dnl 	nrn-7.2/src/nrniv/Makefile
dnl 	nrn-7.2/src/ivos/Makefile
dnl 	nrn-7.2/src/ivos/InterViews/Makefile
dnl 	nrn-7.2/src/ivos/OS/Makefile
dnl 	nrn-7.2/src/nrnjava/Makefile
dnl 	nrn-7.2/src/nrnjava/nrnccmb/Makefile
dnl 	nrn-7.2/src/nrnjava/neuron/Makefile
dnl 	nrn-7.2/src/nrnpython/Makefile
dnl 	nrn-7.2/src/ni_pci_6229/Makefile
dnl 	nrn-7.2/src/mac/Makefile
dnl 	nrn-7.2/src/mswin/Makefile
dnl 	nrn-7.2/src/mswin/batch/Makefile
dnl 	nrn-7.2/src/mswin/nrnsetup.nsi
dnl 	nrn-7.2/src/mswin/nrncygso.sh
dnl 	nrn-7.2/src/mswin/lib/mknrndll.mak
dnl 	nrn-7.2/src/mswin/extra/Makefile
dnl 	nrn-7.2/src/mswin/rdln/Makefile
dnl 	nrn-7.2/src/mswin/windll/Makefile
dnl 	nrn-7.2/src/mswin/wnrnbbs/Makefile
dnl 	nrn-7.2/src/mswin/lib/Makefile
dnl 	nrn-7.2/src/mswin/bin/Makefile
dnl 	nrn-7.2/src/neuronmusic/Makefile
dnl 	nrn-7.2/src/neuronmusic/setup.py
dnl 	nrn-7.2/share/Makefile
dnl 	nrn-7.2/bin/nrnoc_makefile
dnl 	nrn-7.2/bin/nrniv_makefile
dnl 	nrn-7.2/bin/nrnmech_makefile
dnl 	nrn-7.2/share/lib/Makefile
dnl 	nrn-7.2/share/lib/hoc/Makefile
dnl 	nrn-7.2/share/lib/python/Makefile
dnl 	nrn-7.2/share/lib/hoc/celbild/Makefile
dnl 	nrn-7.2/share/lib/hoc/mulfit/Makefile
dnl 	nrn-7.2/share/lib/hoc/netbild/Makefile
dnl 	nrn-7.2/share/lib/hoc/lincir/Makefile
dnl 	nrn-7.2/share/lib/hoc/mview/Makefile
dnl 	nrn-7.2/share/lib/hoc/chanbild/Makefile
dnl 	nrn-7.2/share/lib/hoc/import3d/Makefile
dnl 	nrn-7.2/share/lib/auditscripts/Makefile
dnl 	nrn-7.2/share/lib/nrn.defaults
dnl 	nrn-7.2/bin/Makefile
dnl 	nrn-7.2/bin/nrnocmodl
dnl 	nrn-7.2/bin/nrnivmodl
dnl 	nrn-7.2/bin/neurondemo
dnl 	nrn-7.2/bin/nrngui
dnl 	nrn-7.2/bin/bbswork.sh
dnl 	nrn-7.2/bin/mos2nrn2.sh
dnl 	nrn-7.2/bin/hel2mos1.sh
dnl 	nrn-7.2/share/examples/Makefile
dnl 	nrn-7.2/share/examples/ivoc/Makefile
dnl 	nrn-7.2/share/examples/nrniv/Makefile
dnl 	nrn-7.2/share/examples/nrniv/cable/Makefile
dnl 	nrn-7.2/share/examples/nrniv/kkin/Makefile
dnl 	nrn-7.2/share/examples/nrniv/netcon/Makefile
dnl 	nrn-7.2/share/examples/nrniv/netsyn/Makefile
dnl 	nrn-7.2/share/examples/nrniv/nmodl/Makefile
dnl 	nrn-7.2/share/examples/nrniv/nrnoc/Makefile
dnl 	nrn-7.2/share/examples/nrniv/randomsyn/Makefile
dnl 	nrn-7.2/share/examples/nrniv/soma/Makefile
dnl 	nrn-7.2/share/examples/nrniv/vrecorder/Makefile
dnl 	nrn-7.2/share/examples/nrniv/xmech/Makefile
dnl 	nrn-7.2/share/demo/Makefile
dnl 	nrn-7.2/share/demo/release/Makefile
dnl 	nrn-7.2/share/demo/dend3/Makefile
dnl 	nrn-7.2/share/demo/sync/Makefile
dnl 	nrn-7.2/src/nrnpython/setup.py
dnl 	])


AC_OUTPUT

