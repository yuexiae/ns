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

#ifndef NID3DSHADERPROGRAMCREATOR_H
#define NID3DSHADERPROGRAMCREATOR_H

#include "NiD3DDefines.h"
#include "NiD3DRendererHeaders.h"

NiSmartPointer(NiD3DVertexShader);
NiSmartPointer(NiD3DPixelShader);

class NID3D_ENTRY NiD3DShaderProgramCreator
{
public:
    virtual ~NiD3DShaderProgramCreator();

    // Shader creation flags - apply to all shaders
    static unsigned int GetUniversalShaderCreationFlags();
    static void SetUniversalShaderCreationFlags(unsigned int uiFlags);

    // Shader creation flags - apply only to specific shaders
    virtual unsigned int GetShaderCreationFlags() const = 0;
    virtual void SetShaderCreationFlags(unsigned int uiFlags) = 0;

    // *** begin NDL internal use only ***
    
    // These functions should only be called from NiD3DShaderProgramFactory

    // Vertex shader creation
    virtual NiD3DVertexShader* CreateVertexShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget, 
        NiD3DVertexDeclaration hDecl, unsigned int uiUsage,
        bool bSoftwareVP = false) = 0;
    virtual NiD3DVertexShader* CreateVertexShaderFromBuffer(
        const void* pvBuffer, unsigned int uiBufferSize, 
        const char* pcShaderName, const char* pcEntryPoint, 
        const char* pcShaderTarget, NiD3DVertexDeclaration hDecl, 
        unsigned int uiUsage, bool bSoftwareVP = false) = 0;
    // Pixel  shader creation
    virtual NiD3DPixelShader* CreatePixelShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget) = 0;
    virtual NiD3DPixelShader* CreatePixelShaderFromBuffer(
        const void* pvBuffer, unsigned int uiBufferSize, 
        const char* pcShaderName, const char* pcEntryPoint, 
        const char* pcShaderTarget) = 0;

    // Shader recreation
    virtual bool RecreateVertexShader(NiD3DVertexShader* pkVertexShader) = 0;
    virtual bool RecreatePixelShader(NiD3DPixelShader* pkPixelShader) = 0;

    static void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);

    static void _SDMInit();
    static void _SDMShutdown();

    // *** end NDL internal use only ***

protected:
    NiD3DShaderProgramCreator();

    NiD3DVertexShaderHandle CreateVertexShader(void* pvCode, 
        NiD3DVertexDeclaration& hDecl, unsigned int uiUsage,
        void* pvConstantData = NULL, unsigned int uiConstantSize = 0, 
        bool bSoftwareVP = false);
    NiD3DPixelShaderHandle CreatePixelShader(void* pvCode);

    static unsigned int ms_uiUniversalShaderCreationFlags;

    static void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    static D3DDevicePtr ms_pkD3DDevice;
    static NiD3DRenderer* ms_pkD3DRenderer;
};

#include "NiD3DShaderProgramCreator.inl"

#endif  //NID3DSHADERPROGRAMCREATOR_H
