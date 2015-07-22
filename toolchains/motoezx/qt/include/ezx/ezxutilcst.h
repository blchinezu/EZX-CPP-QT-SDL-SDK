#if !defined(__EZX_UTIL_CST_H__)
#define __EZX_UTIL_CST_H__

#include <qstring.h>
#include <ZPushButton.h>
#define EZX_CST_BTN_MENU QString("CST_Menu")
#define EZX_CST_BTN_EXIT QString("CST_Exit")
#define EZX_CST_BTN_BACK QString("CST_Back")

/*

*/

class QPopupMenu;
class UTIL_CST : public QWidget //fox size: D4, C4
{
	Q_OBJECT

public:
	UTIL_CST(QWidget *mainWidget, QString middleButton=QString(), QString leftButton = EZX_CST_BTN_MENU, QString rightButton = EZX_CST_BTN_EXIT);
		 
//	virtual ~UTIL_CST();  //fox removed

	ZPushButton *getLeftBtn(void);
	ZPushButton *getMidBtn(void);
	ZPushButton *getRightBtn(void);
	bool getQuickExit();
	
public slots:
	void blockSignals(bool);
	
	void setQuickExit(bool);  //fox: true时创建一个PopupMenu,并创建一个退出的MenuItem与Application.quit()关联,菜单并分配给RightButton;
	
private:
	ZPushButton *LeftButton;  //fox: $C4
	ZPushButton *MidButton;   //fox: $C8
	ZPushButton *RightButton; //fox: $CC
	QPopupMenu  *PopupMenu;   //fox: $D0		
};


#endif  /* !defined(__EZX_UTIL_CST_H__) */
