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
#ifndef TZSELECT_H
#define TZSELECT_H

#include <qhbox.h>
#include <qcombobox.h>
#include <qstringlist.h>

class QToolButton;

// a function to load defaults in case there is no file
QStringList timezoneDefaults( void );

class TZCombo : public QComboBox
{
    Q_OBJECT
public:
    TZCombo( QWidget* parent, const char* name = 0 );
    ~TZCombo();

    QString currZone() const;
    void setCurrZone( const QString& id );

protected:
    void keyPressEvent( QKeyEvent *e );
    void mousePressEvent(QMouseEvent*e);
    void updateZones();

private slots:
    void handleSystemChannel(const QCString&, const QByteArray&);

private:
    QStringList identifiers;
    QStringList extras;
};

class TimeZoneSelectorPrivate;
class TimeZoneSelector : public QHBox
{
    Q_OBJECT
public:
    TimeZoneSelector( QWidget* parent = 0, const char* name=0 );
    ~TimeZoneSelector();
    
    QString currentZone() const;
    void setCurrentZone( const QString& id );

signals:
    void signalNewTz( const QString& id );

private slots:
    void slotTzActive( int index );
    void slotExecute( void );

private:
    TZCombo *cmbTz;
    QToolButton *cmdTz;
    TimeZoneSelectorPrivate *d;
};

#endif
