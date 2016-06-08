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
#ifndef NISCRIPTMANAGEMENTDIALOG_H
#define NISCRIPTMANAGEMENTDIALOG_H

#include "NiDialog.h"
#include "NiScriptInfo.h"
#include "NiScriptInfoSet.h"

class NIPLUGINTOOLKIT_ENTRY NiScriptManagementDialog : public NiDialog
{
    public:
        NiScriptManagementDialog(NiModuleRef hInstance, NiScriptInfo* pkInfo,
            NiScriptInfoSet* pkInfoSet, NiWindowRef hWndParent,
            const char* pcTypes);
        ~NiScriptManagementDialog();

        void AddScriptsToComboBox(int iComboBoxID);
        void AddPluginTypesToTabControl(int iTabID);
        void PopulatePluginsList(int iListID, NiScriptInfo* pkInfo);
        void AddTypesToComboBox(int iComboBoxID);

        virtual void InitDialog();
        virtual BOOL OnCommand(int iWParamLow, int iWParamHigh, long lParam);
        virtual BOOL OnMessage(unsigned int uiMessage, int iWParamLow, 
                         int iWParamHigh, long lParam);
        virtual void OnDestroy();
        virtual void OnClose();

        enum TabOption
        {
            ALL_PLUGINS = 0,
            IMPORT_PLUGINS,
            EXPORT_PLUGINS,
            PROCESSOR_PLUGINS,
            VIEWER_PLUGINS,
            NUM_TABS
        };

        NiString MakePluginString(NiPluginInfo* pkInfo);
        void SaveScript(NiScriptInfo* pkInfo, bool bPromptLocation);
        void RenameScript(NiScriptInfo* pkInfo);
        void EditPlugin(NiScriptInfo* pkInfo);
        void AddPlugin(NiScriptInfo* pkInfo);
        void RemovePlugin(NiScriptInfo* pkInfo);
        void MovePluginUp(NiScriptInfo* pkInfo);
        void MovePluginDown(NiScriptInfo* pkInfo);
        void ScriptChange();
        void TabChange();
        void RemoveScript();
        void AddScript();
        void NewScript(bool bFromTemplate);
        void NewScriptFromTemplate();
        void NewBlankScript();
        void VerifyStates();
        void PromptForSave();
        void AddPluginsToKnownPluginsList(int iListIDd);
        void ViewDescription();
        
        NiScriptInfoPtr m_spInfo;
        NiScriptInfoPtr m_spOriginalInfo;
        NiScriptInfoSetPtr m_spScriptSet;
        TabOption m_eTabOption;
        NiString m_strTypes;
        NiTArray<NiString> m_kScriptTypes;

        int m_idReturnState;
        NiScriptInfoSetPtr m_spRemovedScripts;
};

#endif