//generated by genheader.sh write by wangbin
/********************************************************
**libezxaddrbk.so.1.0.0
**2010年 05月 01日 星期六 12:31:05 CST
*************************************************************/
/*!

	libezxtapi.so
libezxappsdk.so.1
libezxmystuff-play.so.1
libezxsendmail.so.1
libezxsort.so
libezxphone.so.1
libezxcalendarengine.so.1
libezximagebase.so.1
libezxdrmclibhack.so.1
libezxdrmcipher.so.1
libezxdrmsp.so.1
libezxaddrbkeng.so.1
libezxappbase.so.1
libqte-mt.so.2
libpthread.so.0
libstdc++.so.5
libm.so.6
libgcc_s.so.1
libc.so.6
libezxaddrbk.so.1
-lezxtapi -lezxmystuff-play -lezxsendmail -lezxsort -lezxphone -lezxcalendarengine -lezximagebase -lezxdrmclibhack -lezxdrmcipher -lezxdrmsp -lezxaddrbkeng -lezxaddrbk -ldmnative -lezx_mp_utility -lezxsound -lezxshare -lezxam -lezxicalendar -lezxalarmserver -lezxaschangelog -lezxdsreportchange -lezxmime -lezx_mp_playerengine -lezxworldcity -lezxdb2 -lezxflex -lezxdrmsecuretime -lcipci -lezx-cmseccert -lezx_mpsdk_ringtone -lezxssl -lezxmidi -lipp-codecAC -lipp-codecSC -laacplusdec -lipp-ac -lipp-sc -lezxappsdk -lipp-jp -lezxopenwindow -lipp-miscGen -lezxappbase -lqte-mt -lezxjpeg -lezxpm
*/
#ifndef ADDRBK_SELECTDLG_H
#define ADDRBK_SELECTDLG_H

#include <ZBaseDialog.h>

class ADDRBK_SelectDlg :public ZBaseDialog
{
public:
	enum ContentType { Type0, Type1, Type2, Type3 };
	
	void accept();
	void setLimit(int);
	ADDRBK_SelectDlg(ADDRBK_SelectDlg::ContentType, QWidget* parent=0, char const* name=0, bool mode=0, unsigned int flag=0);
	~ADDRBK_SelectDlg();
private:
	char a[256];
	
};

#endif //ADDRBK_SELECTDLG_H

