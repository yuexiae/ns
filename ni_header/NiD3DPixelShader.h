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

#ifndef NID3DPIXELSHADER_H
#define NID3DPIXELSHADER_H

#include "NiD3DShaderProgram.h"

// 
class NID3D_ENTRY NiD3DPixelShader : public NiD3DShaderProgram
{
public:
    NiD3DPixelShader(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DPixelShader();

    virtual NiD3DPixelShaderHandle GetShaderHandle();
    virtual void SetShaderHandle(NiD3DPixelShaderHandle hShader);

    virtual void DestroyRendererData();
    virtual void RecreateRendererData();

    // Shader constants
    virtual bool SetPixelShaderConstant(NiD3DShaderConstantMapEntry* pkEntry,
        const void* pvDataSource = NULL, unsigned int uiRegisterCount = 0);
    virtual bool SetPixelShaderConstantArray(
        NiD3DShaderConstantMapEntry* pkEntry, const void* pvDataSource, 
        unsigned int uiNumEntries, unsigned int uiRegistersPerEntry,
        unsigned short* pusReorderArray = NULL);

protected:
    NiD3DPixelShaderHandle m_hShader;
};

typedef NiPointer<NiD3DPixelShader> NiD3DPixelShaderPtr;

#include "NiD3DPixelShader.inl"

#endif  //#ifndef NID3DPIXELSHADER_H
