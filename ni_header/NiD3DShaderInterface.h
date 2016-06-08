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

#ifndef NID3DSHADERINTERFACE_H
#define NID3DSHADERINTERFACE_H

#include <NiShader.h>
#include <NiGeometry.h>
#include <NiSmartPointer.h>

#include "NiD3DDefines.h"
#include "NiD3DError.h"

class NiD3DRenderState;
NiSmartPointer(NiD3DRenderState);
class NiD3DShaderDeclaration;
#if defined(_XBOX)
class NiXBoxVBCache;
#endif  //#if defined(_XBOX)

// NiD3DShaderInterface
// Shader derived for D3D-based renderers. (DX8/DX9/Xbox)

class NID3D_ENTRY NiD3DShaderInterface : public NiShader
{
    NiDeclareRTTI;

    // *** begin NDL internal use only ***
protected:
    void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    void SetD3DRenderState(NiD3DRenderState* pkRS);
public:
    void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    
    // Called by the renderer upon creation.
    // This can not go into the SDM initialization scheme, as it requires
    // an intialized renderer!
    static NiD3DError InitializeShaderSystem(NiD3DRenderer* pkD3DRenderer);
    static NiD3DError ShutdownShaderSystem();
    // *** end NDL internal use only ***

public:
    NiD3DShaderInterface();
    virtual ~NiD3DShaderInterface();

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
    virtual unsigned int PostRender(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, 
        const NiSkinPartition::Partition* pkPartition, 
        NiGeometryBufferData* pkBuffData, const NiPropertyState* pkState, 
        const NiDynamicEffectState* pkEffects, const NiTransform& kWorld, 
        const NiBound& kWorldBound);
    virtual unsigned int PostProcessPipeline(NiGeometry* pkGeometry, 
        const NiSkinInstance* pkSkin, NiGeometryBufferData* pkBuffData, 
        const NiPropertyState* pkState, const NiDynamicEffectState* pkEffects,
        const NiTransform& kWorld, const NiBound& kWorldBound);

    // Advance to the next pass.
    virtual unsigned int FirstPass();
    virtual unsigned int NextPass();

    // Shader Declaration (Packing definition)
    virtual NiD3DShaderDeclaration* GetShaderDecl() const;
    virtual void SetShaderDecl(NiD3DShaderDeclaration* pkShaderDecl);

    // Allow for device resets
    virtual void HandleLostDevice();
    virtual void HandleResetDevice();

    // This function is called by NiShaderFactory::AttachShader, and
    // is used to verify the geometry is usable for the shader, as well
    // as to 'process' the geometry, adding what is needed.
    virtual bool SetupGeometry(NiGeometry* pkGeometry);

    // Allow for complete shader reconstruction
    virtual void DestroyRendererData();
    virtual void RecreateRendererData();

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

protected:
    // D3DDevice, Renderer, and RenderState access members
    D3DDevicePtr m_pkD3DDevice;
    // Use standard pointers to prevent circular dependencies
    NiD3DRenderer* m_pkD3DRenderer;
    NiD3DRenderState* m_pkD3DRenderState;
#if defined(_XBOX)
    NiXBoxVBCache* m_pkVBCache;
#endif  //#if defined(_XBOX)

    bool m_bInitialized;
    bool m_bIsBestImplementation;
};

typedef NiPointer<NiD3DShaderInterface> NiD3DShaderInterfacePtr;

#include "NiD3DShaderInterface.inl"

#endif  //#ifndef NID3DSHADERINTERFACE_H
