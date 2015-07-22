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

#ifndef _TIMESTRING_H_
#define _TIMESTRING_H_
#include <qdatetime.h>
#include <qstring.h>

// return a string with the time based on whether or not you want
// you want it in 12 hour form.   if ampm is true, then return
// it in 12 hour (am/pm) form otherwise return it in 24 hour form
// in theory Qt 3,0 handles this better (hopefully obsoleteing this)
class DateFormat 
{
public:
    // date format type 001,010,100 = day month year
    enum Order {
	DayMonthYear = 0x0111, // 0x001 + 0x010(0x2 << 3) + 0x100(0x4 << 3)
	MonthDayYear = 0x010A,
	YearMonthDay = 0x0054
    };

    DateFormat(QChar s = '/', Order so = MonthDayYear) : _shortOrder(so),
        _longOrder(so), _shortSeparator(s) { }
    DateFormat(QChar s, Order so, Order lo) :  _shortOrder(so),
        _longOrder(lo), _shortSeparator(s) { }
    DateFormat(const DateFormat &o) : _shortOrder(o._shortOrder),
        _longOrder(o._longOrder), _shortSeparator(o._shortSeparator) { }

    bool operator==(const DateFormat &o)
    {
	if (o._shortOrder == _shortOrder && o._longOrder == _longOrder &&
		o._shortSeparator == _shortSeparator)
	    return TRUE;
	return FALSE;
    }

    // verbosity specifiers
    enum Verbosity {
	shortNumber = 0x01, // default
	longNumber  = 0x02,

	padNumber = 0x04,

	shortWord = 0x08, // default
	longWord = 0x10,

	showWeekDay = 0x20
    };

    QString toNumberString() const; // the M/D/Y string.
    QString toWordString() const; // the Month day, year string.

    QString numberDate(const QDate &d, int v = 0) const;
    QString wordDate(const QDate &d, int v = 0) const;

#ifndef QT_NO_DATASTREAM
    void load(QDataStream&);
    void save(QDataStream&) const;
#endif

    QChar separator() const { return _shortSeparator; };
    Order shortOrder() const { return _shortOrder; };
    Order longOrder() const { return _longOrder; };

private:
    Order _shortOrder;
    Order _longOrder;
    QChar _shortSeparator;
};

#ifndef QT_NO_DATASTREAM
QDataStream &operator<<(QDataStream &s, const DateFormat&df);
QDataStream &operator>>(QDataStream &s, DateFormat&df);
#endif

class TimeString
{
public:

    //enum DateFormat { MonthDayYear, DayMonthYear, ISO8601, 
		      //YearMonthDay = ISO8601 };


    static QString shortDate( const QDate &d ) 
    { return shortDate( d, currentDateFormat() ); }
    static QString dateString( const QDate &d )
    { return dateString( d, currentDateFormat() ); }
    static QString longDateString( const QDate &d )
    { return longDateString( d, currentDateFormat() ); }
    static QString dateString( const QDateTime &dt, bool ampm, bool seconds )
    { return dateString( dt, ampm, seconds, currentDateFormat() ); }

    static QString dateString( const QDateTime &t, bool ampm = false );
    static QString timeString( const QTime &t, bool ampm, bool seconds );
    static QString timeString( const QTime &t, bool ampm = false );
    static QString shortTime( bool ampm, bool seconds );
    static QString shortTime( bool ampm = false );



    static QString shortDate( const QDate &, DateFormat );
    static QString dateString( const QDate &, DateFormat  );
    static QString longDateString( const QDate &, DateFormat );

    static DateFormat currentDateFormat();

private:
    static QString dateString( const QDateTime &t, bool ampm, bool seconds, DateFormat );
    

};
#endif

