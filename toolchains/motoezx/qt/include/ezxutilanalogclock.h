/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2007 SigarRon.China. <sigarron@163.com>
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

#if !defined(__EZX_UTIL_ANALOGCLOCK_H__)
#define __EZX_UTIL_ANALOGCLOCK_H__

#include <qlabel.h>
#include <qstring.h>
#include <qlayout.h>
#include <quuid.h>
#include <ZGlobal.h>
#include <ZPushButton.h>
#include <qdatetime.h>
	
class UTIL_AnalogClock : public QWidget {
	
public:
	//UTIL_AnalogClock(QString const&,QWidget *,const char *name=0) ;	//nukin removed
	//UTIL_AnalogClock(QString const&,const char *name=0 );				//nukin removed
	UTIL_AnalogClock(QWidget*,const char *name=0);
	UTIL_AnalogClock(QPixmap  const&,QWidget *,char  const* name=0);			//nukin add
	
	void display(QTime const&);
	void rotate(QPoint,QPoint,int);										//nukin add
	void drawContents(QPainter *);										//nukin add
	QSize sizeHint(void) const;											//nukin add
	
	~UTIL_AnalogClock();

};
#endif
