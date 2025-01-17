/****************************************************************************
** $Id: qt/src/kernel/qsocketnotifier.h   2.3.6   edited 2001-01-26 $
**
** Definition of QSocketNotifier class
**
** Created : 951114
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QSOCKETNOTIFIER_H
#define QSOCKETNOTIFIER_H

#ifndef QT_H
#include "qobject.h"
#endif // QT_H


class Q_EXPORT QSocketNotifier : public QObject
{
    Q_OBJECT
public:
    enum Type { Read, Write, Exception };

    QSocketNotifier( int socket, Type, QObject *parent=0, const char *name=0 );
   ~QSocketNotifier();

    int		 socket()	const;
    Type	 type()		const;

    bool	 isEnabled()	const;
    virtual void setEnabled( bool );

signals:
    void	 activated( int socket );

protected:
    bool	 event( QEvent * );

private:
    int		 sockfd;
    Type	 sntype;
    bool	 snenabled;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    QSocketNotifier( const QSocketNotifier & );
    QSocketNotifier &operator=( const QSocketNotifier & );
#endif
};


inline int QSocketNotifier::socket() const
{ return sockfd; }

inline QSocketNotifier::Type QSocketNotifier::type() const
{ return sntype; }

inline bool QSocketNotifier::isEnabled() const
{ return snenabled; }


#endif // QSOCKETNOTIFIER_H
