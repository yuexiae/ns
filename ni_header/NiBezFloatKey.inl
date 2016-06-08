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
inline NiBezFloatKey::NiBezFloatKey ()
{
}
//---------------------------------------------------------------------------
inline NiBezFloatKey::NiBezFloatKey (float fTime, float fVal, float fInTan,
    float fOutTan)
    :
    NiFloatKey(fTime,fVal)
{
    m_fInTan = fInTan;
    m_fOutTan = fOutTan;
}
//---------------------------------------------------------------------------
inline void NiBezFloatKey::SetInTan (float fInTan)
{
    m_fInTan = fInTan;
}
//---------------------------------------------------------------------------
inline void NiBezFloatKey::SetOutTan (float fOutTan)
{
    m_fOutTan = fOutTan;
}
//---------------------------------------------------------------------------
inline float NiBezFloatKey::GetInTan () const
{
    return m_fInTan;
}
//---------------------------------------------------------------------------
inline float NiBezFloatKey::GetOutTan () const
{
    return m_fOutTan;
}
//---------------------------------------------------------------------------
