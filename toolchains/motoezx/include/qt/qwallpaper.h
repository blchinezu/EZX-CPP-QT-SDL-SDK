#ifndef QWALLPAPER_H
#define QWALLPAPER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//---------------------------------------------------------------------------
//                                                                    
//   Header Name: qwallpaper.h
//   General Description: functions get/set the qt wallpaper
//
//---------------------------------------------------------------------------
//
//                   Motorola Confidential Proprietary
//        Template ID and version: IL93-TMP-01-0107  Version 1.10
//         (c) Copyright Motorola 2002-2003, All Rights Reserved
//
// Revision History:
//                             Modification     Tracking
//---------------------------------------------------------------------------
// Author (core ID)                Date          Number     Changes
//
// Peter McDermott (w20027)      01/25/2004    
//
//---------------------------------------------------------------------------
//                              INCLUDE FILES
//---------------------------------------------------------------------------

#include <qpixmap.h>

//---------------------------------------------------------------------------
//2010.02.06 nukin modified.
//remove setSysWallpaperEnabled() sysWallpaperEnabled
//add enum Position and it's comment
//add setSysDialogWallpaper sysDialogWallpaper dialogWallpaper setFillColor
//correct setSysWallpaper setAppWallpaper
/****************************************
**setSysWallpaper是改变手机壁纸的另一种方法，相比Am_Global::setWallPaper(const Qstring&)
**多了2种图片填充模式，Am_Global::setWallPaper()实际相当于第一种CenterFitScreen
**setSysDialogWallpaper可以设置手机所有的对话框的背景图片，这个是安装主题达不到的效果
**setFillColor(uint) 没测试出来
**********************************************/

class QWallpaper {

public:

/*************************Position************************************
**如果图像尺寸和屏幕尺寸一致，则与Position无关
**Stretch:				取中心按比例3:4不超过图片大小的区域缩放到屏幕尺寸。
**Center:				与屏幕中心对准，原始尺寸
**Tile:					与屏幕左上角对准，原始尺寸。自动用图片填补多余空间
***********************************************************/
	enum Position
    {
        Stretch = 0,
        Center,
        Tile
    };
	
	enum Mode
    {
        UseSysWallpaper,
        UseAppWallpaper,
        Off
    };
	
    // set/get the system wallpaper
    //
    // By default, the system wallpaper points to NULL.  This has the 
    // effect of turning off wallpaper blending for all applications
    //
    
    static void setSysWallpaper(const QPixmap*,QWallpaper::Position = QWallpaper::Stretch);
    static QPixmap* sysWallpaper();

	static void setSysDialogWallpaper(const QPixmap*,QWallpaper::Position = QWallpaper::Stretch);
    static QPixmap* sysDialogWallpaper();
    //
    // enabling the system wallpaper will enable blending the system
    // wallpaper with application data
    //
    
    //static void setSysWallpaperEnabled(bool enable);
    //static bool sysWallpaperEnabled();

    //removed*******
    // set/get the application wallpaper
    //
    // By default, the application wallpaper points to NULL, which means
    // no wallpaper when you call setAppWallpaperMode(UseAppWallpaper). So
    // call setAppWallpaper() with your favorite pixmap and then call
    // setAppWallpaperMode(UseAppWallpaper)
    //
   
    // set the wallpaper mode for your application.  
    // default is UseSysWallpaper
    static void setAppWallpaperMode(Mode mode);
    static Mode appWallpaperMode();
    static void setAppWallpaper(const QPixmap*,QWallpaper::Position pos = QWallpaper::Stretch);
    static QPixmap* appWallpaper();

    //
    // get the current wallpaper. 
    //
    // Returns a pointer to the current wallpaper, whether system or 
    // application.  It returns NULL if the wallpaper is either NULL or
    // set to Off.
    //

    static QPixmap* wallpaper(); 
    static QPixmap* dialogWallpaper();
    static void setFillColor(uint);
    
};

#endif // QWALLPAPER_H

