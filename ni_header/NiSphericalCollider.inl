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
inline void NiSphericalCollider::SetRadius(float fRadius) 
{ 
    m_fRadius = fRadius; 
    m_fRadiusSq = fRadius * fRadius; 
}
//---------------------------------------------------------------------------
inline float NiSphericalCollider::GetRadius() const
{
    return m_fRadius;
}
//---------------------------------------------------------------------------
inline void NiSphericalCollider::SetPos(const NiPoint3& kPos)
{
    m_kPosition = kPos;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiSphericalCollider::GetPos() const
{
    return m_kPosition;
}
//---------------------------------------------------------------------------
