//------------------------------------------------------------------------
//
//  Header Name: ZIMethod.h
//
//  General Description: Input method definitions
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z760_IMETHOD_H
#define Z760_IMETHOD_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif


#include <quuid.h>
#include <qmap.h>
#include <qstring.h>

/**
 * This file defines the EZX pre-defined keyboards and some keyboard 
 * related functions.
 */

/**
 * English keyboard 
 *
 * {637A8A14-AF98-41DA-969A-2BD16ECDA800}
 */
#ifndef IMID_ENGLISH_KB
#  define IMID_ENGLISH_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x00)
#endif


/**
 * Number keyboard 
 *
 * {637A8A14-AF98-41DA-969A-2BD16ECDA810}
 */
#ifndef IMID_NUMBER_KB
#  define IMID_NUMBER_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x10)
#endif

/**
 * Chinese PinYin keyboard 
 *
 * {637A8A14-AF98-41DA-969A-2BD16ECD0010}
 */
#ifndef IMID_PINYIN_KB
#  define IMID_PINYIN_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0x00, 0x10)
#endif


/**
 * Chinese ZhuYin keyboard 
 *
 * {637A8A14-AF98-41DA-969A-2BD16ECDA010}
 */
#ifndef IMID_ZHUYIN_KB
#  define IMID_ZHUYIN_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa0, 0x10)
#endif

// {637A8A10-AF98-41DA-969A-2BD16ECDA813}
# ifndef IMID_THAI_KB
#  define IMID_THAI_KB QUuid( 0x637a8a10, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x13)
# endif

/**
 * Handwriting keyboard 
 *
 * {HWRCLASS-AF98-41DA-969A-2BD16ECDA410}
 */
#define HWRCLASS     0x6919720a
#ifndef IMID_HANDWRITING_KB
#  define IMID_HANDWRITING_KB QUuid( HWRCLASS, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa4, 0x10)
#endif



/**
 * MMS message composer object keyboard 
 *
 * {637A8A00-AF98-41DA-969A-2BD16ECD0000}
 */
#ifndef IMID_MMSOBJECT_KB
#  define IMID_MMSOBJECT_KB QUuid( 0x637a8a00, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0x00, 0x00)
#endif


/**
 * EMS message composer object keyboard 
 *
 * {637A8A00-AF98-41DA-969A-2BD16ECD0010}
 */
#ifndef IMID_EMSOBJECT_KB
#  define IMID_EMSOBJECT_KB QUuid( 0x637a8a00, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0x00, 0x10)
#endif


#ifndef IMID_UNDEFINED
#define IMID_UNDEFINED QUuid()
#endif

typedef QMap<QUuid, QString> QIMMap;

namespace ZGlobal
{
    /**
     * Set the input method
     *
     * @param inputMethod the input method selected.  If the input method is not 
     * specified, the default input method will be used
     *
     * @see ZApplication
     *
     * @see ZMainWidget
     *
     * @note the function will be implemented in the A780
     */
    void setInputMethod(const QUuid& inputMethod = IMID_UNDEFINED);

    /**
     * Hide the input method widget
     *
     * @note the function will be implemented in the A780
     */
    void hideInputWidget();

    /**
     * Show the input method widget
     *
     * @param mwId the id of the widget which is bound with input widget
     *
     * @internal
     */
    void showInputWidget(int mwId, int show, bool local = false,QUuid  const& kb=IMID_ENGLISH_KB);

    /**
     * Set the input method
     *
     * @param mwId the id of the widget which is bound with input widget
     * @param inputMethod the input method selected
     *
     * @internal
     */
    void setInputMethod(int mwId, const QUuid& inputMethod, bool local = false);
};

#endif //Z760_IMETHOD_H



