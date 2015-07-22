/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2005 Sam Revitch <samr7@cs.washington.edu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Further, this software is distributed without any warranty that it is
 * free of the rightful claim of any third person regarding infringement
 * or the like.  Any license provided herein, whether implied or
 * otherwise, applies only to this software file.  Patent licenses, if
 * any, provided herein do not apply to combinations of this program with
 * other software, or any other product whatsoever.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef Z_SKIN_H
#define Z_SKIN_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qbitmap.h>
#include <qmovie.h>
#include <zresource.h>

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



/*
#include <qstring.h>
//#include <qpixmap.h>
//#include <qarray.h>
//#include <qsortedlist.h>
#include <zresource.h>

class ZDirectPixmap;

class ZSkin : public ZResReader {
public:
    static const ZSkin& skin();

    // Reimplemented virtual methods
    virtual bool exists(const QString& ID) const;

    // New virtual methods
    virtual QPixmap getQPixmap(const QString& ID) const;
    virtual QImage getQImage(const QString& ID) const;
    virtual QBitmap getQBitmap(const QString& ID) const;
    virtual QMovie getQMovie(const QString& ID) const;

    virtual bool get(const QString& ID,
                     unsigned char** ppOutData,
                     int* pOutLength) const;

    static void reloadSkin();

protected:
    // Non-virtual methods
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
*/

#endif
