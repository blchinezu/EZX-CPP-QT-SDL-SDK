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

#ifndef TASKBARAPPLETINTERFACE_H
#define TASKBARAPPLETINTERFACE_H

#include <qpe/qcom.h>

#ifndef QT_NO_COMPONENT
// {6CA34D0B-C637-4865-A667-7D4CD8A70407}
# ifndef IID_TaskbarApplet
#  define IID_TaskbarApplet QUuid( 0x6ca34d0b, 0xc637, 0x4865, 0xa6, 0x67, 0x7d, 0x4c, 0xd8, 0xa7, 0x04, 0x07)
# endif
#endif

class QWidget;

struct TaskbarAppletInterface : public QUnknownInterface
{
    virtual QWidget *applet( QWidget *parent ) = 0;
    virtual int position() const = 0;
};

#endif
