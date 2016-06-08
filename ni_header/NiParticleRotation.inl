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
inline bool NiParticleRotation::GetRandomInitialAxis() const
{
    return m_bRandomInitialAxis;
}
//---------------------------------------------------------------------------
inline void NiParticleRotation::SetRandomInitialAxis(bool bRandom)
{
    m_bRandomInitialAxis = bRandom;
}
//---------------------------------------------------------------------------
inline NiPoint3 NiParticleRotation::GetInitialAxis() const
{
    return m_kInitialAxis;
}
//---------------------------------------------------------------------------
inline void NiParticleRotation::SetInitialAxis(NiPoint3 kAxis)
{
    m_kInitialAxis = kAxis;
}
//---------------------------------------------------------------------------
inline float NiParticleRotation::GetRotationSpeed() const
{
    return m_fRotationSpeed;
}
//---------------------------------------------------------------------------
inline void NiParticleRotation::SetRotationSpeed(float fSpeed)
{
    m_fRotationSpeed = fSpeed;
}
//---------------------------------------------------------------------------
