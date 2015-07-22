/**********************************************************************
** Copyright (C) 2001 Trolltech AS.  All rights reserved.
**
** This file is part of the Qtopia Environment.
**
** Licensees holding valid Qtopia Developer license may use this
** file in accordance with the Qtopia Developer License Agreement
** provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE.
**
** email sales@trolltech.com for information about Qtopia License
** Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef POWER_H
#define POWER_H

#include <qobject.h>

class PowerStatus
{
public:
    PowerStatus() {
	ac = Offline;
	bs = NotPresent;
	bbs = NotPresent;
	percentRemain = -1;
	secsRemain = -1;
    }

    enum ACStatus { Offline, Online, Backup };
    ACStatus acStatus() const { return ac; }

    enum BatteryStatus { High=0x01, Low=0x02, VeryLow=0x04, Critical=0x08,
			 Charging=0x10, NotPresent=0x20 };
    BatteryStatus batteryStatus() const { return bs; }
    BatteryStatus backupBatteryStatus() const { return bbs; }

    bool batteryPercentAccurate() const { return percentAccurate; }
    int batteryPercentRemaining() const { return percentRemain; }
    int batteryTimeRemaining() const { return secsRemain; }

    bool operator!=( const PowerStatus &ps ) {
	return  (ps.ac != ac) || (ps.bs != bs) || (ps.bbs != bbs) ||
		(ps.percentRemain != percentRemain) ||
		(ps.secsRemain != secsRemain );
    }

private:
    ACStatus ac;
    BatteryStatus bs;
    BatteryStatus bbs;
    int percentRemain;
    int secsRemain;
    bool percentAccurate;

    friend class PowerStatusManager;
};


class PowerStatusManager
{
public:
    PowerStatusManager();

    static const PowerStatus &readStatus();

protected:
    bool getProcApmStatus( int &ac, int &bs, int &bf, int &pc, int &sec );
    void getStatus();

private:
    static PowerStatus *ps;
    static PowerStatusManager *powerManager;
};


#endif

