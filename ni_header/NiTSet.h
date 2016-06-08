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

#ifndef NITSET_H
#define NITSET_H

// This template class implements an unordered set. Because it does not
// set removed elements to 0, it should not be used for smart pointers.
#include "NiRTLib.h"

template <class T> class NiTSet
{
public:
    NiTSet(unsigned int uiInitialSize = 0);
    ~NiTSet();

    unsigned int GetSize() const;
    T *GetBase() const;
    const T& GetAt(unsigned int uiIndex) const;
    T& GetAt(unsigned int uiIndex);
    void Add(const T& element);
    void AddUnique(const T& element); // Slow. Use with caution.
    void RemoveAt(unsigned int uiIndex);
    void OrderedRemoveAt(unsigned int uiIndex); // Preserve order.
    void ReplaceAt(unsigned int uiIndex, const T& element);
    void RemoveAll();
    void Realloc();
    int Find(const T& element) const; // Slow. Use with caution.

protected: 
    void Realloc(unsigned int uiNewSize);

    T *m_pBase;
    unsigned int m_uiAlloced;
    unsigned int m_uiUsed;

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTSet(const NiTSet&);
    NiTSet& operator=(const NiTSet&);
};

#include "NiTSet.inl"

#endif // NITSET_H
