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
#ifndef NIDX8RENDERTARGET_H
#define NIDX8RENDERTARGET_H

#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"

class NiDX8PixelFormat;

//---------------------------------------------------------------------------
// Abstract base class designed to represent all rendering targets
class NIDX8RENDERER_ENTRY NiDX8RenderTarget
{
public:
    virtual ~NiDX8RenderTarget();

    // *** begin NDL internal use only ***

    virtual bool Swap() = 0;

    bool SetRenderTarget(LPDIRECT3DDEVICE8 pkD3DDevice8);

    unsigned int GetWidth() const { return m_uiWidth; }
    unsigned int GetHeight() const { return m_uiHeight; }

    bool HasDepthStencil() { return m_pkDepthStencil ? true : false; }

    bool IsValid() { return m_pkRenderTarget ? true : false; }

    const NiDX8PixelFormat& GetPixelFormat() 
        { return *m_pkRenderImagePixFmt; }

    LPDIRECT3DSURFACE8 GetTargetSurface() { return m_pkRenderTarget; }
    LPDIRECT3DSURFACE8 GetDepthStencil() { return m_pkDepthStencil; }

    // *** end NDL internal use only ***

protected:
    NiDX8RenderTarget();
    virtual void ReleaseReferences();
    void ReleaseRTReferences();

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
    LPDIRECT3DSURFACE8 m_pkRenderTarget;
    LPDIRECT3DSURFACE8 m_pkDepthStencil;

    NiDX8PixelFormat* m_pkRenderImagePixFmt;
};
//---------------------------------------------------------------------------
// Class representing textures to which the system can render
class NIDX8RENDERER_ENTRY NiDX8TextureRenderTarget 
    : public NiDX8RenderTarget
{
public:
    ~NiDX8TextureRenderTarget();

    static NiDX8TextureRenderTarget* Create(LPDIRECT3DTEXTURE8 pkD3DTexture,
        D3DFORMAT eD3DDepthStencilFormat, LPDIRECT3DDEVICE8 pkD3DDevice8);
    static NiDX8TextureRenderTarget* Create(LPDIRECT3DTEXTURE8 pkD3DTexture,
        LPDIRECT3DSURFACE8 pkD3DDepthStencil);
    static NiDX8TextureRenderTarget* CreateCubeFace(
        LPDIRECT3DCUBETEXTURE8 pkD3DCubeTexture, D3DCUBEMAP_FACES eFace, 
        NiDX8TextureRenderTarget* pkExistingFace, 
        LPDIRECT3DDEVICE8 pkD3DDevice8);
    static NiDX8TextureRenderTarget* CreateCubeFace(
        LPDIRECT3DCUBETEXTURE8 pkD3DCubeTexture, D3DCUBEMAP_FACES eFace, 
        NiDX8TextureRenderTarget* pkExistingFace, 
        LPDIRECT3DSURFACE8 pkD3DDepthStencil);

    // *** begin NDL internal use only ***

    virtual bool Swap();

    // *** end NDL internal use only ***

protected:
    NiDX8TextureRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseTRTReferences();

    LPDIRECT3DBASETEXTURE8 m_pkRenderTexture;
};
//---------------------------------------------------------------------------
// Abstract class representing rendering targets that are visible on-screen,
// either windowed or fullscreen
class NIDX8RENDERER_ENTRY NiDX8OnscreenRenderTarget 
    : public NiDX8RenderTarget
{
public:
    // *** begin NDL internal use only ***
    virtual bool Shutdown() = 0;
    // Rebuilds the surfaces after a device reset - returns false if the
    // target could not be successfully reset at the time of the call
    // In such cases, this call will leave the object with IsValid false
    virtual bool Recreate(LPDIRECT3DDEVICE8 pkD3DDevice8) = 0;

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
class NIDX8RENDERER_ENTRY NiDX8ImplicitRenderTarget 
    : public NiDX8OnscreenRenderTarget
{
public:
    ~NiDX8ImplicitRenderTarget();
    
    // *** begin NDL internal use only ***
    virtual bool Swap();

    virtual bool Shutdown();
    virtual bool Recreate(LPDIRECT3DDEVICE8 pkD3DDevice8);

    // Creates a new render target object, but only queries the existing 
    // buffers from the device - it does not create new ones
    static NiDX8ImplicitRenderTarget* Create(LPDIRECT3DDEVICE8 pkD3DDevice8,
        const D3DPRESENT_PARAMETERS& kD3DPresentParams);
    // *** end NDL internal use only ***

protected:
    NiDX8ImplicitRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseIRTReferences();

    LPDIRECT3DDEVICE8 m_pkD3DDevice8;
};
//---------------------------------------------------------------------------
// Class representing a render target that was created after the device,
// generally as a secondary window.  Such render targets are created from
// swap chain objects, and are thus called SwapChain render targets
class NIDX8RENDERER_ENTRY NiDX8SwapChainRenderTarget 
    : public NiDX8OnscreenRenderTarget
{
public:
    ~NiDX8SwapChainRenderTarget();

    // *** begin NDL internal use only ***
    virtual bool Swap();

    virtual bool Shutdown();
    virtual bool Recreate(LPDIRECT3DDEVICE8 pkD3DDevice8);

    // Creates a new target for the given device based on the given creation
    // parameters, including backbuffers and a depth/stencil surface.
    // Returns NULL on failure
    static NiDX8SwapChainRenderTarget* Create(
        LPDIRECT3DDEVICE8 pkD3DDevice8, 
        const D3DPRESENT_PARAMETERS& kD3DPresentParams);
    // *** end NDL internal use only ***

protected:
    NiDX8SwapChainRenderTarget();
    virtual void ReleaseReferences();
    void ReleaseSCRTReferences();

    // The swap chain contains references to all of the backbuffers for the
    // target.  The base class m_pkRenderTarget holds a reference to the
    // first backbuffer, which it uses for rendering
    IDirect3DSwapChain8* m_pkSwapChain;
};
//---------------------------------------------------------------------------

#endif
