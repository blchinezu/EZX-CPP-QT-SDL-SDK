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
#ifndef CALENDAR_H
#define CALENDAR_H

#include <qstring.h>
#include <qvaluelist.h>

class Calendar
{
public:
    struct Day
    {
	enum Type { PrevMonth, ThisMonth, NextMonth };
	
	Day() : date( 0 ), type( ThisMonth ), holiday( FALSE ) {}
	Day( int d, Type t, bool h ) : date( d ), type( t ), holiday( h ) {}
	
	int date;
	Type type;
	bool holiday;
    };

    static QString nameOfMonth( int m );
    static QString nameOfDay( int d );
    static QValueList<Day> daysOfMonth( int year, int month, bool startWithMonday = FALSE );

};

#endif
