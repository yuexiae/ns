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

#ifndef NIDEVIMAGEQUANTIZER_H
#define NIDEVIMAGEQUANTIZER_H

#include <NiDevImageConverter.h>
#include "NiDevImageQuantizerLibType.h"

class QuantizeUtil;
struct IDirectDraw7;

//---------------------------------------------------------------------------
class NIDEVIMAGEQUANTIZER_ENTRY NiDevImageQuantizer : public NiDevImageConverter
{
public:
    static NiDevImageQuantizer* Create();

    virtual ~NiDevImageQuantizer();
    
    static NiPixelDataPtr ProcessPixelData(NiPixelDataPtr spPixelData, 
        NiTexture::FormatPrefs kPrefs, bool bMipMap, bool bUseAlphaIfAvailable,
        NiPixelFormat kDestFormat, unsigned int uiSizeDivideBy, bool bPS23Pass, 
        NiDevImageConverter::Platform ePlatform, 
        float fOutputLevel, const char* pcFilename, char* pcErrorBuffer, 
        unsigned int uiErrorBufferLength);

    static char* GetImageFormatString(NiPixelFormat kFormat);
    static unsigned int CalcMaskSize(unsigned int uiMask);

    virtual bool CanConvertPixelData(const NiPixelFormat& kSrcFmt, 
        const NiPixelFormat& kDestFmt);

    virtual NiPixelData* ConvertPixelData(const NiPixelData& kSrc, 
        const NiPixelFormat& kDestFmt, NiPixelData* pkOptDest, bool bMipmap);

    virtual bool ConvertPixelDataFormat(NiPixelData& kDest, 
        const NiPixelData& kSrc, int iMipmapLevel = 0);

    virtual bool IsAnAlphaSupportedMipmapGenerationFormat(const 
        NiPixelFormat& kSrcFmt);

    virtual bool IsANonAlphaSupportedMipmapGenerationFormat(const 
        NiPixelFormat& kSrcFmt);

    virtual NiPixelDataPtr GenerateMipmapLevels(NiPixelDataPtr spSrc, 
        NiPixelDataPtr spOptDest);

    // *** begin NDL internal use only ***
    void SetNumberOfColorBits( unsigned int uiColorBits );

    const static NiPixelFormat XBOX_COMPRESS1;
    const static NiPixelFormat XBOX_COMPRESS3;
    const static NiPixelFormat XBOX_COMPRESS5;
    // *** end NDL internal use only ***

protected:
    NiDevImageQuantizer();
    
    // Incoming format of kSrc _must_ be m_kRGBAFormat
    bool Quantize(NiPixelData& kDest, const NiPixelData& kSrc, 
        int iMipmapLevel);

    static bool FormatHasAlpha(NiPixelFormat eFormat);
    static bool ConvertIfNecessaryForAlphaSwitch(NiPixelFormat& eFormat);

    const NiPixelFormat m_kRGBAFormat;
    QuantizeUtil *m_pQuantUtil;

    // Adds the compressed formats as options, since this version can 
    // compress the textures on the fly
    virtual const NiPixelFormat* FindClosestPixelFormatXBOX(
        const NiTexture::FormatPrefs& kFmtPrefs, 
        const NiPixelFormat& kSrcFmt,
        const NiPixelFormat& kDesiredFmt);

    // Incoming format of kSrc _must_ be m_kRGBAFormat
    bool Compress(NiPixelData& kDest, const NiPixelData& kSrc, 
        int iMipmapLevel);

    IDirectDraw7* m_pkDD7;
    void* m_pkDDrawDLL;

};

//---------------------------------------------------------------------------

#endif
