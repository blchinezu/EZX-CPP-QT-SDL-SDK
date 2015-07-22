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
**********************************************************************/#ifndef IR_H
#define IR_H

#include <qstring.h>
#include <qobject.h>
class DocLnk;
class QCopChannel;

class Ir : public QObject
{
    Q_OBJECT
public:
    static bool supported();
    
    Ir( QObject *parent = 0, const char *name = 0);
    
    void send( const QString &filename, const QString &description, const QString &mimetype = QString::null );
    void send( const DocLnk &doc, const QString &description );

signals:
    void done( Ir * );
    
private slots:
    void obexMessage( const QCString &msg, const QByteArray &data);
private:
    QString filename;
    QCopChannel *ch;
};


#endif
