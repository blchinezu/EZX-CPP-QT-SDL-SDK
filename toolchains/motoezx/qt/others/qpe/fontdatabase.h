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
#ifndef FONTFACTORY_H
#define FONTFACTORY_H

#include <qpe/fontfactoryinterface.h>

#include <qfontdatabase.h>
#include <qvaluelist.h>

class QLibrary;

struct FontFactory
{
#ifndef QT_NO_COMPONENT
    QLibrary *library;
#endif
    FontFactoryInterface *interface;
    QFontFactory *factory;
};

class FontDatabase
#ifndef QT_NO_FONTDATABASE
    : public QFontDatabase
#endif
{
public:
    FontDatabase();

    // minimal functionality
    QStringList families () const;
#ifdef QT_NO_FONTDATABASE
    static QValueList<int> standardSizes ();
#endif

    static void loadRenderers();

private:
    static void readFonts( QFontFactory *factory );

private:
    static QValueList<FontFactory> *factoryList;
};

#endif
