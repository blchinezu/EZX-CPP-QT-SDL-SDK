//generated by genheader.sh write by wangbin
/********************************************************
**libezxaid.so.1.0.0
**2010年 06月 24日 星期四 17:07:01 CST
**libraries depends:
	ezxaid,ezxam,dmnative,ezxphone,ezx-cmseccert,ezxdrmsp,ezxssl,ezxtapi,ezxflex,ezxdrmsecuretime,ezxdrmcipher
*************************************************************/

//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                   Template ID and version: IL93-TMP-01-0107  Version 1.10
//                    (c) Copyright Motorola XXXX-XXXX, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Developer Name/ID            MM/DD/YYYY     CSGceXXXXX   BRIEF description of changes made   
// Tim Zhao/w19411		        6/25/2002			        created first time
// Sheng Wenliang/w21004        04/12/2005                  remove obsoleted interfaces.
//
//
//--------------------------------------------------------------------------------------------------

#ifndef __AM_QTPACKAGEMANAGER_H__
#define __AM_QTPACKAGEMANAGER_H__

#include "AM_PackageManager.h"
#include "AM_Global.h"

class AM_AppLnk;
class AM_MsgBoxInterface;
class AM_ProgressDlgInterface;

class AM_QtPackageManager : public AM_PackageManager //can remove
{
public:
    AM_QtPackageManager();
    virtual ~AM_QtPackageManager();

    virtual bool install( const QString &pkgFile, AM_Global::Device device = AM_Global::Flash2 );
    virtual bool uninstall( const AM_AppLnk &app );

protected:
    ///bool preInstall( void );
    ///bool checkPackageValid( void ) const;
    ///void postInstall( void );

    bool modifyDatabase( const QString &pkgFile, const QString &folderUid, QString &appUid );
    bool uninstallModifyDatabase( const AM_AppLnk &app  );

    void MessageBox( const QPixmap &icon, 
                     const QString &strTitle, 
                     const QString &strInstructText = QString::null,
                     //const AM_MsgBoxInterface::MsgBoxType type = AM_MsgBoxInterface::TypeOK );
                     const QString &button0Text = QString::null,
                     const QString &button1Text = QString::null,
                     const QString &button2Text = QString::null );


private:
    QString _domainName;

    AM_ProgressDlgInterface *pProgress;
    AM_MsgBoxInterface *pMsgBox;
};

#endif //__AM_QTPACKAGEMANAGER_H__
