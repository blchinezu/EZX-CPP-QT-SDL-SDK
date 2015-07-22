//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_GROUPLISTSCROLLVIEW_H
#define AM_GROUPLISTSCROLLVIEW_H

#include <qlistview.h>

class AM_GroupListScrollViewItem :public QListViewItem
{
	Q_OBJECT
public:
	AM_GroupListScrollViewItem(QString, QListView* parent, QString const&, QCheckListItem::Type=QCheckListItem::CheckBox);
	virtual ~AM_GroupListScrollViewItem();
	
private:
			
};

class AM_Folder;

class AM_GroupListScrollView :public QListView
{
	Q_OBJECT
public:
	AM_GroupListScrollView(QList<AM_Folder>, QString, QWidget* parent=0);
	virtual ~AM_GroupListScrollView();
	
	QString getSelectedGroup();	
	
public slots:
	void slotClicked(QListViewItem*);
	
private:
			
};

#endif //AM_GROUPLISTSCROLLVIEW_H

