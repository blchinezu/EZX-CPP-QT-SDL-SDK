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

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <qpe/palmtoprecord.h>
#include <qpe/recordfields.h>

#include <qstringlist.h>

#if defined(QPC_TEMPLATEDLL)
// MOC_SKIP_BEGIN
template class QPC_EXPORT QMap<int, QString>;
// MOC_SKIP_END
#endif

class ContactPrivate;
class QPC_EXPORT Contact : public Qtopia::Record
{
    friend class DataSet;
public:
    Contact();
    Contact( const QMap<int, QString> &fromMap );
    virtual ~Contact();

    static void writeVCard( const QString &filename, const QValueList<Contact> &contacts);
    static void writeVCard( const QString &filename, const Contact &c );
    static QValueList<Contact> readVCard( const QString &filename );

    enum journal_action { ACTION_ADD, ACTION_REMOVE, ACTION_REPLACE };

    void setTitle( const QString &v ) { replace( Qtopia::Title, v ); }
    void setFirstName( const QString &v ) { replace( Qtopia::FirstName, v ); }
    void setMiddleName( const QString &v ) { replace( Qtopia::MiddleName, v ); }
    void setLastName( const QString &v ) { replace( Qtopia::LastName, v ); }
    void setSuffix( const QString &v ) { replace( Qtopia::Suffix, v ); }
    void setFileAs( const QString &v ) { replace( Qtopia::FileAs, v ); }
    void setFileAs();

    // default email address
    void setDefaultEmail( const QString &v ) { replace( Qtopia::DefaultEmail, v ); }
    // the emails should be seperated by a semicolon
    void setEmails( const QString &v );

    // home
    void setHomeStreet( const QString &v ) { replace( Qtopia::HomeStreet, v ); }
    void setHomeCity( const QString &v ) { replace( Qtopia::HomeCity, v ); }
    void setHomeState( const QString &v ) { replace( Qtopia::HomeState, v ); }
    void setHomeZip( const QString &v ) { replace( Qtopia::HomeZip, v ); }
    void setHomeCountry( const QString &v ) { replace( Qtopia::HomeCountry, v ); }
    void setHomePhone( const QString &v ) { replace( Qtopia::HomePhone, v ); }
    void setHomeFax( const QString &v ) { replace( Qtopia::HomeFax, v ); }
    void setHomeMobile( const QString &v ) { replace( Qtopia::HomeMobile, v ); }
    void setHomeWebpage( const QString &v ) { replace( Qtopia::HomeWebPage, v ); }

    // business
    void setCompany( const QString &v ) { replace( Qtopia::Company, v ); }
    void setBusinessStreet( const QString &v ) { replace( Qtopia::BusinessStreet, v ); }
    void setBusinessCity( const QString &v ) { replace( Qtopia::BusinessCity, v ); }
    void setBusinessState( const QString &v ) { replace( Qtopia::BusinessState, v ); }
    void setBusinessZip( const QString &v ) { replace( Qtopia::BusinessZip, v ); }
    void setBusinessCountry( const QString &v ) { replace( Qtopia::BusinessCountry, v ); }
    void setBusinessWebpage( const QString &v ) { replace( Qtopia::BusinessWebPage, v ); }
    void setJobTitle( const QString &v ) { replace( Qtopia::JobTitle, v ); }
    void setDepartment( const QString &v ) { replace( Qtopia::Department, v ); }
    void setOffice( const QString &v ) { replace( Qtopia::Office, v ); }
    void setBusinessPhone( const QString &v ) { replace( Qtopia::BusinessPhone, v ); }
    void setBusinessFax( const QString &v ) { replace( Qtopia::BusinessFax, v ); }
    void setBusinessMobile( const QString &v ) { replace( Qtopia::BusinessMobile, v ); }
    void setBusinessPager( const QString &v ) { replace( Qtopia::BusinessPager, v ); }
    void setProfession( const QString &v ) { replace( Qtopia::Profession, v ); }
    void setAssistant( const QString &v ) { replace( Qtopia::Assistant, v ); }
    void setManager( const QString &v ) { replace( Qtopia::Manager, v ); }

    // personal
    void setSpouse( const QString &v ) { replace( Qtopia::Spouse, v ); }
    void setGender( const QString &v ) { replace( Qtopia::Gender, v ); }
    void setBirthday( const QString &v ) { replace( Qtopia::Birthday, v ); }
    void setAnniversary( const QString &v ) { replace( Qtopia::Anniversary, v ); }
    void setNickname( const QString &v ) { replace( Qtopia::Nickname, v ); }
    void setChildren( const QString &v );

    // other
    void setNotes( const QString &v ) { replace( Qtopia::Notes, v); }

    bool match( const QString &regexp ) const;

// DON'T ATTEMPT TO USE THIS
#ifdef QTOPIA_INTERNAL_CONTACT_MRE
    bool match( const QRegExp &regexp ) const;
#endif

//     // custom
//     void setCustomField( const QString &key, const QString &v )
//         { replace(Custom- + key, v ); }

    // name
    QString fullName() const;
    QString title() const { return find( Qtopia::Title ); }
    QString firstName() const { return find( Qtopia::FirstName ); }
    QString middleName() const { return find( Qtopia::MiddleName ); }
    QString lastName() const { return find( Qtopia::LastName ); }
    QString suffix() const { return find( Qtopia::Suffix ); }
    QString fileAs() const { return find( Qtopia::FileAs ); }

    // email
    QString defaultEmail() const { return find( Qtopia::DefaultEmail ); }
    QString emails() const { return find( Qtopia::Emails ); }
    QStringList emailList() const;

    // home
    QString homeStreet() const { return find( Qtopia::HomeStreet ); }
    QString homeCity() const { return find( Qtopia::HomeCity ); }
    QString homeState() const { return find( Qtopia::HomeState ); }
    QString homeZip() const { return find( Qtopia::HomeZip ); }
    QString homeCountry() const { return find( Qtopia::HomeCountry ); }
    QString homePhone() const { return find( Qtopia::HomePhone ); }
    QString homeFax() const { return find( Qtopia::HomeFax ); }
    QString homeMobile() const { return find( Qtopia::HomeMobile ); }
    QString homeWebpage() const { return find( Qtopia::HomeWebPage ); }
    /** Multi line string containing all non-empty address info in the form
    * Street
    * City, State Zip
    * Country
    */
    QString displayHomeAddress() const;

    // business
    QString company() const { return find( Qtopia::Company ); }
    QString businessStreet() const { return find( Qtopia::BusinessStreet ); }
    QString businessCity() const { return find( Qtopia::BusinessCity ); }
    QString businessState() const { return find( Qtopia::BusinessState ); }
    QString businessZip() const { return find( Qtopia::BusinessZip ); }
    QString businessCountry() const { return find( Qtopia::BusinessCountry ); }
    QString businessWebpage() const { return find( Qtopia::BusinessWebPage ); }
    QString jobTitle() const { return find( Qtopia::JobTitle ); }
    QString department() const { return find( Qtopia::Department ); }
    QString office() const { return find( Qtopia::Office ); }
    QString businessPhone() const { return find( Qtopia::BusinessPhone ); }
    QString businessFax() const { return find( Qtopia::BusinessFax ); }
    QString businessMobile() const { return find( Qtopia::BusinessMobile ); }
    QString businessPager() const { return find( Qtopia::BusinessPager ); }
    QString profession() const { return find( Qtopia::Profession ); }
    QString assistant() const { return find( Qtopia::Assistant ); }
    QString manager() const { return find( Qtopia::Manager ); }
     /** Multi line string containing all non-empty address info in the form
    * Street
    * City, State Zip
    * Country
    */
    QString displayBusinessAddress() const;

    //personal
    QString spouse() const { return find( Qtopia::Spouse ); }
    QString gender() const { return find( Qtopia::Gender ); }
    QString birthday() const { return find( Qtopia::Birthday ); }
    QString anniversary() const { return find( Qtopia::Anniversary ); }
    QString nickname() const { return find( Qtopia::Nickname ); }
    QString children() const { return find( Qtopia::Children ); }
    QStringList childrenList() const;

    // other
    QString notes() const { return find( Qtopia::Notes ); }
    QString groups() const { return find( Qtopia::Groups ); }
    QStringList groupList() const;

//     // custom
//     const QString &customField( const QString &key )
//         { return find( Custom- + key ); }

    static QStringList fields();
    static QStringList trfields();

    QString toRichText() const;
    QMap<int, QString> toMap() const;
    QString field( int key ) const { return find( key ); }


    // journaling...
    void saveJournal( journal_action action, const QString &key = QString::null );
    void save( QString &buf ) const;

    void setUid( int i )
{ Record::setUid(i); replace( Qtopia::AddressUid , QString::number(i)); }

private:
    friend class AbTable;
    void insert( int key, const QString &value );
    void replace( int key, const QString &value );
    QString find( int key ) const;

    QString displayAddress( const QString &street,
			    const QString &city,
			    const QString &state,
			    const QString &zip,
			    const QString &country ) const;

    Qtopia::UidGen &uidGen() { return sUidGen; }
    static Qtopia::UidGen sUidGen;
    QMap<int, QString> mMap;
    ContactPrivate *d;
};

#endif
