//--------------------------------------------------------------------------------------------------
//                                                                               
//   Header Name: AM_StandardDld.h
//
//   General Description: General description of the contents of this header file. 
//
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
//
// Tim Zhao/w19411		10/14/2002		    first time created
//
//
//--------------------------------------------------------------------------------------------------
//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef __AM_STANDARDDLG_H__
#define __AM_STANDARDDLG_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif


#include <qdialog.h>

class UTIL_PushButton;
class QWidget;
class QVBoxLayout;
class QHBoxLayout;

class AM_StandardDlg : public QDialog
{
    Q_OBJECT
public:
    AM_StandardDlg( QWidget *parent = 0, const char *name = 0 );
    virtual ~AM_StandardDlg();

    enum Select
    {
	Cancel = 0,
	OK = 1
    };

    QVBoxLayout* getMainLayout( void );
    Select	 getSelect( void );

protected:
    virtual void init( void );
    void preInit( void );
    void postInit( void );

protected slots:
    virtual void slotOk( void );
    virtual void slotCancel( void );

private:
    QVBoxLayout *pWholeLayout;
    QVBoxLayout *pMainLayout;
    QHBoxLayout *pBottomLayout;

    UTIL_PushButton *pOkButton;
    UTIL_PushButton *pCancelButton;

    Select	select;
};

#endif // __AM_STANDARDDLG_H__
