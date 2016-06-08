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
//  NiNode inline functions

//---------------------------------------------------------------------------
inline void NiNode::RemoveAllChildren()
{
    m_kChildren.RemoveAll();
}
//---------------------------------------------------------------------------
inline void NiNode::CompactChildArray()
{
    m_kChildren.Compact();
    m_kChildren.UpdateSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiNode::GetArrayCount() const
{
    return m_kChildren.GetSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiNode::GetChildCount() const
{
    return m_kChildren.GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline NiAVObject* NiNode::GetAt(unsigned int i) const
{
    if (m_kChildren.GetSize() <= i)
    {
        return 0;
    }
    else
    {
        return m_kChildren.GetAt(i);
    }
}
//---------------------------------------------------------------------------
inline const NiDynamicEffectList& NiNode::GetEffectList() const
{
    return m_kEffectList;
}
//---------------------------------------------------------------------------
