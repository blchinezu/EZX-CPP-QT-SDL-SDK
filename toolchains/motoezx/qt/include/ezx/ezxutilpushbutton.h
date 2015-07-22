#if !defined(__EZX_UTIL_PUSHBUTTON_H__)
#define __EZX_UTIL_PUSHBUTTON_H__

#include <qtoolbutton.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qrect.h>
#include <qpixmap.h>

class UTIL_DirectPixmap;

class UTIL_PushButton : public QToolButton {
	Q_OBJECT
public:
	virtual void drawButton(QPainter*);
	virtual void paintEvent(QPaintEvent*);
	virtual void setPalette(QPalette const&);
	void setDisabled(QPixmap const&);
	virtual void setGeometry(int, int, int, int);
	virtual void setGeometry(QRect const&);
	void popupPressed(void);
	void setResourceID(QString const&);
	virtual void setMinimumSize(int, int);
	void setActiveOverlay(QPixmap const&);
	void setNormalOverlay(QPixmap const&);
	void setDisabledOverlay(QPixmap const&);
	void setTransparencyPercent(int);
	void init(QPixmap const&, QPixmap const&, QPixmap const&,
		  QPixmap const&, QString const&, QPixmap const&,
		  QPixmap const&, int, int, int);
	void init(QString const&, QString const&, int, int, int);
	virtual void polish(void);
	void reload(void);
	virtual void resize(int, int);
	void resize(QSize const&);
	void setFlag(int);
	virtual void setText(QString const&);
	void setFlags(int);
	void setPopup(QPopupMenu*);
	void setActive(QPixmap const&);
	void setNormal(QPixmap const&);

	UTIL_PushButton(QWidget*, int, int, int);
	UTIL_PushButton(QPixmap const&, QPixmap const&,
			QString const&, QWidget*, int, int, int);
	UTIL_PushButton(QPixmap const&, QPixmap const&,
			QString const&, QPixmap const&, QWidget*,
			int, int, int);
	UTIL_PushButton(QPixmap const&, QPixmap const&, QPixmap const&,
			QPixmap const&, QPixmap const&, QPixmap const&,
			QWidget*, int, int, int);
	UTIL_PushButton(QString const&, QWidget*, int, int, int);
	UTIL_PushButton(QString const&, QString const&, QWidget*,
			int, int, int);
	virtual ~UTIL_PushButton();

	QPixmap drawActive() const;
	QPixmap drawNormal() const;
	QString resourceID() const;
	QPixmap activePixmap() const;
	QPixmap normalPixmap() const;
	QPixmap activeOverlay() const;
	QPixmap normalOverlay() const;
	QPixmap disabledOverlay() const;
	QPixmap disabledPixmap() const;
	QPixmap activeOverlayPixmap() const;
	QPixmap normalOverlayPixmap() const;
	QPixmap disabledOverlayPixmap() const;
	void dim1(UTIL_DirectPixmap&, int, int, int) const;
	void dim2(UTIL_DirectPixmap&, int, int, int) const;
	void dim3(UTIL_DirectPixmap&, int, int, int) const;
	void dim4(UTIL_DirectPixmap&, int, int, int) const;
	void dim5(UTIL_DirectPixmap&, int, int, int) const;
	QPixmap fade(QPixmap const&) const;
	QString text() const;
	int flags() const;
	QPixmap active() const;
	QPixmap normal() const;
	QPixmap disabled() const;
	void drawGrad(UTIL_DirectPixmap&, int, int, int, int,
		      QColor const&, QColor const&) const;
	virtual QSize sizeHint(void) const;
	void drawHLine(UTIL_DirectPixmap&, int, int, int, QColor const&) const;
	void drawVLine(UTIL_DirectPixmap&, int, int, int, QColor const&) const;

	static int defaultWidth;
	static int defaultHeight;
	static int multSixTenths;
	static int minWidth;
	static int minHeight;

	/*
	 * There is apparently a weirdo gap between the last
	 * incomplete word of QToolButton and the first fields
	 * of this structure that would not otherwise be filled
	 * in if the members were not smaller than a word.
	 */

	bool		m_b_109;
	bool		m_b_10a;

	// 0x10c

	int		m_unk_10c;
	int		m_unk_110;

	QString		m_string_114;
	QPixmap		m_pix118;
	QPixmap		m_pixmap_12c;
	QPixmap		m_pixmap_140;
	QPixmap		m_pixmap_154;
	QString		m_string_168;
	QPixmap		m_pixmap_16c;
	QPixmap		m_pixmap_180;
	int		m_unk_194;
	QPixmap		m_pixmap_198;
	QPixmap		m_pixmap_1ac;
	int		m_unk_1c0;
	bool		m_b_1c5;
	int		m_b_1c8;

	// 0x1cc
};

#endif  /* !defined(__EZX_UTIL_PUSHBUTTON_H__) */
