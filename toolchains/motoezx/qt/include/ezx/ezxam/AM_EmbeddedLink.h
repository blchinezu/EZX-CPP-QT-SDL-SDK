//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_EMBEDDEDLINK_H
#define AM_EMBEDDEDLINK_H
#include <AM_AppObject.h>
//class AM_LauncherInterface;

class AM_EmbeddedLink : public AM_AppObject
{
public:
	AM_EmbeddedLink();
	virtual ~AM_EmbeddedLink();
	
	virtual AM_RESULT_CODE_T createObject(QMap<QString, QString> const&);
	virtual AM_RESULT_CODE_T getInvisiblNetLinkFromDmt(QString*, QString*);
	virtual AM_RESULT_CODE_T dump();
	virtual AM_RESULT_CODE_T invoke(AM_LauncherInterface const&);
	
private:
	
};

#endif //AM_EMBEDDEDLINK_H

