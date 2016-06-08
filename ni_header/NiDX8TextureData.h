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
#ifndef NIDX8TEXTUREDATA_H
#define NIDX8TEXTUREDATA_H

#include "NiDX8PixelFormat.h"
#include "NiSourceTexture.h"

class NiDX8Renderer;
class NiDX8RenderedTextureData;
class NiDX8SourceTextureData;

class NIDX8RENDERER_ENTRY NiDX8TextureData : public NiTexture::RendererData
{
public:
    NiDX8TextureData(NiTexture* pkTexture, NiDX8Renderer* pkRenderer);
    virtual ~NiDX8TextureData();

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;
    virtual unsigned int GetLevels() const;
    virtual const NiPixelFormat* GetPixelFormat() const;
    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const = 0;
    virtual unsigned int GetD3DPalette() const;

    virtual NiDX8RenderedTextureData* GetAsRenderedTexture() { return NULL; }
    virtual NiDX8SourceTextureData* GetAsSourceTexture() { return NULL; }

    static const NiDX8PixelFormat* FindClosestPixelFormat(
        NiDX8Renderer* pkRenderer, const NiTexture::FormatPrefs& kPrefs,
        NiDX8PixelFormat** ppkDestFmts);

    static void ClearTextureData(NiDX8Renderer* pkRenderer);

protected:
    const NiDX8PixelFormat* FindMatchingPixelFormat(
        const NiPixelFormat& kSrcFmt, const NiTexture::FormatPrefs& kPrefs,
        NiDX8PixelFormat** ppkDestFmts);

    virtual bool InitializeFromD3DTexture(
        LPDIRECT3DBASETEXTURE8 pkD3DTexture);

    static bool IsPowerOf2(unsigned int uiI);

    NiDX8Renderer* m_pkRenderer;
    NiDX8PixelFormat m_kPixelFormat;

    unsigned int m_uiPalette;
    unsigned int m_uiPalRevID;

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
    unsigned int m_uiLevels;
};

#include "NIDX8TextureData.inl"

#endif  //#ifndef NiDX8TEXTUREDATA_H
