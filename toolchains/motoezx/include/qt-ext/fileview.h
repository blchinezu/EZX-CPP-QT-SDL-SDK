/*********************************************************************************************
    FileView: File list view for EZX
    Copyright (C) 2010 Wangbin <wbsecg1@gmail.com>
 	(aka. nukin in ccmove & novesky in http://forum.motorolafans.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*********************************************************************************************/

#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <ZGlobal.h>
#include <qlistview.h>
#include <qfileinfo.h>
#include <qdir.h>
//#include <UTIL_ListViewItem.h>

class QListView;
//class UTIL_ListViewItem;//(bool null-key?) //seg fault
class QListViewItem;

class FileViewItem :public QListViewItem
{
public:
	FileViewItem(QListView* parent,QString label0,/*bool key,*/QString label1=QString::null,QString label2=QString::null,QString label3=QString::null, \
	QString label4=QString::null,QString label5=QString::null,QString label6=QString::null,QString label7= QString::null)
		:QListViewItem(parent,label0,/*key,*/label1,label2,label3,label4,label5,label6,label7)
	{}
	
	~FileViewItem() {};
	QString key(int column,bool ascending) const //用于排序
	{
		if(column==0) return QString::null;
		return QListViewItem::key(column,ascending);
	}
};


class FileView :public QListView
{
	Q_OBJECT
public:
	//enum FilterSpec { All=QDir::All | QDir::Hidden | QDir::System, Dir=QDir
	FileView(const QString& namefilter="*",int filter=QDir::All |QDir::Hidden |QDir::System,
	QWidget* parent=0,int sort=QDir::Name |QDir::DirsFirst |QDir::IgnoreCase,const char* name=0,WFlags f=0);
	~FileView();
	
	void setFolderOnly(bool fo) { 
		FolderOnly=fo; 
		//if(FolderOnly) Filter &= ~QDir::Dirs;
		//if(!FolderOnly) Filter |= QDir::Dirs;
	}
	void setFilter(int ft) { Filter=ft; }
	void setDir(const QString& d);// { dir=d;}
	QString getFolder() const { return folder;}
	QString getAbsPath() const { return path;} //folder or file highlighted
	//inline 
	QPixmap getFileXpm(const QString &) const ;

signals:
	void rootDir(bool);	
private:
	//QDir::FilterSpec 
	int Filter;
	//QDir::SortSpec 
	int Sort;
	bool FolderOnly;
	QString NameFilter;
	QString folder;
	QString path; //folder or file path
	QPixmap mmc_xpm, dir_xpm, jar_xpm, mp3_xpm, jpg_xpm, avi_xpm, script_xpm, txt_xpm, pf_xpm; //doc pdf excel
	FileViewItem *item;

private slots:
	void itemClicked(QListViewItem*,const QPoint&,int);
	void itemPressed(QListViewItem*,const QPoint&,int);
};

#endif //FILEVIEW_H

