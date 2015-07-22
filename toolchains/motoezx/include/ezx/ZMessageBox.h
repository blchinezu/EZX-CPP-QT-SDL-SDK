//-------------------------------------------------------------------------------------------------
//
//   Header Name: ZMessageBox.h
//
//   General Description: EZX Message box class
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_MESSAGEBOX_H
#define Z_MESSAGEBOX_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZBaseDialog.h"

class  QLabel;
struct ZMessageBoxPrivate;

/**
 * Displays a brief message, an icon, and some buttons.
 *
 * ZMessageBox provides two types of dialogs: a dialog with up to three buttons 
 * and a dialog which will automatically disappear after specified seconds.
 *
 * As ZMessageBox inherits from ZBaseDialog, the ZMessageBox modal can be 
 * modeless, modal, and system modal. @see ZBaseDialog 
 *
 * For the message box with buttons, the class takes care of the buttons' 
 * geometry management. The return value of exec function is the button index
 * which was clicked. For example, if the leftmost button was clicked, return 
 * valus is 0.
 *
 * @code
 *  ZMessageBox* msgbox = new ZMessageBox(this, pixmapPhone,
 *                            "System Failure\nUnleashing fury upon the world now....",
 *                            "OK",
 *                            "Cancel",
 *                            NULL
 *                            );
 *  int reply = msgbox->exec();
 *
 *  delete msgbox;
 * 
 *  switch(reply)
 *  {
 *    case 0:
 *        cout<<"OK was Pressed"<<endl;
 *        break;
 *    case 1:
 *        cout<<"Cancel was Pressed"<<endl;
 *        break;
 *  }
 * @endcode
 *  
 * Below is the example of a message box which will automitically disappear 
 * after 2 seconds.
 *
 * @code
 *  ZMessageBox* msgbox = new ZMessageBox(this, pixmapPhone,
 *                            "System Failure\nFormatting Disk C:",
 *                             2);
 *  msgbox->exec();
 *  delete msgbox;
 * @endcode
 */

class Q_EXPORT ZMessageBox : public ZBaseDialog
{
    Q_OBJECT

public:

    /**
     * Constructor for a message box with a text, an icon and up 
     * to three buttons.
     *
     * @param parent The parent object of this widget.
     * @param iconPixmap Icon shown on the dialog.
     * @param text Content text on the dialog
     * @param button0Text the leftmost button text
     * @param button1Text the middle button text
     * @param button2Text the rightmost button text
     * @param modal the modal of the message box 
     */
    ZMessageBox( QWidget *parent, const QPixmap& iconPixmap,
            const QString& text, 
            const QString& button0Text = QString::null,
            const QString& button1Text = QString::null,
            const QString& button2Text = QString::null,
            int modal = ZBaseDialog::APP_MODAL );

    /**
     * Constructor for a message box with a text, an icon.
     * The message box will automatically disappear after nseconds.
     *
     * @param parent The parent object of this widget.
     * @param iconPixmap Icon shown on the dialog
     * @param text Content text on the dialog
     * @param nseconds Seconds the dialog will disappear
     * @param modal The modal of the dialog
     */
    ZMessageBox( QWidget *parent, const QPixmap& iconPixmap,
            const QString& text, const int nseconds,
            int modal = ZBaseDialog::APP_MODAL );


    /**
     * Destructor.
     */
    ~ZMessageBox();

    /**
     * Sets the message box text to be displayed.
     * 
     * @param text the string will be shown
     */
    void setText( const QString &text );

    /**
     * Sets the message box icon to be displayed.
     * 
     * @param pixmap the icon will be shown.
     */
    void setIconPixmap( const QPixmap &pixmap );

    /**
     * Sets the text of the message box button.
     * 
     * @param button the button index, begin from 0.
     * @param text the string will be shown on the button.
     */
    void setButtonText( int button, const QString &text );

    /**
     * Adjusts the size of the message box to fit the contents just before
     * QDialog::exec() or QDialog::show() is called.
     */
    void adjustSize();

    /**
     * Opens an message box with a text and up to three buttons.
     * 
     * @param parent The parent object of this widget
     * @param iconPixmap the icon on the message box
     * @param text the content text on the message box
     * @param button0Text the leftmost button text
     * @param button1Text the middle button text
     * @param button2Text the rightmost button text
     * @param modal the modal of the message box 
     * 
     * @return the identifier of the button that was clicked. 
     */
    static int information( QWidget *parent, 
                const QPixmap& iconPixmap,
                const QString& text, 
                const QString& button0Text = QString::null,
                const QString& button1Text = QString::null,
                const QString& button2Text = QString::null,
                int modal = ZBaseDialog::APP_MODAL );

    /**
     * Opens an information message box with a text and up to threee buttons.
     * The message box will return if timer is set. 
     * 
     * @param parent the parent of the message box
     * @param iconPixmap the icon on the message box
     * @param text the content text on the message box
     * @param nseconds the seconds the message box will time out
     * @param button0Text the leftmost button text
     * @param button1Text the middle button text
     * @param button2Text the rightmost button text
     * @param modal the modal of the message box 
     * 
     * @return the identifier of the button that was clicked. If timer is set, 
     * when the time timeout, the return value is -1.
     */
    static int timerInformation( QWidget *parent, 
                const QPixmap& iconPixmap,
                const QString& text, 
                int nseconds,
                const QString& button0Text = QString::null,
                const QString& button1Text = QString::null,
                const QString& button2Text = QString::null,
                int modal = ZBaseDialog::APP_MODAL );

    /**
     * Opens an information message box with a text and no button.
     * The message box will return if timer is set. 
     * 
     * @param parent the parent of the message box
     * @param iconPixmap the icon on the message box
     * @param text the content text on the message box
     * @param nseconds the seconds the message box will time out
     * @param modal the modal of the message box 
     */
    static void timerMessage( QWidget *parent, const QPixmap& iconPixmap,
                 const QString& text, const int nseconds, 
                 int modal = ZBaseDialog::APP_MODAL );

protected:
    
    /**
     * @reimplemented
     */
    void resizeEvent( QResizeEvent * );

    /**
     * @reimplemented
     */
    //void keyPressEvent( QKeyEvent * );  //removed by nukin

private slots:
    
    void slotButtonClicked();
    void slotTimerOutForDlgWithBtn();
    void slotTimerDone();

private:
    
    void init( int, int, int );
    int indexOf( int ) const;
    void resizeButtons();
    QLabel *label;
    ZMessageBoxPrivate *d;
};

#endif // Z_MESSAGEBOX_H
