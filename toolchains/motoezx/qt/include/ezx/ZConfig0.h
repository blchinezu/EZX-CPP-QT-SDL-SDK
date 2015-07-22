#ifndef _ZCONFIG_H_
#define _ZCONFIG_H_ 

class ZConfig
{
public:
    int writeEntry(const QString&, const QString&, char*);
    int writeEntry(const QString&, const QString&, const QStringList&, const QChar&);
    int writeEntry(const QString&, const QString&, const QString&);
    int writeEntry(const QString&, const QString&, bool);
    int writeEntry(const QString&, const QString&, double);
    int writeEntry(const QString&, const QString&, int);
    int writeEntry(const QString&, const QString&, unsigned);
    int readNumEntry(const QString&, const QString&, int);
    int readBoolEntry(const QString&, const QString&, bool);
    int readListEntry(const QString&, const QString&, const QChar&);
    int readUIntEntry(const QString&, const QString&, unsigned);
    int readEntryDirect(const QString&, const QString&, const QString&);
    int getGroupsKeyList(QStringList&);
    int getSettingDirectory(void);
    int initSettingDirectory(void);
    int getGroupEntriesKeyList(const QString&);
    int read(void);
    int write(const QString&);
    int setGroup(const QString&);
    int parseLine(const QString&);
    int readEntry(const QString&, const QString&, const QString&);
    
    ZConfig(const QString& , bool);
    bool changed();
    virtual ~ZConfig(); 
    virtual int removeEntry(const QString&, const QString&);
    virtual int clearGroup(const QString&);
    virtual int flush();
    
protected:
    
private:
    void* ConfigData;
};

#endif
