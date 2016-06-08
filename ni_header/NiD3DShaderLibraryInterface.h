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

#ifndef NID3DSHADERLIBRARYINTERFACE_H
#define NID3DSHADERLIBRARYINTERFACE_H

// DLL Library interface function
#if defined(_USRDLL)
#if defined(NIDX8RENDERER_EXPORT) || defined(NIDX9RENDERER_EXPORT)
    // DLL library project uses this
    #define NID3DSHADERLIBRARY_ENTRY __declspec(dllimport)
#else
#if defined(NIDX8RENDERER_IMPORT) || defined(NIDX9RENDERER_IMPORT)
    // client of DLL uses this
    #define NID3DSHADERLIBRARY_ENTRY __declspec(dllexport)
#else
    // static library project uses this
    #define NID3DSHADERLIBRARY_ENTRY
#endif
#endif

class NiD3DShaderLibrary;

typedef bool (*NID3DSLI_LOADLIBRARY)(NiRenderer*, int, 
    char*[], bool, NiShaderLibrary** ppkLibrary);
typedef unsigned int (*NID3DSLI_RUNPARSER)(const char*, bool);
typedef unsigned int (*NIGETCOMPILERVERSIONFUNCTION)(void);

extern "C"
{
NID3DSHADERLIBRARY_ENTRY bool LoadShaderLibrary(
    NiRenderer* pkRenderer, int iDirectoryCount, char* pszDirectories[], 
    bool bRecurseSubFolders, NiShaderLibrary** ppkLibrary);
NID3DSHADERLIBRARY_ENTRY unsigned int RunShaderParser(
    const char* pszDirectory, bool bRecurseSubFolders);
NID3DSHADERLIBRARY_ENTRY unsigned int GetCompilerVersion(void);
};
#endif  //#if defined(_USRDLL)

#endif  //NID3DSHADERLIBRARYINTERFACE_H
