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
//  NiParticleBomb inlines

//---------------------------------------------------------------------------
inline void NiParticleBomb::SetDecay(float fDecay)
{
    m_fDecay = fDecay;
}
//---------------------------------------------------------------------------
inline float NiParticleBomb::GetDecay() const
{
    return m_fDecay;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetDeltaV(float fDeltaV)
{
    m_fDeltaV = fDeltaV;
}
//---------------------------------------------------------------------------
inline float NiParticleBomb::GetDeltaV() const
{
    return m_fDeltaV;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetDuration(float fDuration)
{
    m_fDuration = fDuration;
}
//---------------------------------------------------------------------------
inline float NiParticleBomb::GetDuration() const
{
    return m_fDuration;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetStart(float fStart)
{
    m_fStart = fStart;
}
//---------------------------------------------------------------------------
inline float NiParticleBomb::GetStart() const
{
    return m_fStart;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetDecayType(DecayType eDecayType)
{
    m_eDecayType = eDecayType;
}
//---------------------------------------------------------------------------
inline NiParticleBomb::DecayType NiParticleBomb::GetDecayType() const
{
    return m_eDecayType;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetSymmetry(SymmType eSymmType)
{
    m_eSymmType = eSymmType;
}
//---------------------------------------------------------------------------
inline NiParticleBomb::SymmType NiParticleBomb::GetSymmetry() const
{
    return m_eSymmType;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetPos(const NiPoint3& kPos)
{
    m_kPosition = kPos;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiParticleBomb::GetPos() const
{
    return m_kPosition;
}
//---------------------------------------------------------------------------
inline void NiParticleBomb::SetDir(const NiPoint3& kDir)
{
    m_kDirection = kDir;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiParticleBomb::GetDir() const
{
    return m_kDirection;
}
//---------------------------------------------------------------------------
