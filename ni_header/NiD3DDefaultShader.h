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

#ifndef NID3DDEFAULTSHADER_H
#define NID3DDEFAULTSHADER_H

#include "NiD3DShader.h"
#include <NiTextureEffect.h>

class NiD3DTextureStage;
class NiDynamicEffectState;

// Uncomment this line to recover the alpha behavior of the Ni4.2 pipeline
//#define D3D_NI42_TEXTURE_PIPELINE

// NiD3DDefaultShader
// The Gamebryo pipeline implemented in the NiD3DShader framework

class NID3D_ENTRY NiD3DDefaultShader : public NiD3DShader
{
    NiDeclareRTTI;
public:
    NiD3DDefaultShader();
    virtual ~NiD3DDefaultShader();

    // Initialize function
    virtual bool Initialize(NiD3DRenderer* pkRenderer);

    // Override these functions to implement a custom pipeline...
    virtual unsigned int PreProcessPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);
    virtual unsigned int UpdatePipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);
    virtual unsigned int PostProcessPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);

    void UseWorldSpaceSphereMaps(bool bWorldSpace);
    void UseQuickDecals(bool bQuickDecals);

    // *** begin NDL internal use only ***

    void NextFrame();

    // *** end NDL internal use only ***

protected:
    void InitializeDeviceCaps();

    unsigned int ConstructPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects, 
        const NiTransform& kWorld, const NiBound& kWorldBound);

    void ClearProjectedTextures();
    void UpdateProjectedTextures(const NiDynamicEffectState* pkEffects);

    void PostProcessFogProperties(const NiFogProperty* pkFog, 
        const NiAlphaProperty* pkAlpha, 
        const NiTexturingProperty::Map* pkBaseMap, 
        NiTexturingProperty::ApplyMode eApply);

    bool SaveProjectedTexture(const NiTextureEffect* pkEffect, 
        bool bClipped = false);

    const NiTextureEffect* GetClippedProjectedLight(unsigned int uiIndex)
        const;
    const NiTextureEffect* GetProjectedLight(unsigned int uiIndex) const;
    const NiTextureEffect* GetClippedProjectedShadow(unsigned int uiIndex)
        const;
    const NiTextureEffect* GetProjectedShadow(unsigned int uiIndex) const;
    const NiTextureEffect* GetEnvironmentMap(unsigned int uiIndex) const;
    const NiTextureEffect* GetFogMap(unsigned int uiIndex) const;
    unsigned int GetClippedProjectedLightCount() const;
    unsigned int GetProjectedLightCount() const;
    unsigned int GetClippedProjectedShadowCount() const;
    unsigned int GetProjectedShadowCount() const;
    unsigned int GetEnvironmentMapCount() const;
    unsigned int GetFogMapCount() const;

    void OpenNewPass(D3DBLEND eSrcBlend = D3DBLEND_ONE, 
        D3DBLEND eDestBlend = D3DBLEND_ZERO, 
        bool bReturnBaseTextureAlpha = false, 
        bool bReturnVertexColorAlpha = false);
    void ClosePass(const NiTexturingProperty::Map* pkBaseMap = NULL);
    NiD3DTextureStage* AddTextureStage(const NiTexturingProperty::Map* pkMap, 
        unsigned int uiIndex);
    NiD3DTextureStage* AddTextureStage(
        const NiTexturingProperty::BumpMap* pkMap, unsigned int uiIndex);
    NiD3DTextureStage* AddTextureStage(const NiTextureEffect* pkEffect);
    NiD3DTextureStage* AddClipperStage(const NiTextureEffect* pkEffect);
    bool IsCurrentCombineMode(D3DBLEND eSrcBlend, D3DBLEND eDestBlend);

    // These arrays will only be added to or emptied completely, so
    // they should never not be compact.
    NiTArray<const NiTextureEffect*> m_kClippedProjectedLights;
    NiTArray<const NiTextureEffect*> m_kProjectedLights;
    NiTArray<const NiTextureEffect*> m_kClippedProjectedShadows;
    NiTArray<const NiTextureEffect*> m_kProjectedShadows;
    NiTArray<const NiTextureEffect*> m_kEnvironmentMaps;
    NiTArray<const NiTextureEffect*> m_kFogMaps;

    // Projected texture transform packing functions
    typedef void (NiD3DDefaultShader::*DynamicEffectPacker)(
        const NiMatrix3& kWorldMat, const NiPoint3& kWorldTrans, 
        NiD3DTextureStage* pkStage);

    void PackWorldParallelEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);
    void PackWorldPerspectiveEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);
    void PackWorldSphereEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);
    void PackCameraSphereEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);
    void PackSpecularCubeEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);
    void PackDiffuseCubeEffect(const NiMatrix3& kWorldMat, 
        const NiPoint3& kWorldTrans, NiD3DTextureStage* pkStage);

    // General purpose texture transform packer
    void PackTextureTransform(const NiMatrix3& kTexMatrix, 
        NiD3DTextureStage* pkStage);

    DynamicEffectPacker m_apfnDynEffectPackers[NiTextureEffect::NUM_COORD_GEN];

    // Pipeline construction values
    bool m_bBaseTextureAlphaNeeded;
    bool m_bVertexColorAlphaNeeded;
    unsigned int m_uiMaxTextureIndex;
    unsigned int m_uiRemainingStages;
    unsigned int m_uiRemainingTextures;
    unsigned int m_uiOldLightingValue;

    enum PassFogStatus
    {
        NO_FOG,
        BLACK_FOG,
        STANDARD_FOG
    };

    PassFogStatus* m_peFogPassArray;
    unsigned int m_uiFogPassArraySize;

    // Caps dependent values
    bool m_bBlendTextureAlpha;
    D3DTEXTUREOP m_eEnvBumpOp;

    bool m_bQuickDecals;

    const NiDynamicEffectState* m_pkLastState;
};

typedef NiPointer<NiD3DDefaultShader> NiD3DDefaultShaderPtr;

#endif  //#ifndef NID3DDEFAULTSHADER_H
