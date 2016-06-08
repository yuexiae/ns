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
//  NiDX9TextureData Inline Functions
//---------------------------------------------------------------------------
inline bool NiDX9TextureData::IsPowerOf2(unsigned int uiI)
{
    if (!uiI)
        return false;

    return (uiI & (uiI - 1)) == 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9TextureData::GetWidth() const
{
    return m_uiWidth;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9TextureData::GetHeight() const
{
    return m_uiHeight;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9TextureData::GetLevels() const
{
    return m_uiLevels;
}
//---------------------------------------------------------------------------
inline const NiPixelFormat* NiDX9TextureData::GetPixelFormat() const
{
    return &m_kPixelFormat;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9TextureData::GetD3DPalette() const
{
    return m_uiPalette;
}
//---------------------------------------------------------------------------
