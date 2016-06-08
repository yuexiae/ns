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

#ifndef NIPLUGINDLLINTERFACE_H
#define NIPLUGINDLLINTERFACE_H

#include "NiTPtrSet.h"
#include "NiPlugin.h"

#ifdef NIPLUGINDLL_EXPORT
    // DLL library project uses this
    #define NIPLUGINDLL_ENTRY __declspec(dllexport)
#else
    // client of DLL uses this
    #define NIPLUGINDLL_ENTRY __declspec(dllimport)
#endif

// All DLLs containing NiPlugins must implement these functions.
extern "C" NIPLUGINDLL_ENTRY void GetPlugins(
    NiTPtrSet<NiPluginPtr>& kPluginArray);
extern "C" NIPLUGINDLL_ENTRY unsigned int GetCompilerVersion(void);

typedef void (*NiGetPluginsFunction)(NiTPtrSet<NiPluginPtr>&);
typedef unsigned int (*NiGetCompilerVersionFunction)(void);

#endif  // #ifndef NIPLUGINDLLINTERFACE_H
