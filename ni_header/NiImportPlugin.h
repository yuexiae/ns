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

#ifndef NIIMPORTPLUGIN_H
#define NIIMPORTPLUGIN_H

#include "NiPluginToolkitLibType.h"
#include "NiPlugin.h"

class NiImportPluginInfo;

/// A file input/output plug-in.
class NIPLUGINTOOLKIT_ENTRY NiImportPlugin : public NiPlugin
{
public:
    NiDeclareRTTI;

    /// Constructor takes strings needed for NiPlugin constructor.
    NiImportPlugin(const char* pcName, const char* pcVersion,
        const char* pcShortDescription, const char* pcLongDescription);

    /// Virtual destructor.
    virtual ~NiImportPlugin(){}

    /// Determines whether or not this plug-in can handle this plug-in info
    /// object. This is useful for doing versioning, as it allows plug-ins
    /// to take responsiblity for executing an NiPluginInfo object
    /// arbitrarily.
    /// @return Whether or not this plug-in can handle the NiPluginInfo
    ///         object.
    virtual bool CanExecute(NiPluginInfo* pkInfo);

    /// Execute the NiPluginInfo script.
    /// @return The results of this execution.
    virtual NiExecutionResultPtr Execute(const NiPluginInfo* pkInfo);
    
    /// Determines whether or not this plug-in can handle this import plug-in
    /// info object. This function should be overridden by import plug-ins.
    /// @return Whether or not this plug-in can handle the NiImportPluginInfo
    ///         object.
    virtual bool CanImport(NiImportPluginInfo* pkInfo) = 0;

    /// Execute the NiImportPluginInfo script.
    /// @return The results of this execution.
    virtual NiExecutionResultPtr Import(const NiImportPluginInfo* pkInfo) = 0;

    /// Gets the string describing the supported file types.
    virtual const char* GetFileDescriptorString() = 0;

    /// Gets the string with the supported file type extensions.
    virtual const char* GetFileTypeString() = 0;
};

NiSmartPointer(NiImportPlugin);

#endif  // #ifndef NIIMPORTPLUGIN_H
