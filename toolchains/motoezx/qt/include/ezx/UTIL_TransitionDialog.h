
#ifndef UTIL_TRANSITIONDIALOG_H
#define UTIL_TRANSITIONDIALOG_H

#include "qsemimodal.h"
#include "qlabel.h"
#include "qmovie.h"

#include "UTIL_ProgressBar.h"
#include "UTIL_PushButton.h"

struct UTIL_TransitionData;
class QTimer;

class Q_EXPORT UTIL_TransitionDialog : public QSemiModal
{
    Q_OBJECT
    Q_PROPERTY( bool wasCancelled READ wasCancelled )
    Q_PROPERTY( bool autoReset READ autoReset WRITE setAutoReset )
    Q_PROPERTY( bool autoClose READ autoClose WRITE setAutoClose )
    Q_PROPERTY( QString labelText READ labelText WRITE setLabelText )

public:
    UTIL_TransitionDialog( const QString& labelText, const QString &Button1Text=QString::null, const QString &Button2Text=QString::null,
             bool withPrgrsBar=FALSE, QWidget *creator=0, const char *name=0, bool modal=TRUE, WFlags f=0 );
   ~UTIL_TransitionDialog();

    void    setLabel( QLabel * );
    void    setButton1( UTIL_PushButton * );
    void    setButton2( UTIL_PushButton * );
    void        setAnimation(const QMovie& );  // if set, should let withPrgrsBar = FALSE;

    void    setBar( UTIL_ProgressBar * ); // outdated, should not use this method now.
    int        totalSteps() const;

    bool    wasCancelled() const;

    QSize    sizeHint() const;

    QString     labelText() const;

    void        setAutoReset( bool b ); //outdated, should not use this method now.
    bool        autoReset() const; //outdated, should not use this method now
    void        setAutoClose( bool b );
    bool        autoClose() const;

public slots:
    void    cancel();   // call this slot function if you want to exit this dialog
    void    reset();
    void    setLabelText( const QString &);
    void    setButtonText( const QString &, const QString &); // if you don't need the dialog softkey, just set the button string
                                                                  // to QString().

    void    setMinimumDuration( int ms ); // if you don't want this dialog appear until some seconds passed, just set the time to "ms",
                                              // the default value is 100 ms.

    void    setTotalSteps( int totalSteps ); //valid when progress bar is shown. the defaul value is 100.
    void        setProgressInterval( int ms); //valid when progress bar is shown. the default value is 30 ms.
public:
    int        minimumDuration() const;

signals:
    void    cancelled();
    void        button1Clicked();  // emit this signal when the first button is clicked, you must connect a SLOT to treat it
    void        button2Clicked();  // emit this signal when the second button is clicked, you must connect a SLOT to treat it
    void        progressOneStep(); // emit this signal when the progress bar advance one step. valid only if the progress bar is shown.

protected:
    void    resizeEvent( QResizeEvent * );
    void    closeEvent( QCloseEvent * );
    void    styleChange( QStyle& );
    void    showEvent( QShowEvent *e );

protected slots:
    void    forceShow();
    void    setAutoProgress();

private:
    void    init( QWidget *creator, const QString& lbl, const QString &button1, const QString &button2, bool withPrgrsBar);
    void    center();
    void    layout();

    QLabel      *label()  const;
    UTIL_ProgressBar  *bar()    const;
    UTIL_TransitionData *d;
    QTimer      *forceTimer, *progressTimer;
};

#endif // UTIL_TRANSITIONDIALOG_H

