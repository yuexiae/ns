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
inline NiBezPosKey::NiBezPosKey ()
{
}
//---------------------------------------------------------------------------
inline NiBezPosKey::NiBezPosKey (float fTime, const NiPoint3& pos,
    const NiPoint3& inTan, const NiPoint3& outTan)
    :
    NiPosKey(fTime,pos), m_InTan(inTan), m_OutTan(outTan)
{
}
//---------------------------------------------------------------------------
inline void NiBezPosKey::SetInTan (const NiPoint3& inTan)
{
    m_InTan = inTan;
}
//---------------------------------------------------------------------------
inline void NiBezPosKey::SetOutTan (const NiPoint3& outTan)
{
    m_OutTan = outTan;
}
//---------------------------------------------------------------------------
inline const NiPoint3 &NiBezPosKey::GetInTan () const
{
    return m_InTan;
}
//---------------------------------------------------------------------------
inline const NiPoint3 &NiBezPosKey::GetOutTan () const
{
    return m_OutTan;
}
//---------------------------------------------------------------------------
