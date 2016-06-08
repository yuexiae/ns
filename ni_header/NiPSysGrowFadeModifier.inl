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
inline float NiPSysGrowFadeModifier::GetGrowTime() const
{
    return m_fGrowTime;
}
//---------------------------------------------------------------------------
inline void NiPSysGrowFadeModifier::SetGrowTime(float fGrowTime)
{
    m_fGrowTime = fGrowTime;
}
//---------------------------------------------------------------------------
inline unsigned short NiPSysGrowFadeModifier::GetGrowGeneration() const
{
    return m_usGrowGeneration;
}
//---------------------------------------------------------------------------
inline void NiPSysGrowFadeModifier::SetGrowGeneration(
    unsigned short usGrowGeneration)
{
    m_usGrowGeneration = usGrowGeneration;
}
//---------------------------------------------------------------------------
inline float NiPSysGrowFadeModifier::GetFadeTime() const
{
    return m_fFadeTime;
}
//---------------------------------------------------------------------------
inline void NiPSysGrowFadeModifier::SetFadeTime(float fFadeTime)
{
    m_fFadeTime = fFadeTime;
}
//---------------------------------------------------------------------------
inline unsigned short NiPSysGrowFadeModifier::GetFadeGeneration() const
{
    return m_usFadeGeneration;
}
//---------------------------------------------------------------------------
inline void NiPSysGrowFadeModifier::SetFadeGeneration(
    unsigned short usFadeGeneration)
{
    m_usFadeGeneration = usFadeGeneration;
}
//---------------------------------------------------------------------------
