#ifndef QREGVALIDATOR_H
#define QREGVALIDATOR_H

#include <qregexp.h>
#include <qvalidator.h>
#include <limits.h>
#include <math.h>


class Q_EXPORT QRegExpValidator : public QValidator
{
    //Q_OBJECT
    // Q_PROPERTY( QRegExp regExp READ regExp WRITE setRegExp )

public:
    QRegExpValidator(QWidget *parent,const char *name = 0 )
    	: QValidator(parent, name ),r( QString::fromLatin1(".*")) {};
    QRegExpValidator(const QRegExp& rx,QWidget *parent,const char *name=0)
		: QValidator( parent, name ), r( rx ) {};
    ~QRegExpValidator() {};

    virtual QValidator::State validate( QString& input, int& pos ) const
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

	void setRegExp( const QRegExp& rx ) { r = rx;};
	const QRegExp& regExp() const { return r; }
private:
#if defined(Q_DISABLE_COPY)
    QRegExpValidator( const QRegExpValidator& );
    QRegExpValidator& operator=( const QRegExpValidator& );
#endif
    QRegExp r;
};

#endif //QREGVALIDATOR_H

