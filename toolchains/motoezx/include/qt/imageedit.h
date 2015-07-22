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
#ifndef IMAGEEDIT_H
#define IMAGEEDIT_H

#include <qscrollview.h>
#include <qpixmap.h>

class ImageEditPrivate;
class ImageEdit : public QScrollView
{
    Q_OBJECT

public:
    ImageEdit( QWidget *parent = 0, const char *name = 0 );
    ~ImageEdit();
    
    void setPixmap( const QPixmap &pm );
    QPixmap pixmap() const;
    
protected:
    void drawContents( QPainter *p, int cx, int cy, int cw, int ch );
    void contentsMousePressEvent( QMouseEvent *e );
    void contentsMouseMoveEvent( QMouseEvent *e );
    void contentsMouseReleaseEvent( QMouseEvent *e );
    void viewportResizeEvent( QResizeEvent *e );

private:
    QPoint lastPos;
    QPixmap buffer;
    ImageEditPrivate *d;
    void enlargeBuffer( const QSize& sz );
};

#endif
