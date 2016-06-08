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
#ifndef NIDX8SHADERDECLARATION_H
#define NIDX8SHADERDECLARATION_H

#include "NiD3DShaderDeclaration.h"

class NID3D_ENTRY NiDX8ShaderDeclaration : public NiD3DShaderDeclaration
{
public:
    virtual ~NiDX8ShaderDeclaration();

    static NiDX8ShaderDeclaration* Create(NiRenderer* pkRenderer,
        bool bFixedFunction, unsigned int uiMaxStreamEntryCount, 
        unsigned int uiStreamCount = 1);

    virtual bool SetEntry(unsigned int uiEntry, unsigned int uiRegister, 
        ShaderParameter eInput, ShaderParameterType eType, 
        unsigned int uiStream = 0);
    virtual bool SetEntry(unsigned int uiStream, unsigned int uiEntry, 
        unsigned int uiRegister, ShaderParameter eInput, 
        ShaderParameterType eType, ShaderParameterUsage eUsage,
        unsigned int uiIndex, ShaderParameterTesselator eTess);
    virtual bool RemoveEntry(unsigned int uiEntry, unsigned int uiStream = 0);
    virtual bool ClearAllEntries(unsigned int uiStream = 0);
    virtual bool SetConstantData(unsigned int uiStartRegister, 
        unsigned int uiNumRegisters, float* pfData);

    virtual NiVBChip* PackUntransformedVB(NiGeometryData* pkData, 
        NiSkinInstance* pkSkin, NiSkinPartition::Partition* pkPartition, 
        NiRendererExtraData* pkExtraData, unsigned short usDirtyFlags, 
        NiVBChip* pkOldVBChip, unsigned int uiStream, 
        void* pvLockedBuff = NULL);

    virtual bool GenerateVertexParameters(
        NiD3DVertexDeclaration& pkDeclaration, unsigned int& uiNumStreams);

    virtual unsigned int GetVertexStride(unsigned int uiStream = 0);

    virtual void SetSoftwareVertexProcessing(bool bSoftwareVB);
    virtual bool GetSoftwareVertexProcessing() const;

    // *** begin NDL internal use only ***
    DWORD CreateVertexShader(DWORD* pdwFunction, DWORD dwUsage = 0);
    void ReleaseShaderHandle();

    virtual NiD3DVertexDeclaration GetD3DDeclaration();
    DWORD GetFVF()
    {
        return m_dwFVF;
    }
    // *** end NDL internal use only ***

protected:
    NiDX8ShaderDeclaration(bool bFixedFunction);

    unsigned int AddDeclarationEntry(ShaderRegisterEntry* pkEntry, 
        unsigned int uiStream);

    DWORD* m_pdwDeclaration;

    bool m_bFixedFunction;
    DWORD m_dwHandle;
    DWORD m_dwFVF;
    bool m_bSoftwareVB;

    float* m_pfConstantData;
    unsigned int m_uiConstantStartRegister;
    unsigned int m_uiConstantNumRegisters;
};

NiSmartPointer(NiDX8ShaderDeclaration);

#endif  //#ifndef NIDX8SHADERDECLARATION_H
