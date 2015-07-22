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


//
//   DO NOT ATTEMPT TO USE THIS CLASS
//



#ifndef LNKPROPERTIES_H
#define LNKPROPERTIES_H
#include <qstringlist.h>
#include <qdialog.h>

class AppLnk;
class QListViewItem;
class DocLnk;

class LnkPropertiesBase;

class LnkProperties : public QDialog
{
    Q_OBJECT

public:
// WARNING: Do *NOT* define this yourself. The SL5xxx from SHARP does NOT
//      have this class.
#ifdef QTOPIA_INTERNAL_FSLP
    LnkProperties( AppLnk* lnk, QWidget* parent = 0 );
    ~LnkProperties();
#endif

    void done(int);
private slots:
    void beamLnk();
    void unlinkLnk();
    void duplicateLnk();

signals:
    void select(const AppLnk *);

private:
    void setupLocations();
    bool moveLnk();
    bool copyFile( DocLnk &newdoc );

    AppLnk* lnk;
    int fileSize;
    int currentLocation;
    QStringList locations;
    LnkPropertiesBase *d;
};

#endif // LNKPROPERTIES_H
