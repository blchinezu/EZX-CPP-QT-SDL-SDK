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

#ifndef QPEMENUBAR_H
#define QPEMENUBAR_H

#include <qmenubar.h>
#include <qguardedptr.h>
#include <qvaluelist.h>

class QPEMenuToolFocusManager : public QObject
{
    Q_OBJECT
public:
    QPEMenuToolFocusManager();

    void addWidget( QWidget *w );
    void removeWidget( QWidget *w );
    void setActive( bool a );
    bool isActive() const;
    void moveFocus( bool next );

    static QPEMenuToolFocusManager *manager();
    static void initialize();

protected:
    void setFocus( QWidget *w, bool next=TRUE );
    bool eventFilter( QObject *object, QEvent *event );

private slots:
    void deactivate();

private:
    typedef QGuardedPtr<QWidget> GuardedWidget;
    QValueList<GuardedWidget> list;
    GuardedWidget inFocus;
    GuardedWidget oldFocus;
    static QPEMenuToolFocusManager *me;
};


class QPEMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    QPEMenuBar( QWidget *parent=0, const char* name=0 );
    ~QPEMenuBar();

protected:
    virtual void keyPressEvent( QKeyEvent *e );
};

#endif

