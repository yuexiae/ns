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

#ifndef NITMAP_H
#define NITMAP_H

#include <NiRTLib.h>

#include <NiTMapBase.h>
#include <NiTDefaultAllocator.h>

// The map class implements a hash table of TKEY to store values of TVAL.
// It uses modular arithmetic for building the hash keys with a default
// table size of 37.  If you want a larger table size, the best bet is to
// us a large prime number.  Consult a standard text on hashing for the
// basic theory.
//
// The template class assumes that type TKEY has the following:
//   1.  Default constructor, TKEY::TKEY();
//   2.  Copy constructor, TKEY::TKEY(const TKEY&);
//   3.  Assignment, TKEY& operator=(const TKEY&);
//   4.  Comparison, bool TKEY::operator==(const TKEY&);
//   5.  Implicit conversion, TKEY::operator long(), for building hash key
//
// The template class assumes that type TVAL has the following:
//   1.  Default constructor, TVAL::TVAL();
//   2.  Copy constructor, TVAL::TVAL(const TVAL&);
//   3.  Assignment, TVAL& operator=(const TVAL&);
//
// In both cases, the compiler-generated default constructor, copy
// constructor, and assignment operator are acceptable.
//
// Example of iteration over map
//
//     NiTMap<TKEY,TVAL> kMap;
//     NiTMapIterator pos = kMap.GetFirstPos();
//     while (pos)
//     {
//         TKEY key;
//         TVAL val;
//         kMap.GetNext(pos,key,val);
//         <process key and val here>;
//     }

template <class TKEY, class TVAL> class NiTMap :
    public NiTMapBase<NiTDefaultAllocator<TVAL>, TKEY, TVAL >
{
public:
    NiTMap(unsigned int uiHashSize = 37) :
        NiTMapBase<NiTDefaultAllocator<TVAL>, TKEY, TVAL >(uiHashSize) {};
    ~NiTMap();

    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};

#include "NiTMap.inl"

#endif // NITMAP_H
