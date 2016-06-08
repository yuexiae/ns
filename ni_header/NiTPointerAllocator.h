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

#ifndef NITPOINTERALLOCATOR_H
#define NITPOINTERALLOCATOR_H

#include <NiTAbstractPoolAllocator.h>

#if defined(WIN32) && !defined(_XBOX)
// Instantiate the allocator used by NiTPointerList and NiTPointerMap.
// Disable warnings on extern before template instantiation
#pragma warning (disable : 4231)
#if (defined (NIMAIN_EXPORT) || defined (NIMAIN_IMPORT)) && \
    !defined (NITPOINTERALLOCATOR_INSTANTIATED)
    extern template class NIMAIN_ENTRY NiTAbstractPoolAllocator<unsigned int>;
#endif 
#endif // #if defined(WIN32) && !defined(_XBOX)

template <class T> class NiTPointerAllocator :
    public NiTAbstractPoolAllocator<T>
{
public: 
    void* Allocate();
    void Deallocate (void* p);  
};

//---------------------------------------------------------------------------
// Inline include
#include "NiTPointerAllocator.inl"
//---------------------------------------------------------------------------

#endif