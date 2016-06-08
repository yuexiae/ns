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

#ifndef NISCRIPTREADER_H
#define NISCRIPTREADER_H

#include "NiPluginToolkitLibType.h"
#include <NiRefObject.h>
#include <NiSmartPointer.h>

class NiScriptInfo;
class NiString;

/// The interface for the parser of ScriptInfo objects from character strings.
/// This interface is the counterpart of the ScriptWriter interface.
class NIPLUGINTOOLKIT_ENTRY NiScriptReader: public NiRefObject
{
public:
    /// Takes an input character script and creates the ScriptInfo object
    /// from it.
    virtual NiScriptInfo* Parse(const char* pcScript, NiString& strErrors) = 0;

    /// Returns the file extensions that this reader can support
    virtual NiString GetFileExtensions() = 0;
};

NiSmartPointer(NiScriptReader);

#endif  // #ifndef NISCRIPTREADER_H
