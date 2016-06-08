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

#ifndef NID3DSCM_PIXEL_H
#define NID3DSCM_PIXEL_H

#include "NiD3DShaderConstantMap.h"
#include <NiShaderAttributeDesc.h>

class NID3D_ENTRY NiD3DSCM_Pixel : public NiD3DShaderConstantMap
{
public:
    enum Pixel_DefinedMappings
    {
        SCMP_DEF_INVALID    = 0,
        // Constants
        SCMP_DEF_CONSTS_TAYLOR_SIN,
        SCMP_DEF_CONSTS_TAYLOR_COS,
        SCMP_DEF_CONSTS_TIME,           // RenderMonkey
        SCMP_DEF_CONSTS_SINTIME,
        SCMP_DEF_CONSTS_COSTIME,
        SCMP_DEF_CONSTS_TANTIME,
        SCMP_DEF_CONSTS_TIME_SINTIME_COSTIME_TANTIME,
        // Materials
        SCMP_DEF_MATERIAL_DIFFUSE,
        SCMP_DEF_MATERIAL_AMBIENT,
        SCMP_DEF_MATERIAL_SPECULAR,
        SCMP_DEF_MATERIAL_EMISSIVE,
        SCMP_DEF_MATERIAL_POWER,
        // Insert new predefines above here!
        SCMP_DEF_COUNT
    };

    static NiD3DShaderConstantMap::PredefinedMapping
        ms_akPredefinedMappings[];
    static unsigned int ms_uiNumMappings;

public:
    NiD3DSCM_Pixel(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DSCM_Pixel();

    // *** begin NDL internal use only ***
    static bool ParseKeyName(const char* pszOrigName, char* pszTrueName, 
        unsigned int uiMaxLen, unsigned int& uiRegisterCount);
    static bool LookUpPredefinedMapping(const char* pszMapping,
        unsigned int& uiMappingID, unsigned int& uiNumRegisters);
    static NiShaderAttributeDesc::AttributeType LookUpPredefinedMappingType(
        unsigned int uiMappingID, unsigned int uiNumRegisters);
    static unsigned int LookUpPredefinedMapping(const char* pszMapping);
    static NiShaderAttributeDesc::AttributeType LookUpPredefinedMappingType(
        const char* pszMapping);
    // *** end NDL internal use only ***

protected:
    virtual NiD3DError SetupPredefinedEntry(
        NiD3DShaderConstantMapEntry* pkEntry);
    virtual NiD3DError NiD3DSCM_Pixel::SetDefinedConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound, unsigned int uiPass);
    virtual NiD3DError SetConstantConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass);
    virtual NiD3DError SetAttributeConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound, unsigned int uiPass,
        bool bGlobal = false, NiExtraData* pkExtraData = 0);
    virtual NiD3DError SetGlobalConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass);
    virtual NiD3DError SetOperatorConstant(
        NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, const NiPropertyState* pkState, 
        const NiTransform& kWorld, const NiBound& kWorldBound, 
        unsigned int uiPass);

    unsigned int SetupDefinedConstantValue(unsigned int uiOperatorNum, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, const NiPropertyState* pkState, 
        const NiTransform& kWorld, const NiBound& kWorldBound);
    unsigned int SetupConstantConstantValue(unsigned int uiOperatorNum, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass);
    unsigned int SetupAttributeConstantValue(unsigned int uiOperatorNum, 
        NiD3DShaderConstantMapEntry* pkEntry, NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, const NiPropertyState* pkState, 
        const NiTransform& kWorld, const NiBound& kWorldBound, 
        unsigned int uiPass);
    unsigned int SetupGlobalConstantValue(unsigned int uiOperatorNum, 
        NiD3DShaderConstantMapEntry* pkEntry, unsigned int uiPass);

    NiD3DError PerformOperatorMultiply(NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry,
        NiShaderAttributeDesc::AttributeType eType1, 
        NiShaderAttributeDesc::AttributeType eType2, bool bInverse, 
        bool bTranspose);
    NiD3DError PerformOperatorDivide(NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry,
        NiShaderAttributeDesc::AttributeType eType1, 
        NiShaderAttributeDesc::AttributeType eType2, bool bInverse, 
        bool bTranspose);
    NiD3DError PerformOperatorAdd(NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry,
        NiShaderAttributeDesc::AttributeType eType1, 
        NiShaderAttributeDesc::AttributeType eType2, bool bInverse, 
        bool bTranspose);
    NiD3DError PerformOperatorSubtract(NiD3DShaderProgram* pkShaderProgram, 
        NiD3DShaderConstantMapEntry* pkEntry,
        NiShaderAttributeDesc::AttributeType eType1, 
        NiShaderAttributeDesc::AttributeType eType2, bool bInverse, 
        bool bTranspose);
};

typedef NiPointer<NiD3DSCM_Pixel> NiD3DSCM_PixelPtr;

#endif  //#ifndef NID3DSCM_PIXEL_H
