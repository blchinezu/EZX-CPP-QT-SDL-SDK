//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_CARRIER_INFO_H
#define AM_CARRIER_INFO_H
#include <qobject.h>

class AM_Carrier_Info : public QObject
{
	Q_OBJECT
public:
	AM_Carrier_Info(QObject* parent=0);
	virtual ~AM_Carrier_Info();
	
	QString getInfoString();
	AM_RESULT_CODE_T updateInfoString(QString);
	
	AM_RESULT_CODE_T setIcons();

signals:
	void signalStrUpdate(QString);
	
public slots:
	void slotUpdateInfoString();	
	
};

#endif //AM_CARRIER_INFO_H

