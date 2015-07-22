/*
 * minimalist ZScrollView header
 */

#if !defined(__ZSCROLLVIEW_H__)
#define __ZSCROLLVIEW_H__

#include <qscrollview.h>

class ZScrollView : public QScrollView  
{
    Q_OBJECT
public:
    ZScrollView(QWidget* parent = 0, const char* name = 0, WFlags f = 0);
    virtual ~ZScrollView();
    virtual void addChild(QWidget* w, int x, int y);
    virtual void addChild(QWidget* w, int x, int y, bool b);
};

#endif /* !defined(__ZSCROLLVIEW_H__) */
