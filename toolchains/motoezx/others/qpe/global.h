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
#ifndef GLOBAL_H
#define GLOBAL_H

#include <qstringlist.h>
#include <qguardedptr.h>
class QDawg;
class QLabel;
class QWidget;
class AppLnk;
class DocLnkSet;

class Global
{
public:
    Global();

    // Dictionaries
    static const QDawg& fixedDawg();
    static const QDawg& addedDawg();
    static const QDawg& dawg(const QString& name);

    static void addWords(const QStringList& word);
    static void addWords(const QString& dictname, const QStringList& word);
    // static void removeWords(const QStringList& word); -- if someone wants it

    static void createDocDir();

    static void findDocuments(DocLnkSet* folder, const QString &mimefilter=QString::null);

    static QString applicationFileName(const QString& appname, const QString& filename);

    struct Command {
	const char *file;
	QWidget *(*func)( bool );
	bool maximized;
	bool documentary;
    };
    static void setBuiltinCommands( Command* );

    static void invoke( const QString &exec);
    static void execute( const QString &exec, const QString &document=QString::null );
    static void setDocument( QWidget* receiver, const QString& document );
    static bool terminateBuiltin( const QString& );
    static void terminate( const AppLnk* );

    static bool isBuiltinCommand( const QString &name );

    // system messaging
    static void applyStyle();
    static void statusMessage(const QString&);
    static QWidget *shutdown( bool = FALSE );
    static QWidget *restart( bool = FALSE );
    static void hideInputMethod();
    static void showInputMethod();

    static void writeHWClock();

    static QString shellQuote(const QString& s);
    static QString stringQuote(const QString& s);

private:
    static Command* builtin;
    static QGuardedPtr<QWidget> *running;
};

#endif
