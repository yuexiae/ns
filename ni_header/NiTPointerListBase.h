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

#ifndef NITPOINTERLISTBASE_H
#define NITPOINTERLISTBASE_H

#include "NiTListBase.h"
#include "NiRTLib.h"

// NiTPointerListBase defines the interface for NiTList and NiTPointerList.
// The interface works best for pointer types T, however, other types
// will work when they satisfy the conditions below.  The template
// class assumes that type T has the following:
//   1.  A "zero" element (i.e., T var; var = 0; is supported)
//       which is considered to be a null array element.
//   2.  The default constructor for T must exist and create the
//       "zero" element.  The constructor must also handle all necessary
//       actions for constructing elements.  That is, the template array
//       class cannot make any post-construction member calls that are
//       specific to class T.
//   3.  Copy constructor T::T (const T&) must work properly.  The class T is
//       responsible for implementing this if need be.
//   4.  The destructor must handle all necessary actions for destroying
//       elements.  That is, the template array class cannot make any
//       pre-destruction member calls that are specific to class T.
//   5.  bool operator== (const T&);
//   6.  bool operator!= (const T&);
//   7.  T& operator= (const T&);
//
// NiTPointerList<T> requires sizeof(T) == sizeof(unsigned int), so that
// elements may be block allocated from a shared memory pool.
//
// For true objects, the NiTObjectList is usually a better choice.
//
// Example of iteration from head to tail:
//
//   NiTPointerList<T> kList;
//   NiTListIterator kPos = kList.GetHeadPos();
//   while (kPos)
//   {
//       T element = kList.GetNext(kPos);
//       <process element here>;
//   }

template <class TheAllocator, class T> class NiTPointerListBase : 
    public NiTListBase<TheAllocator,T>
{
public:
    virtual ~NiTPointerListBase();

    // Add/Insert functions 
    void AddHead(const T& element);
    void AddTail(const T& element);
    NiTListIterator InsertBefore(NiTListIterator kPos, const T& element);
    NiTListIterator InsertAfter(NiTListIterator kPos, const T& element);

    // Element access
    const T& GetHead() const;
    const T& GetTail() const;
    const T& Get(NiTListIterator kPos) const;

    // Element access with iteration support
    const T& GetNext(NiTListIterator& kPos) const;
    const T& GetPrev(NiTListIterator& kPos) const;

    // Remove functions
    T RemoveHead();
    T RemoveTail();
    T Remove(const T& element);
    T RemovePos(NiTListIterator& kPos);

    // Element search
    NiTListIterator FindPos(const T& element, 
        NiTListIterator kStart = 0) const;

protected:
    virtual NiTListItem<T>* NewItem();
    virtual void DeleteItem(NiTListItem<T>* pkItem);

};

//---------------------------------------------------------------------------
// Inline include
#include "NiTPointerListBase.inl"
//---------------------------------------------------------------------------

#endif // NITPOINTERLISTBASE_H
