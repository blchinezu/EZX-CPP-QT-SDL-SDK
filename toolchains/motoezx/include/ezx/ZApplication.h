//-------------------------------------------------------------------------------------------------
//
//  Header Name: ZApplication.h
//
//  General Description: Main application class (similar to QApplication)
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_APPLICATION_H
#define Z_APPLICATION_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif


#include "ZGlobal.h"

#include <qapplication.h>
#include <qwindowsystem_qws.h>
#include <qcopchannel_qws.h>
#include <qwsevent_qws.h>

class ZApplicationData;
class ZIMServer;
class QUuid;

#ifndef QT_NO_QWS_MMI_TEST
class QTestCaptureHandler;
#endif

/**
 * The ZApplication class implements various services that are available to 
 * EZX applications.
 *
 * Qt applications that use ZApplication instead of QApplication, should 
 * became standard EZX applications. They inherit EZX Styles, and some 
 * EZX-specific features
 *
 * @code
 * ZApplication a(argc,argv);
 * ZMainWidget* w = new ZMainWidget(true,0);
 * w->show();
 * a.exec();
 * delete w;
 * @endcode
 *
 * @see ZMainWidget
 */
class ZApplication : public QApplication  //fox size: <=$68 TODO : 导出函数还没有处理
{
    Q_OBJECT

public:

    /**
     * Constructor of ZApplication. argc, argv and Type are same as QApplication's.
     * for applications, Type should be GuiClient, only the EZX Server can pass GuiServer.
     */
    ZApplication( int& argc, char **argv, Type = GuiClient );

    /**
     * Destructor of ZApplication. 
     */
    virtual ~ZApplication();

    /**
     * Reimplement
     * Set the main widget of the application
     *
     * @see the setMainWidget() of the QApplication
     *
     * @param mainWidget will be the application's main widget
     */
    //virtual void setMainWidget( QWidget* mainWidget ); //ruthfox in E6 this function not override!

    /**
     * Set the main widget of the application and show it
     *
     * @param mainWidget will be the application's main widget
     */
    void showMainWidget( QWidget* mainWidget );

    /**
     * Reimplement
     * enter the application main event loop
     *
     * @see the exec() of the QApplication
     */
    int exec();

    /**
     * Set the flag to enable/disable invoking the input widget automatically
     * when text entry is clicked.
     *
     * @param invoke if true when text entry is clicked, the input widget will 
     * be invoked automatically; if false the input widget will not be invoked, 
     * the function affects all text entries in the application.
     *
     * The default is to invoke input widget automatically.
     */
    void setAutoInvokeKb( bool invoke = true );
	void setAutoInvokeKb(QWidget *,bool invoke = true);
    /**
     * Get the flag to enable/disable invoking the input widget automatically 
     * when text entry is clicked.
     *
     * @retval if true, input widget will be invoke automatically
     * or return false.
     */
    bool getAutoInvokeKb();

    /**
     * Set the flag to enable/disable hiding the input widget automatically by 
     * clicking a non-text-entry widget when the input widget is visible.
     *
     * @param hide if true when a non-text-entry widget is clicked the input 
     * widget will be hidden automatically; if false the input widget will not 
     * be hidden.
     *
     * The default is to hide input widget automatically.
     */
    void setAutoHideKb( bool hide = false );

    /**
     * Get the flag that indicates whether or not the input widget should 
     * be automatically hidden when a non-text-entry widget is clicked.
     *
     * @retval if true, input widget will be hidden automatically
     * or return false.
     */
    bool getAutoHideKb();

    /**
     * Set the application's default input method.
     *
     * @param method the default input method name.
     *
     * @see ZMainWidget for how to bind special input methods
     * to a text entry and to a ZMainWidget.
     * @see ZGlobal for system default input methods name list.
     *
     * @note if application does not set the default input method,
     * the initial input method is system default input method.
     *
     * @note if the lastest input method user used is not been
     * bound to a special text entry, the application default input method
     * will be set to remember it, but the input method bound by a text entry
     * will be ignored.
     *
     * For example:
     * There are three text entries: text entries A,C do not bind to any 
     * input method, another text entry B binds number keyboard, user uses 
     * the Keyboard as follows:
     *
     * A --> English Keyboard 
     * B --> Number keyboard  
     * C --> English Keyboard --> Change to Hand Writing Keyboard
     * A --> Hand Writing Keyboard (application default is changed)
     * B --> Number keyboard (not affected)
     */
    void setDefaultKbMethod( const QUuid& method ); 

    /**
     * Get the application default input method
     *
     * @param readConfig if false, when the application initial input method is
     * IMID_UNDEFINED, the function will not read the system config to get the system
     * defualt value or the function will read the system config.
     */
    const QUuid getDefaultKbMethod( bool readConfig = false ); 

    /**
     * EZX widgets have two mouse respond modes:
     *
     * 1. Application only responds to press (left) mouse events.
     * 2. Application also responds to press-and-hold (right) mouse events.
     *
     * Can use the setMouseMode() to set the widget's responsive mode. 
     */
    enum
    {
        LEFT_ONLY = 0, ///< \a \c Only support LEFT mouse events 
        PRESS_HOLD     ///< \a \c support PRESS_HOLD funstions
    };

    /**
     * Enable/disable the press-and-hold for a widget
     *
     * @param widget the QWidget whose press-and-hold will be enabled/disabled
     * @param mode mouse mode
     *
     * @code
     * QLineEdit* ln = new QLineEdit(parent);
     * //enable Press and Hold
     * if ( ln )
     * {
     *    ZApplication::setMouseMode(ln, ZApplication::PRESS_HOLD);   
     * }
     * @endcode
     *
     * @note Most widgets default mouse mode is LEFT_ONLY, except for some 
     * special widgets such as ZMultiLineEdit etc...
     *
     * @note when PRESS_HOLD is enabled, the mouse events sequence that the widget may
     * receive are:
     *
     * Left mouse press, Right Mouse Press, Right Mouse Release, Left Mouse Release  
     */
    static void setMouseMode( QWidget* widget, int mode );

    /**
     * Get the widget's mouse mode
     *
     * @retval LEFT_ONLY or PRESS_HOLD
     */
    static int getMouseMode( QWidget* widget ); 

    /**
     * Start to show a wait cursor
     *
     * @code
     * //start to show a wait cusor
     * ZApplication* app = (ZApplication*)qApp;
     * app->startShowWaitCursor();
     *
     * //chance to handle event
     * app->processEvents();
     * ...
     * app->stopShowWaitCursor();
     * @endcode
     *
     * @note param startTime and param resId have not been implemented in the A760
     *
     * @note the application needs to call stopShowWaitCursor() to stop the wait cursor,
     * so the application's UI will be blocked.
     */
    void startShowWaitCursor( int startTime = 0,const QString& resId = QString::null );

    /**
     * Stop a wait cursor
     */
    void stopShowWaitCursor();

    /**
     * Load string resource files (.qm files)
     */
    void loadString( const QString& strFileName );

    /**
     * Get the application's name
     */
    const QString& getAppName() { return appName; }

    /**
     * Enable/disable the touch panel's sound when the application's widgets are 
     * clicked.
     *
     * @param enable enable/disable the touch panel's sound
     * The default is to enable touch panel's sound
     */
    void enableTouchSound( bool enable = true );

    /**
     * Enable/disable the hardkey event filter
     *
     * @note the function is not implemented in the A760 and A768
     */
    //void enableHardKeyEventFilter( bool enable = true );
    
    /**
     * Get the flag to enable/disable the hardkey event filter
     *
     * @note the function is not implemented in the A760 and A768
     */
    bool getHardKeyEventFilter();

    /**
     * Raise all widgets in this application
     *
     * @internal
     */
    void raiseAppWindows();

    /**
     * Get input method name list
     *
     * @internal
     */
    const QIMMap& getIMList();

    /**
     * Update input methods name
     *
     * @note if language is changed, and the application is a deamon,
     * it must call this function to update the imput method names list.
     *
     * @internal
     */
    void updateIMNameList();

    /**
     * Flush the messages in the message queue
     *
     * @internal
     */
    void flushMsgs();

    /**
     * Get the touch panel msg queue
     *
     * @internal
     */
    int getTouchSoundMsgQueue();

#ifndef QT_NO_QWS_MMI_TEST
   // virtual void insertStr( QWSEvent * e );      //fox 这个没有的
#endif

signals:

    /**
     * Emitted when the application receive a message over the application Channel 
     * which is pre-created and its channel name is EZX/Application/appname.
     *
     * @param msg the name of the message
     * @param data the data of the message
     */
    void appMessage( const QCString &msg, const QByteArray &data );

    /**
     * Emitted when the phone is going to shutdown
     */
    void shutdown();

    /**
     * Emitted when the application manager requests this application to quit.
     * The application manager will do this to save RAM.
     *
     * By default, quickQuit() is connected to slotQuickQuit().
     *
     * @see slotQuickQuit()
     */
    void quickQuit();

    /**
     * Emitted when this application icon on the home screen is clicked.
     */
    void clickAppIcon();

    /**
     * Emitted when this application is raised from the background to the foreground.
     */
    void signalRaise();

    /**
     * Emitted when another application requests this application to open a file.
     *
     * @param doc full path name of the document file
     */
    void signalOpenDoc( const QString &doc );

    /**
     * Emitted when another application sends a message to this application.
     *
     * If this application is not running when the message is sent, it will be 
     * launched and then the signal sent.
     *
     * If already running, this application will be raised from the background 
     * to the foreground
     *
     * @param data information sent from another application
     *
     * @see signalBridgeMessage( const QCString &action, const QByteArray &data )
     */
    void signalBridgeMessage( const QByteArray &data );

    /**
     * Emitted when another application sends a message to this application.
     *
     * If this application is not running when the message is sent, it will be 
     * launched and then the signal sent.
     *
     * If already running, this application will be raised from the background 
     * to the foreground
     *
     * @param action another application indicate this application what should
     * be done by this parameter
     * @param data information sent from another application
     *
     * @see signalBridgeMessageWithoutRaise( const QCString &action, const QByteArray &data )
     */
    void signalBridgeMessage( const QCString &action, const QByteArray &data );

    /**
     * Emitted when another application sends a message to this application.
     *
     * If this application is not running when the message is sent, it will be 
     * launched and then the signal sent.
     *
     * If already running, this application will be raised from the background 
     * to the foreground
     *
     * @param action another application indicate this application what
     * should be done by this parameter
     * @param data information sent from another application
     *
     * @see signalBridgeMessage( const QCString &action, const QByteArray &data )
     */
    void signalBridgeMessageWithoutRaise( const QCString &action, const QByteArray &data );

    /**
     * Emitted when the 'Home' hardkey is clicked.
     * @internal
     */
    void signalHomeKeyClicked();

    /**
     * Emitted when user has selected to do a master clear.
     */
    void signalMasterClear();

    /**
     * Emitted when the system is doing a master reset.
     */
    void signalMasterReset();

    /**
     * Emitted when the user has clicked in an editable widget
     * @internal
     */
    void editableWidgetClicked( int mwId,bool canClick );

    /**
     * Emitted when the application received a message via the system
     * QCopChannel.
     *
     * @param msg the name of the message
     * @param data the data of the message
     *
     * @internal
     */
    void systemMessage( const QCString &msg, const QByteArray &data );

protected:

    /**
     * Reimplement
     */
    bool qwsEventFilter( QWSEvent* e );

    /**
     * Reimplement
     */
    virtual bool eventFilter( QObject* o, QEvent* e);

    /**
     * Reimplement
     */
    virtual void timerEvent( QTimerEvent* e);

    /**
     * Try to quit the application
     */
    virtual void tryQuit();      //fox v: Z0

    /**
     * Event filter for the ezx hard keys
     *
     * @retval if true the application can stop the default hardkey behaviors.
     *
     * @note the function is not implemented in the A760 and 768
     */
    //virtual bool hardKeyEventFilter( QEvent* e );  //fox 这个没有的

    /**
     * Set the applications max screen size 
     *
     * @note the function is not implemented in the A760 and A768
     */
    //void setMaxWindowRect(); //fox 这个没有的

    /**
     * Set the environment variable
     *
     * @param env the environment variable
     */
    void setEnv( const QString& env );


protected slots:

    /**
     * The default implementation of this slot will cause the current 
     * application to exit.
     *
     * By default, this slot is connected to signal shutdown().
     */
    virtual void slotShutdown();  //fox v: Z4

    /**
     * The default implementation of this slot will cause the current 
     * application to exit.
     *
     * By default, this slot is connected to signal quickQuit().
     */
    virtual void slotQuickQuit(); //fox v: Z8

    virtual void slotUsbStorageInOut(bool); //fox v: Z$C add

    /**
     * By default, this slot is connected to signal clickAppIcon() 
     */
    virtual void slotClickAppIcon(); //fox v: Z$10

    /**
     * By default, this slot is connected to signal signalRaise()
     *
     * By default, this function will raise the current application from 
     * the background to the foreground
     */
    virtual void slotRaise();  //fox v: Z$14

    virtual void slotLanguageChange(); //fox v: Z$18 add
    virtual void slotThemeChange(); //fox v: Z$1C add
    virtual void slotReturnToIdle(int); //fox v: Z$20 add

    virtual void slotLaunchactionByIdlescreen(const QUuid&); //fox v: Z$24 add
    virtual void slotLaunchactionByMainscreen(const QUuid&); //fox v: Z$28 add
    virtual void slotLaunchactionByVoicecommand(const QUuid&); //fox v: Z$2C add
    virtual void slotLaunchactionByDedicatedkey(const QUuid&); //fox v: Z$30 add
    virtual void slotLaunchactionByAnotherApp(const QUuid&); //fox v: Z$34 add
    virtual void slotKillactionByMassstorage(); //fox v: Z$38 add

private:

    QCopChannel*  getAppChannel() { return appChannel; }
    void soundTouchPanel( QWSEvent* e );
    void loadEZXFonts();
    bool createChannel();
    void startShowPHCursor( int startTime = 0,const QString& resId = QString::null );
    void stopShowPHCursor();
    void resetPHTimer();

    void createTouchSoundMsgQueue();

    bool getIMConnectedState() { return imConnected; }
    void setIMConnectedState( bool connected ) {imConnected = connected;}
    void showInputWidgetAux( int mwId,int show );
    void editableWidgetClicked( QWidget* widget,bool canClick = true );

    enum
    {
        WINS_LOWER = -1,
        WINS_HOLD = 0,
        WINS_SHOW,
        WINS_RAISE
    };
    void manipulateAppWindows( int show );
    void serverManipulateAppWindows( int show,const QString& clientName );
    void clientManipulateAppWindows( int show,QValueList<int>& winList );
    void setFocusToLatestWindow( int winId );

    int applyStyle();
    int initPalette();
    int applyPalette();
    int initTextSize();
    int changeTextSize();

private slots:

    void animationTimeOut();
    void animationStatus( int status );

    void slotSystemMessage( const QCString &msg, const QByteArray &data );
    void slotServerMessage( const QCString &msg, const QByteArray &data );
    void slotAppMessage( const QCString &msg, const QByteArray &data );
    void pidMessage( const QCString &message, const QByteArray &data );
    void updateEditorInfo( QWSWindow* w, QWSServer::WindowEvent e );
    void resetMouseMode();
    void resetPressHoldStatus();

private:

    ZApplicationData* d; //fox f: 44? ZApplication.Size = $68,所以下面有2个参数应该是没有的

    QCopChannel* serverChannel;  //fox f: 48?
    QCopChannel* sysChannel;     //fox f: 4C?
    QCopChannel* appChannel;     //fox f: 50?
    QCopChannel* pidChannel;     //fox f: 54?
    QString appName;             //fox f: 58?

    bool canSoundTouch;          //fox f: 5C?  bool
    int touchMsgQId;             //fox f: 60?

    bool autoInvokeKb;           //fox f: 64?
    bool autoHideKb;             //fox f: 65?
    bool imConnected;            //fox f: 66?

    int mouseMode;               //fox f: 68?

    ZIMServer* imServer;         //fox f: 6C?

#ifndef QT_NO_QWS_MMI_TEST
    QTestCaptureHandler* captureServer;
#endif

    friend class ZMainWidget;
};

#endif // Z_APPLICATION_H
