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
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <qstring.h>
#include <qstringlist.h>

class AppLnk;
class DocLnk;
class FileManagerPrivate;

class FileManager
{
public:
    FileManager();
    ~FileManager();

    bool saveFile( const DocLnk&, const QByteArray &data );
    bool saveFile( const DocLnk&, const QString &text );
    bool loadFile( const DocLnk&, QByteArray &data );
    bool loadFile( const DocLnk&, QString &text );
    bool copyFile( const AppLnk &src, const AppLnk &dest );

    // The caller must delete the return values.
    QIODevice* openFile( const DocLnk& );
    QIODevice* saveFile( const DocLnk& );

    bool exists( const DocLnk& );

protected:
    bool ensurePathExists( const QString &fn );

private:
    FileManagerPrivate *d;
};


#endif
