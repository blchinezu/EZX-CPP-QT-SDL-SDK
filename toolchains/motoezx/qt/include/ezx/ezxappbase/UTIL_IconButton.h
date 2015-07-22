#ifndef UTIL_ICONBUTTON_H
#define UTIL_ICONBUTTON_H
//2010.01.27 wangbin

#include <qtoolbutton.h>

class UTIL_IconButton :public QToolButton
{
	Q_OBJECT
public:
	UTIL_IconButton(QPixmap const& narmal,QPixmap const& active,QPixmap const& disabled,QString const& text="",QWidget *parent=0);
	UTIL_IconButton(QPixmap const& narmal,QPixmap const& active,QString const& text="",QWidget *parent=0);
	UTIL_IconButton(QPixmap const& narmal,QPixmap const& active,QWidget *parent=0);
	
	void setPixmaps(QPixmap const&,QPixmap const&,QPixmap const&);
	void setText(QString const&);
	QSize sizeHint()const;
	QString text() const;
	
protected:
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	
	QPixmap createActivePixmap(QPixmap const&) const;
	QPixmap createDisabledPixmap(QPixmap  const&) const;
	void drawButton(QPainter *);

};

#endif //UTIL_ICONBUTTON_H

