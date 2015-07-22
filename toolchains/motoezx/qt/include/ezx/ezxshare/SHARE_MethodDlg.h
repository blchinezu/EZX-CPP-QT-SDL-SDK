//generated by genheader.sh write by wangbin
/********************************************************
**libezxshare.so.1.0.0
**2010年 04月 07日 星期三 16:36:22 CST
*************************************************************/
//三生石 2010/8/9
#ifndef SHARE_METHODDLG_H
#define SHARE_METHODDLG_H

#include <ZBaseDialog.h>

/*用法示例：
静态函数：
	int ret = SHARE_MethodDlg::selectMethod(13);
	cout<<"the selete is : "<<ret<<endl;
非静态函数：
	SHARE_MethodDlg *dlg = new SHARE_MethodDlg( 13 );
	if (dlg->exec() == 1)
		cout<<"selete is : "<<dlg->method()<<endl;
	else
		qDebug("cancle");
	delete dlg;
*/

class SHARE_MethodDlg : public ZBaseDialog
{
	Q_OBJECT
public:
	/*
	 * methods: NONE = 0, BT = 1, EMAIL = 4, SMS = 8, ALL = 13 = BT | EMAIL | SMS
	 */
	enum {
            NONE      =  0x0000,
            BT        =  0x0001,
            IRDA      =  0x0002,
            EMAIL     =  0x0004,
            MMS       =  0x0008,
            SMS       =  0x0010,
            ALL       =  BT | IRDA | EMAIL | MMS | SMS,
            BIEM      =  BT | IRDA | EMAIL | MMS
        }; //wangbin add
	static int selectMethod(int methods, bool);
	int method();
	SHARE_MethodDlg(int methods, QWidget* parent = 0, char const* name = 0, bool x=true);
	~SHARE_MethodDlg();

private:
	char tmp[256];
};

#endif //SHARE_METHODDLG_H

