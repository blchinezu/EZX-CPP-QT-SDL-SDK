/****************************************************************************
** $Id: qt/src/kernel/qmemorymanager_qws.h   2.3.6   edited 2001-02-09 $
**
** Definition of QMemoryManager class
**
** Created : 000411
**
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses for Qt/Embedded may use this file in accordance with the
** Qt Embedded Commercial License Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QMEMORYMANAGER_H
#define QMEMORYMANAGER_H

#ifndef QT_H
#include <qfontmanager_qws.h>
#include <qstring.h>
#include <qmap.h>
#endif // QT_H

class QFontDef;
class QMemoryManagerPixmap {
    friend class QMemoryManager;
    uchar* data;
    int xoffset;
};

class QMemoryManager {
public:
    QMemoryManager(
	void* vram, int vramsize,
	void* fontrom
	//, ...
    );

    // Pixmaps
    typedef int PixmapID;
    PixmapID newPixmap(int w, int h, int d, int optim );
    void deletePixmap(PixmapID);
    bool inVRAM(PixmapID) const;
    void findPixmap(PixmapID,
	    int width, int depth, // sames as passed when created
	    uchar** address, int* xoffset, int* linestep);

    // Fonts
    typedef void* FontID;
    FontID refFont(const QFontDef&);
    void derefFont(FontID);
    QRenderedFont* fontRenderer(FontID); // XXX JUST FOR METRICS
    bool inFont(FontID, const QChar&) const;
    QGlyph lockGlyph(FontID, const QChar&);
    QGlyphMetrics* lockGlyphMetrics(FontID, const QChar&);
    void unlockGlyph(FontID, const QChar&);
#ifndef QT_NO_QWS_SAVEFONTS
    void savePrerenderedFont(const QFontDef&, bool all=TRUE);
    void savePrerenderedFont(FontID id, bool all=TRUE);
#endif
    bool fontSmooth(FontID id) const;
    int fontAscent(FontID id) const;
    int fontDescent(FontID id) const;
    int fontMinLeftBearing(FontID id) const;
    int fontMinRightBearing(FontID id) const;
    int fontLeading(FontID id) const;
    int fontMaxWidth(FontID id) const;
    int fontUnderlinePos(FontID id) const;
    int fontLineWidth(FontID id) const;
    int fontLineSpacing(FontID id) const;

private:
    QMap<PixmapID,QMemoryManagerPixmap> pixmap_map;
    int next_pixmap_id;
    QMap<QString,FontID> font_map;
    int next_font_id;

#if defined(QT_EZX_MUNGE)
public:
    void setRawData(int, unsigned char*, int, int);
#endif
};

extern QMemoryManager* memorymanager;

#endif
