#if !defined(__EZX_UTIL_GRAPH_H__)
#define __EZX_UTIL_GRAPH_H__

#include <qpainter.h>
#include <qpoint.h>
#include <qcolor.h>
#include <qpixmap.h>

class UTIL_Graph {
public:
	static void drawUnderLine(QPainter*, QColorGroup const&,
				  QPoint const&, QPoint const&);
	static void drawOutlineText(QPainter*, QColor, QColor, int, int,
				    int, int, int, QString const&,
				    int, QRect*, char**);
	static QPixmap createDisabledPixmap(QPixmap const&);
	static QPixmap drawNegativeColorPixmap(QPixmap const&);
	void overlapPixmaps(QValueList<QPixmap>);
	QPixmap* scalePixmap(uchar *,int,int,int,uchar *,int,int,int,int);
	static void makeTitle(QWidget*, int);
};

#endif  /* !defined(__EZX_UTIL_GRAPH_H__) */
