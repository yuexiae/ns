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
//  NiMatrix3 inline functions

//---------------------------------------------------------------------------
// The following macros are supplied only because the Visual C++ optimizer
// does a poor job in many situations of inlining the matrix operations.  The
// input parameters should be single identifiers (to avoid side effects by
// the textual substitution).

// result = mat*pt
#define NiMatrixTimesPoint(result,mat,pt) \
{ \
    result.x = (mat).GetEntry( 0,0 ) * (pt).x + \
               (mat).GetEntry( 0,1 ) * (pt).y + \
               (mat).GetEntry( 0,2 ) * (pt).z;  \
    result.y = (mat).GetEntry( 1,0 ) * (pt).x + \
               (mat).GetEntry( 1,1 ) * (pt).y + \
               (mat).GetEntry( 1,2 ) * (pt).z;  \
    result.z = (mat).GetEntry( 2,0 ) * (pt).x + \
               (mat).GetEntry( 2,1 ) * (pt).y + \
               (mat).GetEntry( 2,2 ) * (pt).z;  \
}

// result = mat*pt0+pt1
#define NiMatrixTimesPointPlusPoint(result,mat,pt0,pt1) \
{ \
    result.x = (mat).GetEntry( 0,0 ) * (pt0).x +          \
               (mat).GetEntry( 0,1 ) * (pt0).y +          \
               (mat).GetEntry( 0,2 ) * (pt0).z + (pt1).x; \
    result.y = (mat).GetEntry( 1,0 ) * (pt0).x +          \
               (mat).GetEntry( 1,1 ) * (pt0).y +          \
               (mat).GetEntry( 1,2 ) * (pt0).z + (pt1).y; \
    result.z = (mat).GetEntry( 2,0 ) * (pt0).x +          \
               (mat).GetEntry( 2,1 ) * (pt0).y +          \
               (mat).GetEntry( 2,2 ) * (pt0).z + (pt1).z; \
}

// result = pt*transpose(mat)
#define NiPointTimesMatrix(result,pt,mat) \
{ \
    result.x = (mat).GetEntry( 0,0 ) * (pt).x + \
               (mat).GetEntry( 1,0 ) * (pt).y + \
               (mat).GetEntry( 2,0 ) * (pt).z;  \
    result.y = (mat).GetEntry( 0,1 ) * (pt).x + \
               (mat).GetEntry( 1,1 ) * (pt).y + \
               (mat).GetEntry( 2,1 ) * (pt).z;  \
    result.z = (mat).GetEntry( 0,2 ) * (pt).x + \
               (mat).GetEntry( 1,2 ) * (pt).y + \
               (mat).GetEntry( 2,2 ) * (pt).z;  \
}

//---------------------------------------------------------------------------
inline NiMatrix3::NiMatrix3()
{
}
//---------------------------------------------------------------------------
//  Row access functions
inline void NiMatrix3::GetRow( unsigned int uiRow, NiPoint3& row ) const
{
    assert( uiRow <= 2 );
    row.x   = m_pEntry[uiRow][0];
    row.y   = m_pEntry[uiRow][1];
    row.z   = m_pEntry[uiRow][2];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetRow( unsigned int uiRow, const NiPoint3& row )
{
    assert( uiRow <= 2 );
    m_pEntry[uiRow][0]  = row.x;
    m_pEntry[uiRow][1]  = row.y;
    m_pEntry[uiRow][2]  = row.z;
}
//---------------------------------------------------------------------------
inline void NiMatrix3::GetRow( unsigned int uiRow, float& f0, float& f1, 
    float& f2 ) const
{
    assert( uiRow <= 2 );
    f0 = m_pEntry[uiRow][0];
    f1 = m_pEntry[uiRow][1];
    f2 = m_pEntry[uiRow][2];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetRow( unsigned int uiRow, float f0, float f1, 
    float f2 )
{
    assert( uiRow <= 2 );
    m_pEntry[uiRow][0]  = f0;
    m_pEntry[uiRow][1]  = f1;
    m_pEntry[uiRow][2]  = f2;
}
//---------------------------------------------------------------------------
inline void NiMatrix3::GetRow( unsigned int uiRow, float* pRow ) const
{
    assert( uiRow <= 2 );
    pRow[0] = m_pEntry[uiRow][0];
    pRow[1] = m_pEntry[uiRow][1];
    pRow[2] = m_pEntry[uiRow][2];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetRow( unsigned int uiRow, const float* pRow )
{
    assert( uiRow <= 2 );
    m_pEntry[uiRow][0]  = pRow[0];
    m_pEntry[uiRow][1]  = pRow[1];
    m_pEntry[uiRow][2]  = pRow[2];
}

//---------------------------------------------------------------------------
//  Column access functions
inline void NiMatrix3::GetCol( unsigned int uiCol, NiPoint3& col ) const
{
    assert( uiCol <= 2 );
    col.x   = m_pEntry[0][uiCol];
    col.y   = m_pEntry[1][uiCol];
    col.z   = m_pEntry[2][uiCol];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetCol( unsigned int uiCol, const NiPoint3& col )
{
    assert( uiCol <= 2 );
    m_pEntry[0][uiCol]  = col.x;
    m_pEntry[1][uiCol]  = col.y;
    m_pEntry[2][uiCol]  = col.z;
}
//---------------------------------------------------------------------------
inline void NiMatrix3::GetCol( unsigned int uiCol, float& f0, float& f1, 
    float& f2 ) const
{
    assert( uiCol <= 2 );
    f0 = m_pEntry[0][uiCol];
    f1 = m_pEntry[1][uiCol];
    f2 = m_pEntry[2][uiCol];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetCol( unsigned int uiCol, float f0, float f1, 
    float f2 )
{
    assert( uiCol <= 2 );
    m_pEntry[0][uiCol] = f0;
    m_pEntry[1][uiCol] = f1;
    m_pEntry[2][uiCol] = f2;
}
//---------------------------------------------------------------------------
inline void NiMatrix3::GetCol( unsigned int uiCol, float* pCol ) const
{
    assert( uiCol <= 2 );
    pCol[0] = m_pEntry[0][uiCol];
    pCol[1] = m_pEntry[1][uiCol];
    pCol[2] = m_pEntry[2][uiCol];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetCol( unsigned int uiCol, const float* pCol )
{
    assert( uiCol <= 2 );
    m_pEntry[0][uiCol] = pCol[0];
    m_pEntry[1][uiCol] = pCol[1];
    m_pEntry[2][uiCol] = pCol[2];
}

//---------------------------------------------------------------------------
//  Entry access functions
inline float NiMatrix3::GetEntry( unsigned int uiRow, 
    unsigned int uiCol ) const
{
    assert( uiRow <= 2 && uiCol <= 2 );
    return m_pEntry[uiRow][uiCol];
}
//---------------------------------------------------------------------------
inline void NiMatrix3::SetEntry( unsigned int uiRow, unsigned int uiCol, 
    float fEntry )
{
    assert( uiRow <= 2 && uiCol <= 2 );
    m_pEntry[uiRow][uiCol]  = fEntry;
}

//---------------------------------------------------------------------------
inline void NiMatrix3::MakeRotation (float fAngle, const NiPoint3& axis)
{
    MakeRotation(fAngle,axis.x,axis.y,axis.z);
}
//---------------------------------------------------------------------------
inline void NiMatrix3::MakeZero ()
{
    SetCol(0, 0.0f, 0.0f, 0.0f);
    SetCol(1, 0.0f, 0.0f, 0.0f);
    SetCol(2, 0.0f, 0.0f, 0.0f);
}
//---------------------------------------------------------------------------
