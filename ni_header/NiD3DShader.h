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

#ifndef NID3DSHADER_H
#define NID3DSHADER_H

#include "NiD3DShaderInterface.h"
#include "NiD3DShaderDeclaration.h"
#include "NiD3DRenderStateGroup.h"
#include "NiD3DSCM_Pixel.h"
#include "NiD3DSCM_Vertex.h"
#include "NiD3DTextureStage.h"
#include "NiD3DPass.h"
#include <NiSCMExtraData.h>
#include <NiTPool.h>

// NiD3DShader
// Shader derived for D3D-based renderers. (DX8/DX9/Xbox)

class NID3D_ENTRY NiD3DShader : public NiD3DShaderInterface
{
    NiDeclareRTTI;
public:
    NiD3DShader();
    virtual ~NiD3DShader();

    virtual bool IsInitialized();

    // Override these functions to implement a custom pipeline...
    // Initialize function
    virtual bool Initialize(NiD3DRenderer* pkRenderer);

    virtual unsigned int PreProcessPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);
    virtual unsigned int UpdatePipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);
    virtual unsigned int SetupRenderingPass(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);
    virtual unsigned int SetupTransformations(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound);
    virtual unsigned int SetupShaderPrograms(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound);
    virtual NiGeometryBufferData* PrepareGeometryForRendering(
        NiGeometry* pkGeometry, const NiSkinPartition::Partition* pkPartition,
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState);
    virtual unsigned int PostProcessPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);

    // Advance to the next pass.
    virtual unsigned int FirstPass();
    virtual unsigned int NextPass();

    virtual NiD3DShaderDeclaration* GetShaderDecl() const;
    virtual void SetShaderDecl(NiD3DShaderDeclaration* pkShaderDecl);

    // Used during UpdatePipeline
    virtual void ResetPasses();

    static void InitializePools();
    static void ShutdownPools();

    // This function is called by NiShaderFactory::AttachShader, and
    // is used to verify the geometry is usable for the shader, as well
    // as to 'process' the geometry, adding what is needed.
    virtual bool SetupGeometry(NiGeometry* pkGeometry);

    // This function sets up an NiSCMExtraData object on the geometry that
    // caches extra data lookups for shaders. It is declared static so that
    // applications can call it if necessary when removing and adding extra
    // data.
    static void SetupSCMExtraData(NiD3DShader* pkD3DShader, 
        NiGeometry* pkGeometry);
    void ResetSCMExtraData(NiGeometry* pkGeometry);

    // Allow for complete shader reconstruction
    virtual void DestroyRendererData();
    virtual void RecreateRendererData();

    // Allows for the shader to use the 
    // NiD3DRenderState::UpdateRenderState function
    bool GetUsesNiRenderState() const;
    void SetUsesNiRenderState(bool bUses);

    // Allows for the shader to use the Ni###LightManager::SetState 
    // function to set lights on the device
    bool GetUsesNiLightState() const;
    void SetUsesNiLightState(bool bUses);

    // Query shader for presence of shader programs
    virtual bool GetVSPresentAllPasses() const;
    virtual bool GetVSPresentAnyPass() const;
    virtual bool GetPSPresentAllPasses() const;
    virtual bool GetPSPresentAnyPass() const;

    // *** begin NDL internal use only

    // This is used by the shader factory to flag that this shader was the
    // best implementation for the hardware.
    virtual bool GetIsBestImplementation() const;
    virtual void SetIsBestImplementation(bool bIsBest);
    // *** end NDL internal use only

    static const char* m_pcNDLShaderMapName;

protected:
    bool m_bUsesNiRenderState;
    bool m_bUsesNiLightState;

    // Packing definition
    NiD3DShaderDeclarationPtr m_spShaderDecl;

    // 'Global' render state settings for the shader
    NiD3DRenderStateGroup* m_pkRenderStateGroup;
    //  'Global' pixel shader mapping for the shader
    NiD3DSCM_PixelPtr m_spPixelConstantMap;
    //  'Global' vertex shader mapping for the shader
    NiD3DSCM_VertexPtr m_spVertexConstantMap;

    // Passes
    unsigned int m_uiCurrentPass;
    unsigned int m_uiPassCount;
    NiD3DPassPtr m_spCurrentPass;
    NiTArray<NiD3DPassPtr> m_kPasses;
};

typedef NiPointer<NiD3DShader> NiD3DShaderPtr;

#include "NiD3DShader.inl"

#endif  //#ifndef NID3DSHADER_H
