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
//  NiBSPNode inline functions

//---------------------------------------------------------------------------
inline NiBSPNode::NiBSPNode()
{
    m_kChildren.SetSize(2);
    m_kChildren.SetGrowBy(0);
}
//---------------------------------------------------------------------------
inline void NiBSPNode::AttachLeft(NiAVObject* pkChild)
{
    SetAt(0,pkChild);
}
//---------------------------------------------------------------------------
inline void NiBSPNode::AttachRight(NiAVObject* pkChild)
{
    SetAt(1,pkChild);
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiBSPNode::DetachLeft()
{
    return DetachChildAt(0);
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiBSPNode::DetachRight()
{
    return DetachChildAt(1);
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiBSPNode::GetLeft()
{
    return m_kChildren.GetAt(0);
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiBSPNode::GetRight()
{
    return m_kChildren.GetAt(1);
}
//---------------------------------------------------------------------------
inline void NiBSPNode::SetModelPlane(const NiPlane& kPlane)
{
    m_kModelPlane = kPlane;
    UpdateWorldPlane();
}
//---------------------------------------------------------------------------
inline const NiPlane& NiBSPNode::GetModelPlane() const
{
    return m_kModelPlane;
}
//---------------------------------------------------------------------------
inline const NiPlane& NiBSPNode::GetWorldPlane() const
{
    return m_kWorldPlane;
}
//---------------------------------------------------------------------------
inline int NiBSPNode::WhichSide(const NiPoint3& kP) const
{
    return m_kWorldPlane.WhichSide(kP);
}
//---------------------------------------------------------------------------
