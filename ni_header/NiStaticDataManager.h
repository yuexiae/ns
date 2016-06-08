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

#ifndef NISTATICDATAMANAGER_H
#define NISTATICDATAMANAGER_H

#include "NiSystemLibType.h"
#include "NiSDMMacros.h"

#define NI_NUM_LIBRARIES 16
//---------------------------------------------------------------------------
class NISYSTEM_ENTRY NiStaticDataManager
{
public:
    static void Init();
    static void Shutdown();

    typedef void (*InitFunction)(void);
    typedef void (*ShutdownFunction)(void);

    static void SetRootLibrary(InitFunction pfnInit,
        ShutdownFunction pfnShutdown);
    static void AddLibrary(InitFunction pfnInit, 
        ShutdownFunction pfnShutdown);
    static void RemoveLibrary(InitFunction pfnInit,
        ShutdownFunction pfnShutdown);

private:
    static InitFunction ms_pfnRootInitFunction;
    static ShutdownFunction ms_pfnRootShutdownFunction;
    static InitFunction ms_apfnInitFunctions[NI_NUM_LIBRARIES];
    static ShutdownFunction ms_apfnShutdownFunctions[NI_NUM_LIBRARIES];
    static unsigned int ms_uiNumLibraries;
};

#define NiInit() NiStaticDataManager::Init()
#define NiShutdown() NiStaticDataManager::Shutdown()

#endif // #ifndef NISTATICDATAMANAGER_H
