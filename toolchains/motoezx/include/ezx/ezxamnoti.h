/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2005 Sam Revitch <samr7@cs.washington.edu>
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

#if !defined(__EZX_AM_NOTI__)
#define __EZX_AM_NOTI__

/*
 * Application Manager notification stuff
 *
 * Supports creation of the different types of entries under the
 * app manager's blinking exclamation point.  Useful for polling
 * services.  Not possible from Java. :-/
 */

class AM_NOTI_Client : public QObject {
	Q_OBJECT
public:
	/* Virtual methods */
	virtual ~AM_NOTI_Client();

	/*
	 * Creates an entry to be displayed in the system notification
	 * list, that is, inside the exclamation-point menu.  If there
	 * are no previous entries in the system notification list,
	 * the exclamation point button will be displayed at the top
	 * of the screen.
	 *
	 * notification_slot is the entry number for the application.
	 * iconName is the resource name of the icon to be displayed
	 *	in the system notification list, minus the .gif
	 *	extension.
	 * caption is the text to be displayed in the system
	 *	notification list for this entry.
	 * unknown1 is unknown.
	 */
	virtual void addData(int notification_slot,
			     QString const &iconName,
			     QString const &caption,
			     QString const &unknown1);

	virtual void deleteData(int);

	/* Called by both of the above two, seems private */
	virtual void sendData(QCString const&, int, QString const&,
			      QString const&, QString const&);

signals:
	/* Signals */
	void signalReceiveData(int, QString const&, QString const&,
			       QString const&);

public slots:
	/* Slots */
	void slotSignalReceiveData(QCString const&, QArray<char> const&);

public:
	/* Constructor - likely protected, use subclass instance() methods */
	AM_NOTI_Client(QCString const &qcopChannelName,
		       QObject *parent,
		       char const *objName);

	QCopChannel	*m_qcc_24;
	QString		m_string_28;
};


class AM_NOTI_EMS : public AM_NOTI_Client {
public:
	/* Apparently the primary method of obtaining an object handle */
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_EMS();
	AM_NOTI_EMS(QObject*, char const*);
};

class AM_NOTI_Task : public AM_NOTI_Client {
public:
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_Task();
	AM_NOTI_Task(QObject*, char const*);
};

class AM_NOTI_EMail : public AM_NOTI_Client {
public:
	/* Apparently the primary method of obtaining an object handle */
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_EMail();
	AM_NOTI_EMail(QObject*, char const*);
};

class AM_NOTI_Phone : public AM_NOTI_Client {
public:
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_Phone();
	AM_NOTI_Phone(QObject*, char const*);
};

class AM_NOTI_Calendar : public AM_NOTI_Client {
public:
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_Calendar();
	AM_NOTI_Calendar(QObject*, char const*);
};

class AM_NOTI_Wvimps : public AM_NOTI_Client {
public:
	static AM_NOTI_Client *instance(void);

	virtual ~AM_NOTI_Wvimps();
	AM_NOTI_Wvimps(QObject*, char const*);
};

#endif /* !defined(__EZX_AM_NOTI__) */
