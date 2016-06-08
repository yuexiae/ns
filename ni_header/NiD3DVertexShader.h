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

#ifndef NID3DVERTEXSHADER_H
#define NID3DVERTEXSHADER_H

#include "NiD3DShaderProgram.h"

class NID3D_ENTRY NiD3DVertexShader : public NiD3DShaderProgram
{
public:
    NiD3DVertexShader(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DVertexShader();

    virtual unsigned int GetUsage() const;
    virtual void SetUsage(unsigned int uiUsage);

    virtual NiD3DVertexShaderHandle GetShaderHandle() const;
    virtual void SetShaderHandle(NiD3DVertexShaderHandle hShader);

    virtual NiD3DVertexDeclaration GetVertexDeclaration() const;
    virtual void SetVertexDeclaration(NiD3DVertexDeclaration hDecl);

    virtual bool GetSoftwareVertexProcessing() const;
    virtual void SetSoftwareVertexProcessing(bool bSoftwareVP);

    virtual void DestroyRendererData();
    virtual void RecreateRendererData();

    // Shader constants
    virtual bool SetVertexShaderConstant(NiD3DShaderConstantMapEntry* pkEntry,
        const void* pvDataSource = NULL, unsigned int uiRegisterCount = 0);
    virtual bool SetVertexShaderConstantArray(
        NiD3DShaderConstantMapEntry* pkEntry, const void* pvDataSource, 
        unsigned int uiNumEntries, unsigned int uiRegistersPerEntry,
        unsigned short* pusReorderArray = NULL);

protected:
    bool m_bSoftwareVP;
    unsigned int m_uiUsage;
    NiD3DVertexShaderHandle m_hShader;
    NiD3DVertexDeclaration m_hDecl;
};

typedef NiPointer<NiD3DVertexShader> NiD3DVertexShaderPtr;

#include "NiD3DVertexShader.inl"

#endif  //#ifndef NID3DVERTEXSHADER_H
