//三生石 2010/8/9
// -lezxshare-xscale-r
//shareByIrda 无效

#ifndef SHARE_TOOL_H
#define SHARE_TOOL_H

#include <qstring.h>
#include <qcstring.h>
#include <qvaluelist.h>


#define SHARE_CHANNEL_NAME               "/EZX/SHARE"
#define SHARE_MSG_BLUETOOTH              "BLUETOOTH"
#define SHARE_MSG_IRDA                   "IRDA"

//--------------------------------------------------------------------------------------------------
//                                         CLASS
//--------------------------------------------------------------------------------------------------
/**
 * Share Tool API will serve as one interface to Share Object through BlueTooth.
 * User can share images, videos, jar file, vCard, vEvent, vBookMark, vTasks etc.
 * file, after call Share API, Share will pop up one BlueTooth Device Selection 
 * Dialog to let user choose which phones he intend to send out. 
 * 
 * Currently Share only support send one session at one time. For example, if user
 * has selected send some files in FileManager to other user, if he intend to send 
 * other files in this time. Share will pop up one Error Dialog to indicate BlueTooth
 * is busy now. 
 * 
 * Share will maintain the sending and receiving file list, control the sequence 
 * of files to enable the file is sent or received one by one.
 * 
 *
 * @see
 *
 * @note
 */

/*用法示例：
	SHARE_Tool::OBJECT_INFO tmp = {"myname","text"};
	bool ret = SHARE_Tool::shareByBt(tmp, "/mmc/mmca1/123.txt" );
	注意：如果此项功能可用，返回值为true。不可用时返回false。属于异步调用方式，立刻返回而不等共享完毕。
*/

class SHARE_Tool
{
public:

        //Share method
        enum SHARE_METHOD
        {
            NONE      =  0x0000,
            BT        =  0x0001,
            IRDA      =  0x0002,
            EMAIL     =  0x0004,
            MMS       =  0x0008,
            SMS       =  0x0010,
            ALL       =  BT | IRDA | EMAIL | MMS | SMS,
            BIEM      =  BT | IRDA | EMAIL | MMS
        };

        //Share object
        struct OBJECT_INFO
        {
            QString  name;
            QString  type;
        };

        struct SHARE_OBJECT
        {
            OBJECT_INFO info;
            QString     file;
            bool        removed;
        };


     static int selectMethod(int methods, bool remove);//参考SHARE_MethodDlg.h

     static int checkBtDeviceStatus();//返回类型未确定

     /**
     * Share one file through bluetooth.
     * 
     * This method should be called if the client application can directly get
     * one file location.
     * 
     * To call this method, user should provide this file information and file
     * location, also indicate if want to remove this file after the send operation
     * is finished.
     * 
     *
     * @param info              the transfer object's information which include the
     *                          file name and file MIME type.
     * 
     * @param file              file name with full file path.
     * @param removed           True means removed after sending, False means NOT 
     *                          removed after sending.
     *
     * @return
     *
     * @see
     *
     * @note    
     *
     * @warning
     */
     static bool shareByBt(const OBJECT_INFO& info,
                           const QString& file, 
                           bool removed = false);
     /**
     * Share one file through bluetooth.
     * 
     * This method should be called if the client application can NOT directly get
     * one file location. Client Application can encapsulate the byte array and Share
     * will create one temporary file with this byte array for sending file.
     * 
     * To call this method, user should provide this file information and file data
     * array.
     * 
     *
     * @param info              the transfer object's information which include the
     *                          file name and file MIME type.
     * 
     * @param obj               file data array.
     *
     * @return
     *
     * @see
     *
     * @note    
     *
     * @warning
     */
     static bool shareByBt(const OBJECT_INFO& info, const QByteArray& obj);
     /**
     * Share mulitiple files through bluetooth.
     *
     * This method should be called if the client application can directly get
     * multiple files location.
     * 
     * To call this method, user should provide these files information and files
     * location, also indicate if want to remove thes files after the send operation
     * is finished.
     *
     * @param objList           the transfer object's information which include the
     *                          files location.
     * @return
     *
     * @see
     *
     * @note   
     *
     * @warning
     */
     static bool shareByBt(const QValueList<SHARE_OBJECT> & objList);
     /**
     * Share multiple objects through bluetooth.
     * 
     * This method should be called if the client application can NOT directly get
     * multiple files location. Client Application can encapsulate the byte array and Share
     * will create temporary files with this byte array for sending file.
     * 
     * To call this method, user should provide these files information and files data
     * array.
     *
     *
     * @param infoList          the transfer object's information which include file
     *                          name and file MIME type.
     * 
     * @param array             the data array which include all files data. Share will
     *                          depend on sizeList parameter to seperate the data array.
     * 
     * @param sizeList          the value list that contains files size information.
     *
     * @return
     *
     * @see
     *
     * @note       array size should equal to the summary of sizeList.
     *
     * @warning
     */
     static bool shareByBt(const QValueList<OBJECT_INFO>& infoList,
                           const QByteArray& array, 
                           const QValueList<int>& sizeList);

     /**
     * Share one file through Irda.
     * 
     * This method should be called if the client application can directly get
     * one file location.
     * 
     * To call this method, user should provide this file information and file
     * location, also indicate if want to remove this file after the send operation
     * is finished.
     * 
     *
     * @param info              the transfer object's information which include the
     *                          file name and file MIME type.
     * 
     * @param file              file name with full file path.
     * @param removed           True means removed after sending, False means NOT 
     *                          removed after sending.
     *
     * @return
     *
     * @see
     *
     * @note    
     *
     * @warning
     */
	static bool shareByIrda(const OBJECT_INFO& info,
	                        const QString& file, 
	                        bool removed = false);
     /**
     * Share one file through Irda.
     * 
     * This method should be called if the client application can NOT directly get
     * one file location. Client Application can encapsulate the byte array and Share
     * will create one temporary file with this byte array for sending file.
     * 
     * To call this method, user should provide this file information and file data
     * array.
     * 
     *
     * @param info              the transfer object's information which include the
     *                          file name and file MIME type.
     * 
     * @param obj               file data array.
     *
     * @return
     *
     * @see
     *
     * @note    
     *
     * @warning
     */
	static bool shareByIrda(const OBJECT_INFO& info, const QByteArray& obj);

    protected:
        static bool shareByBtIrda(SHARE_METHOD method,
                                  const QValueList<SHARE_OBJECT>& objlist);

        static QString genTmpFileName(SHARE_METHOD method, 
                                      const QString& objname, 
                                      const QString& objtype);

        static bool saveObject(const QString& file, 
                               const QByteArray& obj, 
                               int start, 
                               int size);
};

#endif // SHARE_TOOL_H

