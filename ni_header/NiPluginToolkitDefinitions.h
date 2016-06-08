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

#ifndef NIPLUGINTOOLKITDEFINITIONS_H
#define NIPLUGINTOOLKITDEFINITIONS_H

#include "NiPluginToolkitLibType.h"
#include <NiSystem.h>
#include <NiRTTI.h>

extern NIPLUGINTOOLKIT_ENTRY const unsigned int INVALID_INDEX;
#define MAX_STRING_SIZE 5000

typedef HWND NiWindowRef;
typedef HINSTANCE  NiInstanceRef;
typedef HMODULE NiModuleRef;

enum ReturnCode
{
    UNKNOWN_ERROR = -1,
    SUCCESS = 1,
    FILE_NOT_FOUND,
    DIRECTORY_NOT_FOUND,
    FILE_PARSE_ERROR,
    NO_READER_FOR_FILE,
    NO_WRITER_FOR_FILE,
    IO_FAILURE,
    SCRIPT_OF_SAME_NAME_ALREADY_EXISTS,
    NULL_INPUT_SCRIPT,
    SCRIPT_IGNORED,
    CANCELLED,
    NO_SCRIPTS_FOUND
};

enum NiPluginToolkitRenderer
{
    RENDER_UNKNOWN = -1,
    RENDER_DX8 = 0,
    RENDER_PS2,
    RENDER_GAMECUBE,
    RENDER_XBOX,
    RENDER_HURRICANE,
    RENDER_DX9,
    RENDER_MAX
};

#ifdef _DEBUG
    #if (_MSC_VER == 1310) //VC7.1
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC71D"  
    #elif (_MSC_VER == 1300) //VC7.0
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC70D"  
    #elif (_MSC_VER == 1200) //VC6.0
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC60D"  
    #endif
#else 
    #if (_MSC_VER == 1310) //VC7.1
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC71"  
    #elif (_MSC_VER == 1300) //VC7.0
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC70"  
    #elif (_MSC_VER == 1200) //VC6.0
        #define NIPLUGINTOOLKIT_MODULE_NAME "NiPluginToolkit12VC60"  
    #endif
#endif
extern HMODULE gs_hNiPluginToolkitHandle;

inline bool NiIsKindOfStringMatch(const char* pcClassName, const NiRTTI* pkRTTI)
{
    if (pcClassName == NULL)
        return false;

    if (pkRTTI != NULL)
    {
        if (stricmp(pkRTTI->GetName(), pcClassName) == 0)
            return true;
        return NiIsKindOfStringMatch(pcClassName, pkRTTI->GetBaseRTTI());

    }
    return false;
};

#endif