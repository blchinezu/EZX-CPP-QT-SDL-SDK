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
#ifndef FILESELECTOR_H
#define FILESELECTOR_H

#include <qhbox.h>
#include <qvbox.h>
#include <qtoolbutton.h>
#include <qlistview.h>

#include "filemanager.h"
#include "applnk.h"

class QPopupMenu;
class QPushButton;
class FileSelectorView;

class FileSelectorItem : public QListViewItem
{
public:
    FileSelectorItem( QListView *parent, const DocLnk& f );
    ~FileSelectorItem();

    DocLnk file() const { return fl; }

private:
    DocLnk fl;
};

class FileSelectorPrivate;
class FileSelector : public QVBox
{
    Q_OBJECT

public:
    FileSelector( const QString &mimefilter, QWidget *parent, const char *name, bool newVisible = TRUE, bool closeVisible = TRUE );
    ~FileSelector();
    void setNewVisible( bool b );
    void setCloseVisible( bool b );
    void reread();
    int fileCount();
    const DocLnk *selected();

signals:
    void fileSelected( const DocLnk & );
    void newSelected( const DocLnk & );
    void closeMe();

private slots:
    void createNew();
    void fileClicked( int, QListViewItem *, const QPoint &, int );
    // pressed to get 'right down'
    void filePressed( int, QListViewItem *, const QPoint &, int );
    void fileClicked( QListViewItem *);

private:
    FileSelectorView *view;
    QString filter;
    QToolButton *buttonNew, *buttonClose;
    FileSelectorPrivate *d;
};

#endif
