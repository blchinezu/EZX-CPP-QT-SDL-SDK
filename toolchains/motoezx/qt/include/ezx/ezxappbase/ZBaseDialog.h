
//-------------------------------------------------------------------------------------------------
// Header Name: ZBaseDialog.h
//
// General Description: EZX-style base dialog class
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_BASEDIALOG_H
#define Z_BASEDIALOG_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qdialog.h>
#include <qpalette.h>

/**
 * the ZBaseDialog class implements the application modal and system modal dialogs.
 *
 * Application modal: the dialog blocks the application's input.
 * System modal: the dialog blocks the system's input.
 *
 * @note: Due to input-widget limitations, dialogs can not contain text-input
 * fields in A760 and A768.
 */

class ZBaseDialog : public QDialog //fox size $D4 , $D0  //confirmed
{
    Q_OBJECT

public:

    /**
     * Dialog's Modal type
     */
    enum
    {
        NO_MODAL = 0,  ///< \a \c the dialog is modalessness
        APP_MODAL,     ///< \a \c the dialog is application modal    
        SYSTEM_MODAL   ///< \a \c the dialog is system modal     
    };

    /**
     * Constructor of ZBaseDialog
     *
     * @param modal set the dialog modal type 
     *
     * @see the enum above
     */
    ZBaseDialog( QWidget *parent = 0,const char* name = 0,int modal = NO_MODAL,WFlags f = 0 );


    /**
     * Destructor of ZBaseDialog. 
     */
    virtual ~ZBaseDialog();


    /**
     * Get the dialog modal type. 
     *
     * @see the enum above
     */
    int getModalType() { return mModal; }

public slots:

    /**
     * Reimplement
     * Hides the dialog and sets its result code to r
     *
     * @param r the result code 
     */
    virtual void done( int r );

    /**
     * Reimplement
     * Hides the dialog and sets its result code to Rejected
     */
    virtual void reject();

    /**
     * Reimplement
     * Hides the dialog and sets its result code to Accepted
     */
    virtual void accept();

protected:

    /**
     * Reimplement
     */
    //ÃÎ virtual bool qwsEvent( QWSEvent* e );

    /**
     * Reimplement
     */
    //virtual bool event( QEvent* e ); //fox remove it

    /**
     * Reimplement
     */
    //virtual bool eventFilter( QObject* o, QEvent* e);  //fox remove it

private:

    int mModal; //fox $D0
};

#endif




