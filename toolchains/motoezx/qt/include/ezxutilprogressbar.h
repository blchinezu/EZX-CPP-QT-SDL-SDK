#if !defined(__EZX_UTIL_PROGRESSBAR_H__)
#define __EZX_UTIL_PROGRESSBAR_H__

#include <qprogressbar.h>

class UTIL_ProgressBarPrivate;
class UTIL_ProgressBar:public QProgressBar //inherits QProgressBar so we have progress() totalSteps() etc. p->QProgressBar::progress()
{
	Q_OBJECT
	Q_PROPERTY( int totalSteps READ totalSteps WRITE setTotalSteps )
    //Q_PROPERTY( int progress READ progress WRITE setProgress )
    //Q_PROPERTY( bool centerIndicator READ centerIndicator WRITE setCenterIndicator )
    //Q_PROPERTY( bool indicatorFollowsStyle READ indicatorFollowsStyle WRITE setIndicatorFollowsStyle )
public:
	UTIL_ProgressBar(QWidget *parent = 0,const char * name = 0,WFlags f=0);
	
	QSize sizeHint() const;
	
	void setCenterIndicator(bool);
	void setIndicatorFollowsStyle(bool);
	virtual void show();

public slots:
	void	reset();
    virtual void setTotalSteps( int totalSteps );
    virtual void setProgress( int progress );
	
protected:
    void	drawContents( QPainter * );
    void	drawContentsMask( QPainter * );
	virtual void qProgsetIndicator(QString &,int,int);
    virtual bool setIndicator( QString & progress_str, int progress, int totalSteps );
    void styleChange( QStyle& );
	void drawBigProgressAmount(QPainter*,QString const &,int,int,QRect,QColorGroup&);

private:
    UTIL_ProgressBarPrivate * d;
    void         initFrame();
	char x[256];
	QPixmap s_pixmap_6;
	QPixmap s_pixmap_7;
};
#endif
