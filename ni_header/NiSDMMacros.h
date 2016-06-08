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

#ifndef NISDMMACROS_H
#define NISDMMACROS_H

#define NiDeclareSDM(libname, entrytag) \
    class entrytag libname##SDM \
    { \
    public: \
        libname##SDM(); \
        static void Init(); \
        static void Shutdown(); \
    protected: \
        static bool ms_bInitialized; \
    }; 

#define NiImplementSDMConstructor(libname) \
    bool libname##SDM::ms_bInitialized = false; \
    libname##SDM::libname##SDM() \
    { \
        static int siCounter = 0; \
        if (siCounter++ == 0) \
        { \
            NiStaticDataManager:: \
                AddLibrary(libname##SDM::Init, libname##SDM::Shutdown); \
        } \
    }

#define NiImplementSDMInitCheck() \
    if (!ms_bInitialized) \
    { \
        ms_bInitialized = true; \
    } \
    else \
    { \
        return; \
    }

#define NiImplementSDMShutdownCheck() \
    if (ms_bInitialized) \
    { \
        ms_bInitialized = false; \
    } \
    else \
    { \
        return; \
    }

#define NiImplementDllMain(libname) \
    HMODULE gs_h##libname##Handle = 0; \
    BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)\
    { \
        switch (ulReason) \
        { \
            case DLL_PROCESS_ATTACH: \
                gs_h##libname##Handle = hModule; \
                libname##SDM::Init(); \
                break; \
            case DLL_PROCESS_DETACH: \
                gs_h##libname##Handle = 0; \
                libname##SDM::Shutdown(); \
                NiStaticDataManager::RemoveLibrary(libname##SDM::Init, \
                    libname##SDM::Shutdown); \
                break; \
        } \
        return TRUE; \
     }

#endif  // #ifndef NISDMMACROS_H
