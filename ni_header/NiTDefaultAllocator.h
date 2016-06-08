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

#ifndef NITDEFAULTALLOCATOR_H
#define NITDEFAULTALLOCATOR_H

// To help prevent warning C4786 which is caused by template name expansion,
// here we define our name to be less lengthy.
#define NiTDefaultAllocator DFALL

// NiTDefaultAllocator is used for non-pooling allocations
template <class T> class NiTDefaultAllocator
{
public:
    void* Allocate() 
    {
        AllocNode* pkNode = new AllocNode;
        pkNode->m_element = 0;
        return (void*) pkNode;
    }
    void Deallocate (void* p) 
    {
        delete (AllocNode*)p; 
    }

protected:
    // list is doubly-linked
    class AllocNode 
    {
        public:
            AllocNode* m_pkNext;
            void* m_pkData;
            T m_element;
    };
};

#endif