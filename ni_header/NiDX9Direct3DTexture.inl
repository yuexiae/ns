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
inline NiDX9Direct3DTexture::NiDX9Direct3DTexture()
{
    /* */
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9Direct3DTexture::GetWidth() const
{
    return m_uiWidth;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9Direct3DTexture::GetHeight() const
{
    return m_uiHeight;
}
//---------------------------------------------------------------------------
inline void NiDX9Direct3DTexture::SetWidth(unsigned int uiWidth)
{
    m_uiWidth = uiWidth;
}
//---------------------------------------------------------------------------
inline void NiDX9Direct3DTexture::SetHeight(unsigned int uiHeight)
{
    m_uiHeight = uiHeight;
}
//---------------------------------------------------------------------------
