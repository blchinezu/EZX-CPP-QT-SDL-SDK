//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_FOLDER_H
#define AM_FOLDER_H
#include <AM_AppObject.h>

class AM_Folder :public AM_AppObject
{
public:
	AM_Folder();
	virtual ~AM_Folder();
	
	virtual AM_RESULT_CODE_T createObject(QMap<QString, QString> const&);
	void makeNewRecord(QMap<QString, QString>&);
	virtual int getAppPosition(AM_AppObject const*);
	virtual void add(AM_AppObject const*, int position);
	virtual AM_RESULT_CODE_T dump();
	virtual AM_RESULT_CODE_T init();
	virtual AM_RESULT_CODE_T clear();
	virtual AM_RESULT_CODE_T remove(AM_AppObject const*);
	
	void getAppList(QList<AM_AppObject>&) const;
	virtual bool isEmpty() const;
	
private:
    AM_Folder(const AM_Folder & rhs);
    AM_Folder & operator=(const AM_Folder & rhs);
    
private:
	int m_position;
	//QList<AM_AppObject> m_appList; 
};

#endif //AM_FOLDER_H

