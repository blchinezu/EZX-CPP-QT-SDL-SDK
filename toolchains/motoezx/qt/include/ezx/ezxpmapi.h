/**************************************************************
* 
* EZXϵͳ�ĵ�Դ������չ�����б�,�б��ɳ������������Ҹ��˵Ĳ²⣬
* ��Щ����ֵ�Ͳ�������û��һһ���ԣ������������½�,
* �����ʲô�µĳɹ�������ϵ�ҡ����ʹ������б�
* �뿪��Դ���룬�ڴ��㡣
*
* EZX system Power Manage extern function list.
* copyfrom psysun's code By SigarRon
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2.1 of
* the License, or (at your option) any later version.
* 
*
* Unofficial EZX Native Software Development Kit
* Copyright (C) 2007 SigarRon.China. <sigarron@163.com>
*
**************************************************************/


extern "C" int PM_setupBklightBrightness(int b);//no.4
extern "C" int PM_setupLcdSleepTime(int s);//no.0(0~9=never sleep,10=sleep now,when wakeup like 0~9,>10=sleep second.)
extern "C" int PM_setupPowerSavingMode(int boolean);//no.5
extern "C" int PM_setupUseroffSupport(int i);//no.1
extern "C" int PM_setupIgnoreBpSignal(int boolean);//no.3
extern "C" int PM_setupFlipStatus(int stat);//no.2
