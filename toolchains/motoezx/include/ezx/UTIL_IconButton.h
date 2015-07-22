#ifndef UTIL_ICONBUTTON_H
#define UTIL_ICONBUTTON_H
//2010.01.27 wangbin

#include <qtoolbutton.h>

class UTIL_IconButton :public QToolButton
{
	UTIL_IconButton(QPixmap  const&,QPixmap  const&,QPixmap  const&,QString  const&,QWidget *);
	UTIL_IconButton(QPixmap  const&,QPixmap  const&,QString  const&,QWidget *);
	UTIL_IconButton(QPixmap  const&,QPixmap  const&,QWidget *);
	void createActivePixmap(QPixmap  const&);
	QPixmap* createDisabledPixmap(QPixmap  const&) const;
	void drawButton(QPainter *);

	void setPixmaps(QPixmap  const&,QPixmap  const&,QPixmap  const&);
	void setText(QString  const&);
	QSize sizeHint(void)const;
	QString text(void) const;
	
protected:
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

};

#endif //UTIL_ICONBUTTON_H

