#ifndef UTIL_DATETIME_H
#define UTIL_DATETIME_H

//2010.01.27 nukin create

class UTIL_DateTime
{
	Q_OBJECT
public:

	typedef enum DateFormat {
		unkonwn
	};
	
	typedef enum DateAccuracy {
		year, month, week, day
	};
	
	typedef enum TimeFormat {
		clock24,
		clock12
	};   //refrence to ZTimePicker
	
	typedef enum TimeAccuracy {
		second, minute, hour
	};
	 
	UTIL_DateTime(QObject *,char  const*)
	QString dateToString(QDate  const&,UTIL_DateTime::DateAccuracy)
	QString dateToString(QDate  const&,UTIL_DateTime::DateFormat,UTIL_DateTime::DateAccuracy)
	QString getCurrentUTC(void)
	DateFormat getDateFormat(void)
	DateFormat getDateTimeFormat(void)
	QString getTZRuleFromDstRule(QString  const&)
	TimeFormat getTimeFormat(void)
	QString getWeekdayName(int)
	QString getWeekdayShortName(int)
	bool isDateTimeChangeAllowed(void)
	void setDateFormat(UTIL_DateTime::DateFormat)
	void setTimeFormat(UTIL_DateTime::TimeFormat)
	void setTimeZoneEnv(void)
	

	QString timeToString(QTime  const&,UTIL_DateTime::TimeAccuracy)
	QString timeToString(QTime  const&,UTIL_DateTime::TimeFormat,UTIL_DateTime::TimeAccuracy)
	QString toString(QDate  const&)
	QString toString(QTime  const&)

	~UTIL_DateTime();
	
public slots:
	void slotFormatChanged(QCString  const&,QArray<char>  const&)

}

#endif //UTIL_DATETIME_H

