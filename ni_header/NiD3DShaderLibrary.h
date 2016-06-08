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

#ifndef NID3DSHADERLIBRARY_H
#define NID3DSHADERLIBRARY_H

#include <NiShaderLibrary.h>
#include <NiShaderLibraryDesc.h>
#include "NiD3DDefines.h"
#include "NiD3DRendererHeaders.h"

// NiD3DShaderLibrary
class NID3D_ENTRY NiD3DShaderLibrary : public NiShaderLibrary
{
public:
    NiD3DShaderLibrary(char* pcName);
    virtual ~NiD3DShaderLibrary();

    static void SetDirectoryInfo(const char* pcDirectory);
    static const char* GetDirectory();
    static void SetPlatform(unsigned int uiPlatform);
    static unsigned int GetPlatform();
    static void SetVersionInfo(const char* pcVersionName, 
        unsigned int uiVersion);
    static unsigned int GetVersionNumber(const char* pcVersionName);

    virtual void SetRenderer(NiD3DRenderer* pkRenderer);
    NiD3DRenderer* NiD3DShaderLibrary::GetRenderer();

    virtual NiShader* GetShader(NiRenderer* pkRenderer, char* pcName, 
        unsigned int uiImplementation);
    
    virtual NiShaderLibraryDesc* GetShaderLibraryDesc();

    // *** begin NDL internal use only ***
    virtual void SetShaderLibraryDesc(NiShaderLibraryDesc* pkLibDesc);
    // *** end NDL internal use only ***

protected:
    static char* ms_pcDirectory;
    static unsigned int ms_uiPlatform;
    static unsigned int ms_uiPSVersion;
    static unsigned int ms_uiVSVersion;
    static unsigned int ms_uiUserVersion;

    NiD3DRenderer* m_pkD3DRenderer;
    
    HMODULE m_hLibrary;

    NiShaderLibraryDescPtr m_spShaderLibraryDesc;
};

typedef NiPointer<NiD3DShaderLibrary> NiD3DShaderLibraryPtr;

#endif  //#ifndef NID3DSHADERLIBRARY_H
