#if !defined(__EZX_UTIL_PROGRESSBAR_H__)
#define __EZX_UTIL_PROGRESSBAR_H__

#include <qstring.h>
#include <qpainter.h>
#include <qwidget.h>
#include <qprogressbar.h>

class UTIL_ProgressBar:public QWidget
{
Q_OBJECT
public:
void setProgress(int);
//void styleChange(QStyle);
void drawContents(QPainter);
void setIndicator(QString const &,int,int);
void setTotalSteps(int);
//void init();
void drawContentsMask(QPainter);
void qProgsetIndicator(QString const &,int,int);
void setCenterIndicator(bool);
void drawBigProgressAmount(QPainter,QString const &,int,int,QRect,QColorGroup);
void setIndicatorFollowsStyle(bool);
virtual void show();
virtual void reset();
virtual void initFrame(void);

public:
UTIL_ProgressBar(QWidget *,const char * name = 0,WFlags f=0);
~UTIL_ProgressBar();

int tmp[512];
QPixmap s_pixmap_6;
QPixmap s_pixmap_7;
//char cc[256];
};
#endif
