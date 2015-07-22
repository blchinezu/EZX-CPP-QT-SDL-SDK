#ifndef UTIL_SKIN_H
#define UTIL_SKIN_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//----------------------------------------------------------------------------
//                                                                        
//   Module Name: UTIL_Skin.h
//
//   General Description: Base class for resource readers
//
//----------------------------------------------------------------------------
//
//                     Motorola Confidential Proprietary
//          Template ID and version: IL93-TMP-01-0108  Version 1.10
//           (c) Copyright Motorola 2002-2003, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description
// -------------------------   ------------    ----------   ----------------
// Peter McDermott/w20027       04/04/2003                  created 
//
// Portability: should be portable to any compliant C++ compiler
//
//----------------------------------------------------------------------------
//                                INCLUDE FILES
//----------------------------------------------------------------------------

#include <qpixmap.h>

#include "UTIL_ResReader.h"

class UTIL_ResFileReader;

//----------------------------------------------------------------------------
//                            CLASS UTIL_Skin
//----------------------------------------------------------------------------
class UTIL_Skin : public UTIL_ResReader {

public:

    //
    // call get to get the skin object
    //

    static UTIL_Skin& get();                    // get ref to the default skin
    static void reloadDef();                    // reload the default skin

    // d-tor

    virtual ~UTIL_Skin();
    
    //
    // return bool indicating whether or not a resource exists
    //

    virtual bool exists(const char *pID) const;
    virtual bool pixmapExists(const char * pGraphicID) const;
    
    //
    // getPixmapPtr - returns a QPixmap* for a given graphic id.
    //
    // Note: a graphic id does not have a file extension.
    //       So, if the file is named, 'Somegraphic.gif,"
    //       the graphic id is just 'Somegraphic'
    //
    // Note: returns NULL if no pixmap matches the graphicID
    //
    // NOTE: CALLER MUST DELETE QPIXMAP* RETURNED FROM THIS METHOD
    //

    virtual QPixmap* getPixmapPtr(const char *pGraphicID);
    
    //
    // getPixmap - returns a QPixmap for a given graphic id.
    //
    // Note: a graphic id does not have a file extension.
    //       So, if the file is named, 'Somegraphic.gif,"
    //       the graphic id is just 'Somegraphic'
    //
    // Note: returns a NULL QPixmap if no pixmap matches the graphicID
    //
    // Note: this incurs an object copy.  getPixmapPtr() is faster, if you can use it.
    //

    virtual QPixmap getPixmap(const char *pGraphicID);
    
    //
    // get the data for a resource.
    //
    // Do not delete/de-allocate the pointer returned from this function.
    //

    virtual bool get(const char *pID, 
                     unsigned char** ppOutData, 
                     int* pOutLength) const;

    // 
    // same as above, but gets the resource matching the full file name
    // specified.  This is slightly slower than get().
    //
    
    virtual bool getByFullFileName(const char *pFullFileName, 
                                   unsigned char **ppOutData, 
                                   int *pOutLength) const;

    //
    // same as above, but gets the resource matching the file name
    // specified.  Evertything before and including the last '/' in
    // the file name is thrown away. This is slightly slower than get().
    //
    
    virtual bool getByFileName(const char *pFileName, 
                               unsigned char **ppOutData, 
                               int *pOutLength) const;

private:

    UTIL_Skin();
    UTIL_Skin(const char *, const char *);

    void init(const char * pBaseName, const char * pSkinName);

    UTIL_ResFileReader *base;
    UTIL_ResFileReader *skin;
   
    static UTIL_Skin *defaultSkin; 
};

#endif // UTIL_SKIN_H


