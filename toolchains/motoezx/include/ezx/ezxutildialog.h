#if !defined(__EZX_UTIL_DIALOG_H__)
#define __EZX_UTIL_DIALOG_H__

#include <ZBaseDialog.h>


class UTIL_Dialog : public ZBaseDialog  // fox size $E8, $D4 confirmed
{
        Q_OBJECT

public:
        
        /*
        enum DialogType {
                DTUnkown = 0,
        };
        */        // fixed by hutu_cn
        enum DialogType {
                DTLargeSize = 0, // LargeSize Dialog , DlgA Layout rules
                DTMiddleSize = 1, // MiddleSize, DlgB Layout rules
                DTSmallSize = 2, // SmallSize, DlgC Layout rules
        };
        QString getDlgTitle(void);
        bool getHasTitle(void);
        void setDlgTitle(QString);
        void setHasTitle(bool);
        QWidget *getDlgContent(void);
        void setDlgContent(QWidget*);
        QWidget *getDlgCst(void);
        void setDlgCst(QWidget*);

        UTIL_Dialog(UTIL_Dialog::DialogType dt,
                    bool, /*dlg title*/
                    QWidget *parent=0,
                    char const *name=0,
                    int modal=0,
                    unsigned int flags=0);

        //virtual ~UTIL_Dialog();       //fox : removed

        DialogType        m_dtype;        // fox : $D4 //���Թ��캯���еĲ���1
        bool                m_consp2;        // fox : $D8 //���Թ��캯���еĲ���2 // false: con't set dlg Title
        //bool                m_boold0;        // fox : $D9 Remove
        int             temp_consp2;    // fox : $DC add, ����ʱ��m_consp2��չ����
        QWidget                *m_qwd4;        // fox : $E0 //$C4��С��QWidget
        QWidget                *m_qwd8;        // fox : $E4 //$C4��С��QWidget
};

#endif  /* !defined(__EZX_UTIL_DIALOG_H__) */
