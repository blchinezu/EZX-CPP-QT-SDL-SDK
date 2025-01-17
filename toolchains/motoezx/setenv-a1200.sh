#!/bin/bash

#if [ "$HOSTNAME" = "Vasile" ] && [ "$USER" = "brucelee" ]; then
if [ "$HOSTNAME" = "ubuntu" ] && [ "$USER" = "ubuntu" ]; then
	export SDK_VERSION="`/bin/date +'%Y/%m/%d'`"
else
	export SDK_VERSION="2011/08/31"
fi

syntax='. setenv-a1200.sh <ezx|sdl> <lib> <shared|static>'
mod=''

if [ "$1" != "ezx" ] && [ "$1" != "sdl" ]; then printf "\n > Syntax: $syntax\n\n"; else mod="$1"
	PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]'$mod' SDK\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '

# SDK Dirs
	SDK_PATH=/opt/toolchains/motoezx
	SDK_DIR=$SDK_PATH
	SDK_INC_DIR=$SDK_PATH/include
	SDK_LIB_DIR=$SDK_PATH/lib
	export SDK_PATH SDK_DIR SDK_INC_DIR SDK_LIB_DIR

# EZX Dirs
	SDK_EZX_INC_DIR=$SDK_INC_DIR/ezx
	SDK_EZX_LIB_DIR=$SDK_LIB_DIR/ezx/ezx/lib
	SDK_EZX_LIB_DIR1=$SDK_EZX_LIB_DIR
	SDK_EZX_LIB_DIR2=$SDK_LIB_DIR/ezx
	export SDK_EZX_INC_DIR SDK_EZX_LIB_DIR SDK_EZX_LIB_DIR1 SDK_EZX_LIB_DIR2

# QT Dirs
	QTDIR=$SDK_PATH/qt
	SDK_QT_DIR=$QTDIR
	SDK_QT_INC_DIR=$SDK_INC_DIR/qt
	SDK_QT_INC_DIR2=$SDK_INC_DIR/qt-ext
	SDK_QT_LIB_DIR=$SDK_EZX_LIB_DIR
	export QTDIR SDK_QT_DIR SDK_QT_INC_DIR SDK_QT_INC_DIR2 SDK_QT_LIB_DIR

# Crosstool Vars
	QMAKESPEC=$SDK_QT_DIR/mkspecs/qws/linux-gnu-ezx-g++
	case "$mod" in sdl) TMAKEPATH="$SDK_QT_DIR/tmake/lib/qws/linux-gnu-ezx-sdl-g++" ;; ezx) TMAKEPATH="$SDK_QT_DIR/tmake/lib/qws/linux-gnu-ezx-g++" ;; esac
	CROSSTOOL_DIR=$SDK_PATH/crosstool
	PATH=$SDK_QT_DIR/bin:$SDK_QT_DIR/tmake/bin:$CROSSTOOL_DIR/bin:$SDK_PATH/bin:$PATH
	export QMAKESPEC TMAKEPATH CROSSTOOL PATH

# SDL Vars
	case "$mod" in sdl)
		SDK_SDL_INC_DIR=$SDK_INC_DIR/SDL
		SDLCONFIG=$SDK_DIR/bin/sdl-config
		SDK_SDL_CFLAGS=`sdl-config --cflags`
		SDK_SDL_LFLAGS=`sdl-config --libs`
		export SDK_SDL_INC_DIR SDLCONFIG SDK_SDL_CFLAGS SDK_SDL_LFLAGS
	;; esac

# Crosscompiling bins
	base=arm-linux-gnu
	CROSS_COMPILE=$base
	CC=${base}-gcc			; SDK_CC=$CC			;
	CXX=${base}-g++			; SDK_CXX=$CXX			;
	LD=${base}-ld			; SDK_LD=$LD			;
	AR=${base}-ar			; SDK_AR=$AR			;
	AS=${base}-as			; SDK_AS=$AS			;
	OC=${base}-objcopy		; SDK_OC=$OC			; SDK_OBJCOPY=$OC	;
	RANLIB=${base}-ranlib	; SDK_RANLIB=$RANLIB	;
	STRIP=${base}-strip		; SDK_STRIP=$STRIP		;
	export CROSS_COMPILE CC CXX LD AR AS OC RANLIB STRIP SDK_CC SDK_CXX SDK_LD SDK_AR SDK_AS SDK_OC SDK_OBJCOPY SDK_RANLIB SDK_STRIP

# Configure args
	SDK_CONFIGURE="--build=x86_64-unknown-linux-gnu --host=arm-linux --prefix=`pwd`/PREFIX"
	export SDK_CONFIGURE

# Compiling flags
	ARCH=iwmmxt
	SDK_CFLAGS="-O2 -pipe -mcpu=$ARCH -mtune=$ARCH -I$SDK_EZX_INC_DIR -I$SDK_QT_INC_DIR -I$SDK_QT_INC_DIR2 -I$SDK_INC_DIR"; CFLAGS=$SDK_CFLAGS; CFLAGS_EXTRA=$CFLAGS
	SDK_CXXFLAGS=$SDK_CFLAGS; CXXFLAGS=$SDK_CXXFLAGS; CXXFLAGS_EXTRA=$CXXFLAGS
	export ARCH SDK_CFLAGS SDK_CXXFLAGS CFLAGS CXXFLAGS CFLAGS_EXTRA CXXFLAGS_EXTRA

# Linking flags
	SDK_LDFLAGS="-Wl,-rpath-link,$CROSSTOOL_DIR/arm-linux-gnu/lib -Wl,-rpath,$SDK_EZX_LIB_DIR -L$SDK_EZX_LIB_DIR -Wl,-rpath-link,$SDK_EZX_LIB_DIR -L$SDK_EZX_LIB_DIR -Wl,-rpath,$SDK_LIB_DIR -L$SDK_LIB_DIR -Wl,-rpath-link,$SDK_LIB_DIR -L$SDK_LIB_DIR -L$SDK_EZX_LIB_DIR2 -L$SDK_EZX_LIB_DIR/inputmethods -L$SDK_EZX_LIB_DIR/dm_plugin"
	SDK_LFLAGS=$SDK_LDFLAGS; LDFLAGS=$SDK_LDFLAGS; LDFLAGS_EXTRA=$SDK_LDFLAGS; LFLAGS=$SDK_LFLAGS; LFLAGS_EXTRA=$LFLAGS
	export SDK_LDFLAGS SDK_LFLAGS LDFLAGS LFLAGS LDFLAGS_EXTRA LFLAGS_EXTRA

# Clear screen binary from host
	export clear=/usr/bin/clear
	alias clear='$clear'


	printf "\n $mod environment loaded.\n\n"

#	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SDK_LIB_DIR
fi

