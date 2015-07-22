//-------------------------------------------------------------------------------------------------
//
//  Header Name: ZLayout.h
//
//  General Description: Layout-related defines and functions
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_LAYOUT_H
#define Z_LAYOUT_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif


/**
 * Includes common macros and functions about the overall application layout.
 *
 * The EzX platform styleguide defines the layout for all UI applications.
 * The styleguide requirements are codified here.
 *
 * @note Layout related Interface Format & Naming Rules:
 * @{
 * QRect getXXXXYYYYmm_nnR( ) are per Motorola Layout Requirements Spec v0.3
 * get: never changed as a leading one.
 * XXXX: Gnb, Cst, Dlg - Container names.
 * YYYY: A, BC - Dialog names only when XXXX is Dlg.
 * mm: 2, 3a, 3b - button amount and relevant layout scheme,
 * for example, 3a meaning "3 buttons (a) Layout".
 * _: never changed as a intermediate between mm and nn.
 * nn: 1, 2, 3 - which actual button is pointed here. mm_nn means the number nn button
 * in mm buttons Layout.
 * R: never changed as a tail meaning Rect or Region.
 *
 * Return QRect object meaning a rectangle area for the specific widget.
 *
 * For example, a function getCst4a_2R( ) regulates the 2nd button rectangle area
 * of CST with 4 buttons, which is a layout scheme marked (a) in LRS document.
 *
 * Motorola internal developers should be able to find the appropriate function to 
 * use by referencing the layout requirement specification for their application.
 *
 * @}
 *
 * @see ZLRS.h
 */

#include <qrect.h>

/**
 * Dialog (Maxium) Width
 * No dialog or transient can be wider this.
 */
#define EZX_DLG_WIDTH 224

/**
 * Dialog Title Left Spacing
 * Title text for dialogs must have spacing to the left border of the title area,
 * especially for the gradient title bar.
 */
#define EZX_DLGTITLE_LEFT_SPACING 5

/**
 * EzX CheckBox BoxSize
 * Qt default CheckBox BoxSize (16) is too small for a handset device.
 * EzX wants to larger the BoxSize for QCheckBox and QListViewItem, etc.
 */
#define EZX_CHECK_BOXSIZE 20

/**
 * Default font sizes for the application UI display.
 * The Macros are total Theme bounded, mapping to Theme setup UI with
 * "Text Size" Small/Medium/Large.
 * @see EZX_FONT_SIZE_T
 */
#define DEFAULT_FONT_SIZE_SMALL 15
#define DEFAULT_FONT_SIZE_MEDIUM 18
#define DEFAULT_FONT_SIZE_LARGE 21

/**
 * @enum EZX_FONT_SIZE_T maps to Theme setup UI "Text Size" setting.
 * This enumeration doesn't bookkeep the exact font size.
 * @see DEFAULT_FONT_SIZE_SMALL
 * @see DEFAULT_FONT_SIZE_MEDIUM
 * @see DEFAULT_FONT_SIZE_LARGE
 */
typedef enum
{
     EZX_FONT_SIZE_SMALL=0,
     EZX_FONT_SIZE_MEDIUM,
     EZX_FONT_SIZE_LARGE,
} EZX_FONT_SIZE_T;

/**
 * Define the extensions of all scroll bars seen in UI applications.
 * For vertical scroll bars, the extension defines the width of scroll bar;
 * for horizontal scroll bar, teh extension defines the height of scroll bar.
 */
#define EZX_SCROLLBAR_EXTENSION 19

/**
 * Macro functions for convenience
 */
#define ZSetLayout(widgetPtr, globalR) widgetPtr->setGeometry(ZGlobal::mapFromGlobalR(widgetPtr, globalR))
#define ZDiffR(parent, child) ZGlobal::diffRect(ZGlobal::get##parent(), ZGlobal::get##child())

class QWidget;
class QPopupMenu;
class QPoint;

namespace ZGlobal
{
    /**
     * Two functions to keep old code working well
     * @return The appropriate line heigth which is related to application font size
     * @see getLineSpace()
     */
    int getLineHeight();
  
    /**
     * line space for multi-line widget, such as ZMultiLineEdit
     * @return The appropriate line spacing between lines
     * @see getLineHeight()
     */
    int getLineSpace();
  
    /**
     *
     * @param gRect rectangle area in global screen coordinates
     * @param self the widget gRect are going to turn on
     * @return rectangle area in widget coordinate, translated from global screen rectangle gRect
     * @see ZSetLayout(widgetPtr, globalR)
     * 
     * @code
     * //parent widget is a CST with 4 buttons matching LRS CST 4(b)
     * class CSTWidget
     * {
     *     CSTWidget() //constructor
     *     {
     *         ...
     *         //child widget is a button
     *         QPushButton child1=new QPushButton(this);
     *         //get correct layout area
     *         QRect tmp=ZGlobal::mapFromGlobalR(child1, ZGlobal::getCst4b_1R());
     *         //turn on layout regulation
     *         child1->setGeometry(tmp);
     *         ...
     *     }
     * };
     * @endcode
     */
     QRect mapFromGlobalR(QWidget* self, QRect gRect);
  
    /**
     * Return the difference of two rectangles belonging to a parent widget and a 
     * child widget.
     *
     * @param parent: parent widget rectangle area in global screen coordinates
     * @param child: child widget rectangle area in global screen coordinates
     * @return A child rectangle area in parent widget coordinates
     * @see ZDiffR(parent, child)
     *
     * @code
     * //parent widget is a dialog B with 2 buttons matching LRS DlgB2_2
     * class DialogWidget
     * {
     *     DialogWidget() //constructor
     *     {
     *         ...
     *         //sample child widget is a button
     *         QPushButton child1=new QPushButton(this);
     *         //get correct layout area based on the case that DialogWidget
     *         //adopts ZGlobal::getDlgBCR( ) layout definition
     *         QRect tmp=
     *             ZGlobal::diffRect(ZGlobal::getDlgBCR(), ZGlobal::getDlgB2_2R());
     *         //turn on layout regulation
     *         child1->setGeometry(tmp);
     *         ...
     *     }
     * };
     * @endcode
     */     
    QRect diffRect(QRect parent, QRect child);
   
    /*
     * Following are global layout definition
     */
   
    /**
     * @return Screen area: same as Desktop area, just a different name.
     */
    QRect getScreenR();
  
    /**
     * @return Desktop area: Same infomation as screen
     */
    QRect getDesktopRect();
  
    /**
     * @return GNB area
     */
    QRect getGnbR();
  
    /**
     * @return CST area
     */
    QRect getCstR();
  
    /**
     * @return Home area (screen-gnb)
     */
    QRect getHomeR();
   
    /**
     * @return content area (screen-gnb-cst)
     */
    QRect getContentR();
  
    /**
     * @return GNB_Status Bar area: in Content area actually
     */
    QRect getStatusBarR();
  
    /**
     * @return Content -(GNB_StatusBar) area
     */
    QRect getSubContentR();
    
    /**
     * @return The small content rect, use it when the kb appears
     */
    QRect getSmallContentR();
  
    /**
     * @return input keyboard area when popped up
     * @note Useless for LRS0.9.3 - compatible interface
     */
    QRect getKbR();
  
    /**
     * @return The rect of CST area
     */
    QRect getCSTRect();
  
    /**
     * @return GNB area, the same as getGnbR()
     * @see getGnbR()
     */
    QRect getGNBRect();
    
    /**
     * @return The mainwidget area, excludes CST
     * the same as getContentR()
     * @see getContentR()
     */
    QRect getMainWidgetRect();
  
    /**
     * Calculate the prefered popup menu position
     * @param base ???
     * @param popup The popup menu widget
     * @param pos Prefered position to show the popup menu widget popup
     * @note Deprecated interface
     */
    void getPopupMenuTopLeft(QWidget* base,QPopupMenu* popup,QPoint& pos);
  
    /**
     * Function to get the font size
     * @param fontSizeType Theme "Text Size" of Small/Medium/Large
     * @return The exact font size in terms of Theme "Text Size" of Small/Medium/Large
     * @see EZX_FONT_SIZE_T
     * @see DEFAULT_FONT_SIZE_SMALL
     * @see DEFAULT_FONT_SIZE_MEDIUM
     * @see DEFAULT_FONT_SIZE_LARGE
     */
    int getFontSize(EZX_FONT_SIZE_T fontSizeType);
};

#endif //Z_LAYOUT_H
