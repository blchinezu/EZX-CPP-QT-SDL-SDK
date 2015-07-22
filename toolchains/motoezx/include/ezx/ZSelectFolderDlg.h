/*
    Lib: ezxmystuff_fmsdk,ezxam,dmnative,ezxmystuff-play,ezx_mp_utility,ezximagebase,ezxsound,
         ezxphone,ezxdrmsp,ezx_mp_playerengine,ezxdrmcipher,ezx-cmseccert,ezxtapi,ezxssl,
         ezxdrmsecuretime,cipci,ezxsendmail,ezxsort,ezxshare

    ruthfox(foxe6) and dnxh add
    2008-1-11

    ruthfox@163.com
*/

#ifndef _ZSELECTFOLDERDLG_H_
#define _ZSELECTFOLDERDLG_H_

#include <ZBaseDialog.h>

class ZSelectFolderDlg: public ZBaseDialog  //fox size: $FC?, $D4
{
    Q_OBJECT
public:
    ZSelectFolderDlg(const QString&); //�������ݸ�MYSTUFF_FixedFolder::getPathByKey(const QString&)
    ~ZSelectFolderDlg(void);

    QString getSelected(QString* FileName);    //����ѡ����ļ��е�ȫ����. FileName: �����ļ�������,����·��,����Ϊ��

public slots:
    void slotCancel(void);
    void slotNewFolder(const QString&);
    void slotHotPlugUpdateMainWindow(const QCString&, const QByteArray&);
    void slotNewWg(void);

private:
    bool UD4;
    QString UD8;
    ZPushButton* UDC;
    ZPushButton* UE0;
    ZPushButton* UE4;
    int UE8; // MYSTUFF_TreeView_UI* UE8; //MYSTUFF_TreeView_UI size=$F0
    int UEC; // MYSTUFF_NewFolder_WidgetUI* UEC; //size = $FC
    QLabel* UF0;
    QWidget* UF4;
    QWidget* UF8;
};

#endif
