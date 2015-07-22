
//-------------------------------------------------------------------------------------------------
//                                                                    
//   Header Name: zpushbutton.h
//
//   General Description: EZX-style push buttons
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_PUSHBUTTON_H
#define Z_PUSHBUTTON_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qtoolbutton.h>
#include <ZDirectPixmap.h>
#include <ZSkin.h>

/**
 * Class that uses resource-file icons to draw pushbuttons.
 *
 * A ZPushButton has three states:
 *
 * 1. normal -- the button is not pressed and not disabled
 * 2. active -- the button is pressed
 * 3. disabled -- the button is diabled
 *
 * Each state is drawn by two operations.  The first operation draws the
 * background of the button, and the second draws an overlay on top of
 * that background.
 *
 * If ZPushButton finds a pixmap for the button background in the skin,
 * it will load it. If not, ZPushButton will draw the background in the style
 * of a Context-Sensitive Toolbar (CST) button.
 *
 * If ZPushButton finds an overlay pixmap in the skin, it will 
 * load it.  If not, and the user has specified overlay text, ZPushButton
 * will use the text.  If the user has not specified any text, ZPushButton
 * will only draw the background.
 *
 * If ZPushButton can not find a disabled pixmap in the skin, it will 
 * 'dim' the normal pixmap.
 *
 * This means a button can be specified by zero to six pixmaps, as below:
 *
 *   CamV_PhotoAlbum_O.g  -- overlay to display when button not pressed
 *   CamV_PhotoAlbum_OA.g -- overlay to display when button pressed
 *   CamV_PhotoAlbum_OD.g -- overlay to display when button disabled
 *   CamV_PhotoAlbum.g-- background when button enabled and not pressed
 *   CamV_PhotoAlbum_A.g  -- background when button enabled and pressed
 *   CamV_PhotoAlbum_D.g  -- background when button disabled.
 *
 * (Note: .jpg, .png, .gif, files are all stored as .g)
 *
 * Here are some other options:
 *
 * - no pixmap, user specifies text: button background is drawn with code 
 *   and text is overlaid.
 *
 * - CamV_PhotoAlbum.g, CamV_PhotoAlbum_A.g, no text: button is drawn
 *   with first pixmap, or second pixmap when pressed.  Nothing is overlaid.
 */

class ZPushButton : public QToolButton //fox Size: $130, QToolButton = $118, 接口函数未处理
{
    Q_OBJECT

public:
 
    /**
     * used in constructor to determine what the left and right side of the button
     * look like.  
     *
     * If there is another ZPushButton directly to the left, then
     * this button should have the JoinLeft flag set and the button to the left
     * should have the JoinRight flag set.  This will give the buttons a nice
     * appearance at the line where they join.
     *
     */

    enum Flags
    {
        NoFlags = 0,                    // default
        CSTStyle = 0,                   // default button style is CST
        JoinLeft = 1,                   // don't round the left edge
        JoinRight = 2,                  // don't round the right edge
        DialogSyle = 4
    };

    /**
     *
     * create a pushbutton
     *
     * @param parent is a pointer to the parent widget
     * @param flags are some combination of the flags above (default
     * is a CSTStyle button with no joins)
     * @param width is the width of the button
     * @param height is the height of the button
     *
     */

    ZPushButton(QWidget *parent,
                int flags = 0,             // bitmask of Flags
                int width = -1,
                int height = -1);
    
    /**
     *
     * create a pushbutton
     *
     * @param resourceID is the ID of the pixmap resource(s) inside
     * the resource file that are used to draw this button.
     * @param parent is a pointer to the parent widget
     * @param flags are some combination of the flags above (default
     * is a CSTStyle button with no joins)
     * @param width is the width of the button
     * @param height is the height of the button
     *
     */

    ZPushButton(const QString& resourceID, // id used to find pixmaps
                QWidget *parent,
                int flags = 0,             // bitmask of Flags
                int width = -1,
                int height = -1);
    
    /**
     *
     * create a pushbutton
     *
     * @param resourceID is the ID of the pixmap resource(s) inside
     * the resource file that are used to draw this button.
     * @param overlayText is a text string overlaid on top of the button
     * @param parent is a pointer to the parent widget
     * @param flags are some combination of the flags above (default
     * is a CSTStyle button with no joins)
     * @param width is the width of the button
     * @param height is the height of the button
     *
     */
    ZPushButton(const QString& resourceID,   
                const QString& overlayText,  
                QWidget *parent,
                int flags = 0,               
                int width = -1,
                int height = -1);

    /**
     * reimplemented
     */ 
    virtual QSize sizeHint() const;

    /**
     * reimplemented
     */
    virtual void setMinimumSize(int minw, int minh);

    /**
     * reimplemented
     */
    virtual void setGeometry(int x, int y, int w, int h);

    /**
     * reimplemented
     */
    virtual void setGeometry(const QRect&);

    /**
     * reimplemented
     */
    virtual void resize(int w, int h);

    /**
     * reimplemented
     */
    virtual void resize(const QSize&);
   
    /**
     * set the overlay text
     *
     * @param text text to be overlaid on the button
     */
    virtual void setText(const QString& text);

    /**
     * get the overlay text
     */
    virtual QString text() const;

    /** 
     * Set an a popup menu that shows when this button is pressed
     *
     * @param popup pointer to QPopupMenu to show when this button is pressed
     */
    void setPopup(QPopupMenu* popup);

    /**
     * set the resourceID for this button
     */
    void setResourceID(const QString& resourceID);
   
    /**
     * returns the resourceID for this button
     */
    QString resourceID() const;             

    /**
     * set the pushbutton flags
     */
    void setFlags(int flags); 

    /**
     * returns the flags for this button
     */
    int flags() const;                      
  
public slots:

    /**
     * reimplemented
     */
    virtual void polish(); 

protected slots:

    /**
     * reimplemented
     */
    virtual void popupPressed();

protected:

    virtual void drawButton(QPainter*);     
    
    /**
     * initializers called by the various constructors
     */
    void init(const QString& resourceID, 
              const QString& overlayText, 
              int flags,
              int width, 
              int height);
    

    static const int minWidth;      ///< minimum width
    static const int minHeight;     ///< minimum height
    static const int defaultWidth;  ///< default width
    static const int defaultHeight; ///< default height
    static const unsigned char multSixTenths[]; ///< table to multiply everything by 6/10
   
    //fox QToolButton.Size = 118, but zhe last field is a type of bit, so bool m_guessSize locate at $115
    bool m_guessSize;               ///< true if user hasn't specified size   //fox f: $115
    mutable bool m_isSizeCached;    ///< if size has already been calculated  //fox f: $116
    mutable int m_cachedWidth;      ///< cached width                         //fox f: $118
    mutable int m_cachedHeight;     ///< cached height                        //fox f: $11C

protected:
    /**
     * used for getting/drawing the actual button
     */
    QPixmap normal() const;
    QPixmap normalPixmap() const;
    QPixmap normalOverlay() const;
    QPixmap normalOverlayPixmap() const;
    QPixmap active() const;
    QPixmap activePixmap() const;      
    QPixmap activeOverlay() const;
    QPixmap activeOverlayPixmap() const;
    QPixmap disabled() const;
    QPixmap disabledPixmap() const;
    QPixmap disabledOverlay() const;
    QPixmap disabledOverlayPixmap() const;
   
    /**
     * fast fixed-amount alpha blending functions for left and right edges
     */
    void dim1(ZDirectPixmap& img, int x, int y, int h) const;
    void dim2(ZDirectPixmap& img, int x, int y, int h) const;
    void dim3(ZDirectPixmap& img, int x, int y, int h) const;
    void dim4(ZDirectPixmap& img, int x, int y, int h) const;
    void dim5(ZDirectPixmap& img, int x, int y, int h) const;

    /**
     * line functions for drawing button edges
     */
    void drawHLine(ZDirectPixmap& img, int x, int y, int w, const QColor& wc) const;
    void drawVLine(ZDirectPixmap& img, int x, int y, int h, const QColor& wc) const;

    /**
     * gradient fill for tactium buttons
     */
    void drawGrad(ZDirectPixmap& img, int x, int y, int w, int h, 
                  const QColor& start, const QColor& end) const;

    /**
     * functions to actually draw buttons
     */
    QPixmap drawNormal() const;     ///< draw it when no PM is available
    QPixmap drawActive() const;     ///< draw it when no PM is available
    QPixmap fade(const QPixmap&) const; ///< fade input pixmap

    /**
     * state variables
     */
    QString m_resourceID;           ///< same as normalResourceID                 //fox f: $120
    QString m_overlayText;          ///< text overlaid on top of the normal pixmap//fox f: $124
    int m_flags;                    ///< flags used when rendering the button     //fox f: $128
    bool m_pressed;                 ///< current button state                     //fox f: $12c
};

#endif  // Z_PUSHBUTTON_H
