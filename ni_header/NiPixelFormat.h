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
#ifndef NIPIXELFORMAT_H
#define NIPIXELFORMAT_H

#include "NiMainLibType.h"

class NiStream;

class NIMAIN_ENTRY NiPixelFormat
{
public:
    enum Format
    {
        RGB,
        RGBA,
        PAL,
        PALALPHA,
        COMPRESS1,
        COMPRESS3,
        COMPRESS5,
        RGB24NONINTERLEAVED,
        BUMP,
        BUMPLUMA,
        RENDERERSPECIFIC,
        
        FORMAT_FORCEINT = 0x7fffffff
    };

    // RGB(A) format pixel descriptor
    NiPixelFormat(unsigned int uiRedMask, unsigned int uiGreenMask, 
        unsigned int uiBlueMask, unsigned int uiAlphaMask, 
        unsigned int uiBitsPerPixel);

    // BUMP(LUMA) format pixel descriptor
    NiPixelFormat(unsigned int uiUMask, unsigned int uiVMask, 
        unsigned int uiLumaMask, unsigned int uiBitsPerPixel);

    // Palettized descriptor - bits per pixel must be 4 or 8
    NiPixelFormat(bool bPaletteHasAlpha, unsigned int uiBitsPerPixel=8);

    // Creates the default descriptor of the given type (e.g. RGB maps
    // to RGB24, RGBA maps to RGBA32).  Generally, this should be used
    // for COMPRESSED and INTERLEAVED formats, as RGB24, RGBA32, etc can
    // be accessed directly much faster
    NiPixelFormat(Format eFmt, unsigned int uiBPP = 0);

    // Defaults to PAL8
    NiPixelFormat();

    Format GetFormat() const;

    unsigned char GetBitsPerPixel() const;

    bool GetPalettized() const;
    bool GetPaletteHasAlpha() const;
    bool GetCompressed() const;

    enum Component
    {
        RED = 0,
        BUMP_U = 0,

        GREEN = 1,
        BUMP_V = 1,
        
        BLUE = 2,
        
        ALPHA = 3,
        BUMP_L = 3,
        
        NUM_COMPS = 4
    };

    enum SwizzleType
    {
        SWIZZLE_NONE,
        SWIZZLE_PS2,
        SWIZZLE_XBOX
    };

    SwizzleType GetSwizzleType() const;
    void SetSwizzleType(SwizzleType eSwizzle);

    void GetPixelIdentifier(unsigned int(& auiID)[2]) const;

    unsigned int GetMask(Component eComp) const;
    unsigned char GetBits(Component eComp) const;
    unsigned char GetShift(Component eComp) const;

    bool operator==(const NiPixelFormat& kPixDesc) const;
    bool operator!=(const NiPixelFormat& kPixDesc) const;

    // Represent the Gamebryo "standard" pixel formats
    const static NiPixelFormat PAL4;
    const static NiPixelFormat PALA4;
    const static NiPixelFormat PAL8;
    const static NiPixelFormat PALA8;
    const static NiPixelFormat RGB24;
    const static NiPixelFormat RGBA32;
    const static NiPixelFormat BUMP16;
    const static NiPixelFormat BUMPLUMA32;
    const static NiPixelFormat RGBA16;
    const static NiPixelFormat BGRA16;
    const static NiPixelFormat DXT1;
    const static NiPixelFormat DXT3;
    const static NiPixelFormat DXT5;
    
    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);

    // *** end NDL internal use only ***

protected:
    void InitRGBA(unsigned int uiRedMask, unsigned int uiGreenMask, 
        unsigned int uiBlueMask, unsigned int uiAlphaMask, 
        unsigned int uiBitsPerPixel);
    void InitPalettized(bool bPaletteHasAlpha,
        unsigned int uiBitsPerPixel = 8);
    void InitFromFormatEnum(Format eFmt, unsigned int uiBPP = 0);
    void InitBump(unsigned int uiUMask, unsigned int uiVMask, 
        unsigned int uiLumaMask, unsigned int uiBitsPerPixel);

    static unsigned int GetLeastSignificant1Bit(unsigned int uiArg);
    static unsigned int GetLeastSignificant0Bit(unsigned int uiArg);
    static void ComputeFlagsFromMask(unsigned int uiMask, 
        Component eComp, unsigned int &uiBitsFlags, 
        unsigned int &uiOffsetFlags);

    Format m_eFormat;
    SwizzleType m_eSwizzle;

    unsigned int m_auiColorMasks[NUM_COMPS];
    unsigned int m_uiBitsPerPixel;
    unsigned int m_auiFastCompare[2]; // 64-bit fast compare value
    // Fast compare format bits are:
    // DWORD 0:
    // 0-4: Overall format (0=PAL, 1=PALA, 2=RGB, 3=RGBA, 4-6=compress, ...)
    // 5-7 : Bits per pixel 
    //      (0=compressed, 1=8bpp, 2=16bpp, 3=24bpp, 4=32bpp, 5=4bpp, 6=64bpp,
    //       7=128bpp)
    // 8-13 : Bits Red/U (0-32)
    // 14-19 : Bits Green/V (0-32)
    // 20-25 : Bits Blue (0-32)
    // 26-31 : Bits Alpha/Luma (0-32)
    // DWORD 1:
    // 0-7 : Red/U LSBit (0-255)
    // 8-15 : Green/V LSBit (0-255)
    // 16-23 : Blue LSBit (0-255)
    // 24-31 : Alpha/Luma LSBit (0-255)

    static unsigned int ms_uiFormatMask;
    static unsigned int ms_uiFormatShift;
    static unsigned int ms_uiBPPMask;
    static unsigned int ms_uiBPPShift;
    static unsigned int ms_auiColorBitsMask[NUM_COMPS];
    static unsigned int ms_auiColorBitsShift[NUM_COMPS];
    static unsigned int ms_auiColorOffsetMask[NUM_COMPS];
    static unsigned int ms_auiColorOffsetShift[NUM_COMPS];
};

#include "NiPixelFormat.inl"

#endif
