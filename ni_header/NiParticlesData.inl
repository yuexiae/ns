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
//  NiParticlesData inline functions

//---------------------------------------------------------------------------
inline float* NiParticlesData::GetRadii()
{
    return m_pfRadii;
}
//---------------------------------------------------------------------------
inline const float* NiParticlesData::GetRadii() const
{
    return m_pfRadii;
}
//---------------------------------------------------------------------------
inline float* NiParticlesData::GetSizes()
{
    return m_pfSizes;
}
//---------------------------------------------------------------------------
inline const float* NiParticlesData::GetSizes() const
{
    return m_pfSizes;
}
//---------------------------------------------------------------------------
inline NiQuaternion* NiParticlesData::GetRotations()
{
    return m_pkRotations;
}
//---------------------------------------------------------------------------
inline const NiQuaternion* NiParticlesData::GetRotations() const
{
    return m_pkRotations;
}
//---------------------------------------------------------------------------
inline void NiParticlesData::SetRadiiData(float* pfRadii)
{
    m_pfRadii = pfRadii;
}
//---------------------------------------------------------------------------
inline void NiParticlesData::SetSizesData(float* pfSizes)
{
    m_pfSizes = pfSizes;
}
//---------------------------------------------------------------------------
inline void NiParticlesData::SetRotationsData(NiQuaternion* pkRotations)
{
    m_pkRotations = m_pkRotations;
}
//---------------------------------------------------------------------------
inline void NiParticlesData::SetActiveVertexCount(unsigned short usActive)
{
    if (usActive <= m_usVertices)
        m_usActive = usActive;
    else
        m_usActive = m_usVertices;
}
//---------------------------------------------------------------------------
inline unsigned short NiParticlesData::GetActiveVertexCount() const
{
    return m_usActive;
}
//---------------------------------------------------------------------------
inline void NiParticlesData::CalculateNormals()
{
    // NiGeometryData::CalculateNormals is pure virtual.  Particles do not
    // know how to compute their normal vectors.
}
//---------------------------------------------------------------------------
