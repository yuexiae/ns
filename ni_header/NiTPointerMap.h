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

#ifndef NITPOINTERMAP_H
#define NITPOINTERMAP_H

#include "NiTMapBase.h"
#include "NiTPointerAllocator.h"

template <class TKEY, class TVAL> class NiTPointerMap :
    public NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>
{
public:
     NiTPointerMap(unsigned int uiHashSize = 37) : NiTMapBase<
         NiTPointerAllocator<unsigned int>, TKEY, TVAL>(uiHashSize) {}
    ~NiTPointerMap(); 
    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};

#include "NiTPointerMap.inl"

#endif
