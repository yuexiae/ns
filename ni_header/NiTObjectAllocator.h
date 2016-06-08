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

#ifndef NITOBJECTALLOCATOR_H
#define NITOBJECTALLOCATOR_H

#include <NiTAbstractPoolAllocator.h>

template <class T> class NiTObjectAllocator : 
    public NiTAbstractPoolAllocator<T>
{
public: 
    static void* Allocate();
    static void Deallocate (void* p); 
};

//---------------------------------------------------------------------------
// Inline include
#include "NiTObjectAllocator.inl"
//---------------------------------------------------------------------------

#endif