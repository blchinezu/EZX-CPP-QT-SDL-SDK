#ifndef UTIL_SPINBUTTON_H
#define UTIL_SPINBUTTON_H

#include "UTIL_PushButton.h"

class UTIL_SpinButton :public UTIL_PushButton
{
	Q_OBJECT
public:
	UTIL_SpinButton(QWidget *parent=0,char const* name=0);

	bool spined();
	~UTIL_SpinButton();
	
public slots:
	void slotHolding();
	void slotPressed();
	void slotReleased();
	void slotStartHolding();

};

#endif //UTIL_SPINBUTTON_H

