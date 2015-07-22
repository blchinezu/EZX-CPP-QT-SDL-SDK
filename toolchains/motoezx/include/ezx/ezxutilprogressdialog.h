/**************************
*nukin 20090901
*������QProgressDialog.hһ����QProgressDialogò���޷�ʹ�ã�ֻ����UTIL_ProgressDialog
*��ֱ�Ӹ���QProgressDialog.h��Դ�룬��QProgressDialog,QProgressBar,QPushButton�ĳ�UTIL_,��ΪIDA�����������Щ����UTIL_;�Ѽ̳����ΪUTIL_Dialog

**************************************/

#if !defined(__EZX_UTIL_PROGRESSDIALOG_H__)
#define __EZX_UTIL_PROGRESSDIALOG_H__
#include "qsemimodal.h"
#include <ezxutildialog.h>
#include <qlabel.h>
#include <ezxutilprogressbar.h>
#include <ezxutilpushbutton.h>
//class UTIL_ProgressBar

struct QProgressData;
class QTimer;

//QProgressDialog�̳е���QSemiModal,�������������UTIL_Dialog���Ҳµģ�����û����.��̳п��� ��QDialog::show();
class UTIL_ProgressDialog : public UTIL_Dialog    
{
    Q_OBJECT
    Q_PROPERTY( bool wasCancelled READ wasCancelled )
    Q_PROPERTY( int totalSteps READ totalSteps WRITE setTotalSteps )
    Q_PROPERTY( int progress READ progress WRITE setProgress )
    Q_PROPERTY( bool autoReset READ autoReset WRITE setAutoReset )
    Q_PROPERTY( bool autoClose READ autoClose WRITE setAutoClose )
    Q_PROPERTY( QString labelText READ labelText WRITE setLabelText )
        
public:
    UTIL_ProgressDialog( QWidget *parent=0, const char *name=0, bool modal=FALSE,
                     WFlags f=0 );
    UTIL_ProgressDialog( const QString& labelText, const QString &cancelButtonText,
                     int totalSteps, QWidget *parent=0, const char *name=0,
                     bool modal=FALSE, WFlags f=0 );
   ~UTIL_ProgressDialog();

    void        setLabel( QLabel * );
    void        setCancelButton( UTIL_PushButton * );
    void        setBar( UTIL_ProgressBar * );

    bool        wasCancelled() const;

    int         totalSteps() const;
    int         progress()   const;

    QSize       sizeHint() const;

    QString     labelText() const;

    void setAutoReset( bool b );
    bool autoReset() const;
    void setAutoClose( bool b );
    bool autoClose() const;

public slots:
    void        cancel();
    void        reset();
    void        setTotalSteps( int totalSteps );
    void        setProgress( int progress );
    void        setLabelText( const QString &);
    void        setCancelButtonText( const QString &);

    void        setMinimumDuration( int ms );
	UTIL_ProgressBar  *bar()    const;
public:
    int         minimumDuration() const;

signals:
    void        cancelled();

private:
    void           init( QWidget *creator, const QString& lbl, const QString &canc,
                         int totstps);
    void           center();
    void           layout();
    QLabel        *label()  const;
    //UTIL_ProgressBar  *bar()    const;
    QProgressData *d;
    QTimer        *forceTimer;


protected:
    void        resizeEvent( QResizeEvent * );
    void        closeEvent( QCloseEvent * );
    void        styleChange( QStyle& );
    void        showEvent( QShowEvent *e );

protected slots:
	void  forceShow(void); 

private:
	
};

#endif
