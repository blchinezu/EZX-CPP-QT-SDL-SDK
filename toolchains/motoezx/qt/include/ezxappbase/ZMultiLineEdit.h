//-------------------------------------------------------------------------------------------------
//
//  Header Name: ZMulitLineEdit.h
//
//  General Description:  EZX MultiLineEdit widget
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_MULTILINE_H
#define Z_MULTILINE_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#ifndef QT_H
#include "qtableview.h"
#include "qstring.h"
#include "qlist.h"
#include "qregexp.h"
#endif // QT_H

struct ZMultiLineData;
class ZMultiLineEditCommand;
class QValidator;

/**
 * the ZMainWidget class implements the EZX style's MultiLineEdit:
 * for example:
 * 1. support indent 
 * 2. support resize automatically(work with ZScrollView)
 * 3. support under line
 * 4. support input text filter
 *
 * the ZMultiLineEdit is based on the QMultiLineEdit, so for the most functions please refer to 
 * the doc of the QMultiLineEdit, except for these:
 * setIndent(), getIndent(), getLineHeight(), setUnderline(),
 * setFilter(),getFilter(), drawLineText()
 *
 * @code
 * ZScrollView* sv = new ZScrollView( this, "sv" );
 * UTIL_MulitLineEdit *ml1, *ml2;
 *
 * //add a 6 lines ZMultiLineEdit
 * ml1 = new ZMultiLineEdit(sv->viewport(),true,6);
 *
 * //set filter
 * QRegExp tmp("[.*]");
 * ml1->setFilter(tmp);
 * sv->addChild(ml1,0,0);
 *
 * //set indent
 * ml1->setIndent(20);
 * ml2 = new ZMultiLineEdit(sv->viewport());
 * 
 * //need to change the widget when ZScrollView's scrollbar is shown/hidden
 * sv->addChild(ml2,0,30,true);
 * @endcode
 */

class Q_EXPORT ZMultiLineEdit : public QTableView  //fox size: $18C, QTableView: $128 //3 function not processed!
{
    Q_OBJECT

    Q_ENUMS( EchoMode WordWrap WrapPolicy TitlePosition)
    Q_PROPERTY( int numLines READ numLines )
    Q_PROPERTY( bool atBeginning READ atBeginning )
    Q_PROPERTY( bool atEnd READ atEnd )
    Q_PROPERTY( int maxLineWidth READ maxLineWidth )
    Q_PROPERTY( Alignment alignment READ alignment WRITE setAlignment )
    Q_PROPERTY( bool edited READ edited WRITE setEdited DESIGNABLE false )
    Q_PROPERTY( EchoMode echoMode READ echoMode WRITE setEchoMode )
    Q_PROPERTY( int maxLength READ maxLength WRITE setMaxLength )
    Q_PROPERTY( int maxLines READ maxLines WRITE setMaxLines )
    Q_PROPERTY( int hMargin READ hMargin WRITE setHMargin )
    Q_PROPERTY( WordWrap wordWrap READ wordWrap WRITE setWordWrap )
    Q_PROPERTY( int wrapColumnOrWidth READ wrapColumnOrWidth WRITE setWrapColumnOrWidth )
    Q_PROPERTY( WrapPolicy wrapPolicy READ wrapPolicy WRITE setWrapPolicy )
    Q_PROPERTY( bool autoUpdate READ autoUpdate WRITE setAutoUpdate DESIGNABLE false )
    Q_PROPERTY( bool undoEnabled READ isUndoEnabled WRITE setUndoEnabled )
    Q_PROPERTY( int undoDepth READ undoDepth WRITE setUndoDepth )
    Q_PROPERTY( bool readOnly READ isReadOnly WRITE setReadOnly )
    Q_PROPERTY( bool overWriteMode READ isOverwriteMode WRITE setOverwriteMode )
    Q_PROPERTY( QString text READ text WRITE setText )
    Q_PROPERTY( int length READ length )

public:
#	ifdef EZX_A1200	
	ZMultiLineEdit( QWidget *parent=0, const char *name=0,bool x=true);//A1200
    ZMultiLineEdit( QWidget *parent,bool EZXStyle,int lines = 1,const char *name=0 ,bool x=true); //A1200
    
#	else
	ZMultiLineEdit( QWidget *parent=0, const char *name=0);
    /**
     * Constructor of ZMultiLineEdit
     *
     * @param EZXStyle if false, the class is almost the samewith qmultilineedit.
     * if true ezx-special functions will be suported.
     *
     * @param lines the default lines the ZMultiLineEdit has
     */
    ZMultiLineEdit( QWidget *parent,bool EZXStyle,int lines = 1,const char *name=0 );
#	endif //EZX_A1200
    virtual ~ZMultiLineEdit();

    /**
     * set indent
     */
    void setIndent( int idt );
  
    /**
     * get indent
     */
    int getIndent();
  
    /**
     * get the each line's height
     */
    int getLineHeight() const;

    /**
     * set the underline flag
     */
    void setUnderline( bool needUnderline = true );

    /**
     * get the underline flag
     *
     * @retval if true has underline; if false, does not have underline
     */
    bool getUnderline();

    /**
     * set the filter for the text input
     *
     * @param filter the filter 
     * @param match if true the text input need to match the filter
     * @note if the text is big, maybe the performance will be bad
     */
    void setFilter( const QRegExp& filter, bool match = false );

    /**
     * get the filter
     */
    const QRegExp& getFilter() const;



    QString textLine( int line ) const;
    int numLines() const;  //==getLineCount

    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    QSizePolicy sizePolicy() const;

    virtual void setFont( const QFont &font );

    virtual void insertLine( const QString &s, int line = -1 );
    virtual void insertAt( const QString &s, int line, int col, bool mark = FALSE );
    virtual void removeLine( int line );

    void cursorPosition( int *line, int *col ) const;
    virtual void setCursorPosition( int line, int col, bool mark = FALSE );
    void getCursorPosition( int *line, int *col ) const;                              //nukin
    bool atBeginning() const;
    bool atEnd() const;

    virtual void setFixedVisibleLines( int lines );

    int maxLineWidth() const;

    void setAlignment( int flags );
    int alignment() const;

    virtual void setValidator( const QValidator * );
    const QValidator * validator() const;

    void setEdited( bool );
    bool edited() const;

    void cursorWordForward( bool mark );
    void cursorWordBackward( bool mark );

    enum EchoMode { Normal, NoEcho, Password };
    virtual void setEchoMode( EchoMode );
    EchoMode echoMode() const;

    void setMaxLength(int);
    int maxLength() const;
    virtual void setMaxLineLength(int);
    int maxLineLength() const;
    virtual void setMaxLines(int);
    int maxLines() const;
    virtual void setHMargin(int);
    int hMargin() const;

    virtual void setSelection( int row_from, int col_from, int row_to, int col_t );

    enum WordWrap {
        NoWrap,
        WidgetWidth,
        FixedPixelWidth,
        FixedColumnWidth
    };
    void setWordWrap( WordWrap mode );
    WordWrap wordWrap() const;
    void setWrapColumnOrWidth( int );
    int wrapColumnOrWidth() const;

    enum WrapPolicy {
        AtWhiteSpace,
        Anywhere
    };
    void setWrapPolicy( ZMultiLineEdit::WrapPolicy policy );
    WrapPolicy wrapPolicy() const;

    bool autoUpdate()   const;
    virtual void setAutoUpdate( bool );

    void setUndoEnabled( bool );
    bool isUndoEnabled() const;
    void setUndoDepth( int );
    int undoDepth() const;

    bool isReadOnly() const;
    bool isOverwriteMode() const;

    QString text() const;

    int length() const;  //ZMultiLineEdit显示的内容长度，包含空格,tab和\n

    static void setDefaultTabStop( int ex );
    static int defaultTabStop();

    virtual void show();
    
    void    setWidth( int );
	void    updateCellWidth();

    bool    hasMarkedText() const;
    QString markedText() const;
public slots:

    /**
     * change the content size
     * 
     * @param lines how many lines have be changed
     *
     * @param cursorPos cursor position
     *
     * @note internal use
     */
    virtual void changeContentSize( int lines,QPoint cursorPos );

    virtual void       setText( const QString &);
    virtual void       setReadOnly( bool );
    virtual void       setOverwriteMode( bool );

    void       clear();
    void       append( const QString &);
    void       deselect();
    void       selectAll();
#ifndef QT_NO_CLIPBOARD
    void       paste();
    void       pasteSubType(const QCString& subtype);
    void       copyText() const;
    void       copy() const;
    void       cut();
    void       deleteText();
#endif
    void       insert( const QString& );
    void       undo();
    void       redo();

signals:
    
    void    clicked();
    void    textTrancated();
    void    textChanged();
    void    returnPressed();
    void    undoAvailable( bool );
    void    redoAvailable( bool );
    void    copyAvailable( bool );
    
    /**
     * the signal is emitted when size hint is changed
     *
     * @note internal use
     */
    void    changeSizeHint( QWidget* widget,QSize size,QPoint cusrorPos,int larger );

    /**
     * the signal is emitted when lines is changed
     *
     * @note internal use
     */
    void    linesChanged( int lines,QPoint cursorPos );

protected:
    
    void    updateMask();
    void    pixelPosToCursorPos(QPoint p, int* x, int* y) const;
    void    setCursorPixelPosition(QPoint p, bool clear_mark = true);

    void    paintEvent(QPaintEvent * );

#define MOT_BLEND
#ifdef MOT_BLEND
    void    paintCell( QPainter *, int row, int col, int xPos, int yPos );
#else
    void    paintCell( QPainter *, int row, int col );
#endif

    /**
     * draw the line text
     * override the function to draw own style's text.
     * for example:
     * change color of the line text
     *
     * @param (x,y) the base line to draw  
     * @param width width of the area to draw
     * @param height height of the area to draw
     * @param flags alignment
     * @param flags lineStr line text
     * @param lineStr line text
     * @param marked if true, the text is in the marked area, or it is not marked
     *
     * @note all the params above have the right initial values
     */
    //virtual void drawLineText( QPainter* painter, int x, int y, int width,
    //                           int height, int flags, const QString& lineStr);
    virtual void drawLineText( QPainter* painter, int x, int y, int width,
        int height, int flags, const QString& lineStr, int, int); //fox add last 2 params
    bool    event( QEvent * );

    void    mousePressEvent( QMouseEvent * );
    void    mouseMoveEvent( QMouseEvent * );
    void    mouseReleaseEvent( QMouseEvent * );
    void    mouseDoubleClickEvent( QMouseEvent * );
    void    wheelEvent( QWheelEvent * );
    void    keyPressEvent( QKeyEvent * );
    void    focusInEvent( QFocusEvent * );
    void    focusOutEvent( QFocusEvent * );
    void    timerEvent( QTimerEvent * );
    void    leaveEvent( QEvent * );
    void    resizeEvent( QResizeEvent * );

    bool    focusNextPrevChild( bool );

#ifndef QT_NO_DRAGANDDROP
    void    dragMoveEvent( QDragMoveEvent* );
    void    dragEnterEvent( QDragEnterEvent * );
    void    dropEvent( QDropEvent* );
    void    dragLeaveEvent( QDragLeaveEvent* );
#endif

//    bool    hasMarkedText() const;
//    QString markedText() const;
    int     textWidth( int );
    int     textWidth( const QString &);

    QPoint  cursorPoint() const;

protected:

    virtual void insert( const QString&, bool mark );
    virtual void newLine();
    virtual void killLine();
    virtual void pageUp( bool mark=FALSE );
    virtual void pageDown( bool mark=FALSE );
    virtual void cursorLeft( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorRight( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorUp( bool mark=FALSE );
    virtual void cursorDown( bool mark=FALSE );
    virtual void backspace();
    virtual void del();
    virtual void home( bool mark=FALSE );
    virtual void end( bool mark=FALSE );

    bool getMarkedRegion( int *line1, int *col1,
                          int *line2, int *col2 ) const;
    int lineLength( int row ) const;
    QString *getString( int row ) const;
    bool isEndOfParagraph( int row ) const;
    QString stringShown( int row ) const;

protected:
    int Temp128; //fox f: $128
    int Temp12C; //fox f: $12C
    int Temp130; //fox f: $130
    int Temp134; //fox f: $134

    bool    cursorOn;             //fox f: $138
    void    insertChar( QChar );

#ifndef QT_NO_QWS_MMI_TEST
    QRect globalRect( int mx, int my, int mwidth, int mheight );
    //virtual int sendPackage();  //fox removed
    //virtual int sendPackageItem( int mmix, int mmiy, int mmiwidth, int mmiheight, QString mmis );  //fox removed
#endif

private slots:
    
    void    clipboardChanged();
    void    blinkTimerTimeout();
    void    scrollTimerTimeout();
    void    dndTimeout();

private:

    void init( QWidget *parent,bool style,int lines,const char *name );
    bool isValidChar( const QChar& ch );
    void filterString( QString& filtered,const QString& s );
    void autoSendScrollRequest( int lines,const QPoint& curPos );

#ifndef AMT_NO_THAI_ADDITIONS
    int clusterForward(int cp) const;
    int clusterBackward(int cp) const;
    int toClusterEnd(int cp) const;
#endif
#ifndef QT_NO_MIME
    QCString pickSpecial( QMimeSource* ms, bool always_ask, const QPoint& );
#endif
/* #ifndef QT_NO_MIMECLIPBOARD */
    void       pasteSpecial(const QPoint&);
/* #endif */
    struct ZMultiLineEditRow {
        ZMultiLineEditRow( QString string, int width, bool nl = TRUE )
            :s(string), w(width), newline( nl ) {
        };
        QString s;
        int w;
        bool newline;
    };

    QList<ZMultiLineEditRow>*  contents;    //fox f: $13C
    ZMultiLineData*   d;                    //fox f: $140

    int     indent;                         //fox f: $144
    QSize   hint;                           //fox f: $148
    bool    ezx_style;                      //fox f: $150
    int     lines;                          //fox f: $154
    int     minLines;                       //fox f: $158
    bool    underline;                      //fox f: $15C   

    bool    readOnly;                       //fox f: $15D
    bool    dummy;                          //fox f: $15E
    bool    markIsOn;                       //fox f: $15F
    bool    dragScrolling ;                 //fox f: $160   
    bool    dragMarking;                    //fox f: $161
    bool    textDirty;                      //fox f: $162
    bool    wordMark;                       //fox f: $163
    bool    overWrite;                      //fox f: $164   

    int     cursorX;                        //fox f: $168
    int     cursorY;                        //fox f: $16C
    int     markAnchorX;                    //fox f: $170
    int     markAnchorY;                    //fox f: $174
    int     markDragX;                      //fox f: $178
    int     markDragY;                      //fox f: $17C
    int     curXPos;    // cell coord of cursor   //fox f: $180
    int     blinkTimer; // #### not used anymore - remove in 3.0  //fox f: $184
    int     scrollTimer; // #### not used anymore - remove in 3.0 //fox f: $188
                                                                  
    int     mapFromView( int xPos, int row );                     
    int     mapToView( int xIndex, int row );                   

   // void    setWidth( int );
    //void    updateCellWidth();
    bool    partiallyInvisible( int row );
    void    makeVisible();
    void    setBottomCell( int row );

    void    newMark( int posx, int posy, bool copy=TRUE );
    void    markWord( int posx, int posy );
    void    extendSelectionWord( int &newX, int&newY);
    int     charClass( QChar );
    void    turnMark( bool on );
    bool    inMark( int posx, int posy ) const;
    bool    beforeMark( int posx, int posy ) const;
    bool    afterMark( int posx, int posy ) const;
    void     setNumRowsAndTruncate();

#ifndef QT_NO_DRAGANDDROP
    void    doDrag();
#endif
    //void    startAutoScroll();
    //void    stopAutoScroll();

    void    cursorLeft( bool mark, bool clear_mark, bool wrap );
    void    cursorRight( bool mark, bool clear_mark, bool wrap );
    void    cursorUp( bool mark, bool clear_mark );
    void    cursorDown( bool mark, bool clear_mark );

    void    wrapLine( int line, int removed = 0);
    void    rebreakParagraph( int line, int removed = 0 );
    void    rebreakAll();
    void    insertAtAux( const QString &s, int line, int col, bool mark = FALSE );
    void    killLineAux();
    void    delAux();
    int     positionToOffsetInternal( int row, int col ) const;
    void    offsetToPositionInternal( int position, int *row, int *col ) const;
    void    deleteNextChar( int offset, int row, int col );

    void    addUndoCmd( ZMultiLineEditCommand* );
    void    addRedoCmd( ZMultiLineEditCommand* );
    void    processCmd( ZMultiLineEditCommand*, bool );

private:  // Disabled copy constructor and operator=

#if defined(Q_DISABLE_COPY)
    ZMultiLineEdit( const ZMultiLineEdit & );
    ZMultiLineEdit &operator=( const ZMultiLineEdit & );
#endif

public: //fox add
	void    startAutoScroll();  //nukin
    void    stopAutoScroll();  //nukin
    int deleteWord(void);
    int bufferUpdate(int, int);
    int bufferUpdate(void);

    int calCursorPos(QPoint, int);
    int getLineCount(void);  //==numLines()

    QRect getMDTopArea(void);  //nukin
    QString getRowString(int);
    int paintCell_if(QPainter*, int, int, bool, int, bool, int, int, QString, QFontMetrics, QRect, QColorGroup);

    int clearUndoList(void);
    int cursorChanged(int, int);
//    int drawMultiArea(QPainter*, const QRect&, const QRect&, ZSkinBase*);  //fox todo ZSkinBase
//    int drawOtherArea(QPainter*, const QRect&, const QRect&, ZSkinBase*);  //fox todo ZSkinBase

    int getInputField(void);
    QRect getMDLeftArea(void);
    int addReplacedStr(const QString&, int);
    int contentChanged(void);

    int getLineContent(int);
    QRect getMDRightArea(void);
    int emitTextChanged(void);

    QRect getMDBottomArea(void);
    int insertString_if(QPoint, QString);
    int setTruncateInfo(int, const QString&);
    int setWordComplete(bool);
    int getContentsWidth(void);

    int getTruncateCount(void);
    
    enum TitlePosition {
    	Hidden,  //Hidden
    	OneLine,  //TopLeft and text start at a new line;
    	InsertAtHead  //TopLeft and text start at the same line;
    	//named by nukin; Only lineWidth width is visiable;
    	//edited() will change to true; 
    };
    int setTitlePosition(ZMultiLineEdit::TitlePosition); //fox todo TitlePosition
    QString title() const;  //nukin add
    int setTitle(const QString&);
    
    int smartPunctuation(void);
    int getFormItemTopArea(void);

    int setAutoFixedHeight(bool);
    int fastDelTimerTimeout(void);

    QRect getFormItemLeftArea(void);
    int setTitlePositionAux(const QString&, int);
    QRect getFormItemRightArea(void);
    int cursorPosBeforeInsert(int, int, int, int*, int*);

    int rightSmartPuncOccurred(void);
    
    bool phonenoText(void);  //nukin add
    void setFrameRect(QRect  const&);  //nukin add
};

inline bool ZMultiLineEdit::isReadOnly() const { return readOnly; }

inline bool ZMultiLineEdit::isOverwriteMode() const { return overWrite; }

inline void ZMultiLineEdit::setOverwriteMode( bool on )
{
    overWrite = on;
}

inline int ZMultiLineEdit::lineLength( int row ) const
{
    return contents->at( row )->s.length();
}

inline bool ZMultiLineEdit::atEnd() const
{
    return cursorY == (int)contents->count() - 1
        && cursorX == lineLength( cursorY ) ;
}

inline bool ZMultiLineEdit::atBeginning() const
{
    return cursorY == 0 && cursorX == 0;
}

inline QString *ZMultiLineEdit::getString( int row ) const
{
    return &(contents->at( row )->s);
}

inline int ZMultiLineEdit::numLines() const
{
    return contents->count();
}

#endif 







