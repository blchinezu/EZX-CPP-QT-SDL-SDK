//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone

	
not tested
*************************************************************/
#ifndef AM_SECURITYMANAGER_H
#define AM_SECURITYMANAGER_H
#include <AM_Defs.h>

class AM_SecurityManager
{
public:
	AM_SecurityManager();
	~AM_SecurityManager(); //not virtual
	
	AM_RESULT_CODE_T verifySecurity(QString const&, char*, int*, int*);
	AM_RESULT_CODE_T parseSignedFile(QString const&);
	AM_RESULT_CODE_T verifySecurityByLaunch(QString const&, char*, int*);
	AM_RESULT_CODE_T verifySecurityByInstall(QString const&, QString&);
	
private:
	
};

#endif //AM_SECURITYMANAGER_H

