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
inline bool NiPSysAgeDeathModifier::GetSpawnOnDeath() const
{
    return m_bSpawnOnDeath;
}
//---------------------------------------------------------------------------
inline void NiPSysAgeDeathModifier::SetSpawnOnDeath(bool bSpawnOnDeath)
{
    m_bSpawnOnDeath = bSpawnOnDeath;
}
//---------------------------------------------------------------------------
inline NiPSysSpawnModifier* NiPSysAgeDeathModifier::GetSpawnModifier() const
{
    return m_pkSpawnModifier;
}
//---------------------------------------------------------------------------
inline void NiPSysAgeDeathModifier::SetSpawnModifier(
    NiPSysSpawnModifier* pkSpawnModifier)
{
    m_pkSpawnModifier = pkSpawnModifier;
}
//---------------------------------------------------------------------------
