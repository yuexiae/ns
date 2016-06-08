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
//  NiSpotLight inline functions

//---------------------------------------------------------------------------
inline const NiPoint3& NiSpotLight::GetWorldDirection() const
{
    return m_kWorldDir;
}
//---------------------------------------------------------------------------
inline void NiSpotLight::SetSpotAngle(float fSpotAngle)
{
    m_fSpotAngle = fSpotAngle;
    IncRevisionID();
}
//---------------------------------------------------------------------------
inline float NiSpotLight::GetSpotAngle() const
{
    return m_fSpotAngle;
}
//---------------------------------------------------------------------------
inline void NiSpotLight::SetSpotExponent(float fSpotExponent)
{
    m_fSpotExponent = fSpotExponent;
    IncRevisionID();
}
//---------------------------------------------------------------------------
inline float NiSpotLight::GetSpotExponent() const
{
    return m_fSpotExponent;
}
//---------------------------------------------------------------------------
inline NiDynamicEffect::EffectType NiSpotLight::GetEffectType() const
{
    return SPOT_LIGHT;
}
//---------------------------------------------------------------------------
