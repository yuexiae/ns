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
inline unsigned short NiTriStripsData::GetStripCount() const
{
    return m_usStrips;
}

//---------------------------------------------------------------------------
inline unsigned short* NiTriStripsData::GetStripLengths() const
{
    return m_pusStripLengths;
}

//---------------------------------------------------------------------------
inline unsigned short* NiTriStripsData::GetStripLists() const
{
    return m_pusStripLists;
}

//---------------------------------------------------------------------------
inline unsigned short NiTriStripsData::GetStripLengthSum () const
{
    return m_usTriangles + 2 * m_usStrips;
}

