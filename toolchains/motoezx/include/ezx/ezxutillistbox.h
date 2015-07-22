#if !defined(__EZX_UTIL_LISTBOX_H__)
#define __EZX_UTIL_LISTBOX_H__

#include <qlist.h>
#include <qlistbox.h>

class ItemInfo;

class UTIL_ListBoxItem : public QListBoxItem {

public:
	UTIL_ListBoxItem(QListBox *parent, QString caption, bool radio=true);

	QPixmap itemPixmap(void);
	QString getItemType(void);
	bool setMaxLines(int);
	unsigned int getReservedData(void);
	void setReservedData(unsigned int);
	QFont font(void);
	bool isOn(void);
	int state(void);
	bool isDown(void);
	bool setFont(QFont const&);
	void setLink(QColor const&, bool);
	QString itemText(void);
	QPixmap getPixmap(int);
	QString getString(int);
	bool isChecked(void);
	void setActive(void);
	void setPixmap(int, QPixmap const&);
	void setString(int, QString const&);
	int getMaxLines() const;
	int perfectWidth(QListBox const*) const;
	int perfectHeight(QListBox const*) const;

	virtual ~UTIL_ListBoxItem();
	virtual QString text() const;
	virtual int height(QListBox const*) const;
	virtual int width(QListBox const*) const;
	virtual void paint(QPainter*);
	virtual void setText(QString const&);
	virtual void drawCheckboxButton(QPainter*, int, int&);
	virtual void drawRadioboxButton(QPainter*, int, int&);
	virtual void drawUnderLine(QPainter*, QPoint const&, QPoint const&);


	QList<ItemInfo>		m_list20;
	int			m_unk40;
	int			m_state44;
	bool			m_b48;
	int			m_unk4c;
	int			m_unk50;
	unsigned int		m_resdata54;
	QFont			m_font58;
	bool			m_b60;
	int			m_maxlines64;
	bool			m_b68;
	QColor			m_color6c;
	int			m_unk74;

	// 0x78
};


typedef QList<UTIL_ListBoxItem> UTIL_ListBoxItemList;

class UTIL_ListBox : public QListBox {
	Q_OBJECT
 public:
	void removeItem(int);
	void selectBtns(UTIL_ListBoxItem*);
	void updateItem(QListBoxItem*);
	bool itemChecked(int);
	bool itemChecked(UTIL_ListBoxItem*);
	UTIL_ListBoxItemList *itemsChecked(void);
	virtual void keyPressEvent(QKeyEvent*);
	virtual void mouseMoveEvent(QMouseEvent*);
	virtual void mousePressEvent(QMouseEvent*);
	void sendItemPackage(QListBoxItem*);
	virtual void mouseReleaseEvent(QMouseEvent*);
	void init(QString, QWidget*, unsigned int);
	void clear(void);
	void checkItem(int, bool);
	void checkItem(UTIL_ListBoxItem*, bool);
	virtual void paintCell(QPainter*, int, int);

	/*
	 * This constructor sets the widget's name to "ezx_util_list".
	 */
	UTIL_ListBox(QString, QWidget*, unsigned int);

	UTIL_ListBox(QWidget *parent = NULL, unsigned int f = 0);
	virtual ~UTIL_ListBox();

	int		m_ie0;
	int		m_ie4;
	char		m_ie8;
	QString		m_strec;
};

#endif  /* !defined(__EZX_UTIL_LISTBOX_H__) */
