// $Id: EZXStyle.h,v 1.8 2002/12/04 09:27:26 a18604 Exp $
//---------------------------------------------
//
// Header Name: EZXStyle.h
//
// General Description: EZXStyle class declaration file.
//
//---------------------------------------------
// Motorola Confidential Proprietary
// Advance Technology and software operations
// (c)Copyright Motorola 2002, All Rights Reserved
//
// Revision History:
//                             Modification     Tracking
// Author                          Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Kenny Yu                    11/14/2002                   Created
//
// No Q_OBJECT, so No moc preprocess.
//
// Engineering control macros involved:
// #define RICHTEXT_DRAWITEM
// #define IMAGE_TEST
// #define SORTBAR_ENABLED
// #define USELESS_CODE

#ifndef EZXSTYLE_H
#define EZXSTYLE_H

#include <qwindowsstyle.h>
#include <qpalette.h>
#include "ZSkinReader.h"

// To differenciate scrollBar direction: Horizontal/Vertical with Boolean
#define EZXSTYLE_HORIZONTAL      (sb->orientation() == QScrollBar::Horizontal)
#define EZXSTYLE_VERTICAL        !EZXSTYLE_HORIZONTAL

#define EZXSTYLE_SLIDER_MIN      9

// Common Ezx widget style: QWindowsStyle as parent
// QStyle and QCommonStyle cannot be inherited because of private constructor
class EZXStyle : public QWindowsStyle
{
public:
    // constructor: sbext regulate extent of scrollBar(Horizontal/Vertical)
    EZXStyle( int sbext = -1, int sortButtonSpace = 0 );
    
    bool setSkinFile(QString &skinFile);

    void drawProgressBackground(QPainter *p, QRect r, QColorGroup &g);
    void drawProgressAmount(QPainter *p, QRect r, QRect bar, int x, int nu,
                            const int unit_width, const int unit_height, QColorGroup &g);
    void drawDialogBackground(QPainter *p, int x, int y, int w, int h, QBrush &brush);
    //void drawLineEditBackground(QPainter *p, int x, int y, int w, int h, QBrush &brush);

    void drawFocusRect ( QPainter *, const QRect &, const QColorGroup &, const QColor * bg = 0, bool = FALSE );
//    void polish ( QWidget * );

    void drawPopupMenuItem ( QPainter * p, bool checkable, int maxpmw, int tab, QMenuItem * mi,
            const QPalette & pal, bool act, bool enabled, int x, int y, int w, int h );

/*    void drawBevelButton( QPainter *p, int x, int y, int w, int h,
      const QColorGroup &g, bool sunken = FALSE,
      const QBrush *fill = 0 );*/

//    void drawPushButton( QPushButton* btn, QPainter *p);
    
    void drawPopupPanel ( QPainter * p, int x, int y, int w, int h, const QColorGroup & cg, int lineWidth = 2, const QBrush * fill = 0 );
    QSize scrollBarExtent();
    void drawScrollBarControls( QPainter*,  const QScrollBar*, int sliderStart,
            uint controls, uint activeControl );
    void scrollBarMetrics( const QScrollBar* sb, int &sliderMin, int &sliderMax,
            int &sliderLength, int&buttonDim );
    QSize indicatorSize() const;
    QSize exclusiveIndicatorSize() const;
    void drawIndicator( QPainter* p, int x, int y, int w, int h, const QColorGroup &g, int s,
            bool down = FALSE, bool enabled = TRUE );
    void drawExclusiveIndicator ( QPainter *p, int x, int y, int w, int h, const QColorGroup &cg,
            bool on, bool down = FALSE, bool enabled = TRUE );
    void drawComboButton ( QPainter * p, int x, int y, int w, int h, const QColorGroup & g,
            bool sunken = FALSE, bool editable = FALSE, bool enabled = TRUE, const QBrush * fill = 0 );
    QRect comboButtonRect( int x, int y, int w, int h);
    void drawArrow( QPainter *p, Qt::ArrowType type, bool down,
             int x, int y, int w, int h,
             const QColorGroup &g, bool enabled, const QBrush *fill = 0 );
    void polishPopupMenu( QPopupMenu* popup );

    QPixmap getResourceImage( const QString & id, int height, int width );

private:
    // scrollBar button name cosistent with button Arrow direction
    enum { PointUp, PointDown, PointLeft, PointRight };
    // SortBar Icon put into scrollBars' corner,
    // default corner widget space plus sortButtonSpace to contain Icon
    // Note: should be separated style like sortBarStyle,
    // will be implemented in inherited style class
    int sortButtonSpace;
    int sbext;
    ZSkinReader reader;
 };


#endif
