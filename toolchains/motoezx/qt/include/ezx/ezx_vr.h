/*********************************************************************************************
    EZX_VR: EZX Audio Play class
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
/**********************************************************************************
**lib: libezxvr.so (VRClient) and libezxappsdk.so (ZVRClient)
**
**Wangbin 2010-03-19
****************/

#ifndef EZX_VR_H
#define EZX_VR_H

#define QT_THREAD_SUPPORT

#include <qstring.h>
//#include <qthread.h>

enum VR_PLAYTTS_T {
		Type1, Type2, Type3
};

class VRClient
{
public:
	static int getTTSVolumn();
	static int VR_TTS_play_Text(const QString& text,VR_PLAYTTS_T);
	static QString VR_TTS_get_Pinyin(const QString&);
	static int VR_interruptVR();
	static int VR_startVR();
	static VR_PLAYTTS_T VR_getVRType();

	
};

//4237b020 V vtable for VRStartThread
//4237b008 V vtable for VRPlayTTSThread
#include <qobject.h>

class ZVRClient :public QObject, public VRClient
{
public:
	ZVRClient();
	virtual ~ZVRClient();
	
	int addCommand(QString,QCString,unsigned char);//_ZN9ZVRClient10addCommandE7QString8QCStringh
	int deleteCommand(QString,QCString,bool);
	int updateCommand(QString,QCString,QCString,unsigned char);
	int LaunchVR();
	bool isVRSupport();
	int PlayoutText(const QString& text,VR_PLAYTTS_T=Type1);

private:
	char unkown[256];
};


#endif //EZX_VR_H

