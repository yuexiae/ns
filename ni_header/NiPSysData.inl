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
inline NiParticleInfo* NiPSysData::GetParticleInfo()
{
    return m_pkParticleInfo;
}
//---------------------------------------------------------------------------
inline void NiPSysData::Replace(
    NiParticleInfo* pkParticleInfo)
{
    delete[] m_pkParticleInfo;
    m_pkParticleInfo = pkParticleInfo;
}
//---------------------------------------------------------------------------
inline void NiPSysData::SetData(
    NiParticleInfo* pkParticleInfo)
{
    m_pkParticleInfo = pkParticleInfo;
}
//---------------------------------------------------------------------------
inline unsigned short NiPSysData::GetMaxNumParticles() const
{
    return m_usVertices;
}
//---------------------------------------------------------------------------
inline unsigned short NiPSysData::GetNumParticles() const
{
    return m_usActive;
}
//---------------------------------------------------------------------------
inline unsigned short NiPSysData::AddParticle()
{
    if (m_usNumAddedParticles == 0)
    {
        m_usAddedParticlesBase = m_usActive;
        // Assert that we are not exceeding our max number of particles.
        if (m_usActive + m_usNumAddedParticles < m_usVertices)
        {
            return (m_usActive + m_usNumAddedParticles++);
        }
    }
    else
    {
        // Assert that we are not exceeding our max number of particles.
        if (m_usAddedParticlesBase + m_usNumAddedParticles < m_usVertices)
        {
            return (m_usAddedParticlesBase + m_usNumAddedParticles++);
        }
    }

    return INVALID_PARTICLE;
}
//---------------------------------------------------------------------------
inline void NiPSysData::ClearAllParticles()
{
    SetActiveVertexCount(0);
    m_usNumAddedParticles = 0;
    m_usAddedParticlesBase = 0;
}
//---------------------------------------------------------------------------
