
//-------------------------------------------------------------------------------------------------
//
// Header Name: ZDef.h
//
// General Description: Platform-level definitions.
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_DEFS_H
#define Z_DEFS_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif
/*
#include <qstringlist.h>
#include <qcstring.h>
#include <qwidget.h>
#include <qrect.h>
#include <qsize.h>
#include <qpopupmenu.h>
#include <quuid.h>
#include <qmap.h>
#include <qstring.h>
*/
/**
 * Define platform level Macros of application setup, and global type definitions.
 * Application setup module defines Macros are related to AP flex, Theme,
 * TouchScreen, Language, handwriting, configuration paths
 * and default locale stuffs like region.
 */

/**
 * EZX date range
 */
#define EZX_YEAR_MAX 2069
#define EZX_YEAR_MIN 1901

/**
 * EZX server application's channel name
 */
#define EZXQTSERVER_CHANNEL "EZX/QtServer"

/**
 * EZX input widget server's channel name
 */
#define IMSERVCHANNEL_NAME "EZX/IMServer"

/**
 * EZX system channel name
 */
#define SYSTEM_CHANNEL "EZX/System"

/**
 * EZX application channel name prefix
 */
#define APP_CHANNEL_PREF "EZX/Application/"

#include <qevent.h>

#define RETURN_IDLE_EVENT            5678
#define RETURN_IDLE_BY_END_KEY       -5000
#define RETURN_IDLE_BY_FLIP          -5001
#define RETURN_IDLE_BY_APP_TIMEOUT   -5002
namespace ZGlobal
{
    /**
     * @enum TouchSoundType_T enumerates all possible touch screen sound configurations.
     * One of these enumeration value is valid for the software system in all time.
     */
    enum TouchSoundType_T
    {
        CLICK = 0,///<Play a quick sound at the moment of touching screen, analog to click.
        TONE,///<Play a slip of sound when screen touched, counterpart to @@see CLICK
        SILENT,///<No sound played when screen touched.
        THEMED///<The sound is theme configurated.
    };
};

#endif //Z_DEFS_H
