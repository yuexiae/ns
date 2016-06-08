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
inline NiOBBNode::NiOBBNode()
{
    m_pLeft = 0;
    m_pRight = 0;
    m_uiChangeStamp = 0;
}
//---------------------------------------------------------------------------
inline bool NiOBBNode::IsLeaf()
{
    return false;
}
//---------------------------------------------------------------------------
inline bool NiOBBNode::HasChildren()
{
    return m_pLeft || m_pRight;
}
//---------------------------------------------------------------------------
inline const NiOBBox& NiOBBNode::GetBox() const
{
    return m_box;
}
//---------------------------------------------------------------------------
inline NiOBBNode* NiOBBNode::GetLeft()
{
    return m_pLeft;
}
//---------------------------------------------------------------------------
inline NiOBBNode* NiOBBNode::GetRight()
{
    return m_pRight;
}
//---------------------------------------------------------------------------
inline void NiOBBNode::TransformBox(const NiTransform& xform)
{
    m_box.Transform(xform);
}
//---------------------------------------------------------------------------
inline void NiOBBNode::SetChangeStamp(unsigned int uiChangeStamp)
{
    m_uiChangeStamp = uiChangeStamp;
}
//---------------------------------------------------------------------------
inline unsigned int NiOBBNode::GetChangeStamp() const
{
    return m_uiChangeStamp;
}
//---------------------------------------------------------------------------
