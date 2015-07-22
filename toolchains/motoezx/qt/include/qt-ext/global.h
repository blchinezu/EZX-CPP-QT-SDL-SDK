#ifndef GLOBAL_H
#define GLOBAL_H
//#include <qglobal.h>

#if defined(linux) || defined(__linux) || defined(__linux__)
#define _OS_LINUX_
#elif defined(__CYGWIN__)
#define _OS_CYGWIN_
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define _OS_WIN32_
#elif defined(MSDOS) || defined(_MSDOS) || defined(__MSDOS__)
#define _OS_MSDOS_
#endif


#if (__GNUC__ < 4)
#   if QT_VERSION >= 0x040000
#   define EZXT_QT4
#   define NO_EZX
#   endif
#else
#   define EZXT_QT4 (QT_VERSION >= 0x040000)
#   define NO_EZX (QT_VERSION >= 0x040000)
#endif

#ifdef EZXT_QT4
#include <QtGui/QApplication>
#include <QColorGroup>
#include <QDebug>
#include <QDesktopWidget> //QApplication::desktop()
#include <QMouseEvent>
#   define QT_NO_RICHTEXT
#   define QWMatrix QMatrix
//#   define WFLAGS Qt::Dialog|Qt::WindowStaysOnTopHint
#   define WFlags Qt::WindowFlags
#   define QPopupMenu QMenu
//#   define Q3ListView Q3ListView
#   define ezDebug(s) qDebug()<<s
#else
#   define MyQListViewItem QListViewItem
#   define Q3ListView QListView
#   define Q3ListViewItem UTIL_ListViewItem
#include <qapplication.h>
# ifdef NO_EZX
# else
#include <ZApplication.h>
# endif //NO_EZX
#define ezDebug(s) qDebug(s)
#endif //EZXT_QT4


#ifndef NO_EZX
#   define EZ_BaseDialog(parent,name,flag) ZBaseDialog(parent,name,flag)
#   define EZ_Dialog(dt,hastitle,parent,name,modal,flag) UTIL_Dialog(dt,hastitle,parent,name,modal,flag)
#   define EZ_ListView(parent,args...) QListView(parent,##args)
//#   define EZ_ListViewItem(parent,x) Q3ListViewItem(parent,x)
#   define EZ_ListViewItem(parent,afterOrLabel,x,labels...) Q3ListViewItem(parent,afterOrLabel,x,## labels)
#   define EZ_UPushButton(act_pix,nor_pix,text,parent,flag,w,h) UTIL_PushButton(act_pix,nor_pix,text,parent,flag,w,h)
#   define EZ_PushButton(sid_icon,text,parent,flw...) ZPushButton(sid_icon,text,parent,## flw)
//#define addWidget(item,fr,fc,rspan,cspan,align) addMultiCellWidget(item,fr,fc,fr+rspan-1,fc+cspan-1,align)
//confilct
//#   define addItem(item,fr,fc,rspan,cspan,align...) addMultiCell(item,fr,fr+rspan-1,fc,fc+cspan-1,## align)
//#   define addLayout(layout,fr,fc,rspan,cspan,align...) addMultiCellLayout(layout,fr,fr+rspan-1,fc,fc+cspan-1,## align)
#else
#   define ZApplication QApplication
#   define ZBaseDialog QDialog
#   define UTIL_Dialog QDialog
#   define MyQListViewItem Q3ListViewItem
#   define UTIL_PushButton QToolButton
#   define ZPushButton QPushButton
#   define EZ_BaseDialog(parent,name,flag) ZBaseDialog(parent,flag)
#   define EZ_Dialog(dt,hastitle,parent,name,modal,flag) UTIL_Dialog(parent,flag)
#   define EZ_ListView(parent,...) Q3ListView(parent)
//#   define EZ_ListViewItem(parent,x) Q3ListViewItem(parent)
#   define EZ_ListViewItem(parent,afterOrLabel,x,labels...) Q3ListViewItem(parent,afterOrLabel,## labels)
#   define EZ_UPushButton(act_pix,nor_pix,text,parent,name,w,h) UTIL_PushButton(parent)
#   define EZ_PushButton(sid_icon,text,parent,...) ZPushButton(text,parent)
#ifndef QT3_SUPPORT
#   define insertStringList(strList) addItems(strList)
#   define setMaxValue(max) setMaximum(max)
#   define addMultiCellWidget(widget,fr,tor,fc,toc,align...) addWidget(widget,fr,fc,tor-fr+1,toc-fc+1,## align)
#   define addMultiCell(item,fr,tor,fc,toc,align...) addItem(item,fr,fc,tor-fr+1,toc-fc+1,## align)
#endif //QT3_SUPPORT
#endif //NO_EZX
#include <stdio.h>
#define ZDEBUG(fmt,args...) printf("line: %d, function: %s, file: %s\n"fmt"\n",__LINE__,__FUNCTION__,__FILE__,## args)

#define SCREEN_W QApplication::desktop()->width()
#define SCREEN_H QApplication::desktop()->height()


#endif // GLOBAL_H
