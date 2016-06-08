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

#ifndef NIEXPORTEROPTIONSSHAREDDATA_H
#define NIEXPORTEROPTIONSSHAREDDATA_H

#include <NiPluginToolkitDefinitions.h>
#include "NiStandardSharedDataLibType.h"
#include "NiSharedData.h"
#include <NiTStringMap.h>
#include <NiMain.h>
#include <NiScriptInfo.h>

/// This class contains the current information about timing
/// for the animations in the scene graph
class NISTANDARDSHAREDDATA_ENTRY NiExporterOptionsSharedData : public NiSharedData
{
    public:
        NiDeclareRTTI;
        /// Default constructor.
        NiExporterOptionsSharedData();

        /// Virtual destructor.
        virtual ~NiExporterOptionsSharedData();
        
        NiScriptInfo* GetCurrentScript();
        void SetCurrentScript(NiScriptInfo* pkInfo);

        NiPluginToolkitRenderer GetTargetPlatform();
        void SetTargetPlatform(NiPluginToolkitRenderer eTargetRenderer);
        
        bool GetViewerRun();
        void SetViewerRun(bool bViewerRun);

        bool GetStripifyForViewer();
        void SetStripifyForViewer(bool bViewerStrip);

    protected:
        NiScriptInfoPtr m_spCurrentScript;
        NiPluginToolkitRenderer m_eTargetRenderer;
        bool m_bViewerRun;
        bool m_bViewerStripify;
};


NiSmartPointer(NiExporterOptionsSharedData);

#endif  // #ifndef NIEXPORTEROPTIONSSHAREDDATA_H
