#include "qapplication_x.h"

QApplication_X::QApplication_X(int &argc, char** argv, Type type)
	:ZApplication(argc,argv,type)
{
	xdebug("Namespace X");
}

QApplication_X::~QApplication_X()
{
	xdebug("Namespace X");
}
