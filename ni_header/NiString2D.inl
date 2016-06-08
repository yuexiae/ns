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
// NiString2D inline functions
//---------------------------------------------------------------------------
inline void NiString2D::SetPosition(unsigned int uiX, unsigned int uiY)
{
    if ((m_uiX != uiX) || (m_uiY != uiY))
    {
        m_uiX = uiX;
        m_uiY = uiY;
        m_bModified = true;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiString2D::GetLimitWidth()
{
    return m_uiLimitWidth;
}
//---------------------------------------------------------------------------
