# - Find the curses include file and library
#
#  CURSES_FOUND - system has Curses
#  CURSES_INCLUDE_DIR - the Curses include directory
#  CURSES_LIBRARIES - The libraries needed to use Curses
#  CURSES_HAVE_CURSES_H - true if curses.h is available
#  CURSES_HAVE_NCURSES_H - true if ncurses.h is available
#  CURSES_HAVE_NCURSES_NCURSES_H - true if ncurses/ncurses.h is available
#  CURSES_HAVE_NCURSES_CURSES_H - true if ncurses/curses.h is available
#  CURSES_LIBRARY - set for backwards compatibility with 2.4 CMake
#
# Set CURSES_NEED_NCURSES to TRUE before the FIND_PACKAGE() command if NCurses 
# functionality is required.

FIND_LIBRARY(CURSES_LIBRARY NAMES curses )

FIND_LIBRARY(CURSES_NCURSES_LIBRARY NAMES ncurses )

SET(CURSES_USE_NCURSES FALSE)

IF(CURSES_NCURSES_LIBRARY  AND NOT  CURSES_LIBRARY)
  SET(CURSES_USE_NCURSES TRUE)
ENDIF(CURSES_NCURSES_LIBRARY  AND NOT  CURSES_LIBRARY)


# Not sure the logic is correct here.
# If NCurses is required, use the function wsyncup() to check if the library
# has NCurses functionality (at least this is where it breaks on NetBSD).
# If wsyncup is in curses, use this one.
# If not, try to find ncurses and check if this has the symbol.
# Once the ncurses library is found, search the ncurses.h header first, but
# some web pages also say that even with ncurses there is not always a ncurses.h:
# http://osdir.com/ml/gnome.apps.mc.devel/2002-06/msg00029.html
# So at first try ncurses.h, if not found, try to find curses.h under the same
# prefix as the library was found, if still not found, try curses.h with the 
# default search paths.
IF(CURSES_LIBRARY  AND  CURSES_NEED_NCURSES)
  INCLUDE(CheckLibraryExists)
  CHECK_LIBRARY_EXISTS("${CURSES_LIBRARY}" wsyncup "" CURSES_CURSES_HAS_WSYNCUP)

  IF(CURSES_NCURSES_LIBRARY  AND NOT  CURSES_CURSES_HAS_WSYNCUP)
    CHECK_LIBRARY_EXISTS("${CURSES_NCURSES_LIBRARY}" wsyncup "" CURSES_NCURSES_HAS_WSYNCUP)
    IF( CURSES_NCURSES_HAS_WSYNCUP)
      SET(CURSES_USE_NCURSES TRUE)
    ENDIF( CURSES_NCURSES_HAS_WSYNCUP)
  ENDIF(CURSES_NCURSES_LIBRARY  AND NOT  CURSES_CURSES_HAS_WSYNCUP)

ENDIF(CURSES_LIBRARY  AND  CURSES_NEED_NCURSES)


IF(NOT CURSES_USE_NCURSES)
  FIND_FILE(CURSES_HAVE_CURSES_H curses.h )
  FIND_PATH(CURSES_INCLUDE_PATH curses.h )

  GET_FILENAME_COMPONENT(_cursesLibDir "${CURSES_LIBRARY}" PATH)
  GET_FILENAME_COMPONENT(_cursesParentDir "${_cursesLibDir}" PATH)
ELSE(NOT CURSES_USE_NCURSES)
# we need to find ncurses
  GET_FILENAME_COMPONENT(_cursesLibDir "${CURSES_NCURSES_LIBRARY}" PATH)
  GET_FILENAME_COMPONENT(_cursesParentDir "${_cursesLibDir}" PATH)

  FIND_FILE(CURSES_HAVE_NCURSES_H         ncurses.h)
  FIND_FILE(CURSES_HAVE_NCURSES_NCURSES_H ncurses/ncurses.h)
  FIND_FILE(CURSES_HAVE_NCURSES_CURSES_H  ncurses/curses.h)
  FIND_FILE(CURSES_HAVE_CURSES_H          curses.h  PATHS "${_cursesParentDir}/include" NO_DEFAULT_PATH)
  FIND_FILE(CURSES_HAVE_CURSES_H          curses.h)

  FIND_PATH(CURSES_NCURSES_INCLUDE_PATH ncurses.h ncurses/ncurses.h  ncurses/curses.h)
  FIND_PATH(CURSES_NCURSES_INCLUDE_PATH curses.h  PATHS "${_cursesParentDir}/include" NO_DEFAULT_PATH)
  FIND_PATH(CURSES_NCURSES_INCLUDE_PATH curses.h)

  SET(CURSES_INCLUDE_PATH "${CURSES_NCURSES_INCLUDE_PATH}")
  SET(FORCE_ARG "")
  IF("${CURSES_LIBRARY}" STREQUAL "CURSES_LIBRARY-NOTFOUND")
    SET(FORCE_ARG "FORCE")
  ENDIF("${CURSES_LIBRARY}" STREQUAL "CURSES_LIBRARY-NOTFOUND")
  SET(CURSES_LIBRARY "${CURSES_NCURSES_LIBRARY}" CACHE FILEPATH "path to curses" ${FORCE_ARG})
ENDIF(NOT CURSES_USE_NCURSES)


FIND_LIBRARY(CURSES_EXTRA_LIBRARY cur_colr PATHS "${_cursesLibDir}" NO_DEFAULT_PATH)
FIND_LIBRARY(CURSES_EXTRA_LIBRARY cur_colr )

FIND_LIBRARY(CURSES_FORM_LIBRARY form PATHS "${_cursesLibDir}" NO_DEFAULT_PATH)
FIND_LIBRARY(CURSES_FORM_LIBRARY form )

# Need to provide the *_LIBRARIES
SET(CURSES_LIBRARIES ${CURSES_LIBRARY})

IF(CURSES_EXTRA_LIBRARY)
  SET(CURSES_LIBRARIES ${CURSES_LIBRARIES} ${CURSES_EXTRA_LIBRARY})
ENDIF(CURSES_EXTRA_LIBRARY)

IF(CURSES_FORM_LIBRARY)
  SET(CURSES_LIBRARIES ${CURSES_LIBRARIES} ${CURSES_FORM_LIBRARY})
ENDIF(CURSES_FORM_LIBRARY)

# Proper name is *_INCLUDE_DIR
SET(CURSES_INCLUDE_DIR ${CURSES_INCLUDE_PATH})

# handle the QUIETLY and REQUIRED arguments and set CURSES_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Curses DEFAULT_MSG CURSES_LIBRARY CURSES_INCLUDE_PATH)

# for compatibility
SET(FORM_LIBRARY "${CURSES_FORM_LIBRARY}")

MARK_AS_ADVANCED(
  CURSES_INCLUDE_PATH
  CURSES_LIBRARY
  CURSES_CURSES_INCLUDE_PATH
  CURSES_LIBRARY
  CURSES_NCURSES_INCLUDE_PATH
  CURSES_NCURSES_LIBRARY
  CURSES_EXTRA_LIBRARY
  FORM_LIBRARY
  CURSES_LIBRARIES
  CURSES_INCLUDE_DIR
  CURSES_CURSES_HAS_WSYNCUP
  CURSES_NCURSES_HAS_WSYNCUP
  )

