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
#ifndef NIDX8SOURCETEXTUREDATA_H
#define NIDX8SOURCETEXTUREDATA_H

#include "NiDX8TextureData.h"

//---------------------------------------------------------------------------
class NIDX8RENDERER_ENTRY NiDX8SourceTextureData : public NiDX8TextureData
{
public:
    static NiDX8SourceTextureData* Create(NiSourceTexture* pkTexture, 
        NiDX8Renderer* pkRenderer);
    virtual ~NiDX8SourceTextureData();

    virtual bool IsLoaded() const;

    virtual NiDX8SourceTextureData* GetAsSourceTexture() { return this; }

    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const;

    virtual NiPalette* GetPalette() {   return m_spPalette; };

    virtual void Update();

    static bool SetMipmapSkipLevel(unsigned int uiSkip);
    static unsigned int GetMipmapSkipLevel();

protected:
    NiDX8SourceTextureData(NiSourceTexture* pkTexture, 
        NiDX8Renderer* pkRenderer);

    virtual bool InitializeFromD3DTexture(
        LPDIRECT3DBASETEXTURE8 pkD3DTexture);

    bool UpdatePalette(NiPalette* pkNewPalette);

    static void CopyDataToSurfaceLevel(const NiPixelData& kPixels, 
        unsigned int uiLevel, LPDIRECT3DSURFACE8 pkMipLevel);

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

    bool LoadTextureFile(const char* pcFilename, NiDX8Renderer* pkRenderer,
        const NiTexture::FormatPrefs& kPrefs);

    LPDIRECT3DBASETEXTURE8 m_pkD3DTexture;

    unsigned int m_uiSourceRevID;   // can be compared with source PixelData
};

//---------------------------------------------------------------------------
inline bool NiDX8SourceTextureData::SetMipmapSkipLevel(unsigned int uiSkip)
{
    ms_uiSkipLevels = uiSkip;
    return true;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8SourceTextureData::GetMipmapSkipLevel()
{
    return ms_uiSkipLevels;
}
//---------------------------------------------------------------------------

#endif  //#ifndef NIDX8SOURCETEXTUREDATA_H
