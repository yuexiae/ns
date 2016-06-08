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
inline NiTextKey::NiTextKey ()
{
    m_pText = 0;
}
//---------------------------------------------------------------------------
inline void NiTextKey::SetTime (float fTime)
{
    m_fTime = fTime;
}
//---------------------------------------------------------------------------
inline float NiTextKey::GetTime () const
{
    return m_fTime;
}
//---------------------------------------------------------------------------
inline char* NiTextKey::GetText () const
{
    return m_pText;
}
//---------------------------------------------------------------------------
inline bool NiTextKey::operator== (const NiTextKey& key)
{
    return m_fTime == key.m_fTime && !strcmp(m_pText,key.m_pText);
}
//---------------------------------------------------------------------------
inline bool NiTextKey::operator!= (const NiTextKey& key)
{
    return m_fTime != key.m_fTime || strcmp(m_pText,key.m_pText);
}
//---------------------------------------------------------------------------
