//generated by genheader.sh write by wangbin
/********************************************************
**libezxaddrbk.so.1.0.0
**2010年 05月 01日 星期六 12:31:05 CST
*************************************************************/
/*!
	通讯录单选
	如何返回信息?

*/
#ifndef ADDRBK_PHONECALLDLG_H
#define ADDRBK_PHONECALLDLG_H

#include <ZBaseDialog.h>

class ADDRBK_UI_ListViewItem;

class ADDRBK_PhoneCallDlg :public ZBaseDialog
{
public:
	//void setContent(QList<ADDRBK_SELECT_INFO_T>&);
	void setSelected(int);
	void processIMChange(QCString const&, QArray<char> const&);
	
	void showMenu(int, ADDRBK_UI_ListViewItem*, QPoint const&);
	ADDRBK_PhoneCallDlg(QWidget* parent=0, char const* name=0, bool x=true, unsigned int flag=0);
	~ADDRBK_PhoneCallDlg();

public slots:
	void slotCategoryChanged();
	
private:
	char a[256];
	
};

#endif //ADDRBK_PHONECALLDLG_H

