/****************************************************************************
** $Id: qt/src/kernel/qkeyboard_qws.h   2.3.6   edited 2002-12-09 $
**
** Definition of Qt/Embedded keyboards
**
** Created : 991025
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses for Qt/Embedded may use this file in accordance with the
** Qt Embedded Commercial License Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QKEYBOARD_QWS_H
#define QKEYBOARD_QWS_H

#ifndef QT_H
#include "qobject.h"
#endif // QT_H

#ifndef QT_NO_QWS_KEYBOARD
class Q_EXPORT QWSKeyboardHandler : public QObject {
    Q_OBJECT
public:
    QWSKeyboardHandler();
    virtual ~QWSKeyboardHandler();

protected:
    virtual void processKeyEvent(int unicode, int keycode, int modifiers,
			    bool isPress, bool autoRepeat);
};
#endif

#if !defined(QT_EZX_INPUT)
Q_EXPORT bool qwsSetKeyboardAutoRepeat( int delay, int period );
Q_EXPORT bool qwsGetKeyboardAutoRepeat( int *delay, int *period );
#endif /* !defined(QT_EZX_INPUT) */

#endif
