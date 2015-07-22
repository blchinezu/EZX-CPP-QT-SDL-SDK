/*
    Lib: ezxmystuff_fmsdk,ezxam,dmnative,ezxmystuff-play,ezx_mp_utility,ezximagebase,ezxsound,
         ezxphone,ezxdrmsp,ezx_mp_playerengine,ezxdrmcipher,ezx-cmseccert,ezxtapi,ezxssl,
         ezxdrmsecuretime,cipci,ezxsendmail,ezxsort,ezxshare
         -lezxappsdk -lipp-jp -lezxopenwindow -lipp-miscGen -lezxappbase -lqte-mt -lezxjpeg -lezxpm -lezxmystuff_fmsdk -lezxmystuff-play -lezxam -ldmnative -lezxmystuff-play -lezx_mp_utility -lezximagebase -lezxsound -lezxphone -lezxdrmsp -lezx_mp_playerengine -lezxdrmcipher -lezx-cmseccert -lezxtapi -lezxssl -lezxdrmsecuretime -lcipci -lezxsendmail -lezxsort -lezxshare
    hutu_cn@qq.com, 2008-4-25
*/
#ifndef _ZOPENDLG_H_
#define _ZOPENDLG_H_
#include <ZBaseDialog.h>
#include <qlistbox.h>  // add by yan0
class ZPushButton;

class ZOpenDlg: public ZBaseDialog 
{
  Q_OBJECT
public:
	ZOpenDlg(QStringList &filetypes, const QString &defaultPathKey, bool multiselect); 
	~ZOpenDlg(void);

	QString getFile() const;
	static QStringList getFileList();  
        
	void upDateContent(void);
	void upDateCst(void);
	void upDateTitle(void);
	void setUpData(void);

public slots:
        void slotCancel(void);
        void slotHighlighted(QListBoxItem *);
        void slotHotPlugUpdateMainWindow(QCString  const&,QArray<char>  const&);
//        void slotMouseButtonClicked(int,MYSTUFF_IconView_Item *,QPoint  const&);
//        void slotMouseButtonClicked(int,QListBoxItem *,QPoint  const&);
//        void slotTreeMouseButtonClicked(MYSTUFF_TreeView_Item *); 

private:
        char tmp[256];
};
#endif //_ZOPENDLG_H_

