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
//---------------------------------------------------------------------------
#ifndef NIDX9RENDERTARGET_H
#define NIDX9RENDERTARGET_H

#include "NiDX9Headers.h"
#include "NiDX9RendererLibType.h"

class NiDX9PixelFormat;

//---------------------------------------------------------------------------
// Abstract base class designed to represent all rendering targets
class NIDX9RENDERER_ENTRY NiDX9RenderTarget
{
public:
    virtual ~NiDX9RenderTarget();

    // *** begin NDL internal use only ***
    virtual bool Swap() = 0;

    bool SetRenderTarget(LPDIRECT3DDEVICE9 pkD3DDevice9, 
        unsigned int uiTarget = 0);
    static void ClearRenderTarget(LPDIRECT3DDEVICE9 pkD3DDevice9, 
        unsigned int uiTarget);

    unsigned int GetWidth() const { return m_uiWidth; }
    unsigned int GetHeight() const { return m_uiHeight; }

    bool HasDepthStencil() { return m_pkDepthStencil ? true : false; }

    bool IsValid() { return m_pkRenderTarget ? true : false; }

    const NiDX9PixelFormat& GetPixelFormat() 
        { return *m_pkRenderImagePixFmt; }

    LPDIRECT3DSURFACE9 GetTargetSurface() { return m_pkRenderTarget; }
    LPDIRECT3DSURFACE9 GetDepthStencil() { return m_pkDepthStencil; }

    // *** end NDL internal use only ***

protected:
    NiDX9RenderTarget();
    virtual void ReleaseReferences();
    void ReleaseRTReferences();

    bool CheckMRTCompatibility(unsigned int uiCompareTarget) const;

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
    LPDIRECT3DSURFACE9 m_pkRenderTarget;
    LPDIRECT3DSURFACE9 m_pkDepthStencil;

    NiDX9PixelFormat* m_pkRenderImagePixFmt;

    static LPDIRECT3DSURFACE9 ms_apkCurrentRenderTarget[4];
    static LPDIRECT3DSURFACE9 ms_pkCurrentDepthStencil;

    static unsigned int ms_uiNumRenderTargets;
    static bool ms_bIndependentBitDepths;
};
//---------------------------------------------------------------------------
// Class representing textures to which the system can render
class NIDX9RENDERER_ENTRY NiDX9TextureRenderTarget : 
    public NiDX9RenderTarget
{
public:
    ~NiDX9TextureRenderTarget();

    static NiDX9TextureRenderTarget* Create(LPDIRECT3DTEXTURE9 pkD3DTexture,
        D3DFORMAT eD3DDepthStencilFormat, LPDIRECT3DDEVICE9 pkD3DDevice9);
    static NiDX9TextureRenderTarget* Create(LPDIRECT3DTEXTURE9 pkD3DTexture,
        LPDIRECT3DSURFACE9 pkD3DDepthStencil);
    static NiDX9TextureRenderTarget* CreateCubeFace(
        LPDIRECT3DCUBETEXTURE9 pkD3DCubeTexture, D3DCUBEMAP_FACES eFace, 
        NiDX9TextureRenderTarget* pkExistingFace, 
        LPDIRECT3DDEVICE9 pkD3DDevice9);
    static NiDX9TextureRenderTarget* CreateCubeFace(
        LPDIRECT3DCUBETEXTURE9 pkD3DCubeTexture, D3DCUBEMAP_FACES eFace, 
        NiDX9TextureRenderTarget* pkExistingFace, 
        LPDIRECT3DSURFACE9 pkD3DDepthStencil);

    // *** begin NDL internal use only ***

    virtual bool Swap();

    // *** end NDL internal use only ***

protected:
    NiDX9TextureRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseTRTReferences();

    LPDIRECT3DBASETEXTURE9 m_pkRenderTexture;
};
//---------------------------------------------------------------------------
// Abstract class representing rendering targets that are visible on-screen,
// either windowed or fullscreen
class NIDX9RENDERER_ENTRY NiDX9OnscreenRenderTarget : 
    public NiDX9RenderTarget
{
public:
    // *** begin NDL internal use only ***
    virtual bool Shutdown() = 0;
    // Rebuilds the surfaces after a device reset - returns false if the
    // target could not be successfully reset at the time of the call
    // In such cases, this call will leave the object with IsValid false
    virtual bool Recreate(LPDIRECT3DDEVICE9 pkD3DDevice9) = 0;

    D3DPRESENT_PARAMETERS& GetPresentParams() 
    { return m_kD3DPresentParams; }
    // *** end NDL internal use only ***

protected:
    D3DPRESENT_PARAMETERS m_kD3DPresentParams;
};
//---------------------------------------------------------------------------
// Class representing the render target that is created along with a device,
// which is considered "implicit", as the device owns a special reference to 
// it
class NIDX9RENDERER_ENTRY NiDX9ImplicitRenderTarget : 
    public NiDX9OnscreenRenderTarget
{
public:
    ~NiDX9ImplicitRenderTarget();
    
    // *** begin NDL internal use only ***
    virtual bool Swap();

    virtual bool Shutdown();
    virtual bool Recreate(LPDIRECT3DDEVICE9 pkD3DDevice9);

    // Creates a new render target object, but only queries the existing 
    // buffers from the device - it does not create new ones
    static NiDX9ImplicitRenderTarget* Create(LPDIRECT3DDEVICE9 pkD3DDevice9,
        const D3DPRESENT_PARAMETERS& kD3DPresentParams);
    // *** end NDL internal use only ***

protected:
    NiDX9ImplicitRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseIRTReferences();

    LPDIRECT3DDEVICE9 m_pkD3DDevice9;
};
//---------------------------------------------------------------------------
// Class representing a render target that was created after the device,
// generally as a secondary window.  Such render targets are created from
// swap chain objects, and are thus called SwapChain render targets
class NIDX9RENDERER_ENTRY NiDX9SwapChainRenderTarget : 
    public NiDX9OnscreenRenderTarget
{
public:
    ~NiDX9SwapChainRenderTarget();

    // *** begin NDL internal use only ***
    virtual bool Swap();

    virtual bool Shutdown();
    virtual bool Recreate(LPDIRECT3DDEVICE9 pkD3DDevice9);

    // Creates a new target for the given device based on the given creation
    // parameters, including backbuffers and a depth/stencil surface.
    // Returns NULL on failure
    static NiDX9SwapChainRenderTarget* Create(
        LPDIRECT3DDEVICE9 pkD3DDevice9, 
        const D3DPRESENT_PARAMETERS& kD3DPresentParams);
    // *** end NDL internal use only ***

protected:
    NiDX9SwapChainRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseSCRTReferences();

    // The swap chain contains references to all of the backbuffers for the
    // target.  The base class m_pkRenderTarget holds a reference to the
    // first backbuffer, which it uses for rendering
    LPDIRECT3DSWAPCHAIN9 m_pkSwapChain;
};
//---------------------------------------------------------------------------

#endif
