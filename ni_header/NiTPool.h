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

#ifndef NITPOOL_H
#define NITPOOL_H

// This template class implements an unordered set. Because it does not
// set removed elements to 0, it should not be used for smart pointers.
#include "NiRTLib.h"
#include <NiTSet.h>

template <class T> class NiTPoolContainer
{
public:
    NiTPoolContainer(unsigned int uiSize);
    ~NiTPoolContainer();

    T* GetObject(unsigned int uiIndex);

    void SetNext(NiTPoolContainer<T>* pkNext);
protected:
    T* m_pkObjectArray;
    unsigned int m_uiSize;

    NiTPoolContainer<T>* m_pkNext;

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTPoolContainer(const NiTPoolContainer&);
    NiTPoolContainer& operator=(const NiTPoolContainer&);
};

template <class T> class NiTPool
{
public:
    NiTPool(unsigned int uiInitialSize = 8);
    ~NiTPool();

    T* GetFreeObject();
    void ReleaseObject(T* pkObject);
    
    void PurgeAllObjects();

protected: 
    void CreateNewObjects(unsigned int uiSize);

    NiTSet<T*> m_kFreeObjects;

    unsigned int m_uiCurrentSize;
    unsigned int m_uiInitialSize;
    NiTPoolContainer<T>* m_pkContainers;

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTPool(const NiTPool&);
    NiTPool& operator=(const NiTPool&);
};

#include "NiTPool.inl"

#endif // NITPOOL_H
