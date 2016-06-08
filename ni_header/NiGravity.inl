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
inline void NiGravity::SetDecay(float fDecay)
{ 
    m_fDecay = fDecay; 
}
//---------------------------------------------------------------------------
inline float NiGravity::GetDecay() const
{ 
    return m_fDecay; 
}
//---------------------------------------------------------------------------
inline void NiGravity::SetStrength(float fStrength)
{ 
    m_fStrength = fStrength; 
}
//---------------------------------------------------------------------------
inline float NiGravity::GetStrength() const
{ 
    return m_fStrength; 
}
//---------------------------------------------------------------------------
inline void NiGravity::SetType(ForceType eType)
{ 
    m_eType = eType; 
};
//---------------------------------------------------------------------------
inline NiGravity::ForceType NiGravity::GetType() const
{ 
    return m_eType; 
}
//---------------------------------------------------------------------------
inline void NiGravity::SetPos(const NiPoint3& kPos)
{ 
    m_kPosition = kPos;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiGravity::GetPos() const
{ 
    return m_kPosition; 
}
//---------------------------------------------------------------------------
inline void NiGravity::SetDir(const NiPoint3& kDir)
{ 
    m_kDirection = kDir;
    m_kDirection.Unitize();
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiGravity::GetDir() const
{ 
    return m_kDirection; 
}
//---------------------------------------------------------------------------
