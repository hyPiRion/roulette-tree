AC_INIT([rtree], [0.1.0-SNAPSHOT], [jeannikl@hypirion.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CC([clang gcc cc])
AM_PROG_AR
LT_INIT


dnl Find the build directory and the source directory
top_builddir_absolute=`pwd`
AC_SUBST(top_builddir_absolute)
top_srcdir_absolute=`(cd $srcdir && pwd)`
AC_SUBST(top_srcdir_absolute)

dnl Setup debug variables for c
case $CC in
   *clang*) DEBUG_VARS='-Weverything -Wno-cast-align' ;;
   *gcc*)   DEBUG_VARS='-Wall' ;;
   *)       DEBUG_VARS='' ::
esac
AC_SUBST([DEBUG_VARS])

AC_PROG_CC_STDC

dnl Check for header files here.
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_HEADERS([stdbool.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([string.h])

AC_CHECK_HEADERS([time.h])
AC_CHECK_HEADERS([math.h])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile test-suite/Makefile src/Makefile])

AC_OUTPUT
