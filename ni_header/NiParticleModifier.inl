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
inline NiParticleModifier::NiParticleModifier()
{
    m_spNext = 0;
    m_pkTarget = 0;
}
//---------------------------------------------------------------------------
inline NiParticleModifier::~NiParticleModifier()
{
    m_spNext = 0;
}
//---------------------------------------------------------------------------
inline NiParticleSystemController* NiParticleModifier::GetTarget() const
{
    return m_pkTarget;
}
//---------------------------------------------------------------------------
inline void NiParticleModifier::SetNext(NiParticleModifier* pkNext)
{
    m_spNext = pkNext;
}
//---------------------------------------------------------------------------
inline NiParticleModifier* NiParticleModifier::GetNext()
{
    return m_spNext;
}
//---------------------------------------------------------------------------
inline unsigned int NiParticleModifier::GetListSize()
{
    if (m_spNext)
    {
        return m_spNext->GetListSize() + 1;
    }
    else
    {
        return 1;
    }
}
//---------------------------------------------------------------------------
