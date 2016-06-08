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
#ifndef NIDDSREADER_H
#define NIDDSREADER_H

#include "NiImageReader.h"
#include "NiPixelFormat.h"

class NIMAIN_ENTRY NiDDSReader : public NiImageReader
{
public:
    NiDDSReader();
    ~NiDDSReader();

    virtual bool CanReadFile(const char* pcFileExtension) const;

    virtual NiPixelData* ReadFile(NiFile& kIst, NiPixelData* pkOptDest);

    virtual bool ReadHeader(NiFile& kIst, 
        unsigned int& uiWidth, unsigned int& uiHeight, 
        NiPixelFormat& kFormat, bool& bMipmap);

protected:
    enum 
    {
        NI_ALPHAPIXELS  = 0x00000001,
        NI_FOURCC       = 0x00000004,
        NI_RGB          = 0x00000040 
    };

    enum 
    {
        NI_DXTC1 = 0x31545844,
        NI_DXTC3 = 0x33545844,
        NI_DXTC5 = 0x35545844
    };

    enum
    {
        NI_DDS = 0x20534444
    };

    enum
    {
        NI_DDSD_CAPS = 0x00000001,
        NI_DDSD_HEIGHT = 0x00000002,
        NI_DDSD_WIDTH = 0x00000004,
        NI_DDSD_PIXELFORMAT = 0x00001000,
        NI_DDSD_LINEARSIZE = 0x00080000,
        NI_DDSD_DEPTH = 0x00800000
    };

    enum
    {
        NI_DDSCAPS_COMPLEX = 0x00000008,
        NI_DDSCAPS_TEXTURE = 0x00001000,
        NI_DDSCAPS_MIPMAP = 0x00400000
    };

    enum
    {
        NI_DDSCAPS2_CUBEMAP = 0x00000200,
        NI_DDSCAPS2_VOLUME = 0x00200000
    };

    unsigned int m_uiHeight;
    unsigned int m_uiWidth;
    unsigned int m_uiMipmapLevels;
    NiPixelFormat m_kFormat;

    NiPixelFormat ComputeFinalFormat(const NiPixelFormat kSrcFormat);
    bool ValidateRGBABitmasks(unsigned int uiRedMask, 
        unsigned int uiGreenMask, unsigned int uiBlueMask, 
        unsigned int uiAlphaMask, unsigned int uiBitsPerPixel);

    static void Read24Bit(NiFile& kIst, NiPixelData* pkDest,
        NiPixelFormat kSrcFmt, NiPixelFormat kDestFmt, unsigned int uiMipMapIdx);
    static void Read32Bit(NiFile& kIst, NiPixelData* pkDest,
        NiPixelFormat kSrcFmt, NiPixelFormat kDestFmt, unsigned int uiMipMapIdx);
    static void Read16Bit(NiFile& kIst, NiPixelData* pkDest,
        NiPixelFormat kSrcFmt, NiPixelFormat kDestFmt, unsigned int uiMipMapIdx);

    unsigned int CalcMaskSize(unsigned int uiMask);

};

#endif
