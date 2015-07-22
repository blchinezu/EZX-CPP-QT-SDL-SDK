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

#endif //Z760_HKEY_H
