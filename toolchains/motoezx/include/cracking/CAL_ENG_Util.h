//generated by genheader.sh write by wangbin
/********************************************************
**libezxcalendarengine.so.1.0.0
**2010年 04月 17日 星期六 13:52:08 CST
*************************************************************/
/*#ifndef CAL_ENG_UTIL_H
#define CAL_ENG_UTIL_H

class CAL_ENG_Util
{
public:
	void checkEvent(ZCalendarEvent&, bool);
	void getDSTDate(int, QString&, QDateTime&);
	void adjustAlarm(ZCalendarEvent&);
	void fromISO8601(QCString const&, ZCalendarTimeZone_T*);
	void isDateInDST(QDateTime&, ZCalendarTimeZone_T&, bool&);
	void generateUUID();
	void getAlarmTime(ZCalendarEvent const&, long&, ZCalendarTimeZone_T*);
	void getCurrentTime();
	void getUTCTimeZone(ZCalendarTimeZone_T&);
	void getLocalTimeZone(ZCalendarTimeZone_T&);
	void getCalendarWritePath(QString&);
	void getLunarCalendarDate(QDate&, unsigned short&, unsigned short&, unsigned short&);
	void toUTC(QDateTime&, ZCalendarTimeZone_T&, long&);
	void fromUTC(long, ZCalendarTimeZone_T&, QDateTime&);
	void getDate(int, int, int, int, QDate&);
	void toISO8601(QDateTime const&, CAL_ISO8601_FORMAT_T);
	void toISO8601(long const&);
	
};

#endif //CAL_ENG_UTIL_H
*/


// Copyright (c) 30-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef CAL_ENG_UTIL_H
#define CAL_ENG_UTIL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qcstring.h>
#include <qdatetime.h>

#include "EZX_TypeDefs.h"

#include "ZCalendarTypeDefs.h"
#include "ZCalendarEvent.h"
#include "CAL_ENG_Global.h"

#include "WORLDCLOCK_ITimeClient.h"
#include "WORLDCLOCK_Service.h"
#include "WORLDCLOCK_TypeDefs.h"

class CAL_ENG_Util
{
public:
    static bool getDSTDate(int year, QString &strRule, QDateTime &ruleDateTime);

    static bool getDate(int iYear, int iMonth, int iWeek,  int iDay, QDate &qDate);

    static bool fromUTC(ZCalendarTime_T uTime, ZCalendarTimeZone_T &timeZone, QDateTime &qTime);

    static bool toUTC(QDateTime &qTime, ZCalendarTimeZone_T &timeZone, ZCalendarTime_T &uTime);

    static bool toZCalendarTimeZoneT(CityInfo vCity,ZCalendarTimeZone_T &newTz);

    static bool updateNewTimeZone(ZCalendarTimeZone_T newTz,ZCalendarTimeZone_T oldTz,ZCalendarEvent &event);        

    static bool isDateInDST(QDateTime &dt, ZCalendarTimeZone_T &timeZone, bool &bRes);

    static bool getLocalTimeZone(ZCalendarTimeZone_T &timeZone);

    static bool getUTCTimeZone(ZCalendarTimeZone_T &timeZone);

    static QString generateUUID();

    static QCString toISO8601(const ZCalendarTime_T &dt );

    static QCString toISO8601(const QDateTime &dt,  \
           CAL_ISO8601_FORMAT_T fmt = CAL_ISO8601_FORMAT_STANDARD);

    static ZCalendarTime_T fromISO8601(const QCString &s, ZCalendarTimeZone_T *tz = NULL);

    static UINT16* toUnicode(const QString& inputString);

    static QString fromUnicode(const UINT16* inputString);

    static bool checkEvent(ZCalendarEvent &event, bool isExcept = false);

    static bool adjustAlarm(ZCalendarEvent &event);

    static void getLunarCalendarDate(QDate  &qDate, UINT16 &lunarYear, UINT16 &lunarMonth, UINT16 &lunarDay);

    static bool getAlarmTime(const ZCalendarEvent &event, ZCalendarTime_T &alarmTime, \
                             ZCalendarTimeZone_T *tz = NULL);

    static ZCalendarTime_T getCurrentTime();

    static bool getCalendarWritePath( QString &path );

    static bool myFavesAvailable();

};

#endif  

