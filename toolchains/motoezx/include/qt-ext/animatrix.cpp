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
/***********************************AniMatrix********************************************
**这是计算并发送随时间变化的矩阵的类，可用于制作简单的动画效果，方法是新建AniMatrix的对象，通过信号newMatrix把矩阵发送至接收对象，
**接收对象根据该矩阵对图片进行变换或者改变QPainter坐标系进行绘图，由此可以得到一些简单的动画效果。
**QAnimationPoroperty
**loop or not
**enum Effects { ....}
**start(), 产生指定效果 
** startRander() 产生随机效果
**stop()
**
**不足： 仅能对图像进行线性变换；
************************************************************************************/

#include "animatrix.h"

#include <iostream>
#include <qtimer.h>
#include <stdio.h>

using namespace std;

AniMatrix::AniMatrix()
	:QObject(0,0)
{
	//effect=Zoom | Rotate;
	//circles=1,frames=20,time=1;
	//dmag=0.02;
	magXT=magYT=1.0;
	//mag=.01;
	mag_c=0.1;
	degree=0.;
	shearVT=shearHT=0.;
	//shearMax=0.5;
	//shearMin=-shearMax;
	//x=y=-120.; 
	xT=yT=0.;//屏幕中心。无位移
}

void AniMatrix::start()
{
	randVars();
	startTimer(dt);
	//circle=0;
	
}

void AniMatrix::stop()
{
	killTimers();
}

void AniMatrix::ZoomEffect()
{
	frame=0;
	x=y=0.;
	magX=magY=0.02;
	circles=0;
	time=800;
	frames=20; //分母不能为0
	shearH=shearV=0.;
	
	cout<<" x:"<<x<<" y:"<<y<<" magX:"<<magX<<" magY:"<<magY<<" circles:"<<circles<<" time:"<<time<<" frames:"<<frames<<" shear:"<<shearH<<","<<shearV<<endl;
	
	dx=(xT-x)/frames;
	dy=(yT-y)/frames;
	dmagX=(magXT-magX)/frames;
	dmagY=(magYT-magY)/frames;
	dt=(int)time/frames;  //单位: ms
	ddeg=360.*circles/frames;
	dshearH=(shearHT-shearH)/frames;
	dshearV=(shearVT-shearV)/frames;
	
	startTimer(dt);
}

void AniMatrix::randVars()
{
	frame=0;
	
	x=rand()%360-180;//240-120;
	y=rand()%480-240;//320-160;
	magX=0.02*(rand()%50);
	magY=0.02*(rand()%50);
	circles=rand()%2;
	time=rand()%1002;
	frames=rand()%20+1; //分母不能为0
	shearH=(rand()%100)*0.01-0.6;
	shearV=(rand()%100)*0.01-0.6;
	
	cout<<" x:"<<x<<" y:"<<y<<" magX:"<<magX<<" magY:"<<magY<<" circles:"<<circles<<" time:"<<time<<" frames:"<<frames<<" shear:"<<shearH<<","<<shearV<<endl;
	
	dx=(xT-x)/frames;
	dy=(yT-y)/frames;
	dmagX=(magXT-magX)/frames;
	dmagY=(magYT-magY)/frames;
	dt=(int)time/frames;  //单位: ms
	ddeg=360.*circles/frames;
	dshearH=(shearHT-shearH)/frames;
	dshearV=(shearVT-shearV)/frames;
}

void AniMatrix::timerEvent(QTimerEvent*)
{
	frame++;
	
	if(magX<magXT) magX+=dmagX+0.1*magX;
	if(magY<magYT) magY+=dmagY+0.1*magY;
	degree+=ddeg;
	shearH+=dshearH;
	shearV+=dshearV;
	m=QWMatrix().translate(x+=dx,y+=dy);
	m.scale(magX,magY);
	m.shear(shearH,shearV);
	m.rotate(degree);
	
	emit newMatrix(m);

	if(frame==frames ){
		killTimers();
	}

}

#include "animatrix.moc"


