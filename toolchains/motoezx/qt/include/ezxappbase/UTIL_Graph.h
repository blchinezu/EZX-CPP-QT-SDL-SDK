#ifndef UTIL_GRAPH_H
#define UTIL_GRAPH_H
//2010.01.27 nukin
#include <qpixmap.h>

class UTIL_Graph
{
public:
	QPixmap* createDisabledPixmap(QPixmap  const&);
	QPixmap* drawNegativeColorPixmap(QPixmap  const&);
	void drawOutlineText(QPainter *,QColor,QColor,int,int,int,int,int,QString const&,int,QRect *,char **);
	void drawUnderLine(QPainter *,QColorGroup const&,QPoint const&,QPoint const&);
	void makeTitle(QWidget *,int);
	void overlapPixmaps(QValueList<QPixmap>);
	QPixmap* scalePixmap(uchar *,int,int,int,uchar *,int,int,int,int);

};

#endif //UTIL_GRAPH_H

