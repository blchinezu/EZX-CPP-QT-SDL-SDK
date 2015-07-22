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


//
//   DO NOT ATTEMPT TO USE THIS CLASS
//

#ifndef __FINDDIALOG_H__
#define __FINDDIALOG_H__

#include <qdatetime.h>
#include <qdialog.h>

class FindWidget;

class FindDialogPrivate;
class FindDialog : public QDialog
{
    Q_OBJECT
public:

// WARNING: Do *NOT* define this yourself. The SL5xxx from SHARP does NOT
//      have this class.
#ifdef QTOPIA_INTERNAL_FD

    FindDialog( const QString &appName,
                QWidget *parent = 0, const char *name = 0, bool modal = TRUE );
    ~FindDialog();
#endif

    QString findText() const;
    void setUseDate( bool show );
    void setDate( const QDate &dt );

public slots:
    void slotNotFound();
    void slotWrapAround();

signals:
    void signalFindClicked( const QString &txt, bool caseSensitive,
                            bool backwards, int category );
    void signalFindClicked( const QString &txt, const QDate &dt,
			    bool caseSensitive, bool backwards, int category );

private:
    FindWidget *fw;
    FindDialogPrivate *d;
};

#endif
