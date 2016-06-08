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
inline int NiBoxBV::Type() const
{
    return BOX_BV;
}
//---------------------------------------------------------------------------
inline NiBoxBV::NiBoxBV(const NiBoxBV& kABV)
{
    SetBox(kABV.GetBox());
}
//---------------------------------------------------------------------------
inline NiBoundingVolume* NiBoxBV::Create() const 
{ 
    return new NiBoxBV; 
}
//---------------------------------------------------------------------------
inline void NiBoxBV::SetBox(const NiBox& kBox)
{
    m_kBox = kBox;
}
//---------------------------------------------------------------------------
inline const NiBox& NiBoxBV::GetBox() const
{
    return m_kBox;
}
//---------------------------------------------------------------------------
inline void NiBoxBV::SetCenter(const NiPoint3& kCenter)
{
    m_kBox.m_kCenter = kCenter;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiBoxBV::GetCenter() const
{
    return m_kBox.m_kCenter;
}
//---------------------------------------------------------------------------
inline void NiBoxBV::SetAxis(int iWhich, const NiPoint3& kAxis)
{
    assert(0 <= iWhich && iWhich <= 2);
    m_kBox.m_akAxis[iWhich] = kAxis;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiBoxBV::GetAxis(int iWhich) const
{
    assert(0 <= iWhich && iWhich <= 2);
    return m_kBox.m_akAxis[iWhich];
}
//---------------------------------------------------------------------------
inline const NiPoint3* NiBoxBV::GetAxes() const
{
    return m_kBox.m_akAxis;
}
//---------------------------------------------------------------------------
inline void NiBoxBV::SetExtent(int iWhich, float fExtent)
{
    assert(0 <= iWhich && iWhich <= 2);
    m_kBox.m_afExtent[iWhich] = fExtent;
}
//---------------------------------------------------------------------------
inline float NiBoxBV::GetExtent(int iWhich) const
{
    assert(0 <= iWhich && iWhich <= 2);
    return m_kBox.m_afExtent[iWhich];
}
//---------------------------------------------------------------------------
inline const float* NiBoxBV::GetExtents() const
{
    return m_kBox.m_afExtent;
}
//---------------------------------------------------------------------------
