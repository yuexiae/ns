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
// NiCursor inline functions
//---------------------------------------------------------------------------
inline const int NiCursor::GetShow() const
{
    return m_iShowCount;
}
//---------------------------------------------------------------------------
inline void NiCursor::GetHotSpot(unsigned int& uiX, unsigned int& uiY)
{
    uiX = m_uiHotSpotX;
    uiY = m_uiHotSpotY;
}
//---------------------------------------------------------------------------
inline void NiCursor::GetScreenSpacePosition(int& iX, int& iY)
{
    iX = m_iScreenSpaceX;
    iY = m_iScreenSpaceY;
}
//---------------------------------------------------------------------------
inline void NiCursor::SetRect(NiRect<int>& kRect)
{
    m_kRect.m_left = kRect.m_left;
    m_kRect.m_top = kRect.m_top;
    m_kRect.m_right = kRect.m_right;
    m_kRect.m_bottom = kRect.m_bottom;
}
//---------------------------------------------------------------------------
inline void NiCursor::SetHotSpot(unsigned int uiX, unsigned int uiY)
{
    m_uiHotSpotX = uiX;
    m_uiHotSpotY = uiY;
}
//---------------------------------------------------------------------------
inline void NiCursor::SetFlags(unsigned int uiFlags)
{
    m_uiFlags = uiFlags;
}
//---------------------------------------------------------------------------
