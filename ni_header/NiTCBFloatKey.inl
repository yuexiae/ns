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
inline NiTCBFloatKey::NiTCBFloatKey ()
{
}
//---------------------------------------------------------------------------
inline NiTCBFloatKey::NiTCBFloatKey (float fTime, float fValue,
    float fTension, float fContinuity, float fBias)
    :
    NiFloatKey(fTime,fValue)
{
    m_fTension = fTension;
    m_fContinuity = fContinuity;
    m_fBias = fBias;
}
//---------------------------------------------------------------------------
inline void NiTCBFloatKey::SetTension (float fTension)
{
    m_fTension = fTension;
}
//---------------------------------------------------------------------------
inline void NiTCBFloatKey::SetContinuity (float fContinuity)
{
    m_fContinuity = fContinuity;
}
//---------------------------------------------------------------------------
inline void NiTCBFloatKey::SetBias (float fBias)
{
    m_fBias = fBias;
}
//---------------------------------------------------------------------------
inline float NiTCBFloatKey::GetTension () const
{
    return m_fTension;
}
//---------------------------------------------------------------------------
inline float NiTCBFloatKey::GetContinuity () const
{
    return m_fContinuity;
}
//---------------------------------------------------------------------------
inline float NiTCBFloatKey::GetBias () const
{
    return m_fBias;
}
//---------------------------------------------------------------------------
