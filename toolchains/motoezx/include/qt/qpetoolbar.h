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

#ifndef QPETOOLBAR_H
#define QPETOOLBAR_H

#include <qtoolbar.h>

class QMainWindow;

class QPEToolBar : public QToolBar
{
    Q_OBJECT
public:
    QPEToolBar( QMainWindow *parent = 0, const char *name = 0 );

protected:
    virtual void childEvent( QChildEvent *e );
};

#endif

