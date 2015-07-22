//-------------------------------------------------------------------------------------------------
//
//  Header Name: ZScrollView.h
//
//  General Description: EZX ScrollView class
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_SCROLLVIEW_H
#define Z_SCROLLVIEW_H
 
#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qscrollview.h>
#include <qsize.h>
#include <qrect.h>

class ZScrollViewData;

/**
 * ZScrollView is similar to QScrollView, but has a few additional behaviors:
 *
 * 1. Adjusts the children's geometry automatically when the size of 
 * ZMultiLineEdit child is changed because of text set.
 *
 * 2. Changes the geometry of the text-entry area when the keyboard is shown/
 * hidden.
 *
 * @code
 * ZScrollView* sv = new ZScrollView( this, "sv" );
 * sv->enableClipper(true);
 * UTIL_MulitLineEdit *ml1, *ml2;
 *
 * //add a 6 lines ZMultiLineEdit
 * ml1 = new ZMultiLineEdit(sv->viewport(),true,6);
 * sv->addChild(ml1,0,0);
 *
 * //set indent
 * ml1->setIndent(20);
 * ml2 = new ZMultiLineEdit(sv->viewport());
 * 
 * //need to change the widget width when ZScrollView's scrollbar is shown/hidden
 * sv->addChild(ml2,0,30,true);
 * @endcode

 * @see ZMultiLineEdit
 *
 * @note for the class, has change the scrollview's resize policy to Manual
 * setResizePolicy(Manual), and turn off the horizon scroll bar
 * setHScrollBarMode(QScrollView::AlwaysOff).
 *
 *scrollArea->setHScrollBarMode(QScrollView::Auto);
 *scrollArea->setResizePolicy(QScrollView::AutoOneFit);
 */

class ZScrollView : public QScrollView  
{
    Q_OBJECT

public:

    /**
     * Constructor of ZScrollView
     */
    ZScrollView( QWidget* parent = 0, const char* name = 0, WFlags f = 0) ;

    /**
     * Destructor of ZScrollView. 
     */
    virtual ~ZScrollView();

    /**
     * Reimplement
     */
    virtual void addChild( QWidget* child, int x = 0, int y = 0 );

    /**
     * ZScrollView's addChild.
     * 
     * @param autoAdjustWidth if true when vertical scrollbar appears/disappear,
     * the widget's width will be adjusted, it is width() -(+) verticalScrollBar->width()
     */
    virtual void addChild( QWidget* child, int x, int y, bool autoAdjustWidth );

    /**
     * ZScrollView's moveChild.
     * 
     * @param autoAdjustWidth if true when vertical scrollbar appears/disappear,
     * the widget's width will be adjusted, it is width() -(+) verticalScrollBar->width()
     */
    virtual void moveChild( QWidget* child, int x, int y, bool autoAdjustWidth = false );

    /**
     * Update Content Size correctly by the all children's frame geometry
     */
    void updateContentSize();

    /**
     * Set a flag for flush events in doLayout(), it is to call sendPostedEvents()
     * which reduces screen flash. 
     *
     * By default, the flag is on.
     *
     * If the application needs to assure the sequence of the events during the period,
     * please turn off the flag.
     *
     * @param flush if true need to flush the events during doLayout
     *
     * @see doLayout()
     */
    void setFlushEvents( bool flush = true );

    /**
     * Get the flush event flag
     *
     * @see setFlushEvents()
     */
    bool getFlushEvents() const;

    /**
     * Set the flag to do layout automatically, usually doing layout is caused
     * by the ZMultiLineEdit's text change.
     *
     * @param doLayout if true, do layout automatically, or need to do layout by yourself
     * The default is to do layout automatically.
     *
     * @see doLayout()
     */
    void setAutoLayout( bool doLayout = true ); 

    /**
     * Get the DoLayout flag
     *
     * @see setDoLayout()
     */
    bool getAutoLayout() const; 

public slots:

     /**
      * Reimplement
      */
     virtual void show();

    /**
     * Reimplement
     */
    virtual void hide();

    /**
     * Layout the children in the ZScrollView.
     *
     * @param widget the widget whose geometry changed.
     * @param size the size(height and width) changed. Now only supports height
     * @param cursorPos the cursor's position. 
     * @param enlarge if true the size of widget is enlarged
     */
    virtual void doLayout( QWidget* widget,QSize size,QPoint cursorPos,int enlarge );

    /**
     * ZScrollView's enableClipper 
     */
    void enableClipper( bool clipper );

signals:

    /**
     * Emitted when the vertical scrollbar of the ZScrollView is shown/hidden
     *
     * @param show if true, the vertical scrollbar is shown
     */
    void vScrollBarStateChanged( int show );

protected:

    /**
     * Reimplement
     */
    virtual bool eventFilter( QObject *obj, QEvent* event );

    /**
     * Reimplement
     */
    virtual bool event ( QEvent* event );

    /**
     * Reimplement
     */
    virtual void keyPressEvent( QKeyEvent* event );


private:

    void removeSVChild( QWidget* child );

private slots:

    void updateFieldsWidth( int cause );
    void makeFocusWidgetVisible( bool show );
    
private:

    bool flushEvents;
    bool autoLayout;
    ZScrollViewData* d;
};

#endif 
