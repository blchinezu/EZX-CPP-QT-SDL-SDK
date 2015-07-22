//generated by genheader.sh write by wangbin
/********************************************************
**libezxappsdk.so.1.0.0
**2010年 07月 07日 星期三 10:44:16 CST
*************************************************************/
#ifndef ZCAMERA_H
#define ZCAMERA_H
#include <qsize.h>

class ZCamera
{
public:
	enum DialogFunction {fun1,fun2,fun3,fun4};
	
	ZCamera(ZCamera::DialogFunction, int, QWidget* parent=0, char const* name=0, bool b1=true, bool b2=true, char const* x=0);
	~ZCamera();
	
	QString fileName();
	QString mimeType();
	int maxDataSize();
	int minDataSize();
	
	QSize photoLimitation();
	QSize videoLimitation();
	int maxPhotoResolution();
	int maxVideoResolution();
	void setFileName(QString&);
	void setPhotoLimitation(int, int);
	void setVideoLimitation(int, int);
	
	char** data();
	int exec();
};

#endif //ZCAMERA_H

