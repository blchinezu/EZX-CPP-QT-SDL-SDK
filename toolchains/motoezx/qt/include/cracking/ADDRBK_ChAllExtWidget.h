//generated by genheader.sh write by wangbin
/********************************************************
**libezxaddrbk.so.1.0.0
**2010年 05月 01日 星期六 12:31:04 CST
*************************************************************/
#ifndef ADDRBK_CHALLEXTWIDGET_H
#define ADDRBK_CHALLEXTWIDGET_H

#include <ZMainWidget.h>

class ADDRBK_ENGINE_Category;
class ZPushButton;

class ADDRBK_ChAllExtWidget :public ZMainWidget
{
public:
	ADDRBK_ChAllExtWidget(QWidget* parent=0, char const* name=0, unsigned int flag=0);
	ADDRBK_ChAllExtWidget(QString const& title, bool all=false, QWidget* parent=0, char const* name=0, unsigned int flag=0);
	~ADDRBK_ChAllExtWidget();
	
	
	bool isCheckAll();
	void setHeadMsg(QString const&);
	ADDRBK_ENGINE_Category* getCategory();
	void setCategory(ADDRBK_ENGINE_Category*);
	void setSubContent(QWidget*);
	
	void setCategoryInfo(QString const&, bool);
	
	int getListViewHeight(bool, int);
	
	int exec();
	void hide();
	void init();
	void accept();
	void reject();
	ZPushButton* getBtn1();
	ZPushButton* getBtn2();
	ZPushButton* getBtn3();
	QWidget* getTitle();
	void selectAll(bool);
	
signals:
	//void categoryChanged(ADDRBK_CATEGORY_TYPE_T);
	
public slots:
	void slotClickFindBtn();
	void slotLoadCategory();
	void slotKbStateChanged(bool, QUuid const&, int);
	void slotCategoryMenuChosen(int);
	
	
	
};

#endif //ADDRBK_CHALLEXTWIDGET_H

