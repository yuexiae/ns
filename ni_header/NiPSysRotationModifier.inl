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
inline float NiPSysRotationModifier::GetRotationSpeed() const
{
    return m_fRotationSpeed;
}
//---------------------------------------------------------------------------
inline void NiPSysRotationModifier::SetRotationSpeed(float fRotationSpeed)
{
    m_fRotationSpeed = fRotationSpeed;
}
//---------------------------------------------------------------------------
inline bool NiPSysRotationModifier::GetRandomInitialAxis() const
{
    return m_bRandomInitialAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysRotationModifier::SetRandomInitialAxis(
    bool bRandomInitialAxis)
{
    m_bRandomInitialAxis = bRandomInitialAxis;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysRotationModifier::GetInitialAxis() const
{
    return m_kInitialAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysRotationModifier::SetInitialAxis(
    const NiPoint3& kInitialAxis)
{
    m_kInitialAxis = kInitialAxis;
}
//---------------------------------------------------------------------------
