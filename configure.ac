#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(dec128, 0.0.1, hnakamur@gmail.com)
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE($PACKAGE_NAME, $PACKAGE_VERSION)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB(cunit, CU_basic_run_suite)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdint.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
