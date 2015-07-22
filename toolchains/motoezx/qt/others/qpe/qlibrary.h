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

#ifndef QLIBRARY_H
#define QLIBRARY_H

#include <qstring.h>

#ifndef QT_NO_COMPONENT

#include <qpe/qcom.h>

class QLibraryPrivate;

class Q_EXPORT QLibrary
{
public:
    enum Policy
    {
	Delayed,
	Immediately,
	Manual
    };

    QLibrary( const QString& filename, Policy = Delayed );
    ~QLibrary();

    void *resolve( const char* );
    static void *resolve( const QString &filename, const char * );

    bool unload( bool force = FALSE );
    bool isLoaded() const;

    void setPolicy( Policy pol );
    Policy policy() const;

    QString library() const;

    QRESULT queryInterface( const QUuid&, QUnknownInterface** );

private:
    bool load();
    void createInstanceInternal();

    QLibraryPrivate *d;

    QString libfile;
    Policy libPol;
    QUnknownInterface *entry;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    QLibrary( const QLibrary & );
    QLibrary &operator=( const QLibrary & );
#endif
};

#endif // QT_NO_COMPONENT

#endif //QLIBRARY_H
