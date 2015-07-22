//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_APPFACTORY_H
#define AM_APPFACTORY_H
#include <AM_AppObject.h>

class AM_AppFactory :public AM_AppObject
{
public:
	AM_AppFactory();
	~AM_AppFactory();
	
	virtual AM_RESULT_CODE_T createAppObject(AM_AppObject::Type);
	
	
};

#endif //AM_APPFACTORY_H

