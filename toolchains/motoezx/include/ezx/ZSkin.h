//-------------------------------------------------------------------------------------------------
//                                                                        
//   Module Name: zskin.h
//
//   General Description: Used to access resources in current skin set
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef ZSKIN_H
#define ZSKIN_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif


#include <qstring.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qbitmap.h>
#include <qmovie.h>
#include <ZResource.h>


/**
 * Implements the application skin.
 *
 * The application skin is a stack of between zero and four resource files,
 * the application skin, the applicaiton base, the system skin, and the 
 * system base.
 *
 * @code
 * void myClass::myFunc(...)
 * {
 *     // skin is const (read-only)
 *     const ZSkin& skin = ZSkin::skin();   
 *     
 *     QPixmap pm = skin.getPixmap("CST_Back_O.g");
 *     // pm now contains the pixmap for the 'back' button overlay.
 *
 *     void *data;
 *     int length;
 *
 *     if (skin.get("somedata.dat", &data, &length))
 *     {
 *          printf("somedata.dat is located at 0x%08x and is of length %d",
 *                 data, length);
 *     }
 *     else
 *     {
 *          printf("somedata.dat could not be found");
 *     }
 * }
 * @endcode
 */
class ZSkin : public ZResReader
{
public:

    /**
     * get a reference to the application's skin.
     */
    static const ZSkin& skin();

    /**
     * @return bool indicating whether or not a resource exists
     */
    virtual bool exists(const QString& ID) const;
   
    /**
     * get a QPixmap associated with a resource ID
     *
     * @param ID is the resource ID of the pixmap ("name.g")
     *
     * @note resource IDs for graphics do not maintain the file-extension
     * of the file stored on disk (.gif, .jpg, etc.).  When put into
     * the resource file, the all are changed to .g
     */
    virtual QPixmap getQPixmap(const QString& ID) const;
  
    /**
     * get a QImage associated with a resource ID
     *
     * @param ID is the resource ID of the pixmap ("name.g")
     *
     * @note resource IDs for graphics do not maintain the file-extension
     * of the file stored on disk (.gif, .jpg, etc.).  When put into the
     * resource file, the all are changed to .g
     */
    virtual QImage getQImage(const QString& ID) const;

    /**
     * get a QBitmap associated with a resource ID
     *
     * @param ID is the resource ID of the pixmap ("name.bmp")
     */
    virtual QBitmap getQBitmap(const QString& ID) const;

    /**
     * get a QMovie associated with a resource ID
     *
     * @param ID is the resource ID of the pixmap ("name.swf")
     */
    virtual QMovie getQMovie(const QString& ID) const;
    
    /**
     * get the data associated with a resource ID
     *
     * @note Do not delete/de-allocate the pointer returned from this function.
     */
    virtual bool get(const QString& ID, 
                     unsigned char** ppOutData, 
                     int* pOutLength) const;
    
    /**
     * reload the default skin
     *
     * @internal
     */
    static void reloadSkin();                

protected:

    ZSkin();
    virtual ~ZSkin();
    
    ZSkin(const QString& systemBaseName, 
          const QString& systemSkinName,
          const QString& applicationBaseName,
          const QString& applicationSkinName);

    void init(const QString& systemBaseName, 
              const QString& systemSkinName,
              const QString& applicationBaseName,
              const QString& applicationSkinName);

    ZResFileReader *systemBase;
    ZResFileReader *systemSkin;
    ZResFileReader *appBase;
    ZResFileReader *appSkin;
   
    static ZSkin *defaultSkin; 
};

#endif // #ifndef ZSKIN_H
