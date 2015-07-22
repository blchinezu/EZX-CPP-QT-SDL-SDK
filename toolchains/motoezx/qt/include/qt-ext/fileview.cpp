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
//rename to QFileListView. Options new remove etc
//addItem(int col,int row,int strech)
//qmap<QString path,int index> an item is unselected, the last item of _selections drawDetail

#include "fileview.h"
#include "global.h"
#include <qheader.h>
#include <ezxres.h>
#include <UTIL_ListViewItem.h>
#include <qdir.h>
#include <qfileinfo.h>
#include <qfontmetrics.h>
#include <ZApplication.h>
//const QString head[]={"Name","Size","Time","Permision"}; //time: last read/modified
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

QString size2Str(uint s)
{
	QString unit="b";
	float v=(float)s;
	if(v>1024.) {
		v/=1024;
		unit="Kb";
	}
	if(v>1024.) {
		v/=1024;
		unit="Mb";
	}
	return QString().sprintf("%.2f",v)+unit;
}

QString dateTime2String(const QDateTime& dt,const QString& sep="-")
{
	return QString::number(dt.date().year())+sep+QString::number(dt.date().month()) \
	+sep+QString::number(dt.date().day())+" "+dt.time().toString();
}

void mode_to_letters(int mode,char str[])
{
	strcpy(str,"----------");
	if(S_ISDIR(mode)) str[0] = 'd';
	if(S_ISCHR(mode)) str[0] = 'c';
	if(S_ISBLK(mode)) str[0] = 'b';
	if(S_ISFIFO(mode)) str[0] = 'p';
	if(S_ISLNK(mode)) str[0] = 'l';
	if(S_ISSOCK(mode)) str[0] = 's';
 
	if( mode & S_IRUSR ) str[1] = 'r';
	if( mode & S_IWUSR ) str[2] = 'w';
	if( mode & S_IXUSR ) str[3] = 'x';
	if( mode & S_IRGRP ) str[4] = 'r';
	if( mode & S_IWGRP ) str[5] = 'w';
	if( mode & S_IXGRP ) str[6] = 'x';
	if( mode & S_IROTH ) str[7] = 'r';
	if( mode & S_IWOTH ) str[8] = 'w';
	if( mode & S_IXOTH ) str[9] = 'x';
}

char * uid_to_name(uid_t uid)
{
	static char numstr[10];
	struct passwd * pw_ptr;
	if((pw_ptr = getpwuid(uid)) == NULL) {
		sprintf(numstr,"%d",uid);
		return numstr;
	}
	else return pw_ptr->pw_name;
}

char * gid_to_name(gid_t gid)
{
	struct group * grp_ptr;
	static char numstr[10];
	if((grp_ptr = getgrgid(gid))==NULL) {
		sprintf(numstr,"%d",gid);
		return numstr;
	} else {
		return grp_ptr->gr_name;
	}
}
/**
**/

	
QString FileViewItem::key(int column,bool ascending) const //用于排序
{
	if(column==0) return QString::null;
	return QListViewItem::key(column,ascending);
}
	
void FileViewItem::setFileSize(uint s)
{
	_size=size2Str(s);
}

void FileViewItem::setFileTime(const QDateTime& dt)
{
	_time=dateTime2String(dt);
}

void FileViewItem::setFileInfo(const QFileInfo& fi)
{
	_name=fi.fileName(); //text(0);
	_size=size2Str(fi.size());
	_time=dateTime2String(fi.lastModified());
	_path=fi.absFilePath();
	
	char str[11];
	struct stat info;
	if(stat(_path.local8Bit(),&info)!=-1) {
		mode_to_letters(info.st_mode,str);
		_uid=uid_to_name(info.st_uid);
		_gid=gid_to_name(info.st_gid);
	}
	else perror(_path.local8Bit());
	_perm=QString(str);
}

void FileViewItem::drawSimple()
{
	if(_mode==Simple) return;
	//setText(0,_oldText0);
	setText(1,_oldText1);
	
	_mode=Simple;
	
	//QFontMetrics fm(QFont());
	int h=30;//height()/4;//QMAX(12,pixmap(0)->height())+2*listView()->itemMargin();
	setHeight(h);

	repaint();
}

void FileViewItem::drawDetail()
{
	if(_mode==Detail1Col) return;
	//_oldText0=text(0);
	_oldText1=text(1);
	_details=_perm+" "+_uid+":"+_gid+"\n"+_size+" "+_time;
	//setText(0,_oldText0+"\n"+_details);  //text(0) 与setDir相关，不能改变
	setText(1,_oldText1+"\n"+_size);
	
	_mode=Detail1Col;
	
	//QFontMetrics fm(QFont());
	int h=50;//height()*4;//QMAX(36,pixmap(0)->height())+2*listView()->itemMargin();;
	setHeight(h);
	
	repaint();
}

void FileViewItem::paintCell(QPainter *p,const QColorGroup &cg,int column,int width,int align)
{
	if(_mode!=Detail1Col) {
		UTIL_ListViewItem::paintCell(p,cg,column,width,align);
		return;
	}
	
	if ( !p ) return;

	QFont font=QFont();
	QListView *lv = listView();
	int r = lv ? lv->itemMargin() : 1;
	int marg = lv ? lv->itemMargin() : 1;
	
	int h=0;
	if(column>0) {
		UTIL_ListViewItem::paintCell(p,cg,column,width,align);
		return;
	}
	
	h=0;
	if ( isSelected() && (column==0 || listView()->allColumnsShowFocus()) ) {
		p->fillRect( r - marg, h, width - r + marg, height(), cg.brush( QColorGroup::Highlight ) );
		p->setPen( cg.highlightedText() );
    } else {
		p->setPen( cg.text() );
    }
	
	const QPixmap * icon = pixmap( column );
	if ( icon ) {
		p->drawPixmap( r, (height()-icon->height())/2, *icon);
		r += icon->width() + listView()->itemMargin();
    }
	
	if ( !_name.isEmpty() ) {
		if (!(align & AlignTop | align & AlignBottom))
            align |= AlignVCenter;
		
		font.setPointSizeFloat(height()*3/7);
		p->setFont(font);
        p->drawText( r, h, width-marg-r, height()/2, align, _name );
    }
	
	h+=height()/2;
	
	if(!(align & AlignTop | align & AlignBottom))
		align |= AlignVCenter;
	p->setPen(darkRed);
		
	font.setPointSizeFloat(height()/4);
	p->setFont(font);
	p->drawText( r, h, width-marg-r, height()/2, align, _details );
}
	
/*
	listview
*/
FileView::FileView(const QString& namefilter,int filter,QWidget *p,int sort,const char* name,WFlags f)
	:QListView(p,name,f),Filter(filter),Sort(sort),FolderOnly(false),NameFilter(namefilter),vmode(Detail1Col)
{
	//Filter= QDir::All | QDir::Hidden | QDir::System ;//| QDir::Dirs; 
	//if(!FolderOnly) Filter |= QDir::Dirs;
	//Sort=QDir::Name | QDir::DirsFirst | QDir::IgnoreCase ;
	
#ifndef NO_EZX
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
#else
	jar_xpm = QPixmap("res/jar.png").isNull() ? txt_xpm : QPixmap("res/jar.png");
	jpg_xpm = QPixmap("res/jpg.png").isNull() ? txt_xpm : QPixmap("res/jpg.png");
	pf_xpm = QPixmap("res/pf.png").isNull() ? txt_xpm : QPixmap("res/pf.png");
	dir_xpm = QPixmap("res/dir.png").isNull() ? txt_xpm : QPixmap("res/dir.png");
	mp3_xpm = QPixmap("res/mp3.png").isNull() ? txt_xpm : QPixmap("res/mp3.png");
	avi_xpm = QPixmap("res/avi.png").isNull() ? txt_xpm : QPixmap("res/avi.png");
	txt_xpm = QPixmap("res/txt.png").isNull() ? txt_xpm : QPixmap("res/txt.png");
	script_xpm = QPixmap("res/script.png").isNull() ? txt_xpm : QPixmap("res/script.png");
	mmc_xpm = QPixmap("res/mmc.png").isNull() ? txt_xpm : QPixmap("res/mmc.png");
#endif
	doc_xpm=QPixmap("res/doc.png").isNull() ? txt_xpm : QPixmap("res/doc.png");
	pdf_xpm=QPixmap("res/pdf.png").isNull() ? txt_xpm : QPixmap("res/pdf.png");
	excel_xpm=QPixmap("res/excel.png").isNull() ? txt_xpm : QPixmap("res/excel.png");
	chr_xpm=QPixmap("res/chr.png").isNull() ? txt_xpm : QPixmap("res/chr.png");
	lnk_xpm=QPixmap("res/lnk.png").isNull() ? txt_xpm : QPixmap("res/lnk.png");
	fifo_xpm=QPixmap("res/fifo.png").isNull() ? txt_xpm : QPixmap("res/fifo.png");
	sock_xpm=QPixmap("res/sock.png").isNull() ? txt_xpm : QPixmap("res/sock.png");
	blk_xpm=QPixmap("res/blk.png").isNull() ? txt_xpm : QPixmap("res/blk.png");
	
	//for(int i=0;i<4;i++) addColumn(head[i]);
	addColumn("Name");
	//if(!FolderOnly) addColumn("Size");
	//如何判断只显示dir?
	if(Filter==QDir::Dirs || Filter==(QDir::Dirs |QDir::Hidden)){
		qDebug("Dirs only");
		FolderOnly=true;
	}else if(vmode==Normal || vmode==DetailMultiCols) {
		addColumn("Size");
	} else {
		printf("vs-w: %d\n",verticalScrollBar()->width()); //100
		if(p!=0) setColumnWidth(0,p->width()-24);
	}
	header()->hide();
	
	connect(this,SIGNAL(clicked(QListViewItem*,const QPoint&,int)),SLOT(itemClicked(QListViewItem*,const QPoint&,int))); //测试各个信号
	connect(this,SIGNAL(pressed(QListViewItem*,const QPoint&,int)),SLOT(itemPressed(QListViewItem*,const QPoint&,int)));
	connect(this,SIGNAL(currentChanged(QListViewItem*)),SLOT(itemHighlighted(QListViewItem*)));
	//connect(this,SIGNAL(currentChanged(QListViewItem*)),SLOT(updateSelections(QListViewItem*)));
	
	setSelectionMode(Multi);
	setAllColumnsShowFocus(true);
}

FileView::~FileView()
{
	ZDEBUG();
	//delete _lastItem;
}

void FileView::popupMenu()
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
		
	struct stat info;
	if(stat(file.local8Bit(),&info)!=-1) {
		if(S_ISCHR(info.st_mode)) return chr_xpm;
		if(S_ISBLK(info.st_mode)) return blk_xpm;
		if(S_ISFIFO(info.st_mode)) return fifo_xpm;
		if(S_ISLNK(info.st_mode)) return lnk_xpm;
		if(S_ISSOCK(info.st_mode)) return sock_xpm;
		//if(S_ISDIR(info.st_mode)) return dir_xpm;
	}
	
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
	
	//const QFileInfoList *
	list=*dir.entryInfoList(NameFilter,Filter,Sort);
	QFileInfoListIterator it( list );      // create list iterator
	QFileInfo *fi;
    
	while((fi=it.current())) {
		QString file=fi->fileName();
		if((file!= ".")&&(file!= "..")) {
			//qDebug(d+ d.right(1)=="/" ? "" : "/"+file);
			bool is_dir=QFileInfo(fi->absFilePath()).isDir();
			if(!is_dir && FolderOnly) break;
			_lastItem=new FileViewItem(this,file,FolderOnly ? QString::null : (is_dir ? QString::null : QString::number(fi->size())));
			_lastItem->setPixmap(0,getFileXpm(fi->absFilePath()));
			_lastItem->setFileInfo(*fi);
			_lastItem->setText(3,size2Str(fi->size()));
			_lastItem->setText(4,dateTime2String(fi->lastModified()));
		}
		++it;
		//qApp->processEvents();
	}
	setSorting(0,false);  //Folder first sorting
	folder=dir.absPath();
}

void FileView::itemPressed(QListViewItem* item,const QPoint&,int)
{
	qDebug("selected "+QString::number(isSelected(item)));
	if(!item) return;

	if(isSelected(item)) {
		((FileViewItem*)item)->drawDetail();
		_selections<<((FileViewItem*)item)->path();
	} else {
		((FileViewItem*)item)->drawSimple();
		_selections.remove(((FileViewItem*)item)->path());
	}
	path= (folder=="/") ? "/"+item->text(0) : folder+"/"+item->text(0);
	qDebug("pressed: "+path);
	
}

void FileView::itemClicked(QListViewItem* item,const QPoint& pos,int)
{
	if(!item) return;

	//path= (folder=="/") ? "/"+item->text(0) : folder+"/"+item->text(0);  //hightlight first, so we can remove this line
	if(QFileInfo(path).isSymLink()) { qDebug("SymLink"); }//path=QFileInfo(path).readLink(); }
	qDebug("clicked: "+path);
	for ( QStringList::Iterator it = _selections.begin(); it != _selections.end(); ++it ) {
            printf( "%s <<", (*it).latin1() );
        }
	ZDEBUG();
	if(mapFromGlobal(pos).x()<parentWidget()->width()/5) {
		
		return;
	} else {
		//setSelectionMode(Extended);
		clearSelection();
		setSelected(item,true);//setCurrentItem(item); //
		((FileViewItem*)item)->drawDetail();
		//setSelectionMode(Multi);
		
		_selections.clear();
		_selections<<((FileViewItem*)item)->path();

		
		if(mapFromGlobal(pos).x()>parentWidget()->width()*4/5) return; //不进入目录
	}
	if(QFileInfo(path).isDir()) setDir(path);
	
	
}

void FileView::itemHighlighted(QListViewItem* item)
{
	if(_lastItem==item) return;
	_lastItem->drawSimple();
	_lastItem=(FileViewItem*)item;
	_lastItem->drawDetail();
}

void FileView::updateSelections(QListViewItem* item)
{
	if(item->isSelected()) 
		_selections+=((FileViewItem*)item)->path();
	else
		_selections.remove(((FileViewItem*)item)->path());
		
}
