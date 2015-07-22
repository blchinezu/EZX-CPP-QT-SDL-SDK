#ifndef QAPPLICATION_X_H
#define QAPPLICATION_X_H
#include <ZApplication.h>

#include "../../corelib/global/qglobal_x.h"

class QApplication_X :public ZApplication {
	Q_OBJECT
public:
	QApplication_X(int &argc, char** argv, Type type=GuiClient);
	
	virtual ~QApplication_X();
};

QT_BEGIN_NAMESPACE
typedef QApplication_X QApplication;
QT_END_NAMESPACE

#endif //QAPPLICATION_X_H
