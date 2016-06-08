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
#ifndef NIDX9TEXTUREDATA_H
#define NIDX9TEXTUREDATA_H

#include "NiDX9PixelFormat.h"
#include "NiSourceTexture.h"

class NiDX9Renderer;
class NiDX9RenderedTextureData;
class NiDX9SourceTextureData;

class NIDX9RENDERER_ENTRY NiDX9TextureData : public NiTexture::RendererData
{
public:
    NiDX9TextureData(NiTexture* pkTexture, NiDX9Renderer* pkRenderer);
    virtual ~NiDX9TextureData();

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;
    virtual unsigned int GetLevels() const;
    virtual const NiPixelFormat* GetPixelFormat() const;
    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const = 0;
    virtual unsigned int GetD3DPalette() const;

    virtual NiDX9RenderedTextureData* GetAsRenderedTexture() { return NULL; }
    virtual NiDX9SourceTextureData* GetAsSourceTexture() { return NULL; }

    static const NiDX9PixelFormat* FindClosestPixelFormat(
        NiDX9Renderer* pkRenderer, const NiTexture::FormatPrefs& kPrefs,
        NiDX9PixelFormat** ppkDestFmts);

    static void ClearTextureData(NiDX9Renderer* pkRenderer);

protected:
    const NiDX9PixelFormat* FindMatchingPixelFormat(
        const NiPixelFormat& kSrcFmt, const NiTexture::FormatPrefs& kPrefs,
        NiDX9PixelFormat** ppkDestFmts);

    virtual bool InitializeFromD3DTexture(
        LPDIRECT3DBASETEXTURE9 pkD3DTexture);

    static bool IsPowerOf2(unsigned int uiI);

    NiDX9Renderer* m_pkRenderer;
    NiDX9PixelFormat m_kPixelFormat;

    unsigned int m_uiPalette;
    unsigned int m_uiPalRevID;

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
    unsigned int m_uiLevels;
};

#include "NIDX9TextureData.inl"

#endif  //#ifndef NiDX9TEXTUREDATA_H
