#ifndef UTIL_SLIDER_H
#define UTIL_SLIDER_H

/*!
	UTIL_Slider::setValue(int) 无效果，初始化时要调用QSlider::setValue(int);
	
	UTIL_Slider::reallyMoveSlider(int) 滑动dot


*/
#include <qpixmap.h>
#include <qslider.h>

class UTIL_Slider : public QSlider
{
	Q_OBJECT
public:
	
	UTIL_Slider(QPixmap const& dot, QPixmap const& disabledDot, QPixmap const& slot, QPixmap const& disabledSlot, 
		int , int , int pageStep, int value, Qt::Orientation, QWidget *parent, int minValue, int maxValue);
	UTIL_Slider(Qt::Orientation, QWidget *parent, int n1, int n2);
	UTIL_Slider(QString  const& name, Qt::Orientation, QWidget *parent, int n1, int n2);
	UTIL_Slider(int minValue, int maxValue, int pageStep, int value, Qt::Orientation,QWidget *parent, int minValue, int maxValue);
	UTIL_Slider(QString  const&, int, int, int, int, Qt::Orientation, QWidget *parent, int, int);
	UTIL_Slider(QPixmap  const&, QPixmap  const&, QPixmap  const&, QPixmap  const&, Qt::Orientation, QWidget *parent, int, int);
	
	~UTIL_Slider();
public:
	void init(QString  const&, QPixmap  const&, QPixmap  const&, QPixmap  const&, QPixmap  const&, Qt::Orientation, int, int, int);
	virtual void setOrientation(Qt::Orientation);  //qslide
	Orientation orientation(void)const;
	virtual void setTracking(bool enable);
	bool tracking(void)const;

	QRect sliderRect(void)const;
	QSize sizeHint(void)const;
	QSize minimumSizeHint(void)const;
	
	QSizePolicy sizePolicy(void)const;
	void rot90(QPixmap  const&);
	void setGeometry(int, int, int, int);
	void setGeometry(QRect  const&);
	void resize(int, int);
	void resize(QSize  const&);
		
	void setMinValue(int);
	void setPageStep(int);
	void setLineStep(int);
	void setMinimumSize(int, int);  //?
	

	int minValue(void)const;
	QPoint positionFromValue(int)const;
	int lineStep(void)const;
	
	QPixmap *pixmap(QPixmap  const&, QString  const&)const;
	void pixmapOrDraw(QPixmap  const&, QPixmap (UTIL_Slider::*)(void)const)const ;

	void reallyMoveSlider(int);	
signals:
	void sliderPressed();
	void valueChanged(int  value);
	void sliderReleased();
	void sliderMoved(int);

public slots:
	virtual void setValue(int);   //qslider
	void subtractStep(void);
	void addStep(void);

	
protected:
	void resizeEvent(QResizeEvent *);
	void paintEvent(QPaintEvent *);
	void mouseEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
		
	void rangeChange(void);
	void valueChange(void);

	virtual void drawDot(void)const;
	virtual void drawDisabledDot(void)const;
	virtual void drawSlot(void)const;
	virtual void drawDisabledSlot(void)const;

private:
	int valueFromPosition(int)const;

	
	int available(void)const;
	int disabledDot(void)const;
	int disabledSlot(void)const;
	QPixmap disabledDotPixmap(void)const;
	QPixmap slotPixmap(void)const;
	QPixmap disabledSlotPixmap(void)const;
	QPixmap dotPixmap(void)const;

	int	dot(void)const;                    //??
	int slot(void)const;         //???
	int fade(QPixmap  const&)const;     //??
	
	//int multSixTenths; //???
	//int defaultDot;
	int defaultDotLen;
	char tmp[256];	
};
#endif // UTIL_SLIDER_H
 
