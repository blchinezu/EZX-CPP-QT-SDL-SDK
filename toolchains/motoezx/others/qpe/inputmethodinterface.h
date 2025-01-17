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

#ifndef INPUTMETHODINTERFACE_H
#define INPUTMETHODINTERFACE_H

#include <qpe/qcom.h>

#include <qnamespace.h>
#include <qstring.h>

#ifndef QT_NO_COMPONENT
// {637A8A14-AF98-41DA-969A-2BD16ECDA8C7}
# ifndef IID_InputMethod
#  define IID_InputMethod QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0xc7)
# endif
#endif

class QWidget;
class QPixmap;
class QObject;

struct InputMethodInterface : public QUnknownInterface
{
    virtual QWidget *inputMethod( QWidget *parent, Qt::WFlags f ) = 0;
    virtual void resetState() = 0;
    virtual QPixmap *icon() = 0;
    virtual QString name() = 0;
    virtual void onKeyPress( QObject *receiver, const char *slot ) = 0;
};

#endif
