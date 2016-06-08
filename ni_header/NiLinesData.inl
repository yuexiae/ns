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
//  NiLinesData inline functions

//---------------------------------------------------------------------------
inline NiBool* NiLinesData::GetFlags()
{
    return m_pkFlags;
}
//---------------------------------------------------------------------------
inline const NiBool* NiLinesData::GetFlags() const
{
    return m_pkFlags;
}
//---------------------------------------------------------------------------
inline void NiLinesData::CalculateNormals()
{
    // NiGeometry::CalculateNormals is pure virtual.  Lines do not have
    // normal vectors.
}
//---------------------------------------------------------------------------
