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

#if !defined(__EZX_STYLE_H__)
#define __EZX_STYLE_H__

#include <qpixmap.h>
#include <qimage.h>
#include <qmovie.h>
#include <qbitmap.h>

#include <zskin.h>

class QPainter;
class QPopupMenu;
class QScrollBar;
class QColorGroup;
class QPalette;
class QBrush;

class EZXStyle
{
public:

    void setSkinFile(QString&);
    void drawFocusRect(QPainter*, QRect const&, QColorGroup const&, QColor const*, bool);
    void drawPopupPanel(QPainter*, int, int, int, int, QColorGroup const&, int, QBrush const*);
    void comboButtonRect(int, int, int, int);
    void drawComboButton(QPainter*, int, int, int, int, QColorGroup const&, bool, bool, bool, QBrush const*);
    void polishPopupMenu(QPopupMenu*);
    QRect scrollBarExtent();
    QImage getResourceImage(QString const&, int, int);
    QPaintDeviceMetrics scrollBarMetrics(QScrollBar const*, int&, int&, int&, int&);
    void drawPopupMenuItem(QPainter*, bool, int, int, QMenuItem*, QPalette const&, bool, bool, int, int, int, int);
    void drawProgressAmount(QPainter*, QRect, QRect, int, int, int, int, QColorGroup&);
    void drawDialogBackground(QPainter*, int, int, int, int, QBrush&);
    void drawScrollBarControls(QPainter*, QScrollBar const*, int, unsigned int, unsigned int);
    void drawExclusiveIndicator(QPainter*, int, int, int, int, QColorGroup const&, bool, bool, bool);
    void drawProgressBackground(QPainter*, QRect, QColorGroup&);
    void drawArrow(QPainter*, Qt::ArrowType, bool, int, int, int, int, QColorGroup const&, bool, QBrush const*);

protected:

    EZXStyle(int, int);
    virtual ~EZXStyle();

    QSize indicatorSize() const;
    QSize exclusiveIndicatorSize() const;
};

#endif //__EZX_STYLE_H__
