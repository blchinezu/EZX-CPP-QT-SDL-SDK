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

#ifndef __CATEGORYMENU_H__
#define __CATEGORYMENU_H__

#include <qpopupmenu.h>
#include <qstring.h>
#include <qarray.h>
#include <qmap.h>

class CategoryMenuPrivate;
class CategoryMenu : public QPopupMenu
{
    Q_OBJECT
public:
    CategoryMenu( const QString &appName, bool, QWidget *parent = 0, 
	    const char *name = 0 );
    ~CategoryMenu();

    bool isSelected(const QArray<int> &cUids) const;

    void setCurrentCategory( int newCatUid );
    void setCurrentCategoryAll( );
    void setCurrentCategoryUnfiled( );

signals:
    void categoryChange();

public slots:
    void reload();

private slots:
    void mapMenuId(int);

private:
    QString appName;
    bool includeGlobal;

    QMap<int, int> menuToId;
    QMap<int, int> idToMenu;
    int currentMid;

    CategoryMenuPrivate *d;
};

#endif
