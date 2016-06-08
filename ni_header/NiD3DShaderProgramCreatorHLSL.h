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

#ifndef NiD3DShaderProgramCreatorHLSL_H
#define NiD3DShaderProgramCreatorHLSL_H

#include "NiD3DShaderProgramCreator.h"
#include "NiD3DShaderProgramFactory.h"

class NID3D_ENTRY NiD3DShaderProgramCreatorHLSL : 
    public NiD3DShaderProgramCreator
{
public:
    virtual ~NiD3DShaderProgramCreatorHLSL();

    // Shader assembly flags
    virtual unsigned int GetShaderCreationFlags() const;
    virtual void SetShaderCreationFlags(unsigned int uiFlags);

    // *** begin NDL internal use only ***

    // These functions should only be called from NiD3DShaderProgramFactory

    // Vertex shader creation
    virtual NiD3DVertexShader* CreateVertexShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget, 
        NiD3DVertexDeclaration hDecl, unsigned int uiUsage,
        bool bSoftwareVP = false);
    virtual NiD3DVertexShader* CreateVertexShaderFromBuffer(
        const void* pvBuffer, unsigned int uiBufferSize, 
        const char* pcShaderName, const char* pcEntryPoint, 
        const char* pcShaderTarget, NiD3DVertexDeclaration hDecl, 
        unsigned int uiUsage, bool bSoftwareVP = false);
    // Pixel  shader creation
    virtual NiD3DPixelShader* CreatePixelShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget);
    virtual NiD3DPixelShader* CreatePixelShaderFromBuffer(
        const void* pvBuffer, unsigned int uiBufferSize, 
        const char* pcShaderName, const char* pcEntryPoint, 
        const char* pcShaderTarget);

    // Shader recreation
    virtual bool RecreateVertexShader(NiD3DVertexShader* pkVertexShader);
    virtual bool RecreatePixelShader(NiD3DPixelShader* pkPixelShader);

    static void _SDMInit();
    static void _SDMShutdown();

    static NiD3DShaderProgramCreatorHLSL* GetInstance();
    static void Shutdown();
    // *** end NDL internal use only ***

protected:
    NiD3DShaderProgramCreatorHLSL();

    bool LoadShaderCodeFromFile(const char* pcFileName, 
        const char* pcEntryPoint, const char* pcShaderTarget, void*& pvCode, 
        unsigned int& uiCodeSize, LPD3DXCONSTANTTABLE& pkConstantTable);
    bool LoadShaderCodeFromBuffer(const void* pvBuffer, 
        unsigned int uiBufferSize, const char* pcEntryPoint, 
        const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize, 
        LPD3DXCONSTANTTABLE& pkConstantTable);

    unsigned int m_uiShaderCreationFlags;

    static NiD3DShaderProgramCreatorHLSL* ms_pkCreator;
};

#include "NiD3DShaderProgramCreatorHLSL.inl"

#endif  //NiD3DShaderProgramCreatorHLSL_H
