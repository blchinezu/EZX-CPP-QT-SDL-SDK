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

#ifndef __CATEGORYWIDGET_H__
#define __CATEGORYWIDGET_H__

#include <qvbox.h>
#include <qarray.h>

class CategoryEdit;

class CategoryWidget : public QVBox
{
public:
    CategoryWidget( QWidget *parent = 0, const char *name = 0 );
    CategoryWidget( const QArray<int> &vlRecs, const QString &appName,
		    QWidget *parent = 0, const char *name = 0 );
    CategoryWidget( const QArray<int> &vlRecs, const QString &appName,
		    const QString &visibleName,
		    QWidget *parent = 0, const char *name = 0 );
    ~CategoryWidget();
    void setCategories( const QArray<int> &vlRecs, const QString &appName );
    void setCategories( const QArray<int> &vlRecs, const QString &appName,
			const QString &visibleName );
    QArray<int> newCategories();
    void kludge();

private:
    CategoryEdit *ce;
};


#endif
