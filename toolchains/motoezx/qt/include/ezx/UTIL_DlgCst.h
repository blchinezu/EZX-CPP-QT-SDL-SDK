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
	//dctOK: ��ʾһ��[ȷ��]��ť
	//dctOKCancel: ��ʾһ���Եȴ�С��[ȡ��][ȷ��]��ť
	//dctBigOKSmallCancel: ��ʾһ���˵���ť��С��[ȡ��],ʣ��ռ���ʾ[ȷ��]��ť
	//dctBigOKCancelCustom: ��ʾһ���˵���ť��С��[ȡ��]��[�հ�]��ť,�м�ʣ��ռ���ʾ[ȷ��]��ť
	//dctOKCancelCustom: ��ʾһ���Եȴ�С��[ȡ��][ȷ��][�հ�]��ť
	//dctSmallCancelOKCustom: ��ʾһ���˵���ť��С��[ȡ��],ʣ��ռ���ʾ�Եȴ��[ȷ��]��[�հ�]��ť
	
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

