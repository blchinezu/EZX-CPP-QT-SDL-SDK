//generated by genheader.sh write by wangbin
/********************************************************
**libezxaid.so.1.0.0
**2010年 06月 24日 星期四 17:07:01 CST
*************************************************************/
#ifndef AM_PROGRESSDLGIMPL_H
#define AM_PROGRESSDLGIMPL_H

class AM_ProgressDlgImpl
{
public:
	void setProgress(int);
	void setAutoReset(bool);
	void setInstructText(QString const&);
	void setCancelButtonText(QString const&);
	void setProgressTotalStep(int);
	void hide();
	void show();
	void setTitle(QString const&);
	AM_ProgressDlgImpl(QWidget*, char const*, bool, unsigned int);
	AM_ProgressDlgImpl(QString const&, QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int);
	AM_ProgressDlgImpl(QWidget*, char const*, bool, unsigned int);
	AM_ProgressDlgImpl(QString const&, QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int);
	~AM_ProgressDlgImpl();
	void setProgress(int);
	void setAutoReset(bool);
	void setInstructText(QString const&);
	void setCancelButtonText(QString const&);
	void setProgressTotalStep(int);
	void hide();
	void show();
	void setTitle(QString const&);
	~AM_ProgressDlgImpl();
	
};

#endif //AM_PROGRESSDLGIMPL_H

