#include "qregvalidator.h"
#if !CONFIG_QT4
#include <limits.h>
#include <math.h>

QRegExpValidator::QRegExpValidator(QWidget *parent,const char *name )
	: QValidator(parent, name ),r( QString::fromLatin1(".*"))
{};

QRegExpValidator::QRegExpValidator(const QRegExp& rx,QWidget *parent,const char *name)
	: QValidator( parent, name ), r( rx )
{};

QRegExpValidator::~QRegExpValidator() {};

QValidator::State QRegExpValidator::validate( QString& input, int& pos ) const
{
//not sure
	int len;
	int p=r.match(input,0,&len);
	if ( p ) {
		return Acceptable;
	} else {
		if ( len == (int) input.length() ) {
			return Intermediate;
		} else {
			pos = input.length();
			return Invalid;
		}
	}
}

void QRegExpValidator::setRegExp( const QRegExp& rx )
{
	r = rx;
};

const QRegExp& QRegExpValidator::regExp() const {
	return r;
}

#endif //CONFIG_QT4
