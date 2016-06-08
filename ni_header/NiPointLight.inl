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
//  NiPointLight inline functions

//---------------------------------------------------------------------------
inline NiPointLight::NiPointLight()
{
    m_fAtten0 = 0.0f;
    m_fAtten1 = 1.0f;
    m_fAtten2 = 0.0f;
}
//---------------------------------------------------------------------------
inline void NiPointLight::SetConstantAttenuation(float fC)
{
    m_fAtten0 = fC;
    IncRevisionID();
}
//---------------------------------------------------------------------------
inline float NiPointLight::GetConstantAttenuation() const
{
    return m_fAtten0;
}
//---------------------------------------------------------------------------
inline void NiPointLight::SetLinearAttenuation(float fL)
{
    m_fAtten1 = fL;
    IncRevisionID();
}
//---------------------------------------------------------------------------
inline float NiPointLight::GetLinearAttenuation() const
{
    return m_fAtten1;
}
//---------------------------------------------------------------------------
inline void NiPointLight::SetQuadraticAttenuation(float fQ)
{
    m_fAtten2 = fQ;
    IncRevisionID();
}
//---------------------------------------------------------------------------
inline float NiPointLight::GetQuadraticAttenuation() const
{
    return m_fAtten2;
}
//---------------------------------------------------------------------------
inline NiDynamicEffect::EffectType NiPointLight::GetEffectType() const
{
    return POINT_LIGHT;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPointLight::GetWorldLocation() const
{
    return m_kWorld.m_Translate;
}
//---------------------------------------------------------------------------
