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
#ifndef NIDX8RENDEREDEXTUREDATA_H
#define NIDX8RENDEREDEXTUREDATA_H

#include "NiDX8TextureData.h"
#include "NiDX8Renderer.h"

class NiDX8TextureRenderTarget;
class NiRenderedTexture;

//---------------------------------------------------------------------------
class NIDX8RENDERER_ENTRY NiDX8RenderedTextureData : public NiDX8TextureData
{
public:
    static NiDX8RenderedTextureData* Create(NiRenderedTexture* pkTexture, 
        NiDX8Renderer* pkRenderer);
    virtual ~NiDX8RenderedTextureData();

    virtual bool IsLoaded() const;

    virtual NiDX8RenderedTextureData* GetAsRenderedTexture() { return this; }

    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const;

    virtual NiDX8TextureRenderTarget* GetTarget() 
    { return m_pkTarget; }

protected:
    NiDX8RenderedTextureData(NiRenderedTexture* pkTexture, 
        NiDX8Renderer* pkRenderer);

    NiDX8PixelFormat m_kPixelFormat;

private:
    // The following are declared private, as they are used only for the
    // implementation of rendered, single textures, and have no relation
    // to the more general rendered-texture interfaces themselves
    NiDX8PixelFormat* CreateSurf(const NiRenderedTexture* pkTexture,
        NiDX8Renderer::TexFormat& eFmt);

    LPDIRECT3DTEXTURE8 m_pkD3DTexture;
    NiDX8TextureRenderTarget* m_pkTarget;
};

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX8RENDEREDEXTUREDATA_H
