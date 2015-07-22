//generated by genheader.sh write by wangbin

#ifndef ZSAVEDLG_H
#define ZSAVEDLG_H
#include <ZBaseDialog.h>

class ZSaveDlg: public ZBaseDialog
{
	Q_OBJECT
public:
	ZSaveDlg(QStringList&, QString const& dir);
	ZSaveDlg(QString const&, QString const&, QString const&);
	~ZSaveDlg();

	void initWidget(int);
	void raiseDialog();

	void selectFolder(QString const&);

	void exec();
	void hide();
	void init(QString const&);


	QString getSaveName();
	int result();

signals:
	void signalClose(QString const&);
	
public slots:
	void slotTextChanged();
	void slotOkButtClicked();
	void slotSelectFolderWg();	
	void slotClose();

private:
	char x[128];
	
};

#endif //ZSAVEDLG_H
