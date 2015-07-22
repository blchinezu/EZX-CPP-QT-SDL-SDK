//------------------------------------------------------------------------
//
// Header Name: ZGlobal.h
//
// General Description: EZX Global defines
//
//-------------------------------------------------------------------------
//
//                    Motorola Confidential Proprietary
//             Template ID and version: TMP_LFC_50068  Version 1.2
//              (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------

#ifndef UTIL_CST_H
#define UTIL_CST_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//--------------------------------------------------------------------------
//                              INCLUDE FILES
//--------------------------------------------------------------------------
#include "qwidget.h"
#include "qstring.h"
#include <ZPushButton.h>
#define EZX_CST_BTN_MENU QString("CST_Menu")
#define EZX_CST_BTN_EXIT QString("CST_Exit")
#define EZX_CST_BTN_BACK QString("CST_Back")
//--------------------------------------------------------------------------
//                            CLASS DECLARATION
//--------------------------------------------------------------------------
class QPopupMenu;
//class ZPushButton;

/**
 * CST widget for all A780 styleGuide defined
 * 
 * Only three gradient buttons
 * Layout is also defined by styleGuide
 * and LRS 4(a) button scheme.
 *
 * e.g. Construct a CST with specified resource ID for leftbutton and rightbutton,
 *      and specified text for midbutton;
 * QWidget *cst = new UTIL_CST(this,
 *                             "MyMainButtonText",
 *                             "MyLeftButtonResID",
 *                             "MyRightButtonResID");
 *
 * e.g. Default Construct a CST
 * QWidget *cst = new UTIL_CST;
 *
 * There will be no quickExit popup menu untill
 * quickExit(TRUE) is called.
 */
class UTIL_CST: public QWidget
{
	Q_OBJECT
public:
    /**
     * UTIL_CST Constructor
     * Using default parameters instantiate CST widget
     * with specified  button text for the main (middle) button
     *
     * @param parent: parent widget
     * @param leftResID: left button icon resouce ID
     * @param midText: middle button Text
     * @param rightResID: right button icon resource ID
     */
    UTIL_CST( QWidget* parent=0, QString midText = NULL, QString leftResID = "CST_Menu", QString rightResID = "CST_Back" );

    /**
     * @return left button
     */
    ZPushButton* getLeftBtn();
    /**
     * @return main (middle) button
     */
    ZPushButton* getMidBtn();
    /**
     * @return right button
     */
    ZPushButton* getRightBtn();

/**
     * @return TRUE if quick-exit popup menu has been enabled
     */
    bool getQuickExit();
public slots:
    /**
     * Block all CST signal-slot
     * Simply block/unblock all CST button signal-slot connections
     * @param block: TRUE, block; FALSE, release.
     */
    void blockSignals( bool block );

    /**
     * Set EzX application quick exit popup menu
     * in terms of A780 styleGuide
     * If press-hold the back button for seconds,
     * a shortcut popup menu with item "Exit" will
     * show for exit applcation immediately.
     * The shortcut just call qapp->quit()
     *
     * @param has: TRUE, has the exit popup menu;
     * FALSE, has no the exit popup menu.
     */
    void setQuickExit( bool has );
    
private:
    ZPushButton* leftBtn;//CSM button, 
    ZPushButton* midBtn;//main button, 
    ZPushButton* rightBtn;//back|exit button
    QPopupMenu* quickExit;
};

#endif //UTIL_CST_H
