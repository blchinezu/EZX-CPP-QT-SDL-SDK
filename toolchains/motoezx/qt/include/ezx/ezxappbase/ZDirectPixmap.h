//-------------------------------------------------------------------------------------------------
//                                                                    
//   Header Name: ZDirectPixmap.h
//
//   General Description: Used to access the protected fields in QPixmap.
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef ZDIRECTPIXMAP_H
#define ZDIRECTPIXMAP_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qpixmap.h>

/**
 * Provides a wrapper so that applications can directly access the fields of 
 * a QPixmap
 *
 * Qt does not allow applications to access the individual bytes of a 
 * QPixmap because, traditionally, the QPixmap might live on another computer
 * (an X-Windows server, for example).  However, qt-embedded applications
 * don't have this restriction.  So ZDirectPixmap was created to allow
 * a QPixmap to be directly accessible.
 */

class ZDirectPixmap : public QPixmap
{
public:

    /**
     * Constructor for a DirectPixmap.
     *
     * @param width width in pixels
     * @param height height in pixels
     * @param depth depth in bits per pixel (default is -1)
     */
    ZDirectPixmap(int width, int height, int depth=-1);
   
    /**
     * returns a pointer to the actual data contained in the pixmap
     */ 
    unsigned char* bits();

    /**
     * returns a const pointer to the actual data contained in the pixmap
     */
    const unsigned char* bits() const;

    /**
     * returns the number of bytes per line for the pixmap. 
     */
    int bytesPerLine() const;

};

#endif // #ifndef ZDIRECTPIXMAP_H
    
