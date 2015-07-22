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
#ifndef ALARM_SERVER_H
#define ALARM_SERVER_H

#include <qstring.h>
#include <qdatetime.h>

class AlarmServer
{
public:
    static void addAlarm ( QDateTime when, const QCString& channel, const QCString& msg, int data=0);
    static void deleteAlarm (QDateTime when, const QCString& channel, const QCString& msg, int data=0);

private:
    friend int initApplication(int, char **);
    static void initialize();
};

#endif

