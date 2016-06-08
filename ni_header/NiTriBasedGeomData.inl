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
//  NiTriBasedGeomData inline functions

//---------------------------------------------------------------------------
inline unsigned short NiTriBasedGeomData::GetTriangleCount() const
{
    return m_usTriangles;
}
//---------------------------------------------------------------------------
inline void NiTriBasedGeomData::SetTriangleCount(unsigned short usTriangles)
{
    m_usTriangles = usTriangles;
}
//---------------------------------------------------------------------------
inline void NiTriBasedGeomData::SetActiveTriangleCount(
    unsigned short /*usActive*/)
{
    // stub for derived classes
}
//---------------------------------------------------------------------------
inline unsigned short NiTriBasedGeomData::GetActiveTriangleCount() const
{
    return m_usTriangles;
}
//---------------------------------------------------------------------------
