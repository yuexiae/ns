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
//  NiOBBox inline functions

//---------------------------------------------------------------------------
inline NiOBBox::NiOBBox (NiOBBRoot* pRoot)
{
    m_pRoot = pRoot;
}
//---------------------------------------------------------------------------
inline NiPoint3& NiOBBox::GetCenter ()
{
    return m_center;
}
//---------------------------------------------------------------------------
inline NiPoint3* NiOBBox::GetBasis ()
{
    return m_basis;
}
//---------------------------------------------------------------------------
inline float* NiOBBox::GetExtent ()
{
    return m_extent;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiOBBox::GetWorldCenter () const
{
    return m_wCenter;
}
//---------------------------------------------------------------------------
inline const NiPoint3* NiOBBox::GetWorldBasis () const
{
    return m_wBasis;
}
//---------------------------------------------------------------------------
inline const float* NiOBBox::GetWorldExtent () const
{
    return m_wExtent;
}
//---------------------------------------------------------------------------
inline void NiOBBox::SetRoot (NiOBBRoot* pRoot)
{
    m_pRoot = pRoot;
}
//---------------------------------------------------------------------------
inline const NiOBBRoot* NiOBBox::GetRoot () const
{
    return m_pRoot;
}
//---------------------------------------------------------------------------
