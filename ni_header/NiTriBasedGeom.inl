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
//  NiTriBasedGeom inline functions

//---------------------------------------------------------------------------
inline unsigned short NiTriBasedGeom::GetTriangleCount() const
{
    NiTriBasedGeomData* pkData =
        NiSmartPointerCast(NiTriBasedGeomData, m_spModelData);
    return pkData->GetTriangleCount();
}
//---------------------------------------------------------------------------
inline void NiTriBasedGeom::SetActiveTriangleCount(unsigned short usActive)
{
    ((NiTriBasedGeomData*) GetModelData())->
        SetActiveTriangleCount(usActive);
}
//---------------------------------------------------------------------------
inline unsigned short NiTriBasedGeom::GetActiveTriangleCount() const
{
    return ((NiTriBasedGeomData*) GetModelData())->
        GetActiveTriangleCount();
}
//---------------------------------------------------------------------------
inline void NiTriBasedGeom::GetTriangleIndices(unsigned short i,
    unsigned short& i0, unsigned short& i1, unsigned short& i2) const
{
    ((NiTriBasedGeomData*) GetModelData())->
        GetTriangleIndices(i, i0, i1, i2);
}
//---------------------------------------------------------------------------
