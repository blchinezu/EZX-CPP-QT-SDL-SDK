//-------------------------------------------------------------------------------------------------
//
// Header Name: Z760HKey.h
//
// General Description: Hardkey definitions
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z760_HKEY_H
#define Z760_HKEY_H


/**
 * These model-dependent defines map harkey names to 
 * Qt key names.
 *
 * As more hardkeys are added to new products,
 * for example, A780, a new model-dependent header must
 * be created and symbolically linked to ZHKey.h
 *
 * @see ZGlobal.h
 */
//total 17

#define EZX_KEY_VALUE_UP            Qt::Key_PageUp
#define EZX_KEY_VALUE_DOWN          Qt::Key_PageDown
#define EZX_KEY_VALUE_JOY_R         Qt::Key_Return
#define EZX_KEY_VALUE_HOME          Qt::Key_F4
#define EZX_KEY_VALUE_JOY_L         Qt::Key_Up
#define EZX_KEY_VALUE_JOY_M         Qt::Key_Down
#define EZX_KEY_VALUE_VOICE_REC     Qt::Key_F2
#define EZX_KEY_VALUE_ANSWER        Qt::Key_F5
#define EZX_KEY_VALUE_FLIP          Qt::Key_F3
#define EZX_KEY_VALUE_HEADSET_INT   Qt::Key_F1


#define E6_KEY_VALUE_OK            Qt::Key_Return
#define E6_KEY_VALUE_LEFT          Qt::Key_Left
#define E6_KEY_VALUE_UP            Qt::Key_Up
#define E6_KEY_VALUE_RIGHT         Qt::Key_Right
#define E6_KEY_VALUE_DOWN          Qt::Key_Down
#define E6_KEY_VALUE_CALL          Qt::Key_F1
#define E6_KEY_VALUE_HANG          Qt::Key_F2
#define E6_KEY_VALUE_BROWSER       Qt::Key_F4
#define E6_KEY_VALUE_CAM           Qt::Key_F5
#define E6_KEY_VALUE_SHORTCUT      Qt::Key_F30
#define E6_KEY_VALUE_VOICE_UP      Qt::Key_PageUp
#define E6_KEY_VALUE_VOICE_DOWN    Qt::Key_PageDown
#define E6_KEY_VALUE_PLAY          Qt::Key_F26
#define E6_KEY_VALUE_PLAY_PRE      Qt::Key_F28
#define E6_KEY_VALUE_PLAY_NEXT     Qt::Key_F29


#endif //Z760_HKEY_H
