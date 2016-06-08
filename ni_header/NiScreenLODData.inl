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
//  NiScreenLODData inline functions

//---------------------------------------------------------------------------
inline void NiScreenLODData::SetBound(const NiBound& kBound)
{
    m_kBound = kBound;
}
//---------------------------------------------------------------------------
inline const NiBound& NiScreenLODData::GetBound() const
{
    return m_kBound;
}
//---------------------------------------------------------------------------
inline const NiBound& NiScreenLODData::GetWorldBound() const
{
    return m_kWorldBound;
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenLODData::GetNumProportions() const
{
    return m_uiNumProportions;
}
//---------------------------------------------------------------------------
inline float NiScreenLODData::GetProportion(unsigned int uiIndex) const
{
    assert(uiIndex < m_uiNumProportions);
    return m_pfProportions[uiIndex];
}
//---------------------------------------------------------------------------
inline void NiScreenLODData::SetProportion(unsigned int uiIndex, 
    float fProportion)
{
    if(uiIndex >= m_uiNumProportions)
    {
        SetNumProportions(uiIndex + 1);
    }

    m_pfProportions[uiIndex] = fProportion;
}
//---------------------------------------------------------------------------
