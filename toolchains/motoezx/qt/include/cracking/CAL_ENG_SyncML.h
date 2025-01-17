//generated by genheader.sh write by wangbin
/********************************************************
**libezxcalendarengine.so.1.0.0
**2010年 04月 17日 星期六 13:52:08 CST
*************************************************************/
#ifndef CAL_ENG_SYNCML_H
#define CAL_ENG_SYNCML_H

class CAL_ENG_SyncML
{
public:
	void removeEvent(unsigned int const&);
	void updateEvent(std::string const&, unsigned int const&);
	void translateRet(ZCalendarResult_T);
	void endSync();
	void addEvent(std::string const&, unsigned int&);
	void getEvent(std::string&, unsigned int const&, CAL_VCAL_FORMAT_T);
	void beginSync();
	void getAllIDs(std::vector<unsigned int, std::allocator<unsigned int> >&);
	void removeAll();
	CAL_ENG_SyncML();
	~CAL_ENG_SyncML();
	
};

#endif //CAL_ENG_SYNCML_H

