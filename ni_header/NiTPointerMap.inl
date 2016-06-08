// NiTPointerMap.cpp
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
template <class TKEY, class TVAL> inline
NiTPointerMap<TKEY,TVAL>::~NiTPointerMap()
{
    // RemoveAll is called from here because it depends on virtual functions
    // implemented in NiTAllocatorMap.  It will also be called in the 
    // parent destructor, but the map will already be empty.
    RemoveAll();
}
//---------------------------------------------------------------------------
template <class TKEY, class TVAL> inline
NiTMapItem<TKEY, TVAL>* NiTPointerMap<TKEY, TVAL>::NewItem()
{
    return (NiTMapItem<TKEY, TVAL>*)m_kAllocator.Allocate();
}
//---------------------------------------------------------------------------
template <class TKEY, class TVAL> inline
void NiTPointerMap<TKEY, TVAL>::DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem)
{
    // set key and val to zero so that if they are smart pointers
    // their references will be decremented.
    pkItem->m_val = 0;
    m_kAllocator.Deallocate(pkItem);
}
//---------------------------------------------------------------------------