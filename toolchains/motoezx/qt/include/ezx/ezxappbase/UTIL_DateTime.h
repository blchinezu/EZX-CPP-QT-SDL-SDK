#ifndef UTIL_DATETIME_H
#define UTIL_DATETIME_H

//2010.01.27 nukin create
#include <qdatetime.h>
class UTIL_DateTime :public QDateTime
{
	Q_OBJECT
public:

	typedef enum DateFormat {
		unkonwn
	};
	
	typedef enum DateAccuracy {
		Year, Month, Week, Day
	};
	
	typedef enum TimeFormat {
		Clock24,
		Clock12
	};   //refrence to ZTimePicker
	
	typedef enum TimeAccuracy {
		Second, Minute, Hour
	};
	 
	UTIL_DateTime(QObject *parent=0,char const* name=0);
	QString dateToString(QDate const& date,UTIL_DateTime::DateAccuracy da=Day);
	QString dateToString(QDate const& date,UTIL_DateTime::DateFormat df=Clock24,UTIL_DateTime::DateAccuracy da=Day);
	QString getCurrentUTC();
	DateFormat getDateFormat();
	DateFormat getDateTimeFormat();
	QString getTZRuleFromDstRule(QString const&);
	TimeFormat getTimeFormat();
	QString getWeekdayName(int);
	QString getWeekdayShortName(int);
	bool isDateTimeChangeAllowed();
	void setDateFormat(UTIL_DateTime::DateFormat);
	void setTimeFormat(UTIL_DateTime::TimeFormat);
	void setTimeZoneEnv();
	

	QString timeToString(QTime const&,UTIL_DateTime::TimeAccuracy da=Day);
	QString timeToString(QTime const&,UTIL_DateTime::TimeFormat df=Clock24,UTIL_DateTime::TimeAccuracy da=Day);
	QString toString(QDate const&);
	QString toString(QTime const&);

	~UTIL_DateTime();
	
public slots:
	void slotFormatChanged(QCString const&,QByteArry const&);
	
private:
	DateAccuracy _dateAccuracy;
	DateFormat _dateFormat;
	TimeAccuracy _timeAccuracy;
	TimeFormat _timeFormat;
	QString _utc, _tzRule;

}

#endif //UTIL_DATETIME_H

