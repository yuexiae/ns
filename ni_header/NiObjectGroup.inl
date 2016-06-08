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
inline void* NiObjectGroup::Allocate(unsigned int uiBytes)
{
    void* pvMem = m_pvFree;
    m_pvFree = (void*)(((unsigned int)m_pvFree) + uiBytes);
    m_uiRefCount++;
    return pvMem;
}
//---------------------------------------------------------------------------
inline void NiObjectGroup::DecRefCount()
{
    if (--m_uiRefCount == 0)
        delete this;
}
//---------------------------------------------------------------------------
inline void NiObjectGroup::SetSize(unsigned int uiSize)
{
    m_uiSize = uiSize;
}
//---------------------------------------------------------------------------
inline unsigned int NiObjectGroup::GetSize() const
{
    return m_uiSize;
}
//---------------------------------------------------------------------------
