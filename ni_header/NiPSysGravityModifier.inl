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
inline NiAVObject* NiPSysGravityModifier::GetGravityObj() const
{
    return m_pkGravityObj;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetGravityObj(NiAVObject* pkGravityObj)
{
    m_pkGravityObj = pkGravityObj;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysGravityModifier::GetGravityAxis() const
{
    return m_kGravityAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetGravityAxis(const NiPoint3& kGravityAxis)
{
    m_kGravityAxis = kGravityAxis;
}
//---------------------------------------------------------------------------
inline float NiPSysGravityModifier::GetDecay() const
{
    return m_fDecay;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetDecay(float fDecay)
{
    m_fDecay = fDecay;
}
//---------------------------------------------------------------------------
inline float NiPSysGravityModifier::GetStrength() const
{
    return m_fStrength;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetStrength(float fStrength)
{
    m_fStrength = fStrength;
}
//---------------------------------------------------------------------------
inline NiPSysGravityModifier::ForceType NiPSysGravityModifier::GetType() const
{
    return m_eType;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetType(ForceType eType)
{
    m_eType = eType;
}
//---------------------------------------------------------------------------
inline float NiPSysGravityModifier::GetTurbulence()
{
    return m_fTurbulence;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetTurbulence(float fTurbulence)
{
    m_fTurbulence = fTurbulence;
}
//---------------------------------------------------------------------------
inline float NiPSysGravityModifier::GetTurbulenceScale()
{
    return m_fScale;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityModifier::SetTurbulenceScale(float fScale)
{
    m_fScale = fScale;
}
//---------------------------------------------------------------------------
