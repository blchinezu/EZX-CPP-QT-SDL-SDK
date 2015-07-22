#ifndef _ZOPENWITHDLG_H_
#define _ZOPENWITHDLG_H_

/*
    Lib: ezxmystuff_fmsdk,ezxam,dmnative,ezxmystuff-play,ezx_mp_utility,ezximagebase,ezxsound,
         ezxphone,ezxdrmsp,ezx_mp_playerengine,ezxdrmcipher,ezx-cmseccert,ezxtapi,ezxssl,
         ezxdrmsecuretime,cipci,ezxsendmail,ezxsort,ezxshare

    ruthfox(foxe6) add
    2008-6-13

    ruthfox@163.com

*/
#include <ZBaseDialog.h>

class ZOpenWithDlg: public ZBaseDialog //fox size: $118, $D4
{
	Q_OBJECT
public:
	ZOpenWithDlg(const QString&);
	~ZOpenWithDlg(void);

	void chooseProgram(void);
	void refreshUI(void);

public slots:
	//void slotSelectApp(QListBoxItem*);         //not declared in this scope
	void slotOkButtClicked(void);
	void slotCheckLabelClicked(void);

protected:
	void customEvent(QCustomEvent*);
private:
	int TempD4;
	int TempD8;
	bool TempDC;
	int TempE0;
	int TempE4;
	int TempE8;
	int TempEC;
	int TempF0;
	int TempF4;
	int TempF8;
	int TempFC;
	int Temp100;
	int Temp104;
	int Temp108;
	int Temp10C;
	int Temp110;
	int Temp114;
};

#endif
