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

#ifndef NID3DSHADERCONSTANTMAP_H
#define NID3DSHADERCONSTANTMAP_H

#include <NiGeometry.h>
#include "NiD3DDefines.h"
#include "NiD3DError.h"
#include "NiD3DRenderState.h"
#include "NiD3DShaderConstantMapEntry.h"

class NiD3DShaderProgram;

class NID3D_ENTRY NiD3DShaderConstantMap : public NiRefObject
{
    // *** begin NDL internal use only ***
protected:
    void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    void SetD3DRenderState(NiD3DRenderState* pkRS);
public:
    void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    // *** end NDL internal use only ***

public:
    enum Usage
    {
        SCM_USAGE_PIXEL  = 0x00000001,
        SCM_USAGE_VERTEX = 0x00000002
    };

    class PredefinedMapping
    {
    public:
        unsigned int m_uiMappingID;
        char* m_pszMappingName;

        PredefinedMapping(unsigned int uiMappingID, 
            char* pszMappingName);
    };

    NiD3DShaderConstantMap(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DShaderConstantMap();

    //*** Access functions
    const Usage GetUsage();
    bool GetModified();
    void SetModified(bool bModified);
    NiD3DError GetLastError();

    //*** Entry access/manipulation functions
    unsigned int GetEntryCount();

    virtual NiD3DError AddEntry(const char* pszKey, unsigned int uiFlags,
        unsigned int uiExtra, unsigned int uiShaderRegister, 
        unsigned int uiRegisterCount, const char* pszVariableName = NULL, 
        unsigned int uiDataSize = 0, unsigned int uiDataStride = 0, 
        const void* pvDataSource = NULL, bool bCopyData = false);
    virtual NiD3DError AddPredefinedEntry(const char* pszKey, 
        unsigned int uiExtra, unsigned int uiShaderRegister, 
        const char* pszVariableName);
    virtual NiD3DError AddAttributeEntry(const char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
        const char* pszVariableName, unsigned int uiDataSize, 
        unsigned int uiDataStride, const void* pvDataSource, 
        bool bCopyData = true);
    virtual NiD3DError AddConstantEntry(const char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
        const char* pszVariableName, unsigned int uiDataSize, 
        unsigned int uiDataStride, const void* pvDataSource, 
        bool bCopyData = true);
    virtual NiD3DError AddGlobalEntry(const char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
        const char* pszVariableName, unsigned int uiDataSize, 
        unsigned int uiDataStride, const void* pvDataSource, 
        bool bCopyData = false);
    virtual NiD3DError AddOperatorEntry(const char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
        const char* pszVariableName);

    virtual NiD3DError RemoveEntry(const char* pszKey);
    virtual NiD3DShaderConstantMapEntry* GetEntry(const char* pszKey);
    virtual NiD3DShaderConstantMapEntry* GetEntryAtIndex(
        unsigned int uiIndex);

    //*** Pipeline functions
    virtual NiD3DError SetShaderConstants(NiD3DShaderProgram* pkShaderProgram, 
        NiGeometry* pkGeometry, const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound, unsigned int uiPass = 0, 
        bool bGlobal = false);

    // *** begin NDL internal use only ***
    static const char* GetTimeExtraDataName();
    virtual unsigned int GetEntryIndex(const char* pszKey);
    // *** end NDL internal use only ***

protected:
    virtual NiD3DError InsertEntry(NiD3DShaderConstantMapEntry* pkEntry);
    virtual NiD3DError SetupPredefinedEntry(
        NiD3DShaderConstantMapEntry* pkEntry) = 0;
    virtual NiD3DError SetDefinedConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound, unsigned int uiPass) = 0;
    virtual NiD3DError SetConstantConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass) = 0;
    virtual NiD3DError SetAttributeConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound, unsigned int uiPass, 
        bool bGlobal = false, NiExtraData* pkExtraData = 0) = 0;
    virtual NiD3DError SetGlobalConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass) = 0;
    virtual NiD3DError SetOperatorConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, const NiPropertyState* pkState, 
        const NiTransform& kWorld, const NiBound& kWorldBound, 
        unsigned int uiPass) = 0;

    // Attribute Mapping Helper functions
    const void* MapAttributeValue(NiD3DShaderConstantMapEntry* pkEntry,
        NiExtraData* pkExtra);
    // Constant Mapping Helper functions
    const void* MapConstantValue(NiD3DShaderConstantMapEntry* pkEntry);

    static D3DVECTOR4 ms_vTaylorSin;
    static D3DVECTOR4 ms_vTaylorCos;

    static D3DXVECTOR4 ms_vMappingValue;
    static D3DXMATRIX ms_mMappingValue;

#if defined(_DX9) || defined(_XENON)
    static BOOL ms_bMappingValue;
    static int ms_aiMappingValue[4];
#endif //#if defined(_DX9) || defined(_XENON)

    static const char* ms_pcTimeExtraDataName;

    Usage m_eUsage;
    NiTArray<NiD3DShaderConstantMapEntryPtr> m_aspEntries;
    bool m_bModified;

    NiD3DShaderProgram* m_pkLastShaderProgram;
    NiD3DError m_eLastError;

protected:
    D3DDevicePtr m_pkD3DDevice;
    NiD3DRenderer* m_pkD3DRenderer;
    NiD3DRenderState* m_pkD3DRenderState;


    static D3DXALIGNEDMATRIX ms_kD3DMat[2];
    static D3DXVECTOR4 ms_kD3DVector4[2];
    static D3DXALIGNEDMATRIX ms_kD3DMatResult;
    static D3DXVECTOR4 ms_kD3DVector4Result;
};

typedef NiPointer<NiD3DShaderConstantMap> NiD3DShaderConstantMapPtr;

#include "NiD3DShaderConstantMap.inl"

#endif  //#ifndef NID3DSHADERCONSTANTMAP_H
