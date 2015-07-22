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
#ifndef QCOPENVELOPE_H
#define QCOPENVELOPE_H

#ifndef QT_H
#include <qcopchannel_qws.h>
#include <qdatastream.h>
#endif // QT_H

#ifndef QT_NO_COP

class QCopEnvelope : public QDataStream {
    QCString ch, msg;
public:
    QCopEnvelope( const QCString& channel, const QCString& message );
    ~QCopEnvelope();
};

#endif

#endif
