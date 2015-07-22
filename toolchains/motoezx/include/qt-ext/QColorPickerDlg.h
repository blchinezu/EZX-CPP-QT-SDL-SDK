#ifndef QCOLORPICKERDLG_H
#define QCOLORPICKERDLG_H


#ifndef NO_EZX
#include <UTIL_Slider.h>
#define QSlider UTIL_Slider
#endif //NO_EZX
#include <ezxutildialog.h>

class QSlider;
class QLabel;
class QColorPickerDlg : public UTIL_Dialog
{
	Q_OBJECT
public:
	QColorPickerDlg(QWidget *p=0,const QColor& cl=QColor(123,123,123));
	~QColorPickerDlg();
	//rgb,hsv
	QColor getColor() const; //return QColor(x,y,z,type);
	//setColor(const QColor& c,int type t);
	void setColor(const QColor& c,bool rgb);
	
	static QColor getColorDirect(QWidget* p=0,const QColor& cl=QColor(123,123,123));
public slots:
	void colorPreview(int);
	void colorPreviewU();
private:
	QLabel *color;
	QSlider *red, *green, *blue;
	int x,y,z;
	//bool rgb;
};
	
#endif //QCOLORPICKERDLG_H

