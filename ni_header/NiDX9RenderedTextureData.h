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
#ifndef NIDX9RENDEREDEXTUREDATA_H
#define NIDX9RENDEREDEXTUREDATA_H

#include "NiDX9TextureData.h"
#include "NiDX9Renderer.h"

class NiDX9TextureRenderTarget;
class NiRenderedTexture;

//---------------------------------------------------------------------------
class NIDX9RENDERER_ENTRY NiDX9RenderedTextureData : public NiDX9TextureData
{
public:
    static NiDX9RenderedTextureData* Create(NiRenderedTexture* pkTexture, 
        NiDX9Renderer* pkRenderer);
    virtual ~NiDX9RenderedTextureData();

    virtual bool IsLoaded() const;

    virtual NiDX9RenderedTextureData* GetAsRenderedTexture() { return this; }

    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const;

    virtual NiDX9TextureRenderTarget* GetTarget() 
    { return m_pkTarget; }

protected:
    NiDX9RenderedTextureData(NiRenderedTexture* pkTexture, 
        NiDX9Renderer* pkRenderer);

    NiDX9PixelFormat m_kPixelFormat;

private:
    // The following are declared private, as they are used only for the
    // implementation of rendered, single textures, and have no relation
    // to the more general rendered-texture interfaces themselves
    NiDX9PixelFormat* CreateSurf(const NiRenderedTexture* pkTexture,
        NiDX9Renderer::TexFormat& eFmt);

    LPDIRECT3DTEXTURE9 m_pkD3DTexture;
    NiDX9TextureRenderTarget* m_pkTarget;
};

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX9RENDEREDEXTUREDATA_H
