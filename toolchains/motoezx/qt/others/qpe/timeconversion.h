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

#ifndef __timeconversion_h__
#define __timeconversion_h__

#include <time.h>
#include <sys/types.h>
#include <qdatetime.h>

#include <qpe/qpcglobal.h>

class QPC_EXPORT TimeConversion
{
public:
    static QString toString( const QDate &d );
    static QDate fromString( const QString &datestr );

    static time_t toUTC( const QDateTime& dt );
    static QDateTime fromUTC( time_t time );
    static int secsTo( const QDateTime &from, const QDateTime &to );

    static QCString toISO8601( const QDate & );
    static QCString toISO8601( const QDateTime & );
    static QDateTime fromISO8601( const QCString & );
};

#endif // __timeconversion_h__
