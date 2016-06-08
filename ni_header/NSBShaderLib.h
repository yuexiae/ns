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

#ifndef NSBSHADERLIB_H
#define NSBSHADERLIB_H

// DLL support
#include "NSBShaderLibLibType.h"
#include <NiShaderLibrary.h>

#if defined(_LIB)
bool NSBShaderLib_LoadShaderLibrary(NiRenderer* pkRenderer, 
    int iDirectoryCount, char* pszDirectories[], bool bRecurseSubFolders, 
    NiShaderLibrary** ppkLibrary);
#endif  //#if defined(_LIB)

#endif  //#ifndef NSBSHADERLIB_H
