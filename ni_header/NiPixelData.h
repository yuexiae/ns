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

#ifndef NIPIXELDATA_H
#define NIPIXELDATA_H

#include "NiObject.h"
#include "NiPalette.h"
#include "NiPixelFormat.h"

class NIMAIN_ENTRY NiPixelData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPixelData(unsigned int uiWidth, unsigned int uiHeight,
        const NiPixelFormat& kDesc, unsigned int uiMipmapLevels = 1);
    NiPixelData(const NiPixelData& kSrc);
    ~NiPixelData();
    
    // The base image is counted as a mip-map level
    unsigned int GetNumMipmapLevels() const;

    unsigned int GetWidth(unsigned int uiMipmapLevel = 0) const;
    unsigned int GetHeight(unsigned int uiMipmapLevel = 0) const;

    unsigned int GetPixelStride() const;

    unsigned int GetSizeInBytes(unsigned int uiMipmapLevel = 0) const;

    unsigned int GetTotalSizeInBytes() const;

    const NiPixelFormat& GetPixelFormat() const;

    void SetPalette(NiPalette* pkPal);
    const NiPalette* GetPalette() const;
    NiPalette* GetPalette();

    const unsigned char* GetPixels(unsigned int uiMipmapLevel = 0) const;
    unsigned char* GetPixels(unsigned int uiMipmapLevel = 0);

    void MarkAsChanged();

    unsigned int GetRevisionID() const;

    void MarkAsSwizzled(NiPixelFormat::SwizzleType eSwizzle);

    const unsigned char* operator()(unsigned int uiX, unsigned int uiY, 
        unsigned int uiMipmapLevel = 0) const;
    unsigned char* operator()(unsigned int uiX, unsigned int uiY, 
        unsigned int uiMipmapLevel = 0);

    static unsigned int ComputeMipmapLevels (unsigned int uiWidth, 
        unsigned int uiHeight);

protected:
    NiPixelData(); 

    void AllocateData(unsigned int uiLevels, unsigned int uiBytes);
    void FreeData();

#if defined(NGC)
    void ByteSwap16();
#endif

    NiPixelFormat m_kPixelFormat;

    NiPalettePtr m_spPalette;

    unsigned char* m_pucPixels; // [pixels for all miplevels]

    unsigned int* m_puiWidth; // [miplevels] 
    unsigned int* m_puiHeight; // [miplevels] 
    unsigned int* m_puiOffsetInBytes; // [miplevels+1] 

    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
};

typedef NiPointer<NiPixelData> NiPixelDataPtr;

#include "NiPixelData.inl"

#endif
