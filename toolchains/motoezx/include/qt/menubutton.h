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
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <qpushbutton.h>
#include <qstringlist.h>

class MenuButton : public QPushButton {
    Q_OBJECT
public:
    MenuButton( QWidget* parent, const char* name=0);
    MenuButton( const QStringList& items, QWidget* parent, const char* name=0);

    void clear();

    int currentItem() const;
    QString currentText() const;

    void insertItems( const QStringList& items );
    void insertItem( const QIconSet& icon, const QString& text=QString::null );
    void insertItem( const QString& text );
    void insertSeparator();

    void setLabel(const QString& label);

signals:
    void selected(int);
    void selected(const QString&);

public slots:
    void select(int);
    void select(const QString&);

private:
    void init();
    QStringList txts;
    QPopupMenu* pop;
    int nitems;
    int cur;
    QString lab;
    void updateLabel();
};

#endif

