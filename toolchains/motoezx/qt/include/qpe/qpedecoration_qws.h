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
#ifndef QPE_DECORATION_QWS_H__
#define QPE_DECORATION_QWS_H__


#include <qwsdefaultdecoration_qws.h>
#include <qimage.h>
#include <qdatetime.h>
#include <qguardedptr.h>


#ifndef QT_NO_QWS_QPE_WM_STYLE

class QPEManager;
class QTimer;

class QPEDecoration : public QWSDefaultDecoration
{
public:
    QPEDecoration();
    virtual ~QPEDecoration();

    virtual QRegion region(const QWidget *, const QRect &rect, Region);
    virtual void paint(QPainter *, const QWidget *);
    virtual void paintButton(QPainter *, const QWidget *, Region, int state);

    void maximize( QWidget * );
    void minimize( QWidget * );
    virtual void help( QWidget * );

    enum QPERegion { Help=LastRegion+1 };
    void buttonClicked( QPERegion r );
    
protected:
    void fillTitle( QPainter *p, const QWidget *w, int x, int y, int w, int h );
//    virtual int getTitleWidth(const QWidget *);
    virtual int getTitleHeight(const QWidget *);
    virtual const char **menuPixmap();
    virtual const char **closePixmap();
    virtual const char **minimizePixmap();
    virtual const char **maximizePixmap();
    virtual const char **normalizePixmap();

protected:
    QImage imageOk;
    QImage imageClose;
    QImage imageHelp;
    QString helpFile;
    bool helpExists;
    QPEManager *qpeManager;
};


class QPEManager : public QObject
{
    Q_OBJECT
    friend class QPEDecoration;
public:
    QPEManager( QPEDecoration *d, QObject *parent=0 );

    void updateActive();

protected:
    int pointInQpeRegion( QWidget *w, const QPoint &p );
    virtual bool eventFilter( QObject *, QEvent * );
    void drawButton( QWidget *w, QPEDecoration::QPERegion r, int state );

protected slots:
    void whatsThisTimeout();

protected:
    QPEDecoration *decoration;
    QGuardedPtr<QWidget> active;
    int helpState;
    QTime pressTime;
    QTimer *wtTimer;
};


#endif // QT_NO_QWS_QPE_WM_STYLE


#endif // QPE_DECORATION_QWS_H__
