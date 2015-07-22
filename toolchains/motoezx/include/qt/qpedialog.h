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
#ifndef __QPE_DIALOG_H__
#define __QPE_DIALOG_H__

#include <qobject.h>

class QPEDialogListenerData;

class QPEDialogListener : public QObject
{
    Q_OBJECT
public:
    QPEDialogListener(QDialog *di);
    ~QPEDialogListener();
    
private slots:
    void appMessage( const QCString &msg, const QByteArray &data );

private:

    QDialog *dialog;
    QPEDialogListenerData *d;
};

#endif

