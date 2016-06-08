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
inline NiTCBPosKey::NiTCBPosKey ()
{
}
//---------------------------------------------------------------------------
inline NiTCBPosKey::NiTCBPosKey (float fTime, const NiPoint3& pos,
    float fTension, float fContinuity, float fBias)
    :
    NiPosKey(fTime,pos)
{
    m_fTension = fTension;
    m_fContinuity = fContinuity;
    m_fBias = fBias;
}
//---------------------------------------------------------------------------
inline void NiTCBPosKey::SetTension (float fTension)
{
    m_fTension = fTension;
}
//---------------------------------------------------------------------------
inline void NiTCBPosKey::SetContinuity (float fContinuity)
{
    m_fContinuity = fContinuity;
}
//---------------------------------------------------------------------------
inline void NiTCBPosKey::SetBias (float fBias)
{
    m_fBias = fBias;
}
//---------------------------------------------------------------------------
inline float NiTCBPosKey::GetTension () const
{
    return m_fTension;
}
//---------------------------------------------------------------------------
inline float NiTCBPosKey::GetContinuity () const
{
    return m_fContinuity;
}
//---------------------------------------------------------------------------
inline float NiTCBPosKey::GetBias () const
{
    return m_fBias;
}
//---------------------------------------------------------------------------
