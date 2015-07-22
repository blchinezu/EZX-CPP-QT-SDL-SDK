/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2006 sigarron <sigarron@163.com>
 *
 *	7-31 completed by sigarron
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
 */

#if !defined(__ZALARMCLIENT_H__)
#define __ZALARMCLIENT_H__

#include <qobject.h>
#include <qwidget.h>
#include <qdatetime.h>

//channel EZX/Alarmserver
class ZAlarmClient : public QObject
{
   Q_OBJECT
public:
	/*
	*	warning,when use QDateTime ,please set seconds number to 00;
	*		like: 01:32:00,otherwise,will not success
	*	
	*	param <type> must be "alarmclock" or other.
	*/
	void addAlarm(QDateTime  when , QCString type, QCString msg, int date=0);
	void deleteAlarm(QDateTime when , QCString type, QCString msg, int date, bool once);
	void slotRecvMsg(QCString const&, QArray<char> const&);
	
	ZAlarmClient(void);
	~ZAlarmClient();
	
	int tmp[1024];

signals:
	//this signal take no effect,i do not know why
	void signalTimeout(QDateTime, QCString, QCString, int);
};

#endif  /* !defined(__EZX_UTIL_DIALOG_H__) */
