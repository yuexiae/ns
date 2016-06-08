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
inline float NiPSysCollider::GetBounce() const
{
    return m_fBounce;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetBounce(float fBounce)
{
    m_fBounce = fBounce;
}
//---------------------------------------------------------------------------
inline bool NiPSysCollider::GetSpawnOnCollide() const
{
    return m_bSpawnOnCollide;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetSpawnOnCollide(bool bSpawnOnCollide)
{
    m_bSpawnOnCollide = bSpawnOnCollide;
}
//---------------------------------------------------------------------------
inline bool NiPSysCollider::GetDieOnCollide() const
{
    return m_bDieOnCollide;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetDieOnCollide(bool bDieOnCollide)
{
    m_bDieOnCollide = bDieOnCollide;
}
//---------------------------------------------------------------------------
inline NiPSysSpawnModifier* NiPSysCollider::GetSpawnModifier() const
{
    return m_pkSpawnModifier;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetSpawnModifier(
    NiPSysSpawnModifier* pkSpawnModifier)
{
    m_pkSpawnModifier = pkSpawnModifier;
}
//---------------------------------------------------------------------------
inline NiPSysColliderManager* NiPSysCollider::GetManager() const
{
    return m_pkManager;
}
//---------------------------------------------------------------------------
inline NiPSysCollider* NiPSysCollider::GetNext() const
{
    return m_spNext;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetNext(NiPSysCollider* pkNext)
{
    m_spNext = pkNext;
}
//---------------------------------------------------------------------------
inline void NiPSysCollider::SetManager(NiPSysColliderManager* pkManager)
{
    m_pkManager = pkManager;
}
//---------------------------------------------------------------------------
