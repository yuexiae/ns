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
#ifndef NIDX9SOURCETEXTUREDATA_H
#define NIDX9SOURCETEXTUREDATA_H

#include "NiDX9TextureData.h"

//---------------------------------------------------------------------------
class NIDX9RENDERER_ENTRY NiDX9SourceTextureData : public NiDX9TextureData
{
public:
    static NiDX9SourceTextureData* Create(NiSourceTexture* pkTexture, 
        NiDX9Renderer* pkRenderer);
    virtual ~NiDX9SourceTextureData();

    virtual bool IsLoaded() const;

    virtual NiDX9SourceTextureData* GetAsSourceTexture() { return this; }

    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const;

    virtual NiPalette* GetPalette() {   return m_spPalette; };

    virtual void Update();

    static bool SetMipmapSkipLevel(unsigned int uiSkip);
    static unsigned int GetMipmapSkipLevel();

protected:
    NiDX9SourceTextureData(NiSourceTexture* pkTexture, 
        NiDX9Renderer* pkRenderer);

    virtual bool InitializeFromD3DTexture(
        LPDIRECT3DBASETEXTURE9 pkD3DTexture);

    bool UpdatePalette(NiPalette* pkNewPalette);

    static void CopyDataToSurfaceLevel(const NiPixelData& kPixels, 
        unsigned int uiLevel, LPDIRECT3DSURFACE9 pkMipLevel);

    bool m_bReplacementData;
    bool m_bMipmap;
    unsigned int m_uiFormattedSize;

    NiPalettePtr m_spPalette;
    unsigned int m_uiPalRevID;      // used w/ palettized src & RGB(A) dest

    unsigned int m_uiLevelsSkipped;

    static unsigned int ms_uiSkipLevels;
private:
    // The following are declared private, as they are used only for the
    // implementation of source-based single textures, and have no relation
    // to the more general source-texture interfaces themselves
    bool CreateSurf(const NiPixelData& kPixels);
    void CopyDataToSurface(const NiPixelData& kPixels);

    bool LoadTextureFile(const char* pcFilename, NiDX9Renderer* pkRenderer,
        const NiTexture::FormatPrefs& kPrefs);

    LPDIRECT3DBASETEXTURE9 m_pkD3DTexture;

    unsigned int m_uiSourceRevID;   // can be compared with source PixelData
};

//---------------------------------------------------------------------------
inline bool NiDX9SourceTextureData::SetMipmapSkipLevel(unsigned int uiSkip)
{
    ms_uiSkipLevels = uiSkip;
    return true;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9SourceTextureData::GetMipmapSkipLevel()
{
    return ms_uiSkipLevels;
}
//---------------------------------------------------------------------------

#endif  //#ifndef NIDX9SOURCETEXTUREDATA_H
