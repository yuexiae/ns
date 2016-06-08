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
inline int NiUnionBV::Type() const
{
    return UNION_BV;
}
//---------------------------------------------------------------------------
inline unsigned int NiUnionBV::GetSize() const
{
    return m_kBoundingVolume.GetSize();
}
//---------------------------------------------------------------------------
inline const NiBoundingVolume* NiUnionBV::GetBoundingVolume(
    unsigned int i) const
{
    if (i < m_kBoundingVolume.GetSize())
        return m_kBoundingVolume.GetAt(i);
    else
        return 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiUnionBV::WhichObjectIntersect() const
{
    return m_uiWhichObjectIntersect;
}
//---------------------------------------------------------------------------
