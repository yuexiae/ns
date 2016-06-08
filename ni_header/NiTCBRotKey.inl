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
inline NiTCBRotKey::NiTCBRotKey ()
{
    // for streaming, members will be filled in by LoadBinary
}
//---------------------------------------------------------------------------
inline NiTCBRotKey::NiTCBRotKey (float fTime, float fAngle,
    const NiPoint3& axis)
    :
    NiRotKey(fTime,fAngle,axis)
{
    // additional members filled in by FillDerivedVals
}
//---------------------------------------------------------------------------
inline NiTCBRotKey::NiTCBRotKey (float fTime, const NiQuaternion& quat)
    :
    NiRotKey(fTime,quat)
{
    // additional members filled in by FillDerivedVals
}
//---------------------------------------------------------------------------
inline void NiTCBRotKey::SetTension (float fTension)
{
    m_fTension = fTension;
}
//---------------------------------------------------------------------------
inline void NiTCBRotKey::SetContinuity (float fContinuity)
{
    m_fContinuity = fContinuity;
}
//---------------------------------------------------------------------------
inline void NiTCBRotKey::SetBias (float fBias)
{
    m_fBias = fBias;
}
//---------------------------------------------------------------------------
inline float NiTCBRotKey::GetTension () const
{
    return m_fTension;
}
//---------------------------------------------------------------------------
inline float NiTCBRotKey::GetContinuity () const
{
    return m_fContinuity;
}
//---------------------------------------------------------------------------
inline float NiTCBRotKey::GetBias () const
{
    return m_fBias;
}
//---------------------------------------------------------------------------
