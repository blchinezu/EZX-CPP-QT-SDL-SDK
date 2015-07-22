//-------------------------------------------------------------------------------------------------
//
// Header Name: ZMainWidget.h
//
// General Description: EZX Mainwidget.
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------
// Modified by FoxE6.
// Modified by eakrin 2008 Mar 14 : 
//   - correct all Input Method Function.
//   - Add singals and slots.

#ifndef Z_MAINWIDGET_H
#define Z_MAINWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif


#include <qscrollview.h>
#include <qlayout.h>
#include <qpopupmenu.h>
#include <qstringlist.h>
#include <qlabel.h>

#include "ZGlobal.h"

class QUuid;
class ZPushButton;
class ZMainWidgetData;

/**
 * The ZMainWidget class implements the EZX style's base screen which consists
 * of two parts, a content Area and a CST Area.
 *
 * |--------------|
 * |              |
 * | Content Area |
 * |              |
 * |------------- |
 * | CST Area     |
 * |--------------|
 
 * You can use getContentWidget()/getCSTWidget() to get a default content/cst widget
 * which is ZScrollView/QFrame.
 *
 * You can also can use setContentWidget()/setCSTWidget() to set your own Content/CST 
 * widget.
 *
 * The class has two modes:
 *
 * 1. Edit mode (note: set constructor's param editorMode true): this class 
 * encapsulates some input methods relating functions.
 *
 * 2. Non-edit mode: in this mode, the input methods functions are not available.
 * The class is a simple container class. 
 *
 * For an application's to add its own input widget (like MMS object keyboard),
 * override showToolBar(), setToolBar(), hideToolBar(), and return true in these 
 * functions to indicate it is the application's special keyboard.
 *
 * @code
 * //set to edit mode
 * ZMainWidget* w = new ZMainWidget(true);
 *
 * ZScrollView* sv =  (ZScrollView*)w->getContentWidget();
 * ZMultiLineEdit* ml = new ZMultiLineEdit( sv->viewport(), true );
 * sv->addChild( ml, 0, 0 );
 * w->showMaximized();
 * @endcode
 */

class ZMainWidget: public QWidget //fox size: $D8 TODO : 导出函数还没有处理
{
    Q_OBJECT

public:

    /**
     * Constructor of ZMainWidget.
     * 
     * @param editorMode if true, it is edit mode, some input methods' functions 
     * are available; if false, it uses non-edit mode, making this just a container
     * class
     */
    ZMainWidget( bool editorMode, QWidget* parent,const char* name = 0,WFlags f = 0 ); //not sure
    ZMainWidget( const QString&, bool editorMode, QWidget* parent,const char* name = 0,WFlags f = 0 ); //fox add

    /**
     * Constructor of non-edit-mode ZMainWidget.
     * Just for convenience
     */
    ZMainWidget( QWidget* parent,const char* name = 0,WFlags f = 0 ); //segfa

    /**
     * Destructor of ZApplication. 
     */
    virtual ~ZMainWidget();

public:
	void paletteChange(QPalette  const&); //nukin add
	QVBoxLayout* getVBoxLayout(); //nukin add
	
	QWidget* getTitleBarWidget(void); //add by eakrin //ZMainWidget( const QString&, bool editorMode, QWidget* parent,const char* name = 0,WFlags f = 0 );

    /**
     * Get the edit mode flag
     */
    bool getEditMode(); 

    /**
     * Get the content widget, if you do not set content widget before
     * calling this, the default content widget, a ZScrollView, will be 
     * created and returned.
     */
    //QWidget* getContentWidget();
    QWidget* getContentWidget(bool unknown); //ruthfox add param
    
	bool getFullScreenMode();  //nukin add    
    /**
     * Set the content widget.
     *
     *@param w the content widget,
     *if NULL, a default content widget, a ZScrollView, is created.
     */
    virtual bool setContentWidget( QWidget* w = NULL );  //fox v: m0

    /**
     * Get the CST widget, if you do not set CST widget before calling
     * this, the default CST widget, a QFrame, will be created.
     */
    virtual QWidget* getCSTWidget(bool);  //ruthfox Add the bool param, Virtual  //fox v: m4

    /**
     * Set the CST widget.
     *
     *@param w the CST widget,
     *if is NULL, a default CST widget, a QFrame, is created.
     *
     * @note for A760 and A768, you can not set CST in the edit mode.
     */
    virtual bool setCSTWidget( QWidget* w = NULL );           //fox v: m8
    virtual int setTitleBarWidget(QWidget*); //fox v: m$C add
    virtual int setFullScreenMode(bool, bool);  //fox v: m$10 add   (true,true) (true,false) :hide title and cst

    /**
     * Get the popup menu which lists the input methods' names.
     *
     * @note after A768, it will be obsolete, because the design is changed
     * so that there is no keyboad button. 
     *
     * New applications should not use this function.
     */
    QPopupMenu* getKbPopupMenu(); //fox: 已经不导出了.

    /**
     * Get the popup menu which lists the input methods' names
     *
     * @note after A768, it will be obsolete, because the design is changed
     * so that there is no keyboad button. 
     *
     * New applications should not use this function.
     */
    ZPushButton* getKbBtn();  //fox : 已经不导出了

    enum
    {
        INPUTWIDGET_HIDE = 0, ///< \a \c input widget is hidden 
        INPUTWIDGET_SHOW,     ///< \a \c input widget is shown 
    };

    /**
     * Get the input widget status
     *
     * @see the enum above
     */
    int getKbState();

    /**
     * Set the current input method.
     *
     * This method will call setToolbar(). So, if want implement your
     * own input widget, you only need to override setToolbar() and return 
     * true
     *
     * @param method input method name
     *
     * @code
     * //set to edit mode
     * ZMainWidget* w = new ZMainWidget(true);
     * if ( w )
     * {
     *     //set english key board
     *     w->setInputMethod(IMID_ENGLISH_KB);
     * }
     * @endcode
     *
     * @see ZGlobal for system default input methods name list.
     *
     * @see setToolbar()
     */
    //void setInputMethod( const QUuid& method = IMID_UNDEFINED );  //removed by nukin
	void setInputMethod( const QUuid& method = IMID_UNDEFINED, int Unknown = 0);// modified by eakrin.
	void setInputMethod( QWidget* widget, const QUuid& method = IMID_UNDEFINED, int Unknown = 0, QString text = "");//Add by eakrin.

    /**
     * Show the main widget and input widget at the same time.
     *
     * @param method input method name
     *
     * @code
     * //set to edit mode
     * ZMainWidget* w = new ZMainWidget(true);
     * if ( w )
     * {
     *     //set english key board and show the main widget 
     *     w->showWithInputMethod(IMID_ENGLISH_KB);
     * }
     * @endcode
     *
     * @see ZGlobal for system default input methods name list.
     */
    void showWithInputMethod( const QUuid & method = IMID_UNDEFINED, int Unknown = 0 ); //ruthfox add the Unknown param

    /**
     * Specify some input methods to the ZMainWidget, the user can see these candidates.
     * if do not set widget favour list, the default is the all input methods that
     * the application knows.
     * 
     * @param imList the ZMainWidget's favour input mathods list
     *
     * @see ZGlobal for system default input methods name list.
     *
     * @see setFavoriteInputMethods
     */
    void setFavoriteInputMethods( QWidget* widget, const QValueList<QUuid> & imList );//add by eakrin.
    void setFavoriteInputMethods( const QValueList<QUuid> & imList );

	const QValueList<QUuid> &getFavoriteInputMethods(void);  //nukin add
    /**
     * Bind the default input method and input methods names list that can 
     * be seen in the menu when the text entry focuses to the text entry.
     *
     * If you do not set the widget's favourite list, the default list is 
     * ZMainWidget's list.
     *
     * @param widget text entry
     * @param defaultIM the default input method
     * @param favourIMList the widget's favour input mathods name list
     *
     * @code
     * ZMultiLineEdit* ml = new UTIL_MultiLineEdit(sv->viewport(),true,2);
     * ml->setFixedWidth(230);
     * sv->addChild(ml,3,30,true);
     *
     * //set the input methods names list and set the default input method
     * QValueList<QUuid> flist1;
     * flist1.append( IMID_NUMBER_KB );
     * flist1.append( IMID_PINYIN_KB );
     * setInputMethods(ml,IMID_NUMBER_KB, flist1);
     * @endcode
     *
     * @see ZGlobal for system default input methods name list.
     *
     * @see setFavoriteInputMethods
     */
    //void setInputMethods( QWidget* widget, const QUuid& defaultIM, 
     //                     const QValueList<QUuid> & favourIMList );         //ld error    nukin20091122
    void setInputMethods( QWidget* widget, const QUuid& defaultIM, 
                          const QValueList<QUuid> & favourIMList, int Unknown = 0, QString text = "");//modified by eakrin.
    /**
     * Almost the same as the above function, but there are all the input 
     * methods are available, just for convenience
     *
     * @param widget text entry
     * @param defaultIM the widget's default input mathod
     *
     * @see ZGlobal for system default input methods name list.
     */
    //void setInputMethods( QWidget* widget, const QUuid& defaultIM );  //nukin removed
    void setInputMethods( QWidget* widget, const QUuid& defaultIM, int Unknown, QString text = "");//modified by eakrin.

public:

    /**
     * Reimplement
     */
    virtual void show();  //fox v: override

    /**
     * Reimplement
     */
    virtual void hide(); //fox v: override


    /**
     * Raise the ZMainWidget
     */
    void raise();

    /**
     * Raise the ZMainWidget
     */
    void lower();

public slots:

	virtual void slotKbStateChanged(bool,QUuid  const&,int); //nukin add
	virtual void slotKbWidgetSizeChanged(QRect  const&,int,bool,bool);  //nukin add
    /**
     * Hide the input widget
     */
    virtual void hideInputWidget();  //fox v: m$14

    /**
     * The slot for the popup menu item is selected,
     * You can override it for the application own input widget
     *
     * @param id the id of the menu item
     */
    virtual void slotPopupMenu( int id ); //fox v: m$18

    /**
     * Invoke the input widget
     *
     * @see setInputMethod()
     *
     * @internal, please use setInputMethod() 
     */
    virtual void invokeInputWidget();  //fox v: m$1C

protected slots:

    /**
     * Update the input widget state
     *
     * @internal
     */
    //virtual void updateInputWidgetState( int mwId,bool canClick ); //ruthfox remove

signals:

    /**
     * The signal is emitted when input widget's status is changed
     *
     * @param show if true, input widget is shown, or it is hidden
     */
    void kbStateChanged( bool show );
    
    void kbStateChanged(bool,QUuid  const&,int); //nukin add
	void fullScreenModeChanged(bool);  //nukin add
	
	void mainWidgetSizeChanged(int,QRect  const&); //nukin add
protected:

    /**
     * Reimplement
     */
    //virtual bool event( QEvent* e); //ruthfox removed

    /**
     * Reimplement
     */
    //virtual bool qwsEvent( QWSEvent* e); //ruthfox removed

    /**
     * Reimplement
     */
    //virtual void keyPressEvent( QKeyEvent* e ); //ruthfox removed

    /**
     * Show a custom input widget, instead of the standard ones.
     *
     * @retval if true, the ZMainWidget has defined its own input widget
     *
     * @note need to care for your own content widget's geometry
     */
    virtual bool showToolBar() { return FALSE; }  //fox v: m$20

    /**
     * Set a custom input widget, instead of the standard ones.
     * 
     * @retval if true, the ZMainWidget has set its own input widget
     *
     * @note need to care for your own content widget's geometry
     */
    virtual bool setToolBar( const QUuid& ) { return FALSE; }  //fox v: m$24

    /**
     * Hide a custom input widget, instead of the standard ones.
     * 
     * @retval if true, the ZMainWidget has hide its ownreadConfig input widget
     *
     * @note need to care for your own content widget's geometry
     */
    virtual bool hideToolBar() { return FALSE; }  //fox v: m$28

    /**
     * Get ZMainWidget's current input method 
     * 
     * @param readConfig if true when there is no default input method, the function will
     * read the system config to get the application current input method name
     */
    QUuid getCurrentInputMethodName( bool readConfig = false );  

    /**
     * Set up the input method menu
     *
     * @internal
     */
    virtual void setupInputMethodsPopupMenu(); //fox v: m$2C
    virtual int getLRSBaseIndex(); //fox v: m$30 add

    /**
     * Check the menu item
     * 
     * @internal
     */
    void checkMenuItem( QPopupMenu* popup,QString text,bool select );

    /**
     * Get the loaded input methods list
     * 
     * @internal
     */
    QIMMap&  getIMList();

private:

    void init();
    void updateAppDefaultInputMethod();
    void setPreDefinedKBFuncs();

private slots:

    void popupKBMenu();
    void removeWidgetInputMethod();
    void objectDestroyed();

    void slotAppMessage( const QCString &msg, const QByteArray &data );

private:

    QWidget* sv ;               //fox f: C4?
    QWidget* cst;               //fox f: C8
    QVBoxLayout* vBox;          //fox f: CC, size = $58
    bool editMode;              //fox f: D0
    int* TempD4;
    //TempD4: ^array[0..2] of integer; // fox f: D4, TempD4[2]: ^array[0..2] of int; TempD4[2][1]: ^array[0..5] of Int, [1..5] = 0
    //TempD4[1]: bool = FullScreenMode, TempD4[0] = TitleBarWidget  
    //int kbState;                //fox f: D4?  //已经没有了
    //ZPushButton* kbBtn;         //fox f: D8?  //已经没有了
    //QPopupMenu* kbPopupMenu;    //fox f: DC?  //已经没有了

    //ZMainWidgetData* d;         //fox f: E0?  //已经没有了
};

#endif


 
