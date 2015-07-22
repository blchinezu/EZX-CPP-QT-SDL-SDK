// ZDateTimePicker.h,
// from libezxappbase.so, A1200e,
// by hutu_cn@qq.com, 2008-05-03

#ifndef Z_DATETIMEPICKER_H
#define Z_DATETIMEPICKER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qdatetime.h> 
#include <qstring.h>
#include <qwidget.h>
#include <ZBaseDialog.h>

class ZDatePicker : public QWidget 
{
  Q_OBJECT

public:
  enum WeekStart {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
  
  ZDatePicker(QDate dt, bool showWeek, WeekStart weekstart, int fromYear, int toYear, QWidget *parent,char  const*name, uint flag);
  ZDatePicker(QWidget *parent,char  const*name, uint );
  ~ZDatePicker();
  
  int calculateWeekNumber(QDate);

  QDate getDate(void);
  QString getMonthName(int);
  int getWeek(void);
  void showYear(void);
  
public slots: 
  void slotDatePicked(int,int);
  void slotMonthChanged(int,int);
  void slotNextYear(void);
  void slotNextYearOnly(void);
  void slotPrevYear(void);
  void slotPrevYearOnly(void);
  void slotShowMonth(void);
  void updateWeekNumbers(void);

  void slotHourDown(void);
  void slotHourUp(void);
  void slotMinuteDown(void);
  void slotMinuteUp(void);
  void slotSwitchAMPM(void);
  
private:
  char tmp[256]; // sorry for the ugly-trick, who can tell me how to get the REAL data-members? 
};

class ZDatePickerDialog: public ZBaseDialog 
{
  Q_OBJECT
public:
  
  ZDatePickerDialog(QDate dt,bool bShowWeek,ZDatePicker::WeekStart weekstart, int fromYear, int toYear, QWidget *parent=NULL,char  const* name=NULL,uint wflag=0);
  ZDatePickerDialog(QWidget *parent=NULL,char  const* name=NULL,uint wFlag=0);
    
  ~ZDatePickerDialog(void);
    
  QDate getDate(void);
  int getWeek(void);
  void init(void);

private:
  char tmp[256];
};

class ZTimePicker : public QWidget 
{
  Q_OBJECT
public:
  enum TimeAccuracy {minute,hour};
  enum TimeFormat {clock24,clock12};
  
  ZTimePicker(QTime t, TimeAccuracy ta, TimeFormat tf, QWidget *parent, char  const* name, uint flag);
  ZTimePicker(QWidget *parent,char const* name, uint flag);
  
  ~ZTimePicker();
  
  void displayAMPM(void);
  void displayHour(void);
  void displayMinute(void);
  
  QTime getTime(void);
private:
  char tmp[256];
};

class ZTimePickerDialog: public ZBaseDialog 
{
  Q_OBJECT
public:
  ZTimePickerDialog(QTime t, ZTimePicker::TimeAccuracy ta, ZTimePicker::TimeFormat tf, QWidget *parent=NULL,char  const* name=NULL,uint wFlag=0);
  ZTimePickerDialog(QWidget *parent=NULL,char  const* name=NULL, uint wFlag=0);
    
  ~ZTimePickerDialog(void);
    
  QTime getTime(void);
  void init(void);
private:
  char tmp[256];
};

#endif  // Z_DATETIMEPICKER_H 

