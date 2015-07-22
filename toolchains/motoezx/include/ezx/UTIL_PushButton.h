#ifndef UTIL_PUSHBUTTON_H
#define UTIL_PUSHBUTTON_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//---------------------------------------------------------------------------
//                                                                    
//   Header Name: UTIL_PushButton.h
//
//   General Description: A icon-based push button
//
//---------------------------------------------------------------------------
//
//                   Motorola Confidential Proprietary
//        Template ID and version: IL93-TMP-01-0107  Version 1.10
//         (c) Copyright Motorola 2002-2003, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
//---------------------------------------------------------------------------
// Author (core ID)                Date          Number     Changes
//
// Peter McDermott (w20027)      04/04/2003   libbb92263    created
// Kenny Yu (a18604)             05/22/2003                 +resize/setFlags
//
//---------------------------------------------------------------------------
//                              INCLUDE FILES
//---------------------------------------------------------------------------

#include <qtoolbutton.h>

class UTIL_DirectPixmap;

class UTIL_PushButton : public QToolButton
{
    Q_OBJECT

public:

    //
    // For all cases:
    //
    // resource IDs are a string such as "CamV_PhotoAlbum"
    //
    // This ID is expanded into three resource tags:
    //
    //   CamV_PhotoAlbum.g      -- normal pixmap
    //   CamV_PhotoAlbum_Acti.g -- active pixmap
    //   CamV_PhotoAlbum_Ovl.g  -- overlay pixmap
    //
    // (Note: .jpg, .png, .gif, files are all stored as .g)
    //
    // Note: In some cases, multiple icon names might map to the
    //       same resource tag.  For example, more than one 
    //       resource might use the same normal and active pixmap.
    //
    // 1. If the overlay exists, it is drawn centered, on top of the
    //    normal or active pixmap.  
    //
    // 2. If the overlay does not exist, and the user specifies text,
    //    the text is drawn centered, on top of the normal or active
    //    pixmap.  If both an overlay and text exist, the overly is 
    //    used.
    //
    // 3. The normal pixmap is used when the button is not pressed.
    //
    // 4. If the normal pixmap does not exist, the pixmap is created
    //    with code.
    //
    // 5. The active pixmap is used when the button is pressed.
    //    
    // 6. If the active pixmap does not exist, the pixmap is created
    //    with code.
    //
    // 7. UTIL_PushButton will do it's best to figure out the width and
    //    height, but it the width and height are specified, it will
    //    always obey them.
    //
    // 8. Diabled buttons are drawn the same as normal buttons, but
    //    with their brightness set to 60% of when they are enabled.
    //
    // Finally, in all cases, if a normal or active pixmap does not
    // exist, it is generated with code.
    //
  
    enum Flags
    {
        NoFlags = 0,                    // default
        CSTStyle = 0,                   // default button style is CST
        JoinLeft = 1,                   // don't round the left edge
        JoinRight = 2,                  // don't round the right edge
    };

    //
    // create a button, specifying a resource ID
    //

    UTIL_PushButton(
           const QString& resourceID, // id used to find pixmaps
           QWidget *parent,
           int flags = 0,             // bitmask of Flags
           int width = -1,
           int height = -1);
    
    //
    // create a button, specifying a resource ID and text
    //
    //

    UTIL_PushButton(
           const QString& resourceID,   // id used to find pixmaps
           const QString& overlayText,  // overlaid on normal and active
           QWidget *parent,
           int flags = 0,               // bitmask of flags above
           int width = -1,
           int height = -1);

    //
    // create a button, specifying all the pixmaps. 
    // Pixmaps can be null.
    //
    
    UTIL_PushButton(
           const QPixmap& normal,          // displayed when not pressed
           const QPixmap& normalOverlay,   // overlaid on top of normal
           const QPixmap& active,          // displayed when pressed
           const QPixmap& activeOverlay,   // overlaid on top of active
           const QPixmap& disabled,        // displayed when disabled
           const QPixmap& disabledOverlay, // displayed on top of disabled
           QWidget *parent,
           int flags = 0,               // bitmask of flags above
           int width = -1,
           int height = -1);

    //
    // create a button, specify normal and active pixmaps, also
    // specify the overlay text
    //

    UTIL_PushButton(
           const QPixmap& normal,       // displayed when not pressed   
           const QPixmap& active,       // displayed when pressed
           const QString& overlayText,  // overlaid n normal and active
           QWidget *parent,
           int flags = 0,               // bitmask of flags above
           int width = -1,
           int height = -1);

    //
    // create a button, specify normal and active pixmaps, also
    // specify the overlay text
    //

    UTIL_PushButton(
           const QPixmap& normal,       // displayed when not pressed   
           const QPixmap& active,       // displayed when pressed
           const QString& overlayText,  // overlaid n normal and active
           const QPixmap& disabled,     // displayed when disabled
           QWidget *parent,
           int flags = 0,               // bitmask of flags above
           int width = -1,
           int height = -1);

    //
    //create a button, no text/pixmap specified
    //

    UTIL_PushButton(QWidget *parent,
            int flag = 0,
            int width = -1,
            int height = -1);

    //
    // Supporting methods
    //

    QSize sizeHint() const; 
    virtual void setMinimumSize(int minw, int minh);
    virtual void setGeometry(int x, int y, int w, int h);
    virtual void setGeometry(const QRect&);
    virtual void resize(int w, int h);
    void resize(const QSize&);
    
    void setText(const QString&);
    QString text() const;

    //for performance, no background flickering
    void setPopup( QPopupMenu* popup );
    
    void setResourceID(const QString&);     // change the resource ID 
    QString resourceID() const;             // get the resource ID
    
    void setFlag(int);                      // set flags -- deprecated
    void setFlags(int);                     // set flags
    int flags() const;                      // get flags
   
    void setNormal(const QPixmap&);         // set the normal pixmap
    QPixmap normal() const;                 // return pixmap (maybe drawn)

    void setNormalOverlay(const QPixmap&);  // set the overlay normal pixmap
    QPixmap normalOverlay() const;          // return pixmap (maybe drawn)

    void setActive(const QPixmap&);         // set the active pixmap 
    QPixmap active() const;                 // return pixmap (maybe drawn)

    void setActiveOverlay(const QPixmap&);  // set the overlay active pixmap
    QPixmap activeOverlay() const;          // return pixmap (maybe drawn)

    void setDisabled(const QPixmap&);       // set disabled pixmap
    QPixmap disabled() const;               // return pixmap (maybe drawn)

    void setDisabledOverlay(const QPixmap&);// set the overlay active pixmap
    QPixmap disabledOverlay() const;        // return pixmap (maybe drawn)
   
    void reload();                          // clears any cached information
     
public slots:

    virtual void polish();                  // re-implemented

protected slots:

    void popupPressed();

protected:

    virtual void drawButton(QPainter*);     // re-implemented
    
private:

    // initializers called by the various constructors
    
    void init(const QString& resourceID, 
              const QString& overlayText, 
              int flags,
              int width, 
              int height);

    void init(const QPixmap& normal, 
              const QPixmap& normalOverlay,
              const QPixmap& active, 
              const QPixmap& activeOverlay, 
              const QString& overlayText, 
              const QPixmap& disabled,
              const QPixmap& disabledOverlay,
              int flags,
              int width, 
              int height);

    // used by sizeHint()
    
    static const int minWidth;      // minimum width
    static const int minHeight;     // minimum height
    static const int defaultWidth;  // default width
    static const int defaultHeight; // default height
    static const unsigned char multSixTenths[]; // table to multiply everything by 6/10
   
    bool m_guessSize;               // true if user hasn't specified size 
    mutable bool m_isSizeCached;    // if size has already been calculated
    mutable int m_cachedWidth;      // cached width   
    mutable int m_cachedHeight;     // cached height

    // used for getting/drawing the actual button

    QPixmap normalPixmap() const;
    QPixmap normalOverlayPixmap() const;
    QPixmap activePixmap() const;      
    QPixmap activeOverlayPixmap() const;
    QPixmap disabledPixmap() const;
    QPixmap disabledOverlayPixmap() const;
   
    // fast fixed-amount alpha blending functions for left and right edges
    void dim1(UTIL_DirectPixmap& img, int x, int y, int h) const;
    void dim2(UTIL_DirectPixmap& img, int x, int y, int h) const;
    void dim3(UTIL_DirectPixmap& img, int x, int y, int h) const;
    void dim4(UTIL_DirectPixmap& img, int x, int y, int h) const;
    void dim5(UTIL_DirectPixmap& img, int x, int y, int h) const;

    // line functions for drawing button edges
    void drawHLine(UTIL_DirectPixmap& img, int x, int y, int w, const QColor& wc) const;
    void drawVLine(UTIL_DirectPixmap& img, int x, int y, int h, const QColor& wc) const;

    // gradient fill for tactium buttons
    void drawGrad(UTIL_DirectPixmap& img, int x, int y, int w, int h, 
                  const QColor& start, const QColor& end) const;

    // functions to actually draw buttons
    QPixmap drawNormal() const;     // draw it when no PM is available
    QPixmap drawActive() const;     // draw it when no PM is available
    QPixmap fade(const QPixmap&) const; // fade input pixmap

    // state variables
    QString m_resourceID;           // same as normalResourceID

    QPixmap m_normal;               // user-specified normal PM
    QPixmap m_active;               // user-specified active PM
    QPixmap m_normalOverlay;        // overlaid on normal
    QPixmap m_activeOverlay;        // overlaid on active
    QString m_overlayText;          // user-specified overlay text
    QPixmap m_disabled;             // disabled pixmap
    QPixmap m_disabledOverlay;

    int m_flags;                    // flags used when rendering the button
    bool m_pressed;                 // current button state
};

#endif  // #ifndex UTIL_PUSHBUTTON_H 
