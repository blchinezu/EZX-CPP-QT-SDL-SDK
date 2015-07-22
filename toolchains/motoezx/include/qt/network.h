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
#ifndef NETWORK_H
#define NETWORK_H

#include <qstringlist.h>
class QListBox;
class QObject;
class QWidget;
struct NetworkInterface;
class Config;

class Network {
public:
    static void start(const QString& service=QString::null, const QString& password=QString::null);
    static void stop();

    static QString settingsDir();
    static QString serviceName(const QString& service);
    static QString serviceType(const QString& service);
    static bool serviceNeedsPassword(const QString& service);
    static void connectChoiceChange(QObject* receiver, const char* slot);
    static QStringList choices(QListBox* = 0, const QString& dir=QString::null);
    static void writeProxySettings( Config &cfg );

    static NetworkInterface* loadPlugin(const QString& type);

    static int addStateWidgets(QWidget* parent);

    // Server only
    static void createServer(QObject* parent);
    static bool networkOnline();
};

#endif
