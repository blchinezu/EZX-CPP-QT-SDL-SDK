/*************************************************************************
 * AniMatrix : Animate Effect
 * Copyright (C) 2010 Wangbin <wbsecg1@gmail.com>
 * (aka. nukin in ccmove & novesky in http://forum.motorolafans.com)
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
 ***********************************************************************/
/****************************************************************************
** last edited 2010-03-07
** 
****************************************************************************/
#ifndef ANIMATRIX_H
#define ANIMATRIX_H

#include <qwmatrix.h>
#include <qobject.h>
//class QTimer;

//speed,time,
class AniMatrix :public QObject
{
	Q_OBJECT
public:
	//enum Effects { None, Translate, Zoom, Rotate, Shear, Curv} effect;  //NO Linear
	AniMatrix();
	
	//void setCircleNum(int c) { circles=c;};
	//void setTotalTime(int tt) { time=tt;}
	//void setTotalFrame(int f) { frames=f;}
	void ZoomEffect();

public slots:
	void randVars();
	void start();
	void stop();
signals:
	void newMatrix(const QWMatrix&);
protected:
	void timerEvent(QTimerEvent *);
private:
	QWMatrix m;
	
	int circles,  time, frames; //总数
	int  frame;  //circle  计数
	int dt;
	double x, y, xT, yT, dx, dy; //曲线呢
	double mag_c; //修正系数(加速度) mag+=dmag+mag_c*mag, 
	double magX, magXT, magY, magYT, dmagX, dmagY; //最终放大率magT
	double degree, ddeg;
	double shearH, shearV, shearHT, shearVT, dshearH, dshearV;//shearMax, shearMin;
	
};

#endif //ANIMATRIX_H
	
