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

#ifndef NID3DHLSLVERTEXSHADER_H
#define NID3DHLSLVERTEXSHADER_H

#include "NiD3DVertexShader.h"
#include "NiD3DRendererHeaders.h"

class NID3D_ENTRY NiD3DHLSLVertexShader : public NiD3DVertexShader
{
public:
    NiD3DHLSLVertexShader(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DHLSLVertexShader();

    virtual void DestroyRendererData();
    virtual void RecreateRendererData();

    // Shader constants
    virtual bool SetVertexShaderConstant(NiD3DShaderConstantMapEntry* pkEntry,
        const void* pvDataSource = NULL, unsigned int uiRegisterCount = 0);
    virtual bool SetVertexShaderConstantArray(
        NiD3DShaderConstantMapEntry* pkEntry, const void* pvDataSource, 
        unsigned int uiNumEntries, unsigned int uiRegistersPerEntry,
        unsigned short* pusReorderArray = NULL);

    virtual const char* GetEntryPoint() const;
    virtual void SetEntryPoint(const char* pcEntryPoint);

    virtual const char* GetShaderTarget() const;
    virtual void SetShaderTarget(const char* pcShaderTarget);

    virtual LPD3DXCONSTANTTABLE GetConstantTable() const;
    virtual void SetConstantTable(LPD3DXCONSTANTTABLE pkTable);

protected:
    char* m_pcEntryPoint;
    char* m_pcShaderTarget;

    LPD3DXCONSTANTTABLE m_pkConstantTable;
};

typedef NiPointer<NiD3DHLSLVertexShader> NiD3DHLSLVertexShaderPtr;

#include "NiD3DHLSLVertexShader.inl"

#endif  //#ifndef NID3DHLSLVERTEXSHADER_H
