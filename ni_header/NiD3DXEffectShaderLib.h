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

#ifndef NID3DXEFFECTSHADERLIB_H
#define NID3DXEFFECTSHADERLIB_H

// DLL support
#include "NiD3DXEffectShaderLibType.h"
#include <NiD3DShaderLibrary.h>

#if defined(_LIB)
bool NiD3DXEffectShaderLib_LoadShaderLibrary(
    NiRenderer* pkRenderer, int iDirectoryCount, char* apcDirectories[], 
    bool bRecurseSubFolders, NiShaderLibrary** ppkLibrary);
#endif  //#if defined(_LIB)

unsigned int NiD3DXEffectShaderLib_GetD3DXEffectCreationFlags();
void NiD3DXEffectShaderLib_SetD3DXEffectCreationFlags(unsigned int uiFlags);

void NiD3DXEffectShaderLib_SetApplicationInstance(HINSTANCE hInstance);

#endif  //NID3DXEFFECTSHADERLIB_H
