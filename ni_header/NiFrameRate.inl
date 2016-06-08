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
inline void NiFrameRate::SetLocation(float fX, float fY)
{
    m_fXLocation = fX;
    m_fYLocation = fY;
}
//---------------------------------------------------------------------------
inline void NiFrameRate::GetLocation(float& fX, float& fY) const
{
    fX = m_fXLocation;
    fY = m_fYLocation;
}
//---------------------------------------------------------------------------
inline void NiFrameRate::SetColor(const NiColor& kColor)
{
    m_spMatProp->SetEmittance(kColor);
}
//---------------------------------------------------------------------------
inline const NiColor& NiFrameRate::GetColor() const
{
    return m_spMatProp->GetEmittance();
}
//---------------------------------------------------------------------------
inline void NiFrameRate::SetAlpha(float fAlpha)
{
    m_spMatProp->SetAlpha(fAlpha);
}
//---------------------------------------------------------------------------
inline float NiFrameRate::GetAlpha() const
{
    return m_spMatProp->GetAlpha();
}
//---------------------------------------------------------------------------
inline unsigned int NiFrameRate::GetFrameRate() const
{
    return m_uiFrameRate;
}
//---------------------------------------------------------------------------
