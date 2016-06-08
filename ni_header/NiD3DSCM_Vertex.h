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

#ifndef NID3DSCM_VERTEX_H
#define NID3DSCM_VERTEX_H

#include "NiD3DShaderConstantMap.h"
#include <NiShaderAttributeDesc.h>

class NID3D_ENTRY NiD3DSCM_Vertex : public NiD3DShaderConstantMap
{
public:
    enum Vertex_DefinedMappings
    {
        SCMV_DEF_INVALID    = 0,
        // Common transforms
        SCMV_DEF_PROJ,
        SCMV_DEF_INVPROJ,
        SCMV_DEF_VIEW,
        SCMV_DEF_INVVIEW,
        SCMV_DEF_WORLD,
        SCMV_DEF_INVWORLD,
        SCMV_DEF_WORLDVIEW,
        SCMV_DEF_INVWORLDVIEW,
        SCMV_DEF_VIEWPROJ,
        SCMV_DEF_INVVIEWPROJ,
        SCMV_DEF_WORLDVIEWPROJ,
        SCMV_DEF_INVWORLDVIEWPROJ,
        // Transpose of common transforms
        SCMV_DEF_PROJ_T,
        SCMV_DEF_INVPROJ_T,
        SCMV_DEF_VIEW_T,
        SCMV_DEF_INVVIEW_T,
        SCMV_DEF_WORLD_T,
        SCMV_DEF_INVWORLD_T,
        SCMV_DEF_WORLDVIEW_T,
        SCMV_DEF_INVWORLDVIEW_T,
        SCMV_DEF_VIEWPROJ_T,
        SCMV_DEF_INVVIEWPROJ_T,
        SCMV_DEF_WORLDVIEWPROJ_T,
        SCMV_DEF_INVWORLDVIEWPROJ_T,
        // Bone matrices
        // These are used for matrix palette skinning. They supply the 
        // WorldViewProj matrix w/ the skin transform concated on as well.
        // This reduces the number of matrix operations that must be 
        // performed for each bone!
        SCMV_DEF_SKINWORLDVIEW,
        SCMV_DEF_INVSKINWORLDVIEW,
        SCMV_DEF_SKINWORLDVIEW_T,
        SCMV_DEF_INVSKINWORLDVIEW_T,
        SCMV_DEF_SKINWORLDVIEWPROJ,
        SCMV_DEF_INVSKINWORLDVIEWPROJ,
        SCMV_DEF_SKINWORLDVIEWPROJ_T,
        SCMV_DEF_INVSKINWORLDVIEWPROJ_T,
        SCMV_DEF_BONE_MATRIX_3,
        SCMV_DEF_BONE_MATRIX_4,
        SCMV_DEF_SKINBONE_MATRIX_3,
        SCMV_DEF_SKINBONE_MATRIX_4,
        // Texture matrices
        SCMV_DEF_TEXTRANSFORMBASE,
        SCMV_DEF_INVTEXTRANSFORMBASE,
        SCMV_DEF_TEXTRANSFORMBASE_T,
        SCMV_DEF_INVTEXTRANSFORMBASE_T,
        SCMV_DEF_TEXTRANSFORMDARK,
        SCMV_DEF_INVTEXTRANSFORMDARK,
        SCMV_DEF_TEXTRANSFORMDARK_T,
        SCMV_DEF_INVTEXTRANSFORMDARK_T,
        SCMV_DEF_TEXTRANSFORMDETAIL,
        SCMV_DEF_INVTEXTRANSFORMDETAIL,
        SCMV_DEF_TEXTRANSFORMDETAIL_T,
        SCMV_DEF_INVTEXTRANSFORMDETAIL_T,
        SCMV_DEF_TEXTRANSFORMGLOSS,
        SCMV_DEF_INVTEXTRANSFORMGLOSS,
        SCMV_DEF_TEXTRANSFORMGLOSS_T,
        SCMV_DEF_INVTEXTRANSFORMGLOSS_T,
        SCMV_DEF_TEXTRANSFORMGLOW,
        SCMV_DEF_INVTEXTRANSFORMGLOW,
        SCMV_DEF_TEXTRANSFORMGLOW_T,
        SCMV_DEF_INVTEXTRANSFORMGLOW_T,
        SCMV_DEF_TEXTRANSFORMBUMP,
        SCMV_DEF_INVTEXTRANSFORMBUMP,
        SCMV_DEF_TEXTRANSFORMBUMP_T,
        SCMV_DEF_INVTEXTRANSFORMBUMP_T,
        SCMV_DEF_TEXTRANSFORMDECAL,
        SCMV_DEF_INVTEXTRANSFORMDECAL,
        SCMV_DEF_TEXTRANSFORMDECAL_T,
        SCMV_DEF_INVTEXTRANSFORMDECAL_T,
        SCMV_DEF_TEXTRANSFORMSHADER,
        SCMV_DEF_INVTEXTRANSFORMSHADER,
        SCMV_DEF_TEXTRANSFORMSHADER_T,
        SCMV_DEF_INVTEXTRANSFORMSHADER_T,
        // Matrix count - used to quickly identify matrix-based entries
        SCMV_DEF_MATRIXTYPE_COUNT,
        // Lighting
        SCMV_DEF_LIGHT_POS_WS = SCMV_DEF_MATRIXTYPE_COUNT,
        SCMV_DEF_LIGHT_DIR_WS,
        SCMV_DEF_LIGHT_POS_OS,
        SCMV_DEF_LIGHT_DIR_OS,
        // Materials
        SCMV_DEF_MATERIAL_DIFFUSE,
        SCMV_DEF_MATERIAL_AMBIENT,
        SCMV_DEF_MATERIAL_SPECULAR,
        SCMV_DEF_MATERIAL_EMISSIVE,
        SCMV_DEF_MATERIAL_POWER,
        // Eye
        SCMV_DEF_EYE_POS,
        SCMV_DEF_EYE_DIR,
        // Constants
        SCMV_DEF_CONSTS_TAYLOR_SIN,
        SCMV_DEF_CONSTS_TAYLOR_COS,
        SCMV_DEF_CONSTS_TIME,           // RenderMonkey
        SCMV_DEF_CONSTS_SINTIME,
        SCMV_DEF_CONSTS_COSTIME,
        SCMV_DEF_CONSTS_TANTIME,
        SCMV_DEF_CONSTS_TIME_SINTIME_COSTIME_TANTIME,
        // Insert new predefines above here!
        SCMV_DEF_COUNT
    };

    static NiD3DShaderConstantMap::PredefinedMapping
        ms_akPredefinedMappings[];
    static unsigned int ms_uiNumMappings;

public:
    NiD3DSCM_Vertex(NiD3DRenderer* pkRenderer);
    virtual ~NiD3DSCM_Vertex();

    // *** begin NDL internal use only ***
    static bool ParseKeyName(const char* pszOrigName, char* pszTrueName, 
        unsigned int uiMaxLen, unsigned int& uiRegisterCount);
    static bool LookUpPredefinedMapping(const char* pszMapping,
        unsigned int& uiMappingID, unsigned int& uiNumRegisters);
    static NiShaderAttributeDesc::AttributeType LookUpPredefinedMappingType(
        unsigned int uiMappingID, unsigned int uiNumRegisters);
    static NiShaderAttributeDesc::AttributeType LookUpPredefinedMappingType(
        const char* pszMapping);

    static void SetupTextureTransformMatrix(D3DXMATRIX& kResult, 
        const NiMatrix3* pkTexMatrix = NULL, bool bInv = false, 
        bool bTrans = false);
    // *** end NDL internal use only ***

protected:
    virtual NiD3DError SetupPredefinedEntry(
        NiD3DShaderConstantMapEntry* pkEntry);
    virtual NiD3DError SetDefinedConstant(
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

typedef NiPointer<NiD3DSCM_Vertex> NiD3DSCM_VertexPtr;

#endif  //#ifndef NID3DSCM_VERTEX_H
