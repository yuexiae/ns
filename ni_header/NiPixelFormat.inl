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

//---------------------------------------------------------------------------
inline NiPixelFormat::NiPixelFormat(Format eFmt, unsigned int uiBPP)
{
    InitFromFormatEnum(eFmt, uiBPP);
    m_eSwizzle = SWIZZLE_NONE;
}
//---------------------------------------------------------------------------
inline NiPixelFormat::NiPixelFormat()
{
    m_uiBitsPerPixel = 8;

    m_auiColorMasks[RED] = m_auiColorMasks[GREEN] = m_auiColorMasks[BLUE] 
        = m_auiColorMasks[ALPHA] = 0;

    m_eFormat = PAL;
    m_eSwizzle = SWIZZLE_NONE;

    m_auiFastCompare[0] = (ms_uiBPPMask & (1 << ms_uiBPPShift)) |
        (ms_uiFormatMask & (PAL << ms_uiFormatShift));
    m_auiFastCompare[1] = 0;
}
//---------------------------------------------------------------------------
inline NiPixelFormat::Format NiPixelFormat::GetFormat() const
{
    return m_eFormat;
}
//---------------------------------------------------------------------------
inline unsigned char NiPixelFormat::GetBitsPerPixel() const
{
    return m_uiBitsPerPixel;
}
//---------------------------------------------------------------------------
inline bool NiPixelFormat::GetPalettized() const
{
    return m_eFormat == PAL || m_eFormat == PALALPHA;
}
//---------------------------------------------------------------------------
inline bool NiPixelFormat::GetPaletteHasAlpha() const
{
    return m_eFormat == PALALPHA;
}
//---------------------------------------------------------------------------
inline bool NiPixelFormat::GetCompressed() const
{
    return ((m_eFormat >= COMPRESS1) && (m_eFormat <= COMPRESS5));
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelFormat::GetMask(Component eComp) const
{
    return m_auiColorMasks[eComp];
}
//---------------------------------------------------------------------------
inline unsigned char NiPixelFormat::GetBits(Component eComp) const
{
    return (m_auiFastCompare[0] & ms_auiColorBitsMask[eComp])
        >> ms_auiColorBitsShift[eComp];
}
//---------------------------------------------------------------------------
inline unsigned char NiPixelFormat::GetShift(Component eComp) const
{
    return (m_auiFastCompare[1] & ms_auiColorOffsetMask[eComp])
        >> ms_auiColorOffsetShift[eComp];
}
//---------------------------------------------------------------------------
inline void NiPixelFormat::SetSwizzleType(SwizzleType eSwizzle)
{
    m_eSwizzle = eSwizzle;
}
//---------------------------------------------------------------------------
inline NiPixelFormat::SwizzleType NiPixelFormat::GetSwizzleType() const
{
    return m_eSwizzle;
}
//---------------------------------------------------------------------------
inline bool NiPixelFormat::operator==(const NiPixelFormat& pixDesc) const
{
    return ((m_auiFastCompare[0] == pixDesc.m_auiFastCompare[0]) &&
        (m_auiFastCompare[1] == pixDesc.m_auiFastCompare[1])) ? true : false;
}
//---------------------------------------------------------------------------
inline bool NiPixelFormat::operator!=(const NiPixelFormat& pixDesc) const
{
    return ((m_auiFastCompare[0] != pixDesc.m_auiFastCompare[0]) ||
        (m_auiFastCompare[1] != pixDesc.m_auiFastCompare[1])) ? true : false;
}
//---------------------------------------------------------------------------
inline void NiPixelFormat::GetPixelIdentifier(unsigned int(& auiID)[2]) const
{
    auiID[0] = m_auiFastCompare[0];
    auiID[1] = m_auiFastCompare[1];
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelFormat::GetLeastSignificant1Bit(unsigned int uiArg)
{
    if(!uiArg)
        return 0;

    unsigned int uiShift = 0;
    while(!(uiArg & 0x1))
    {
        uiShift++;
        uiArg >>= 1;
    }

    return uiShift;
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelFormat::GetLeastSignificant0Bit(unsigned int uiArg)
{
    unsigned int uiShift = 0;
    while(uiArg & 0x1)
    {
        uiShift++;
        uiArg >>= 1;
    }

    return uiShift;
}
//---------------------------------------------------------------------------
inline void NiPixelFormat::ComputeFlagsFromMask(unsigned int uiMask,
    Component eComp, unsigned int &uiBitsFlags, unsigned int &uiOffsetFlags)
{
    unsigned int uiShift = GetLeastSignificant1Bit(uiMask);
    unsigned int uiBits = GetLeastSignificant0Bit(uiMask >> uiShift);

    uiBitsFlags = (uiBits << ms_auiColorBitsShift[eComp]) 
        & ms_auiColorBitsMask[eComp];
    uiOffsetFlags = (uiShift << ms_auiColorOffsetShift[eComp])
        & ms_auiColorOffsetMask[eComp];
}
//---------------------------------------------------------------------------
