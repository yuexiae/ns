// NUMERICAL DESIGN LIMITED PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Numerical Design Limited and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1996-2004 Numerical Design Limited.
//      All Rights Reserved.
//
// Numerical Design Limited, Chapel Hill, North Carolina 27514
// http://www.ndl.com

#ifndef NIPLUGINMANAGER_H
#define NIPLUGINMANAGER_H

#include "NiPluginToolkitLibType.h"
#include "NiPluginToolkitDefinitions.h"
#include <NiRTTI.h>
#include "NiTPtrSet.h"
#include "NiBatchExecutionResult.h"
#include "NiScriptInfo.h"
#include "NiImportPlugin.h"
#include "NiExportPlugin.h"
#include "NiViewerPlugin.h"

/// The manager of all exporter, importer, and processing plugins.
class NIPLUGINTOOLKIT_ENTRY NiPluginManager
{
public:
    NiDeclareRootRTTI(NiPluginManager);

    /// The public singleton creator.
    static void CreateInstance();

    /// The public singleton destroyer.
    static void DestroyInstance();
    
    /// The public singleton accessor.
    /// @return A pointer to the one and only instance of the class or
    ///         NULL if no instance exists.
    static NiPluginManager* GetInstance();

    /// Adds a DLL and registers all of its plugins with the plugin manager.
    bool AddLibrary(NiString strPath);
 
    /// Adds an data plugin to the manager.
    virtual void AddPlugin(NiPlugin* pkPlugin);

    /// Add a script directory and all of the scripts in it
    virtual void AddPluginDirectory(const char* pcPath, bool bRecurse = true,
        bool bSilentRunning = false);

    /// Executes a ScriptInfo on a SharedDataList.
    virtual NiBatchExecutionResultPtr ExecuteScript(NiScriptInfo* pkScript, 
        bool bRememberAsLastExecutedScript = true);

    /// Gets the file type strings handled by the import plugins.
    void GetImportStrings(NiTArray<NiString>& kFileDescriptorStrings,
        NiTArray<NiString>& kFileTypeStrings);

    /// Gets the file type strings handled by the export plugins.
    void GetExportStrings(NiTArray<NiString>& kFileDescriptorStrings,
        NiTArray<NiString>& kFileTypeStrings);

    /// Gets the last NiScriptInfo executed by the manager
    static NiScriptInfo* GetLastExecutedScript();

    /// Gets the list of all known NiPlugin objects
    NiTPtrSet<NiPluginPtr>& GetAllPlugins();

    /// Get the plugin by class name
    NiPlugin* GetPluginByClass(NiString strClass);

    /// Get the plugin by name
    NiPlugin* GetPluginByName(NiString strPlugin);

    /// Get the plugin at index uiIndex in the list of plugins
    NiPlugin* GetPluginAt(unsigned int uiIndex);

    /// Get the plugin's index in the master list
    unsigned int GetPluginIndex(NiString strClass);

    /// Get total plugin count
    unsigned int GetTotalPluginCount();

    /// Does this plugin have the ability to provide GUI to manage its values?
    bool HasManagementDialog(NiPluginInfo* pkPluginInfo);

    /// Do the management dialog for the input NiPluginInfo
    bool DoManagementDialog(NiPluginInfo* pkInitialInfo, NiWindowRef hWndParent);

    /// Verify that this ScriptInfo object is capable of being executed
    bool VerifyScriptInfo(NiScriptInfo* pkInfo);

    /// Get the NiPlugin matching this NiPluginInfo object
    NiPlugin* GetMatchingPlugin(NiPluginInfo* pkInfo, unsigned int uiStartIdx = 0);


protected:
    /// Protected default constructor. This is protected to enforce the
    /// Singleton pattern.
    NiPluginManager();

    /// Protected copy constructor. This is protected to enforce the
    /// Singleton pattern.
    NiPluginManager(NiPluginManager&){}

    /// Protected virtual destructor. This is protected to enforce the
    /// Singleton pattern.
    virtual ~NiPluginManager();

    /// The singleton instance.
    static NiPluginManager* ms_pkThis;

    /// The last used script info object
    static NiScriptInfoPtr ms_spCurrentScriptInfo;

    /// Adds an importer to the manager.
    bool AddImporterPlugin(NiImportPlugin* pkImporter);
    
    /// Adds an exporter to the manager.
    bool AddExporterPlugin(NiExportPlugin* pkExporter);

    /// Adds an viewer to the manager.
    bool AddViewerPlugin(NiViewerPlugin* pkViewerer);

    /// The current set of HMODULE handles to DLLs controlled by the manager.
    NiTPtrSet<NiModuleRef> m_kDLLHandles;

    /// The current set of import plug-ins controlled by the manager.
    NiTPtrSet<NiImportPluginPtr> m_kImportPlugins;
    
    /// The current set of export plug-ins controlled by the manager.
    NiTPtrSet<NiExportPluginPtr> m_kExportPlugins;

    /// The current set of viewer plug-ins controlled by the manager.
    NiTPtrSet<NiViewerPluginPtr> m_kViewerPlugins;

    /// The current set of process plug-ins controlled by the manager.
    NiTPtrSet<NiPluginPtr> m_kProcessPlugins;

    /// A set containing pointers to all the plug-ins controlled by the
    /// manager. Each plugin will only appear in this list once. This set is
    /// used by the plugin manager when executing NiScriptInfo objects.
    NiTPtrSet<NiPluginPtr> m_kAllPlugins;
};

#endif  // #ifndef NIPLUGINMANAGER_H
