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
//rename to QFileListView

#include "fileview.h"
#include <qheader.h>
#include <ezxres.h>
#include <UTIL_ListViewItem.h>
#include <qdir.h>
#include <qfileinfo.h>
#include <ZApplication.h>
//const QString head[]={"Name","Size","Time","Permision"}; //time: last read/modified
FileView::FileView(const QString& namefilter,int filter,QWidget *p,int sort,const char* name,WFlags f)
	:QListView(p,name,f),Filter(filter),Sort(sort),FolderOnly(false),NameFilter(namefilter)
{
	//Filter= QDir::All | QDir::Hidden | QDir::System ;//| QDir::Dirs; 
	//if(!FolderOnly) Filter |= QDir::Dirs;
	//Sort=QDir::Name | QDir::DirsFirst | QDir::IgnoreCase ;
	
	RES_ICON_Reader ir;
	jar_xpm = ir.getIcon("FMMS_File_Game_S.g",true);
	jpg_xpm = ir.getIcon("FMMS_File_Image_S.g",true);
	pf_xpm = ir.getIcon("FMMS_Personal_File_S.g",true);
	dir_xpm = ir.getIcon("FMMS_Personal_Folder_S.g",true);
	mp3_xpm = ir.getIcon("FMMS_Folder_Video_S.g",true);
	avi_xpm = ir.getIcon("FMMS_Folder_Audio_S.g",true);
	txt_xpm = ir.getIcon("FMMS_Folder_Note_S.g",true);
	script_xpm = ir.getIcon("FMMS_Folder_Program_S.g",true);
	mmc_xpm = ir.getIcon("FMMS_Personal_MMC_SD.g",true);
	//for(int i=0;i<4;i++) addColumn(head[i]);
	addColumn("Name");
	//if(!FolderOnly) addColumn("Size");
	//如何判断只显示dir?
	if(Filter==QDir::Dirs || Filter==(QDir::Dirs |QDir::Hidden)){
		qDebug("Dirs only");
		FolderOnly=true;
	}else addColumn("Size");
	
	header()->hide();
	
	connect(this,SIGNAL(clicked(QListViewItem*,const QPoint&,int)),SLOT(itemClicked(QListViewItem*,const QPoint&,int))); //测试各个信号
	connect(this,SIGNAL(pressed(QListViewItem*,const QPoint&,int)),SLOT(itemPressed(QListViewItem*,const QPoint&,int)));
}

FileView::~FileView()
{}

inline QPixmap FileView::getFileXpm(const QString& file) const
{
		QString ext=QFileInfo(file).extension().upper();
		if(QFileInfo(file).isDir()){
 			if(file.length()==10 && file.left(8)=="/mmc/mmc") return mmc_xpm; //is mounted //判断次数太多
 			return dir_xpm;
 		}
 		if(ext=="JPG"||ext=="JPEG"||ext=="GIF"||ext=="PNG"||ext=="BMP"||ext=="XPM") return jpg_xpm;
 		//if(ext=="BMP") return bmp_xpm;
 		//if(ext=="PNG") return png_xpm;
 		//if(ext=="GIF") return gif_xpm;
 		if(ext=="TXT"||ext=="CFG"||ext=="INI"||ext=="CONF") return txt_xpm;
 		if(ext=="MP3"||ext=="WMA"||ext=="M4A"||ext=="AAC"||ext=="FLAC") return mp3_xpm;
 		if(ext=="LIN"||ext=="SH") return script_xpm;
 		if(ext=="JAR") return jar_xpm;
 		return txt_xpm;
}

//void int getFileType(const QString& f) //判断char-dev,pipe,socket,hardlink
void FileView::setDir(const QString& d)
{
	if(QDir(d).isRoot()) emit rootDir(true);
	else emit rootDir(false);
	
	QDir dir(d,NameFilter);
	dir.setMatchAllDirs(true);
	
	dir.setSorting(Sort);//QDir::Name | QDir::DirsFirst | QDir::IgnoreCase); //QListView::sort()后会乱次序
	dir.setFilter(Filter);//QDir::All | QDir::Hidden | QDir::System);  //若是pipe,socket,dev,setDir()出错
	
	if(!dir.isReadable()) return;
	clear();
	
	const QFileInfoList *list=dir.entryInfoList(NameFilter,Filter,Sort);
	QFileInfoListIterator it( *list );      // create list iterator
	QFileInfo *fi;
    
	while((fi=it.current())) 
	{
		QString file=fi->fileName();
		if((file!= ".")&&(file!= ".."))
		{
			//qDebug(d+ d.right(1)=="/" ? "" : "/"+file);
			bool is_dir=QFileInfo(fi->absFilePath()).isDir();
			if(!is_dir && FolderOnly) break;
			item=new FileViewItem(this,file,FolderOnly ? QString::null : (is_dir ? QString::null : QString::number(fi->size())));
			item->setPixmap(0,getFileXpm(fi->absFilePath()));
		}
		++it;
		//qApp->processEvents();
	}
	setSorting(0,false);  //Folder first sorting
	folder=dir.absPath();
}

void FileView::itemPressed(QListViewItem* itm,const QPoint&,int)
{
	if(!itm) return;
	path= (folder=="/") ? "/"+itm->text(0) : folder+"/"+itm->text(0);
	qDebug("highlighted: "+path);
}

void FileView::itemClicked(QListViewItem* itm,const QPoint&,int)
{
	if(!itm) return;

	//path= (folder=="/") ? "/"+itm->text(0) : folder+"/"+itm->text(0);  //hightlight first, so we can remove this line
	if(QFileInfo(path).isSymLink()) { qDebug("SymLink"); }//path=QFileInfo(path).readLink(); }
	qDebug("clicked: "+path);
	if(QFileInfo(path).isDir()) setDir(path);
}


