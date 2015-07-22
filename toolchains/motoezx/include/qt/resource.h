/**********************************************************************
** Copyright (C) 2001 Trolltech AS.  All rights reserved.
**
** This file is part of the Qtopia Environment.
**
** Licensees holding valid Qtopia Developer license may use this
** file in accordance with the Qtopia Developer License Agreement
** provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE.
**
** email sales@trolltech.com for information about Qtopia License
** Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/
#ifndef PIXMAPLOADER_H
#define PIXMAPLOADER_H

#include <qimage.h>
#include <qbitmap.h>
#include <qiconset.h>
#include <qstringlist.h>

class Resource
{
public:
    Resource() {}

    static QImage loadImage( const QString &name);

    static QPixmap loadPixmap( const QString &name );
    static QBitmap loadBitmap( const QString &name );
    static QString findPixmap( const QString &name );

    static QIconSet loadIconSet( const QString &name );

    static QString findSound( const QString &name );
    static QStringList allSounds();
};

// Inline for compatibility with SHARP ROMs
inline QIconSet Resource::loadIconSet( const QString &pix ) 
{
    QImage img = loadImage( pix );
    QPixmap pm;
    pm.convertFromImage( img );
    QIconSet is( pm );
    QIconSet::Size size = pm.width() <= 22 ? QIconSet::Small : QIconSet::Large;

    QPixmap dpm = loadPixmap( pix + "_disabled" );

#ifndef QT_NO_DEPTH_32	// have alpha-blended pixmaps
    if ( dpm.isNull() ) {
	QImage dimg( img.width(), img.height(), 32 );
	for ( int y = 0; y < img.height(); y++ ) {
	    for ( int x = 0; x < img.width(); x++ ) {
		QRgb p = img.pixel( x, y );
		uint a = (p & 0xff000000) / 3;
		p = (p & 0x00ffffff) | (a & 0xff000000);
		dimg.setPixel( x, y, p );
	    }
	}

	dimg.setAlphaBuffer( TRUE );
	dpm.convertFromImage( dimg );
    }
#endif

    if ( !dpm.isNull() )
	is.setPixmap( dpm, size, QIconSet::Disabled );

    return is;
}


#endif
