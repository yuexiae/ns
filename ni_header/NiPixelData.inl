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
inline unsigned int NiPixelData::GetNumMipmapLevels() const
{
    return m_uiMipmapLevels;
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelData::GetWidth(unsigned int uiMipmapLevel) const
{
    assert(uiMipmapLevel < m_uiMipmapLevels);
    return m_puiWidth[uiMipmapLevel];
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelData::GetHeight(unsigned int uiMipmapLevel) const
{
    assert(uiMipmapLevel < m_uiMipmapLevels);
    return m_puiHeight[uiMipmapLevel];
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelData::GetPixelStride() const
{
    return m_uiPixelStride;
}
//---------------------------------------------------------------------------
inline unsigned int 
    NiPixelData::GetSizeInBytes(unsigned int uiMipmapLevel) const
{
    assert(uiMipmapLevel < m_uiMipmapLevels);
    return m_puiOffsetInBytes[uiMipmapLevel + 1] - 
        m_puiOffsetInBytes[uiMipmapLevel];
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelData::GetTotalSizeInBytes() const
{
    return m_puiOffsetInBytes[m_uiMipmapLevels];
}
//---------------------------------------------------------------------------
inline const NiPixelFormat& NiPixelData::GetPixelFormat() const
{
    return m_kPixelFormat;
}
//---------------------------------------------------------------------------
inline void NiPixelData::SetPalette(NiPalette* pkPal)
{
    m_spPalette = pkPal;
}
//---------------------------------------------------------------------------
inline const NiPalette* NiPixelData::GetPalette() const
{
    return m_spPalette;
}
//---------------------------------------------------------------------------
inline NiPalette* NiPixelData::GetPalette()
{
    return m_spPalette;
}
//---------------------------------------------------------------------------
inline const unsigned char* 
    NiPixelData::GetPixels(unsigned int uiMipmapLevel) const
{
    assert(uiMipmapLevel < m_uiMipmapLevels);
    return m_pucPixels + m_puiOffsetInBytes[uiMipmapLevel];
}
//---------------------------------------------------------------------------
inline unsigned char* NiPixelData::GetPixels(unsigned int uiMipmapLevel)
{
    assert(uiMipmapLevel < m_uiMipmapLevels);
    return m_pucPixels + m_puiOffsetInBytes[uiMipmapLevel];
}
//---------------------------------------------------------------------------
inline void NiPixelData::MarkAsChanged()
{
    m_uiRevID++;
}
//---------------------------------------------------------------------------
inline unsigned int NiPixelData::GetRevisionID() const
{
    return m_uiRevID;
}
//---------------------------------------------------------------------------
inline void NiPixelData::MarkAsSwizzled(NiPixelFormat::SwizzleType eSwizzle)
{
    m_kPixelFormat.SetSwizzleType(eSwizzle);
}
//---------------------------------------------------------------------------

