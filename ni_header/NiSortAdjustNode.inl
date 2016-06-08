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
//  NiSortAdjustNode inline functions

//---------------------------------------------------------------------------
inline NiSortAdjustNode::NiSortAdjustNode()
{
    m_eSortingMode = SORTING_INHERIT;
    m_spAccum = 0;
}
//---------------------------------------------------------------------------
inline NiSortAdjustNode::~NiSortAdjustNode()
{
    /* */
}
//---------------------------------------------------------------------------
inline void NiSortAdjustNode::SetSortingMode(SortingMode eMode)
{
    m_eSortingMode = eMode;
}
//---------------------------------------------------------------------------
inline NiSortAdjustNode::SortingMode NiSortAdjustNode::GetSortingMode() const
{
    return m_eSortingMode;
}
//---------------------------------------------------------------------------
inline void NiSortAdjustNode::SetSubSorter(NiAccumulator* pkSorter)
{
    m_spAccum = pkSorter;
}
//---------------------------------------------------------------------------
inline NiAccumulator* NiSortAdjustNode::GetSubSorter() const
{
    return m_spAccum;
}
//---------------------------------------------------------------------------

