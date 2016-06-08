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

#ifndef NID3DSHADERPROGRAM_H
#define NID3DSHADERPROGRAM_H

#include <NiSmartPointer.h>
#include <NiRefObject.h>
#include "NiD3DDefines.h"

class NiD3DRenderState;
class NiD3DShaderConstantMapEntry;
class NiD3DShaderProgramCreator;

// 
class NID3D_ENTRY NiD3DShaderProgram : public NiRefObject
{
    // *** begin NDL internal use only ***
protected:
    void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    void SetD3DRenderState(NiD3DRenderState* pkRS);
public:
    void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    // *** end NDL internal use only ***

public:
    NiD3DShaderProgram(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DShaderProgram();

    // Access functions
    virtual const char* GetName() const;
    virtual void SetName(const char* pszName);

    virtual const char* GetShaderProgramName() const;
    virtual void SetShaderProgramName(const char* pszName);

    virtual unsigned int GetCodeSize() const;
    virtual void* GetCode() const;
    virtual void SetCode(unsigned int uiSize, void* pvCode);

    virtual NiD3DShaderProgramCreator* GetCreator() const;
    virtual void SetCreator(NiD3DShaderProgramCreator* pkCreator);

    //*** Helper functions
    virtual bool SetVertexShaderConstant(NiD3DShaderConstantMapEntry* pkEntry,
        const void* pvDataSource = NULL, unsigned int uiRegisterCount = 0);
    virtual bool SetVertexShaderConstantArray(
        NiD3DShaderConstantMapEntry* pkEntry, const void* pvDataSource, 
        unsigned int uiNumEntries, unsigned int uiRegistersPerEntry,
        unsigned short* pusReorderArray = NULL);
    virtual bool SetPixelShaderConstant(NiD3DShaderConstantMapEntry* pkEntry,
        const void* pvDataSource = NULL, unsigned int uiRegisterCount = 0);
    virtual bool SetPixelShaderConstantArray(
        NiD3DShaderConstantMapEntry* pkEntry, const void* pvDataSource, 
        unsigned int uiNumEntries, unsigned int uiRegistersPerEntry,
        unsigned short* pusReorderArray = NULL);
protected:
    char* m_pszName;

    char* m_pszShaderProgramName;
    unsigned int m_uiCodeSize;
    void* m_pvCode;
    NiD3DShaderProgramCreator* m_pkCreator;

    D3DDevicePtr m_pkD3DDevice;
    NiD3DRenderer* m_pkD3DRenderer;
    NiD3DRenderState* m_pkD3DRenderState;
};

typedef NiPointer<NiD3DShaderProgram> NiD3DShaderProgramPtr;

#include "NiD3DShaderProgram.inl"

#endif  //#ifndef NID3DSHADERPROGRAM_H
