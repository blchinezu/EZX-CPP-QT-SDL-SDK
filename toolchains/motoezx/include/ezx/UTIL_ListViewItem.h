#ifndef _UTIL_LISTVIEWITEM_H_
#define _UTIL_LISTVIEWITEM_H_
//nukin 20091123

class UTIL_ListViewItem : public QListViewItem
{
public:
	UTIL_ListViewItem(QListView *parent,QString=QString::null,bool no_sort=true,QString=QString::null,QString=QString::null, \
	QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null);
	UTIL_ListViewItem(QListView *parent,UTIL_ListViewItem* after,QString=QString::null,bool=true,QString=QString::null, \
	QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null);
	UTIL_ListViewItem(QListView *parent,UTIL_ListViewItem* after,bool);
	UTIL_ListViewItem(QListView *parent,bool);
	UTIL_ListViewItem(UTIL_ListViewItem* after,QString,bool,QString,QString,QString,QString,QString,QString,QString);
	//Constructs a new list view item that's a child of the QListViewItem parent, after item after, with at most 8 constant strings as contents.
	UTIL_ListViewItem(UTIL_ListViewItem* parent,UTIL_ListViewItem* after,QString=QString::null,bool=true,QString=QString::null, \
	QString=QString::null,QString=QString::null,\
	QString=QString::null,QString=QString::null,QString=QString::null,QString=QString::null);
	
	UTIL_ListViewItem(UTIL_ListViewItem* parent,UTIL_ListViewItem* after,bool=true);
	UTIL_ListViewItem(UTIL_ListViewItem* parent,bool=true);
	virtual void drawUnderLine(QPainter *,QColorGroup  const&,QPoint  const&,QPoint  const&);
/********************************************************************************************************************************************************
Paints a set of branches from this item to (some of) its children.
p is set up with clipping and translation so that you can draw only in the rectangle you need to; cg is the color group to use; the update rectangle is at 0, 0 and has size w, h.\
 The top of the rectangle you own is at y (which is never greater than 0 but can be outside the window system's allowed coordinate range).
The update rectangle is in an undefined state when this function is called; this function must draw on all of the pixels.
**************************************************************************************************************************************************************/
	virtual void paintBranches(QPainter *p,QColorGroup  const& cg,int w,int y,int h,Qt::GUIStyle);
	
/**********************************************************************************************************************************************************************
This virtual function paints the contents of one column of one item.

p is a QPainter open on the relevant paint device. p is translated so 0, 0 is the top left pixel in the cell and width-1, height()-1 is the bottom right pixel in the 
cell. The other properties of p (pen, brush etc) are undefined. cg is the color group to use. column is the logical column number within the item that is to be painted;
 0 is the column which may contain a tree
****************************************************************************************************************************************/
	virtual void paintCell(QPainter *p,QColorGroup  const& cg,int column,int width,int align);
	void setBranch(bool);

};

#endif  //_UTIL_LISTVIEWITEM_H_
