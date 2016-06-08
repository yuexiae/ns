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

#ifndef NIVIEWERPLUGININFO_H
#define NIVIEWERPLUGININFO_H

#include "NiPluginInfo.h"
#define VIEWER_PLUGIN_TYPE "NiPluginToolkit Renderer"

/// The container for all script-relevant information about a specific plugin.
class NIPLUGINTOOLKIT_ENTRY NiViewerPluginInfo : public NiPluginInfo
{
public:
    NiDeclareRTTI;

    /// Default constructor.
    NiViewerPluginInfo();

    /// Default constructor.
    NiViewerPluginInfo(NiPluginToolkitRenderer eRenderer);

    /// Virtual destructor.
    virtual ~NiViewerPluginInfo(){}

    /// Make a deep copy of the the plugin info
    virtual NiPluginInfo* Clone(NiPluginInfo* pkClone);

    /// Does the input script equal the current plugin
    virtual bool Equals(NiPluginInfo* pkInfo);

    /// Get the renderer for this object.
    NiPluginToolkitRenderer GetRenderer() const;

    /// Set the renderer for this object.
    void SetRenderer(NiPluginToolkitRenderer eRenderer);
};

NiSmartPointer(NiViewerPluginInfo);

#endif  // #ifndef NIVIEWERPLUGININFO_H
