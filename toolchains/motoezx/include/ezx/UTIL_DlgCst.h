/*
	ruthfox(foxe6) add. 
	2008.1.5
	
	EMail: ruthfox@163.com
*/

#ifndef _UTIL_DLGCST_H_
#define _UTIL_DLGCST_H_

class ZPushButton;

class UTIL_DlgCST : public QWidget  //fox size: $D0, $C4 
{
	Q_OBJECT

public:
	enum DlgCstType{dctOK, dctOKCancel, dctBigOKSmallCancel, dctBigOKCancelCustom, dctOKCancelCustom, dctSmallCancelOKCustom};
	//dctOK: 显示一个[确认]按钮
	//dctOKCancel: 显示一个对等大小的[取消][确认]按钮
	//dctBigOKSmallCancel: 显示一个菜单按钮大小的[取消],剩余空间显示[确认]按钮
	//dctBigOKCancelCustom: 显示一个菜单按钮大小的[取消]和[空白]按钮,中间剩余空间显示[确认]按钮
	//dctOKCancelCustom: 显示一个对等大小的[取消][确认][空白]按钮
	//dctSmallCancelOKCustom: 显示一个菜单按钮大小的[取消],剩余空间显示对等大的[确认]和[空白]按钮
	
	UTIL_DlgCST(QWidget* Parent, UTIL_DlgCST::DlgCstType DlgType);

	ZPushButton *getBtn1(void);
	ZPushButton *getBtn2(void);
	ZPushButton *getBtn3(void);

private:
	ZPushButton *btn1;  //fox: C4
	ZPushButton *btn2;  //fox: C8
	ZPushButton *btn3;  //fox: CC

};
#endif

