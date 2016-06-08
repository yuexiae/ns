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
inline float NiParticleCollider::GetBounce() const
{
    return m_fBounce;
}
//---------------------------------------------------------------------------
inline void NiParticleCollider::SetBounce(float fBounce)
{
    m_fBounce = fBounce;
}
//---------------------------------------------------------------------------
inline bool NiParticleCollider::GetSpawnOnCollide() const
{
    return m_bSpawnOnCollide;
}
//---------------------------------------------------------------------------
inline void NiParticleCollider::SetSpawnOnCollide(bool bSpawn)
{
    m_bSpawnOnCollide = bSpawn;
}
//---------------------------------------------------------------------------
inline bool NiParticleCollider::GetDieOnCollide() const
{
    return m_bDieOnCollide;
}
//---------------------------------------------------------------------------
inline void NiParticleCollider::SetDieOnCollide(bool bDie)
{
    m_bDieOnCollide = bDie;
}
//---------------------------------------------------------------------------
    
