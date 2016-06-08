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

#ifndef NITQUEUE_H
#define NITQUEUE_H

// This template class implements a FIFO queue. 

template <class T> class NiTQueue
{
public:
    NiTQueue(unsigned int uiInitialSize = 1);
    ~NiTQueue();

    void Add(T element);
    void AddUnique(T element); // Slow. Use with caution.
    T Remove();
    T Head() const;
    bool IsEmpty() const;
    unsigned int GetSize() const;
    void Realloc();

protected:
    bool IsFull() const;
    void Realloc(unsigned int uiNewSize);

    T *m_pBase;
    unsigned int m_uiAlloced, m_uiHead, m_uiTail;

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTQueue(const NiTQueue&);
    NiTQueue& operator=(const NiTQueue&);
};

#include "NiTQueue.inl"

#endif // NITQUEUE_H
