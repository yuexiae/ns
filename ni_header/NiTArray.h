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

#ifndef NITARRAY_H
#define NITARRAY_H

#include "NiRTLib.h"

// While the template arrays work best for pointer types T, other types
// certainly will work when they satisfy the conditions below.  The template
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
// An example to illustrate what the members of NiTArray mean.  Shown is
// an array of elements (0 = null element, x = an element)
//     index:    0 1 2 3 4 5 6 7 8 9
//     element:  x 0 x x 0 0 x 0 0 0
//
//     m_uiMaxSize = 10 (number of slots in array)
//     m_uiSize    =  7 (next available slot, useful for traversing minimum
//                       block of elements while searching for non-null items)
//     m_uiESize   =  4 (number of used slots)
//
// Note that when m_uiSize = m_uiMaxSize, an attempt to add a new element
// requires growing the array.  SetAtGrow does this.  SetAt does not.

template <class T> class NiTArray 
{
public:
    // construction and destruction
    NiTArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
    virtual ~NiTArray();

    // slots available and used
    unsigned int GetSize() const;
    unsigned int GetEffectiveSize() const;
    unsigned int GetAllocatedSize() const;
    unsigned int GetGrowBy() const;
    void SetSize(unsigned int uiSize);
    void SetGrowBy(unsigned int uiGrowBy);

    // set and get elements
    T* GetBase();
    const T& GetAt(unsigned int uiIndex) const;
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element);

    // add and remove elements
    unsigned int Add(const T& element);
    unsigned int AddFirstEmpty(const T& element);
    T RemoveAt(unsigned int uiIndex);
    // Removes last element in array and places it at uiIndex 
    T RemoveAtAndFill(unsigned int uiIndex);
    T RemoveEnd();
    void RemoveAll();

    // Compact all elements to contiguous space starting at the beginning of
    // the array.  Reallocation is performed to eliminate unused slots.
    void Compact();

    // After deletions before m_uiSize slot, m_uiSize no longer points to
    // the first available slot.  This routine resets it to the first
    // available slot.
    void UpdateSize();

protected:
    T* m_pBase;                // pointer to the array storage
    unsigned int m_uiMaxSize;  // number of slots in array
    unsigned int m_uiSize;     // first available empty slot in array
    unsigned int m_uiESize;    // number of filled slots
    unsigned int m_uiGrowBy;   // number of slots to grow array when full

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTArray(const NiTArray&);
    NiTArray& operator=(const NiTArray&);
};

#include "NiTArray.inl"

#endif // NITARRAY_H
