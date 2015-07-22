/*********************************************************************************************
    Tips: Tip Widget
    Copyright (C) 2010 Wangbin <wbsecg1@gmail.com>
 	(aka. nukin in ccmove & novesky in http://forum.motorolafans.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*********************************************************************************************/

/**********************************************
**参考qwhatsthis
**todo:
**复制粘贴，关闭按钮
**QTimer, more palette
***************************************************/

#include "tips.h"
#ifndef NO_EZX
#include <ezxutilpushbutton.h>
#include <qsimplerichtext.h>
#include <qstylesheet.h>
#define WFLAGS Qt::WDestructiveClose | Qt::WStyle_NoBorder
#else
#define WFLAGS Qt::FramelessWindowHint
#include <qtoolbutton.h>
#endif //NO_EZX
#include <qpainter.h>
#include <qtooltip.h>
#include <qbitmap.h>

static const char * close_btn_xpm[] = {
"17 17 91 1",
" 	c None",
".	c #2F2F2F",
"+	c #373737",
"@	c #3D3D3D",
"#	c #434343",
"$	c #3F3F3F",
"%	c #303030",
"&	c #606060",
"*	c #444444",
"=	c #2D2D2D",
"-	c #696969",
";	c #767676",
">	c #474747",
",	c #535353",
"'	c #BABABA",
")	c #9C9C9C",
"!	c #4C4C4C",
"~	c #5C5C5C",
"{	c #C8C8C8",
"]	c #DDDDDD",
"^	c #6E6E6E",
"/	c #464646",
"(	c #B9B9B9",
"_	c #E8E8E8",
":	c #DFDFDF",
"<	c #4D4D4D",
"[	c #3E3E3E",
"}	c #525252",
"|	c #9A9A9A",
"1	c #EAEAEA",
"2	c #EFEFEF",
"3	c #ECEDED",
"4	c #8E8E8E",
"5	c #454545",
"6	c #9B9B9B",
"7	c #D4D4D4",
"8	c #EEEEEE",
"9	c #797979",
"0	c #383838",
"a	c #989898",
"b	c #F0F0F0",
"c	c #C0BFBF",
"d	c #7A7A7A",
"e	c #C2C2C2",
"f	c #A8A8A8",
"g	c #6D6D6D",
"h	c #CACACA",
"i	c #F5F5F5",
"j	c #F8F8F8",
"k	c #E5E5E5",
"l	c #C9CACA",
"m	c #CDCDCD",
"n	c #424242",
"o	c #545454",
"p	c #B5B5B5",
"q	c #ECEDEC",
"r	c #FBFBFB",
"s	c #F3F3F3",
"t	c #ABABAB",
"u	c #4A4A4A",
"v	c #999999",
"w	c #BBBBBB",
"x	c #DCDCDC",
"y	c #F7F7F6",
"z	c #F7F7F7",
"A	c #BFBFBF",
"B	c #5F5F5F",
"C	c #C1C1C1",
"D	c #B1B1B1",
"E	c #BEBDBD",
"F	c #EDEEEE",
"G	c #F2F2F3",
"H	c #717170",
"I	c #505050",
"J	c #C6C6C6",
"K	c #A1A1A1",
"L	c #D0D0D0",
"M	c #EAE9E9",
"N	c #4B4B4B",
"O	c #D7D7D7",
"P	c #686868",
"Q	c #858585",
"R	c #C7C8C8",
"S	c #BEBEBE",
"T	c #595959",
"U	c #404040",
"V	c #5A5A5A",
"W	c #979797",
"X	c #6B6C6C",
"Y	c #656565",
"Z	c #818181",
"     .+@#@+.     ",
"    $#######$    ",
"  %########&&*%  ",
" =#-;>####,')!#  ",
" $~{]^###/(_:<#[ ",
".}|12345#6789###.",
"0*>a]2bcde8f####0",
"$###ghijklm>####$",
"n####opqrstu####n",
"$#####vwxyzAB###$",
"0####^C:DEFGxH##0",
".###IJ1x<<KLbMgN.",
" $#I'O8P###QRSTU ",
" =#V6kW####5XY>= ",
"  %>TZ>######*%  ",
"    $#######$    ",
"     .0$#$0.     "};
static const char * close_btn_act_xpm[] = {
"17 17 72 1",
" 	c None",
".	c #891A1A",
"+	c #951C1C",
"@	c #9D1E1E",
"#	c #A61F1F",
"$	c #A11E1E",
"%	c #8C1B1B",
"&	c #CC2727",
"*	c #871A1A",
"=	c #D62D2D",
"-	c #DA3F3F",
";	c #AC2121",
">	c #BB2424",
",	c #EC9B9B",
"'	c #E47373",
")	c #B32222",
"!	c #C72626",
"~	c #EFB0B0",
"{	c #F5CACA",
"]	c #D83333",
"^	c #AB2020",
"/	c #F7DADA",
"(	c #F5D0D0",
"_	c #B52222",
":	c #9F1E1E",
"<	c #BA2323",
"[	c #E37070",
"}	c #F8DDDD",
"|	c #F9E4E4",
"1	c #F9E2E2",
"2	c #E06161",
"3	c #A72020",
"4	c #F3C0C0",
"5	c #DA4343",
"6	c #971C1C",
"7	c #E26C6C",
"8	c #FAE7E7",
"9	c #EDA2A2",
"0	c #EEA7A7",
"a	c #E78484",
"b	c #D73232",
"c	c #F0B1B1",
"d	c #FBEEEE",
"e	c #FCEFEF",
"f	c #F7D6D6",
"g	c #F0B5B5",
"h	c #BD2424",
"i	c #EA9595",
"j	c #FDF6F6",
"k	c #FAE9E9",
"l	c #E88787",
"m	c #AE2121",
"n	c #F4C9C9",
"o	c #CB2626",
"p	c #EDA6A6",
"q	c #E98E8E",
"r	c #ECA1A1",
"s	c #D93838",
"t	c #B82323",
"u	c #EFACAC",
"v	c #E57A7A",
"w	c #F1BABA",
"x	c #F8DBDB",
"y	c #B02121",
"z	c #F3C2C2",
"A	c #DE5353",
"B	c #C42525",
"C	c #C62525",
"D	c #E26B6B",
"E	c #D73030",
"F	c #D52828",
"G	c #DD4E4E",
"     .+@#@+.     ",
"    $#######$    ",
"  %########&&#%  ",
" *#=-;####>,')#  ",
" $!~{]###^,/(_#: ",
".<[}|123#[4|5###.",
"6#;7{|8950|a####6",
"$###bcdefcg;####$",
"#####hi1jklm#####",
"$#####[,ndd9o###$",
"6####]p(qr|kns##6",
".###tu}n__vw8xby.",
" $#t,z|=###A~rB$ ",
" *#C[fD####3EF;* ",
"  %;BG;#######%  ",
"    $#######$    ",
"     .6$#$6.     "};

Tips::Tips(const QPoint& pos,const QString& txt,QWidget* p,const char* name,WFlags f)
    :QWidget(p,name,f|WFLAGS),ppos(pos),currentText(txt)
{
	//resize(0,0)很重要，则位置下
	
	tipBtn=new EZ_UPushButton(QPixmap(close_btn_xpm),QPixmap(close_btn_act_xpm),"",this,0,17,17);
#ifndef NO_EZX
	tipBtn->setTransparencyPercent(60);
	tipBtn->setMask(*QPixmap(close_btn_xpm).mask());
#else
	tipBtn->resize(17,17);
	tipBtn->setIcon(QIcon(close_btn_xpm));
    	tipBtn->setMask(QPixmap(close_btn_xpm).mask());
#endif //NO_EZX
	connect(tipBtn,SIGNAL(clicked()),SLOT(close()));
}

void Tips::mousePressEvent(QMouseEvent* e)
{
	gPos=e->globalPos();
}

void Tips::mouseDoubleClickEvent(QMouseEvent*)
{
	emit dobuleClicked();
}

void Tips::mouseMoveEvent(QMouseEvent* e)
{
    move(mapToGlobal(QPoint(0,0))+e->globalPos()-gPos);
    gPos=e->globalPos();
}
	
void Tips::resizeEvent(QResizeEvent* )
{
	tipBtn->move(width()-tipBtn->width()-9,3);
	repaint();
}

void Tips::paintEvent(QPaintEvent* )
{
#ifndef NO_EZX
	setBackgroundMode( QWidget::NoBackground );
#else
    setBackgroundMode( Qt::NoBackground );
#endif //NO_EZX
	setPalette( QToolTip::palette(), TRUE );
	
    const int shadowWidth = 6;   // also used as '5' and '6' and even '8' below
    const int vMargin = 8;
    const int hMargin = 12;

    if ( currentText.isEmpty() )
	return;

    QRect r;
#ifndef QT_NO_RICHTEXT
    QSimpleRichText* doc = 0;

    if ( QStyleSheet::mightBeRichText( currentText ) ) {
		doc = new QSimpleRichText( currentText, font() );
		doc->adjustSize();
		r.setRect( 0, 0, doc->width(), doc->height() );
    }
    else
#endif
    {
		int sw = QApplication::desktop()->width() / 3;
		if ( sw < 200 )
			sw = 200;
		else if ( sw > 300 )
	    	sw = 300;

		r = fontMetrics().boundingRect( 0, 0, sw, 1000, Qt::AlignLeft + Qt::AlignTop + Qt::WordBreak + Qt::ExpandTabs, currentText );
    }

    int w = r.width() + 2*hMargin;
    int h = r.height() + 2*vMargin;

	// okay, now to find a suitable location

	int x;

	// first try locating the widget immediately above/below,
	// with nice alignment if possible.
	QPoint pos;
	if ( parentWidget() )
		pos = parentWidget()->mapToGlobal( QPoint( 0,0 ) );

	if ( parentWidget() && w > parentWidget()->width() + 16 )
		x = pos.x() + parentWidget()->width()/2 - w/2;
	else
	    x = ppos.x() - w/2;

	// squeeze it in if that would result in part of what's this
	// being only partially visible
	if ( x + w > QApplication::desktop()->width() )
	    x = (parentWidget()? (QMIN(QApplication::desktop()->width(),
			      pos.x() + parentWidget()->width())
			 ) : QApplication::desktop()->width() )
		- w;

	int sx = QApplication::desktop()->x();
	int sy = QApplication::desktop()->y();
	
	if ( x < sx ) x = sx;

	int y;
	if ( parentWidget() && h > parentWidget()->height() + 16 ) {
		y = pos.y() + parentWidget()->height() + 2; // below, two pixels spacing
		// what's this is above or below, wherever there's most space
		if ( y + h + 10 > QApplication::desktop()->height() )
		y = pos.y() + 2 - shadowWidth - h; // above, overlap
	}
	y = ppos.y() + 2;

	// squeeze it in if that would result in part of what's this
	// being only partially visible
	if ( y + h > QApplication::desktop()->height() )
	    y = ( parentWidget() ? (QMIN(QApplication::desktop()->height(),
				 pos.y() + parentWidget()->height())
			    ) : QApplication:: desktop()->height() )
		- h;
	if ( y < sy )
		y = sy;
	
	setGeometry( x, y, w + shadowWidth, h + shadowWidth );
	show();

    // now for super-clever shadow stuff.  super-clever mostly in
    // how many window system problems it skirts around.

    QPainter p( this );
    p.setPen( colorGroup().foreground() );
    p.drawRect( 0, 0, w, h );
    p.setPen( colorGroup().mid() );
    p.setBrush( colorGroup().background() );
    p.drawRect( 1, 1, w-2, h-2 );
    p.setPen( colorGroup().foreground() );

#ifndef QT_NO_RICHTEXT
    if ( doc ) {
	doc->draw( &p, hMargin, vMargin, r, colorGroup(), 0 );
	delete doc;
    }
    else
#endif
    {
	p.drawText( hMargin, vMargin, r.width(), r.height(),
		    Qt::AlignLeft + Qt::AlignTop + Qt::WordBreak + Qt::ExpandTabs,
		    currentText );
    }
    p.setPen( colorGroup().shadow() );

    p.drawPoint( w + 5, 6 );
    p.drawLine( w + 3, 6,
		w + 5, 8 );
    p.drawLine( w + 1, 6,
		w + 5, 10 );
    int i;
    for( i=7; i < h; i += 2 )
	p.drawLine( w, i,
		    w + 5, i + 5 );
    for( i = w - i + h; i > 6; i -= 2 )
	p.drawLine( i, h,
		    i + 5, h + 5 );
    for( ; i > 0 ; i -= 2 )
	p.drawLine( 6, h + 6 - i,
		    i + 5, h + 5 );
}

