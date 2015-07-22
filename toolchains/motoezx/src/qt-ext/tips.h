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
//static
#ifndef TIPS_H
#define TIPS_H
#include "global.h"
#include <qwidget.h>
class UTIL_PushButton;
class Tips :public QWidget
{
	Q_OBJECT
public:
	Tips(const QPoint& pos,const QString& txt="hello",QWidget* p=0,const char* name=0,WFlags f=0);
	~Tips(){};
	
signals:
	void dobuleClicked();
protected:
	void resizeEvent(QResizeEvent*);
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseDoubleClickEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent *);
private:
	UTIL_PushButton *tipBtn;
	QPoint ppos;
	QString currentText;
    QPoint gPos;

};

#endif //TIPS_H

