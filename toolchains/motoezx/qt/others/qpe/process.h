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

#ifndef PROCESS_H
#define PROCESS_H

//#ifndef QT_H
#include "qobject.h"
#include "qstringlist.h"
#include "qdir.h"
//#endif // QT_H

//#ifndef QT_NO_PROCESS

class ProcessPrivate;

//
//
//
//
//
//
//
//
//
//
//  This is a subset of the Process API found in Qt 3.0
//
//
//
//
//
//
//
//
//
//
//

class Q_EXPORT Process : public QObject
{
    Q_OBJECT
public:
    Process( QObject *parent=0, const char *name=0 );
    Process( const QString& arg0, QObject *parent=0, const char *name=0 );
    Process( const QStringList& args, QObject *parent=0, const char *name=0 );
    ~Process();

    // set and get the arguments and working directory
    QStringList arguments() const;
    virtual void setArguments( const QStringList& args );
    virtual void addArgument( const QString& arg );
    // control the execution
    virtual bool exec( const QString& in, QString& out, QStringList *env=0 );
    virtual bool exec( const QByteArray& in, QByteArray& out, QStringList *env=0 );

private:
    void init();

private:
    ProcessPrivate *d;
    QStringList _arguments;

    int  exitStat; // exit status
    bool exitNormal; // normal exit?
    bool ioRedirection; // automatically set be (dis)connectNotify
    bool notifyOnExit; // automatically set be (dis)connectNotify
    bool wroteToStdinConnected; // automatically set be (dis)connectNotify

    friend class ProcessPrivate;
    friend class ProcessManager;
    friend class Proc;
};

//#endif // QT_NO_PROCESS

#endif // QPROCESS_H
