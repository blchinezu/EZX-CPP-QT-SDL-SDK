//generated by genheader.sh write by wangbin
/********************************************************
**libezxaid.so.1.0.0
**2010年 06月 24日 星期四 17:07:01 CST
*************************************************************/
//--------------------------------------------------------------------------------------------------
//
//   Header Name: AM_PluginRegMgr.h
//
//   General Description: Class AM_PluginRegMgr: Manage plugins for Alarm Server
//
//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//                     Template ID and version: TMP_LFC_50115 Version 1.1
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Sheng Wenliang/w21004       02/22/2004      LIBXXXXXXX   Created
//
//
//
//--------------------------------------------------------------------------------------------------

#ifndef AM_PLUGINREGMGR_H
#define AM_PLUGINREGMGR_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

class QUuid;

class AM_PluginRegMgr
{
public:
    AM_PluginRegMgr();
    ~AM_PluginRegMgr();
    
    //static AM_PluginRegMgr * instance();
    
    /**
     * Register plugins of the application.
     *
     * @param appId application's application id.
     * 
     * @param pluginId uuid of the plugin
     *
     * @plugin the path name of the plugin, full path name.
     *
     * @return true if successful.
     */
    bool registerPlugins( const QUuid &appId, const QUuid &pluginId, const QString &plugin ) const;
    
    /**
     * Un-register plugins of the application.
     *
     * @param appId application's application id.
     * 
     * @param pluginId uuid of the plugin, if ignored all the plugins of the application are
     * un-registered.
     *
     * @return true if successful.
     */
    bool unregisterPlugins( const QUuid &appId, const QUuid &pluginId = QUuid() ) const;
    
    /**
     * Query plugin's library path and name, return full path name.
     *
     * @param appId application's application id.
     * 
     * @param pluginId uuid of the plugin.
     *
     * @param plugin returned path name of the plugin. full path name format.
     *
     * @return true if successful.
     */
    bool queryPlugins( const QUuid &appId, const QUuid &pluginId, QString &plugin ) const;

private:
    enum RegistryType
    {
        SysPluginRegistry = 0,
        UsrPluginRegistry = 1
    };

    QString getConfigFileName( const RegistryType type ) const;
};

#endif
