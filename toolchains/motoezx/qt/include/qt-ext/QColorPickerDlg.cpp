#include "QColorPickerDlg.h"
#include <ezxres.h>
#include <qhbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <ZPushButton.h>


QColorPickerDlg::QColorPickerDlg(QWidget* parent,const QColor& cl)
 :UTIL_Dialog(UTIL_Dialog::DTLargeSize,true,parent,"Color Dialog",1,0)//,rgb(true)
{
	setHasTitle(true);
	setDlgTitle(tr("Color Picker"));
	
	QWidget* w=getDlgContent();
	QVBoxLayout* vb=new QVBoxLayout(w);
	vb->setAutoAdd(true);
	
	color=new QLabel(w); //setFrame
	color->setBackgroundMode(NoBackground);
	color->setBackgroundColor(cl);
	color->setFixedSize(100,100);

#ifndef NO_EZX
	RES_ICON_Reader ir;
	QPixmap dotr=ir.getIcon("MediaEditor_Color_Picker_Red_S_Dot",true); 
	QPixmap dotg=ir.getIcon("MediaEditor_Color_Picker_Green_S_Dot",true); 
	QPixmap dotb=ir.getIcon("MediaEditor_Color_Picker_Blue_S_Dot",true); 
	QPixmap dotd=ir.getIcon("MediaEditor_Color_Picker_Red_S_Dot_D",true);
	QPixmap slot=ir.getIcon("MediaEditor_Color_Picker_S_Slot",true); 
	QPixmap slotd=ir.getIcon("MediaEditor_Color_Picker_S_Slot_D",true);
	red=new 	QSlider(dotr,dotd,slot,slotd,1,1,5,cl.red(),Horizontal,w,0,255);
	green=new 	QSlider(dotg,dotd,slot,slotd,1,1,5,cl.green(),Horizontal,w,0,255);
	blue=new 	QSlider(dotb,dotd,slot,slotd,1,1,5,cl.blue(),Horizontal,w,0,255);
	
	red->setFixedSize(QSize(slot.width(),dotr.height()));
	green->setFixedSize(QSize(slot.width(),dotg.height()));
	blue->setFixedSize(QSize(slot.width(),dotb.height()));		
	
#else
	red=new QSlider(0,255,1,cl.red(),Horizontal,w,"red");
	green=new QSlider(0,255,1,cl.green(),Horizontal,w,"green");
	blue=new QSlider(0,255,1,cl.blue(),Horizontal,w,"blue");
	
	red->setBackgroundColor(Qt::red);
	green->setBackgroundColor(Qt::green);
	blue->setBackgroundColor(Qt::blue);

#endif //NO_EZX	

	red->setTracking(true);
	green->setTracking(true);
	blue->setTracking(true);
	
	red->setMaxValue(255);
	green->setMaxValue(255);
	blue->setMaxValue(255);			

	setColor(cl,true);
	
	connect(red,SIGNAL( sliderReleased()),this,SLOT(colorPreviewU()));
	connect(green,SIGNAL( sliderReleased()),this,SLOT(colorPreviewU()));
	connect(blue,SIGNAL( sliderReleased()),this,SLOT(colorPreviewU()));
	
	connect(red,SIGNAL( sliderMoved(int)),this,SLOT(colorPreview(int)));
	connect(green,SIGNAL( sliderMoved(int)),this,SLOT(colorPreview(int)));
	connect(blue,SIGNAL( sliderMoved(int)),this,SLOT(colorPreview(int)));

	
	QHBox *hb = new QHBox(this);
	setDlgCst(hb);

	ZPushButton *okBtn = new ZPushButton(hb, 0, -1, -1);
	okBtn->setText(tr("OK"));	
	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
	
	ZPushButton *cancelBtn=new ZPushButton(hb, 0, -1, -1);
	cancelBtn->setText(tr("Cancel"));	
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
	
	
}

QColorPickerDlg::~QColorPickerDlg()
{
}

void QColorPickerDlg::colorPreview(int)
{

	color->setBackgroundColor(QColor(red->value(),green->value(),blue->value()));
}

void QColorPickerDlg::colorPreviewU()
{
	qDebug("r %d, g %d, b %d",red->value(),green->value(),blue->value());
	color->setBackgroundColor(QColor(red->value(),green->value(),blue->value()));
}

void QColorPickerDlg::setColor(const QColor& c,bool)
{
//UTIL_Slider::setValue(int) 无效果
	red->QSlider::setValue(c.red());
	green->QSlider::setValue(c.green());
	blue->QSlider::setValue(c.blue());
#ifndef NO_EZX	
	//red->reallyMoveSlider(c.red());
	//green->reallyMoveSlider(c.green());
	//blue->reallyMoveSlider(c.blue());
#endif //NO_EZX					
}

QColor QColorPickerDlg::getColor() const
{
	//hsv
 	return QColor(red->value(),green->value(),blue->value(),QColor::Rgb); 
}

QColor QColorPickerDlg::getColorDirect(QWidget* p,const QColor& cl)
{
	QColor c=cl;
	QColorPickerDlg* dlg=new  QColorPickerDlg(p,cl);
	if(dlg->exec()==QDialog::Accepted)
		c=dlg->getColor();
	
	delete dlg;
	return c;
}


