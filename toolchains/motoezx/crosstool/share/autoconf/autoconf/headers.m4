# This file is part of Autoconf.			-*- Autoconf -*-
# Checking for headers.
#
# Copyright (C) 1988, 1999, 2000, 2001, 2002, 2003, 2004, 2006 Free Software
# Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.
#
# As a special exception, the Free Software Foundation gives unlimited
# permission to copy, distribute and modify the configure scripts that
# are the output of Autoconf.  You need not follow the terms of the GNU
# General Public License when using or distributing such scripts, even
# though portions of the text of Autoconf appear in them.  The GNU
# General Public License (GPL) does govern all other use of the material
# that constitutes the Autoconf program.
#
# Certain portions of the Autoconf source text are designed to be copied
# (in certain cases, depending on the input) into the output of
# Autoconf.  We call these the "data" portions.  The rest of the Autoconf
# source text consists of comments plus executable code that decides which
# of the data portions to output in any given case.  We call these
# comments and executable code the "non-data" portions.  Autoconf never
# copies any of the non-data portions into its output.
#
# This special exception to the GPL applies to versions of Autoconf
# released by the Free Software Foundation.  When you make and
# distribute a modified version of Autoconf, you may extend this special
# exception to the GPL to apply to your modified version as well, *unless*
# your modified version has the potential to copy into its output some
# of the text that was the non-data portion of the version that you started
# with.  (In other words, unless your change moves or copies text from
# the non-data portions to the data portions.)  If your modification has
# such potential, you must delete any notice of this special exception
# to the GPL from your modified version.
#
# Written by David MacKenzie, with help from
# Franc,ois Pinard, Karl Berry, Richard Pixley, Ian Lance Taylor,
# Roland McGrath, Noah Friedman, david d zuhn, and many others.


# Table of contents
#
# 1. Generic tests for headers
# 2. Default includes
# 3. Headers to tests with AC_CHECK_HEADERS
# 4. Tests for specific headers


## ------------------------------ ##
## 1. Generic tests for headers.  ##
## ------------------------------ ##


# AC_CHECK_HEADER(HEADER-FILE,
#		  [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#		  [INCLUDES])
# ---------------------------------------------------------
# We are slowly moving to checking headers with the compiler instead
# of the preproc, so that we actually learn about the usability of a
# header instead of its mere presence.  But since users are used to
# the old semantics, they check for headers in random order and
# without providing prerequisite headers.  This macro implements the
# transition phase, and should be cleaned up latter to use compilation
# only.
#
# If INCLUDES is empty, then check both via the compiler and preproc.
# If the results are different, issue a warning, but keep the preproc
# result.
#
# If INCLUDES is `-', keep only the old semantics.
#
# If INCLUDES is specified and different from `-', then use the new
# semantics only.
AC_DEFUN([AC_CHECK_HEADER],
[m4_case([$4],
	 [],  [_AC_CHECK_HEADER_MONGREL($@)],
	 [-], [_AC_CHECK_HEADER_OLD($@)],
	      [_AC_CHECK_HEADER_NEW($@)])
])# AC_CHECK_HEADER


# _AC_CHECK_HEADER_MONGREL(HEADER-FILE,
#			   [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#			   [INCLUDES = DEFAULT-INCLUDES])
# ------------------------------------------------------------------
# Check using both the compiler and the preprocessor.  If they disagree,
# warn, and the preproc wins.
#
# This is not based on _AC_CHECK_HEADER_NEW and _AC_CHECK_HEADER_OLD
# because it obfuscate the code to try to factor everything, in particular
# because of the cache variables, and the `checking...' messages.
m4_define([_AC_CHECK_HEADER_MONGREL],
[AS_VAR_PUSHDEF([ac_Header], [ac_cv_header_$1])dnl
AS_VAR_SET_IF(ac_Header,
	      [AC_CACHE_CHECK([for $1], ac_Header, [])],
	      [# Is the header compilable?
AC_MSG_CHECKING([$1 usability])
AC_COMPILE_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT([$4])
@%:@include <$1>])],
		  [ac_header_compiler=yes],
		  [ac_header_compiler=no])
AC_MSG_RESULT([$ac_header_compiler])

# Is the header present?
AC_MSG_CHECKING([$1 presence])
AC_PREPROC_IFELSE([AC_LANG_SOURCE([@%:@include <$1>])],
		  [ac_header_preproc=yes],
		  [ac_header_preproc=no])
AC_MSG_RESULT([$ac_header_preproc])

# So?  What about this header?
case $ac_header_compiler:$ac_header_preproc:$ac_[]_AC_LANG_ABBREV[]_preproc_warn_flag in
  yes:no: )
    AC_MSG_WARN([$1: accepted by the compiler, rejected by the preprocessor!])
    AC_MSG_WARN([$1: proceeding with the compiler's result])
    ac_header_preproc=yes
    ;;
  no:yes:* )
    AC_MSG_WARN([$1: present but cannot be compiled])
    AC_MSG_WARN([$1:     check for missing prerequisite headers?])
    AC_MSG_WARN([$1: see the Autoconf documentation])
    AC_MSG_WARN([$1:     section "Present But Cannot Be Compiled"])
    AC_MSG_WARN([$1: proceeding with the preprocessor's result])
    AC_MSG_WARN([$1: in the future, the compiler will take precedence])
    m4_ifset([AC_PACKAGE_BUGREPORT],
    [( AS_BOX([Report this to ]AC_PACKAGE_BUGREPORT)
     ) | sed "s/^/$as_me: WARNING:     /" >&2])
    ;;
esac
AC_CACHE_CHECK([for $1], ac_Header,
	       [AS_VAR_SET(ac_Header, $ac_header_preproc)])
])dnl ! set ac_HEADER
AS_IF([test AS_VAR_GET(ac_Header) = yes], [$2], [$3])[]dnl
AS_VAR_POPDEF([ac_Header])dnl
])# _AC_CHECK_HEADER_MONGREL


# _AC_CHECK_HEADER_NEW(HEADER-FILE,
#		       [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#		       [INCLUDES = DEFAULT-INCLUDES])
# --------------------------------------------------------------
# Check the compiler accepts HEADER-FILE.  The INCLUDES are defaulted.
m4_define([_AC_CHECK_HEADER_NEW],
[AS_VAR_PUSHDEF([ac_Header], [ac_cv_header_$1])dnl
AC_CACHE_CHECK([for $1], ac_Header,
	       [AC_COMPILE_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT([$4])
@%:@include <$1>])],
				  [AS_VAR_SET(ac_Header, yes)],
				  [AS_VAR_SET(ac_Header, no)])])
AS_IF([test AS_VAR_GET(ac_Header) = yes], [$2], [$3])[]dnl
AS_VAR_POPDEF([ac_Header])dnl
])# _AC_CHECK_HEADER_NEW


# _AC_CHECK_HEADER_OLD(HEADER-FILE,
#		       [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
# --------------------------------------------------------------
# Check the preprocessor accepts HEADER-FILE.
m4_define([_AC_CHECK_HEADER_OLD],
[AS_VAR_PUSHDEF([ac_Header], [ac_cv_header_$1])dnl
AC_CACHE_CHECK([for $1], ac_Header,
	       [AC_PREPROC_IFELSE([AC_LANG_SOURCE([@%:@include <$1>])],
					 [AS_VAR_SET(ac_Header, yes)],
					 [AS_VAR_SET(ac_Header, no)])])
AS_IF([test AS_VAR_GET(ac_Header) = yes], [$2], [$3])[]dnl
AS_VAR_POPDEF([ac_Header])dnl
])# _AC_CHECK_HEADER_OLD


# AH_CHECK_HEADERS(HEADER-FILE...)
# --------------------------------
m4_define([AH_CHECK_HEADERS],
[m4_foreach_w([AC_Header], [$1],
  [AH_TEMPLATE(AS_TR_CPP([HAVE_]m4_defn([AC_Header])),
     [Define to 1 if you have the <]m4_defn([AC_Header])[> header file.])])])


# AC_CHECK_HEADERS(HEADER-FILE...,
#		   [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#		   [INCLUDES])
# ----------------------------------------------------------
AC_DEFUN([AC_CHECK_HEADERS],
[AH_CHECK_HEADERS([$1])dnl
for ac_header in $1
do
AC_CHECK_HEADER($ac_header,
		[AC_DEFINE_UNQUOTED(AS_TR_CPP(HAVE_$ac_header)) $2],
		[$3],
		[$4])dnl
done
])# AC_CHECK_HEADERS


# AC_CHECK_HEADERS_ONCE(HEADER-FILE...)
# -------------------------------------
AC_DEFUN([AC_CHECK_HEADERS_ONCE],
[
  AH_CHECK_HEADERS([$1])
  m4_foreach_w([AC_Header], [$1],
    [AC_DEFUN([_AC_Header_]m4_quote(m4_translit(AC_Header, [./-], [___])),
       [m4_divert_text([INIT_PREPARE],
	  [ac_header_list="$ac_header_list AC_Header"])
	_AC_HEADERS_EXPANSION])
     AC_REQUIRE([_AC_Header_]m4_quote(m4_translit(AC_Header, [./-], [___])))])
])
m4_define([_AC_HEADERS_EXPANSION],
[
  m4_divert_text([DEFAULTS], [ac_header_list=])
  AC_CHECK_HEADERS([$ac_header_list])
  m4_define([_AC_HEADERS_EXPANSION], [])
])




## --------------------- ##
## 2. Default includes.  ##
## --------------------- ##

# Always use the same set of default headers for all the generic
# macros.  It is easier to document, to extend, and to understand than
# having specific defaults for each macro.

# _AC_INCLUDES_DEFAULT_REQUIREMENTS
# ---------------------------------
# Required when AC_INCLUDES_DEFAULT uses its default branch.
AC_DEFUN([_AC_INCLUDES_DEFAULT_REQUIREMENTS],
[m4_divert_text([DEFAULTS],
[# Factoring default headers for most tests.
dnl If ever you change this variable, please keep autoconf.texi in sync.
ac_includes_default="\
#include <stdio.h>
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif
#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_STRINGS_H
# include <strings.h>
#endif
#if HAVE_INTTYPES_H
# include <inttypes.h>
#endif
#if HAVE_STDINT_H
# include <stdint.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif"
])dnl
AC_REQUIRE([AC_HEADER_STDC])dnl
# On IRIX 5.3, sys/types and inttypes.h are conflicting.
AC_CHECK_HEADERS([sys/types.h sys/stat.h stdlib.h string.h memory.h strings.h \
		  inttypes.h stdint.h unistd.h],
		 [], [], $ac_includes_default)
])# _AC_INCLUDES_DEFAULT_REQUIREMENTS


# AC_INCLUDES_DEFAULT([INCLUDES])
# -------------------------------
# If INCLUDES is empty, expand in default includes, otherwise in
# INCLUDES.
# In most cases INCLUDES is not double quoted as it should, and if
# for instance INCLUDES = `#include <stdio.h>' then unless we force
# a newline, the hash will swallow the closing paren etc. etc.
# The usual failure.
# Take no risk: for the newline.
AC_DEFUN([AC_INCLUDES_DEFAULT],
[m4_ifval([$1], [$1
],
	  [AC_REQUIRE([_AC_INCLUDES_DEFAULT_REQUIREMENTS])dnl
$ac_includes_default])])





## ------------------------------------------- ##
## 3. Headers to check with AC_CHECK_HEADERS.  ##
## ------------------------------------------- ##

# errno.h is portable.

AN_HEADER([OS.h],               [AC_CHECK_HEADERS])
AN_HEADER([argz.h],             [AC_CHECK_HEADERS])
AN_HEADER([arpa/inet.h],        [AC_CHECK_HEADERS])
AN_HEADER([fcntl.h],            [AC_CHECK_HEADERS])
AN_HEADER([fenv.h],             [AC_CHECK_HEADERS])
AN_HEADER([float.h],            [AC_CHECK_HEADERS])
AN_HEADER([fs_info.h],          [AC_CHECK_HEADERS])
AN_HEADER([inttypes.h],         [AC_CHECK_HEADERS])
AN_HEADER([langinfo.h],         [AC_CHECK_HEADERS])
AN_HEADER([libintl.h],          [AC_CHECK_HEADERS])
AN_HEADER([limits.h],           [AC_CHECK_HEADERS])
AN_HEADER([locale.h],           [AC_CHECK_HEADERS])
AN_HEADER([mach/mach.h],        [AC_CHECK_HEADERS])
AN_HEADER([malloc.h],           [AC_CHECK_HEADERS])
AN_HEADER([memory.h],           [AC_CHECK_HEADERS])
AN_HEADER([mntent.h],           [AC_CHECK_HEADERS])
AN_HEADER([mnttab.h],           [AC_CHECK_HEADERS])
AN_HEADER([netdb.h],            [AC_CHECK_HEADERS])
AN_HEADER([netinet/in.h],       [AC_CHECK_HEADERS])
AN_HEADER([nl_types.h],         [AC_CHECK_HEADERS])
AN_HEADER([nlist.h],            [AC_CHECK_HEADERS])
AN_HEADER([paths.h],            [AC_CHECK_HEADERS])
AN_HEADER([sgtty.h],            [AC_CHECK_HEADERS])
AN_HEADER([shadow.h],           [AC_CHECK_HEADERS])
AN_HEADER([stddef.h],           [AC_CHECK_HEADERS])
AN_HEADER([stdint.h],           [AC_CHECK_HEADERS])
AN_HEADER([stdio_ext.h],        [AC_CHECK_HEADERS])
AN_HEADER([stdlib.h],           [AC_CHECK_HEADERS])
AN_HEADER([string.h],           [AC_CHECK_HEADERS])
AN_HEADER([strings.h],          [AC_CHECK_HEADERS])
AN_HEADER([sys/acl.h],          [AC_CHECK_HEADERS])
AN_HEADER([sys/file.h],         [AC_CHECK_HEADERS])
AN_HEADER([sys/filsys.h],       [AC_CHECK_HEADERS])
AN_HEADER([sys/fs/s5param.h],   [AC_CHECK_HEADERS])
AN_HEADER([sys/fs_types.h],     [AC_CHECK_HEADERS])
AN_HEADER([sys/fstyp.h],        [AC_CHECK_HEADERS])
AN_HEADER([sys/ioctl.h],        [AC_CHECK_HEADERS])
AN_HEADER([sys/mntent.h],       [AC_CHECK_HEADERS])
AN_HEADER([sys/mount.h],        [AC_CHECK_HEADERS])
AN_HEADER([sys/param.h],        [AC_CHECK_HEADERS])
AN_HEADER([sys/socket.h],       [AC_CHECK_HEADERS])
AN_HEADER([sys/statfs.h],       [AC_CHECK_HEADERS])
AN_HEADER([sys/statvfs.h],      [AC_CHECK_HEADERS])
AN_HEADER([sys/systeminfo.h],   [AC_CHECK_HEADERS])
AN_HEADER([sys/time.h],         [AC_CHECK_HEADERS])
AN_HEADER([sys/timeb.h],        [AC_CHECK_HEADERS])
AN_HEADER([sys/vfs.h],          [AC_CHECK_HEADERS])
AN_HEADER([sys/window.h],       [AC_CHECK_HEADERS])
AN_HEADER([syslog.h],           [AC_CHECK_HEADERS])
AN_HEADER([termio.h],           [AC_CHECK_HEADERS])
AN_HEADER([termios.h],          [AC_CHECK_HEADERS])
AN_HEADER([unistd.h],           [AC_CHECK_HEADERS])
AN_HEADER([utime.h],            [AC_CHECK_HEADERS])
AN_HEADER([utmp.h],             [AC_CHECK_HEADERS])
AN_HEADER([utmpx.h],            [AC_CHECK_HEADERS])
AN_HEADER([values.h],           [AC_CHECK_HEADERS])
AN_HEADER([wchar.h],            [AC_CHECK_HEADERS])
AN_HEADER([wctype.h],           [AC_CHECK_HEADERS])



## ------------------------------- ##
## 4. Tests for specific headers.  ##
## ------------------------------- ##

# AC_HEADER_ASSERT
# ----------------
# Check whether to enable assertions.
AC_DEFUN([AC_HEADER_ASSERT],
[
  AC_MSG_CHECKING([whether to enable assertions])
  AC_ARG_ENABLE([assert],
    [  --disable-assert        turn off assertions],
    [AC_MSG_RESULT([no])
     AC_DEFINE(NDEBUG, 1, [Define to 1 if assertions should be disabled.])],
    [AC_MSG_RESULT(yes)])
])


# _AC_CHECK_HEADER_DIRENT(HEADER-FILE,
#			  [ACTION-IF-FOUND], [ACTION-IF-NOT_FOUND])
# -----------------------------------------------------------------
# Like AC_CHECK_HEADER, except also make sure that HEADER-FILE
# defines the type `DIR'.  dirent.h on NextStep 3.2 doesn't.
m4_define([_AC_CHECK_HEADER_DIRENT],
[AS_VAR_PUSHDEF([ac_Header], [ac_cv_header_dirent_$1])dnl
AC_CACHE_CHECK([for $1 that defines DIR], ac_Header,
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([#include <sys/types.h>
#include <$1>
],
				    [if ((DIR *) 0)
return 0;])],
		   [AS_VAR_SET(ac_Header, yes)],
		   [AS_VAR_SET(ac_Header, no)])])
AS_IF([test AS_VAR_GET(ac_Header) = yes], [$2], [$3])[]dnl
AS_VAR_POPDEF([ac_Header])dnl
])# _AC_CHECK_HEADER_DIRENT


# AH_CHECK_HEADERS_DIRENT(HEADERS...)
# -----------------------------------
m4_define([AH_CHECK_HEADERS_DIRENT],
[m4_foreach_w([AC_Header], [$1],
  [AH_TEMPLATE(AS_TR_CPP(HAVE_[]AC_Header),
	       [Define to 1 if you have the <]AC_Header[> header file, and
		it defines `DIR'.])])])


# AC_HEADER_DIRENT
# ----------------
AN_HEADER([dirent.h],   [AC_HEADER_DIRENT])
AN_HEADER([ndir.h],     [AC_HEADER_DIRENT])
AN_HEADER([sys/dir.h],  [AC_HEADER_DIRENT])
AN_HEADER([sys/ndir.h], [AC_HEADER_DIRENT])
AC_DEFUN([AC_HEADER_DIRENT],
[AH_CHECK_HEADERS_DIRENT(dirent.h sys/ndir.h sys/dir.h ndir.h)
ac_header_dirent=no
for ac_hdr in dirent.h sys/ndir.h sys/dir.h ndir.h; do
  _AC_CHECK_HEADER_DIRENT($ac_hdr,
			  [AC_DEFINE_UNQUOTED(AS_TR_CPP(HAVE_$ac_hdr), 1)
ac_header_dirent=$ac_hdr; break])
done
# Two versions of opendir et al. are in -ldir and -lx on SCO Xenix.
if test $ac_header_dirent = dirent.h; then
  AC_SEARCH_LIBS(opendir, dir)
else
  AC_SEARCH_LIBS(opendir, x)
fi
])# AC_HEADER_DIRENT


# AC_HEADER_MAJOR
# ---------------
AN_FUNCTION([major],     [AC_HEADER_MAJOR])
AN_FUNCTION([makedev],   [AC_HEADER_MAJOR])
AN_FUNCTION([minor],     [AC_HEADER_MAJOR])
AN_HEADER([sys/mkdev.h], [AC_HEADER_MAJOR])
AC_DEFUN([AC_HEADER_MAJOR],
[AC_CACHE_CHECK(whether sys/types.h defines makedev,
		ac_cv_header_sys_types_h_makedev,
[AC_LINK_IFELSE([AC_LANG_PROGRAM([[@%:@include <sys/types.h>]],
				 [[return makedev(0, 0);]])],
		[ac_cv_header_sys_types_h_makedev=yes],
		[ac_cv_header_sys_types_h_makedev=no])
])

if test $ac_cv_header_sys_types_h_makedev = no; then
AC_CHECK_HEADER(sys/mkdev.h,
		[AC_DEFINE(MAJOR_IN_MKDEV, 1,
			   [Define to 1 if `major', `minor', and `makedev' are
			    declared in <mkdev.h>.])])

  if test $ac_cv_header_sys_mkdev_h = no; then
    AC_CHECK_HEADER(sys/sysmacros.h,
		    [AC_DEFINE(MAJOR_IN_SYSMACROS, 1,
			       [Define to 1 if `major', `minor', and `makedev'
				are declared in <sysmacros.h>.])])
  fi
fi
])# AC_HEADER_MAJOR


# AC_HEADER_RESOLV
# ----------------
# According to http://www.mcsr.olemiss.edu/cgi-bin/man-cgi?resolver+3
# (or http://www.chemie.fu-berlin.de/cgi-bin/man/sgi_irix?resolver+3),
# sys/types.h, netinet/in.h and arpa/nameser.h are required on IRIX.
# netinet/in.h is needed on Cygwin, too.
# With Solaris 9, netdb.h is required, to get symbols like HOST_NOT_FOUND.
#
AN_HEADER(resolv.h,	[AC_HEADER_RESOLV])
AC_DEFUN([AC_HEADER_RESOLV],
[AC_CHECK_HEADERS(sys/types.h netinet/in.h arpa/nameser.h netdb.h resolv.h,
		  [], [],
[[#if HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_NETINET_IN_H
#  include <netinet/in.h>   /* inet_ functions / structs */
#endif
#ifdef HAVE_ARPA_NAMESER_H
#  include <arpa/nameser.h> /* DNS HEADER struct */
#endif
#ifdef HAVE_NETDB_H
#  include <netdb.h>
#endif]])
])# AC_HEADER_RESOLV


# AC_HEADER_STAT
# --------------
# FIXME: Shouldn't this be named AC_HEADER_SYS_STAT?
AN_IDENTIFIER([S_ISBLK], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISCHR], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISDIR], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISFIFO], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISLNK], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISREG], [AC_HEADER_STAT])
AN_IDENTIFIER([S_ISSOCK], [AC_HEADER_STAT])
AC_DEFUN([AC_HEADER_STAT],
[AC_CACHE_CHECK(whether stat file-mode macros are broken,
  ac_cv_header_stat_broken,
[AC_EGREP_CPP([You lose], [#include <sys/types.h>
#include <sys/stat.h>

#if defined S_ISBLK && defined S_IFDIR
# if S_ISBLK (S_IFDIR)
You lose.
# endif
#endif

#if defined S_ISBLK && defined S_IFCHR
# if S_ISBLK (S_IFCHR)
You lose.
# endif
#endif

#if defined S_ISLNK && defined S_IFREG
# if S_ISLNK (S_IFREG)
You lose.
# endif
#endif

#if defined S_ISSOCK && defined S_IFREG
# if S_ISSOCK (S_IFREG)
You lose.
# endif
#endif
], ac_cv_header_stat_broken=yes, ac_cv_header_stat_broken=no)])
if test $ac_cv_header_stat_broken = yes; then
  AC_DEFINE(STAT_MACROS_BROKEN, 1,
	    [Define to 1 if the `S_IS*' macros in <sys/stat.h> do not
	     work properly.])
fi
])# AC_HEADER_STAT


# AC_HEADER_STDBOOL
# -----------------
# Check for stdbool.h that conforms to C99.
AN_IDENTIFIER([bool], [AC_HEADER_STDBOOL])
AN_IDENTIFIER([true], [AC_HEADER_STDBOOL])
AN_IDENTIFIER([false],[AC_HEADER_STDBOOL])
AC_DEFUN([AC_HEADER_STDBOOL],
[AC_CACHE_CHECK([for stdbool.h that conforms to C99],
   [ac_cv_header_stdbool_h],
   [AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
      [[
#include <stdbool.h>
#ifndef bool
 "error: bool is not defined"
#endif
#ifndef false
 "error: false is not defined"
#endif
#if false
 "error: false is not 0"
#endif
#ifndef true
 "error: true is not defined"
#endif
#if true != 1
 "error: true is not 1"
#endif
#ifndef __bool_true_false_are_defined
 "error: __bool_true_false_are_defined is not defined"
#endif

	struct s { _Bool s: 1; _Bool t; } s;

	char a[true == 1 ? 1 : -1];
	char b[false == 0 ? 1 : -1];
	char c[__bool_true_false_are_defined == 1 ? 1 : -1];
	char d[(bool) 0.5 == true ? 1 : -1];
	bool e = &s;
	char f[(_Bool) 0.0 == false ? 1 : -1];
	char g[true];
	char h[sizeof (_Bool)];
	char i[sizeof s.t];
	enum { j = false, k = true, l = false * true, m = true * 256 };
	_Bool n[m];
	char o[sizeof n == m * sizeof n[0] ? 1 : -1];
	char p[-1 - (_Bool) 0 < 0 && -1 - (bool) 0 < 0 ? 1 : -1];
#	if defined __xlc__ || defined __GNUC__
	 /* Catch a bug in IBM AIX xlc compiler version 6.0.0.0
	    reported by James Lemley on 2005-10-05; see
	    http://lists.gnu.org/archive/html/bug-coreutils/2005-10/msg00086.html
	    This test is not quite right, since xlc is allowed to
	    reject this program, as the initializer for xlcbug is
	    not one of the forms that C requires support for.
	    However, doing the test right would require a runtime
	    test, and that would make cross-compilation harder.
	    Let us hope that IBM fixes the xlc bug, and also adds
	    support for this kind of constant expression.  In the
	    meantime, this test will reject xlc, which is OK, since
	    our stdbool.h substitute should suffice.  We also test
	    this with GCC, where it should work, to detect more
	    quickly whether someone messes up the test in the
	    future.  */
	 char digs[] = "0123456789";
	 int xlcbug = 1 / (&(digs + 5)[-2 + (bool) 1] == &digs[4] ? 1 : -1);
#	endif
	/* Catch a bug in an HP-UX C compiler.  See
	   http://gcc.gnu.org/ml/gcc-patches/2003-12/msg02303.html
	   http://lists.gnu.org/archive/html/bug-coreutils/2005-11/msg00161.html
	 */
	_Bool q = true;
	_Bool *pq = &q;
      ]],
      [[
	*pq |= q;
	*pq |= ! q;
	/* Refer to every declared value, to avoid compiler optimizations.  */
	return (!a + !b + !c + !d + !e + !f + !g + !h + !i + !!j + !k + !!l
		+ !m + !n + !o + !p + !q + !pq);
      ]])],
      [ac_cv_header_stdbool_h=yes],
      [ac_cv_header_stdbool_h=no])])
AC_CHECK_TYPES([_Bool])
if test $ac_cv_header_stdbool_h = yes; then
  AC_DEFINE(HAVE_STDBOOL_H, 1, [Define to 1 if stdbool.h conforms to C99.])
fi
])# AC_HEADER_STDBOOL


# AC_HEADER_STDC
# --------------
# FIXME: I find this list very strange.  It comes from the original
# autoscan list, but I don't think it is useful for the same reason
# that we don't bind AC_PROG_CC to finding a C function calls: if the
# user uses bcmp, then she will certainly have the `#include', and
# therefore, we will trigger AC_HEADER_STDC elsewhere.  --akim 2002-09-28
# FIXME: Err... index and rindex are _not_ to be used... --akim 2002-09-28
AN_FUNCTION([bcmp],     [AC_HEADER_STDC])
AN_FUNCTION([bcopy],    [AC_HEADER_STDC])
AN_FUNCTION([bzero],    [AC_HEADER_STDC])
AN_FUNCTION([index],    [AC_HEADER_STDC])
AN_FUNCTION([memchr],   [AC_HEADER_STDC])
AN_FUNCTION([memcpy],   [AC_HEADER_STDC])
AN_FUNCTION([memmove],  [AC_HEADER_STDC])
AN_FUNCTION([memset],   [AC_HEADER_STDC])
AN_FUNCTION([rindex],   [AC_HEADER_STDC])

AN_HEADER([float.h],    [AC_HEADER_STDC])
AN_HEADER([stdarg.h],   [AC_HEADER_STDC])
AN_HEADER([stddef.h],   [AC_HEADER_STDC])
AN_HEADER([stdlib.h],   [AC_HEADER_STDC])
AN_HEADER([string.h],   [AC_HEADER_STDC])

AC_DEFUN([AC_HEADER_STDC],
[AC_CACHE_CHECK(for ANSI C header files, ac_cv_header_stdc,
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <float.h>
]])],
		    [ac_cv_header_stdc=yes],
		    [ac_cv_header_stdc=no])

if test $ac_cv_header_stdc = yes; then
  # SunOS 4.x string.h does not declare mem*, contrary to ANSI.
  AC_EGREP_HEADER(memchr, string.h, , ac_cv_header_stdc=no)
fi

if test $ac_cv_header_stdc = yes; then
  # ISC 2.0.2 stdlib.h does not declare free, contrary to ANSI.
  AC_EGREP_HEADER(free, stdlib.h, , ac_cv_header_stdc=no)
fi

if test $ac_cv_header_stdc = yes; then
  # /bin/cc in Irix-4.0.5 gets non-ANSI ctype macros unless using -ansi.
  AC_RUN_IFELSE([AC_LANG_SOURCE(
[[#include <ctype.h>
#include <stdlib.h>
#if ((' ' & 0x0FF) == 0x020)
# define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
# define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))
#else
# define ISLOWER(c) \
		   (('a' <= (c) && (c) <= 'i') \
		     || ('j' <= (c) && (c) <= 'r') \
		     || ('s' <= (c) && (c) <= 'z'))
# define TOUPPER(c) (ISLOWER(c) ? ((c) | 0x40) : (c))
#endif

#define XOR(e, f) (((e) && !(f)) || (!(e) && (f)))
int
main ()
{
  int i;
  for (i = 0; i < 256; i++)
    if (XOR (islower (i), ISLOWER (i))
	|| toupper (i) != TOUPPER (i))
      return 2;
  return 0;
}]])], , ac_cv_header_stdc=no, :)
fi])
if test $ac_cv_header_stdc = yes; then
  AC_DEFINE(STDC_HEADERS, 1,
	    [Define to 1 if you have the ANSI C header files.])
fi
])# AC_HEADER_STDC


# AC_HEADER_SYS_WAIT
# ------------------
AN_HEADER([sys/wait.h], [AC_HEADER_SYS_WAIT])
AC_DEFUN([AC_HEADER_SYS_WAIT],
[AC_CACHE_CHECK([for sys/wait.h that is POSIX.1 compatible],
  ac_cv_header_sys_wait_h,
[AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([#include <sys/types.h>
#include <sys/wait.h>
#ifndef WEXITSTATUS
# define WEXITSTATUS(stat_val) ((unsigned int) (stat_val) >> 8)
#endif
#ifndef WIFEXITED
# define WIFEXITED(stat_val) (((stat_val) & 255) == 0)
#endif
],
[  int s;
  wait (&s);
  s = WIFEXITED (s) ? WEXITSTATUS (s) : 1;])],
		 [ac_cv_header_sys_wait_h=yes],
		 [ac_cv_header_sys_wait_h=no])])
if test $ac_cv_header_sys_wait_h = yes; then
  AC_DEFINE(HAVE_SYS_WAIT_H, 1,
	    [Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible.])
fi
])# AC_HEADER_SYS_WAIT


# AC_HEADER_TIME
# --------------
AN_IDENTIFIER([timeval],  [AC_HEADER_TIME])
AC_DEFUN([AC_HEADER_TIME],
[AC_CACHE_CHECK([whether time.h and sys/time.h may both be included],
  ac_cv_header_time,
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
],
[if ((struct tm *) 0)
return 0;])],
		   [ac_cv_header_time=yes],
		   [ac_cv_header_time=no])])
if test $ac_cv_header_time = yes; then
  AC_DEFINE(TIME_WITH_SYS_TIME, 1,
	    [Define to 1 if you can safely include both <sys/time.h>
	     and <time.h>.])
fi
])# AC_HEADER_TIME


# _AC_HEADER_TIOCGWINSZ_IN_TERMIOS_H
# ----------------------------------
m4_define([_AC_HEADER_TIOCGWINSZ_IN_TERMIOS_H],
[AC_CACHE_CHECK([whether termios.h defines TIOCGWINSZ],
		ac_cv_sys_tiocgwinsz_in_termios_h,
[AC_EGREP_CPP([yes],
	      [#include <sys/types.h>
#include <termios.h>
#ifdef TIOCGWINSZ
  yes
#endif
],
		ac_cv_sys_tiocgwinsz_in_termios_h=yes,
		ac_cv_sys_tiocgwinsz_in_termios_h=no)])
])# _AC_HEADER_TIOCGWINSZ_IN_TERMIOS_H


# _AC_HEADER_TIOCGWINSZ_IN_SYS_IOCTL
# ----------------------------------
m4_define([_AC_HEADER_TIOCGWINSZ_IN_SYS_IOCTL],
[AC_CACHE_CHECK([whether sys/ioctl.h defines TIOCGWINSZ],
		ac_cv_sys_tiocgwinsz_in_sys_ioctl_h,
[AC_EGREP_CPP([yes],
	      [#include <sys/types.h>
#include <sys/ioctl.h>
#ifdef TIOCGWINSZ
  yes
#endif
],
		ac_cv_sys_tiocgwinsz_in_sys_ioctl_h=yes,
		ac_cv_sys_tiocgwinsz_in_sys_ioctl_h=no)])
])# _AC_HEADER_TIOCGWINSZ_IN_SYS_IOCTL


# AC_HEADER_TIOCGWINSZ
# --------------------
# Look for a header that defines TIOCGWINSZ.
# FIXME: Is this the proper name?  Is this the proper implementation?
# I need more help.
AC_DEFUN([AC_HEADER_TIOCGWINSZ],
[_AC_HEADER_TIOCGWINSZ_IN_TERMIOS_H
if test $ac_cv_sys_tiocgwinsz_in_termios_h != yes; then
  _AC_HEADER_TIOCGWINSZ_IN_SYS_IOCTL
  if test $ac_cv_sys_tiocgwinsz_in_sys_ioctl_h = yes; then
    AC_DEFINE(GWINSZ_IN_SYS_IOCTL,1,
	      [Define to 1 if `TIOCGWINSZ' requires <sys/ioctl.h>.])
  fi
fi
])# AC_HEADER_TIOCGWINSZ


# AU::AC_UNISTD_H
# ---------------
AU_DEFUN([AC_UNISTD_H],
[AC_CHECK_HEADERS(unistd.h)])


# AU::AC_USG
# ----------
# Define `USG' if string functions are in strings.h.
AU_DEFUN([AC_USG],
[AC_MSG_CHECKING([for BSD string and memory functions])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[@%:@include <strings.h>]],
				[[rindex(0, 0); bzero(0, 0);]])],
	       [AC_MSG_RESULT(yes)],
	       [AC_MSG_RESULT(no)
		AC_DEFINE(USG, 1,
			  [Define to 1 if you do not have <strings.h>, index,
			   bzero, etc... This symbol is obsolete, you should
			   not depend upon it.])])
AC_CHECK_HEADERS(string.h)],
[Remove `AC_MSG_CHECKING', `AC_LINK_IFELSE' and this warning
when you adjust your code to use HAVE_STRING_H.])


# AU::AC_MEMORY_H
# ---------------
# To be precise this macro used to be:
#
#   | AC_MSG_CHECKING(whether string.h declares mem functions)
#   | AC_EGREP_HEADER(memchr, string.h, ac_found=yes, ac_found=no)
#   | AC_MSG_RESULT($ac_found)
#   | if test $ac_found = no; then
#   |	AC_CHECK_HEADER(memory.h, [AC_DEFINE(NEED_MEMORY_H)])
#   | fi
#
# But it is better to check for both headers, and alias NEED_MEMORY_H to
# HAVE_MEMORY_H.
AU_DEFUN([AC_MEMORY_H],
[AC_CHECK_HEADER(memory.h,
		[AC_DEFINE([NEED_MEMORY_H], 1,
			   [Same as `HAVE_MEMORY_H', don't depend on me.])])
AC_CHECK_HEADERS(string.h memory.h)],
[Remove this warning and
`AC_CHECK_HEADER(memory.h, AC_DEFINE(...))' when you adjust your code to
use HAVE_STRING_H and HAVE_MEMORY_H, not NEED_MEMORY_H.])


# AU::AC_DIR_HEADER
# -----------------
# Like calling `AC_HEADER_DIRENT' and `AC_FUNC_CLOSEDIR_VOID', but
# defines a different set of C preprocessor macros to indicate which
# header file is found.
AU_DEFUN([AC_DIR_HEADER],
[AC_HEADER_DIRENT
AC_FUNC_CLOSEDIR_VOID
test ac_cv_header_dirent_dirent_h &&
  AC_DEFINE([DIRENT], 1, [Same as `HAVE_DIRENT_H', don't depend on me.])
test ac_cv_header_dirent_sys_ndir_h &&
  AC_DEFINE([SYSNDIR], 1, [Same as `HAVE_SYS_NDIR_H', don't depend on me.])
test ac_cv_header_dirent_sys_dir_h &&
  AC_DEFINE([SYSDIR], 1, [Same as `HAVE_SYS_DIR_H', don't depend on me.])
test ac_cv_header_dirent_ndir_h &&
  AC_DEFINE([NDIR], 1, [Same as `HAVE_NDIR_H', don't depend on me.])],
[Remove this warning and the four `AC_DEFINE' when you
adjust your code to use `AC_HEADER_DIRENT'.])
