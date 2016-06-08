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

#ifndef NITABSTRACTPOOLALLOCATOR_H
#define NITABSTRACTPOOLALLOCATOR_H

#include <NiRefObject.h>
#include <NiRTLib.h>
#include <NiCriticalSection.h>

#define NiAllocatorShutdown(T) NiTAbstractPoolAllocator<T>::_SDMShutdown();

#ifdef _DEBUG
    #define NiAllocatorDeclareStatics(T, BLOCKSIZE) \
        NiTAbstractPoolAllocator<T>::AllocNode* \
            NiTAbstractPoolAllocator<T>::ms_pkBlockHeader = NULL; \
        NiTAbstractPoolAllocator<T>::AllocNode* \
            NiTAbstractPoolAllocator<T>::ms_pkFreeMem = NULL; \
        NiCriticalSection NiTAbstractPoolAllocator<T>::ms_kCriticalSection; \
        unsigned int NiTAbstractPoolAllocator<T>::ms_uiBlockSize = BLOCKSIZE; \
        unsigned int NiTAbstractPoolAllocator<T>::ms_uiAllocated = 0; \
        unsigned int NiTAbstractPoolAllocator<T>::ms_uiMaxAllocated = 0;
#else
    #define NiAllocatorDeclareStatics(T, BLOCKSIZE) \
        NiTAbstractPoolAllocator<T>::AllocNode* \
            NiTAbstractPoolAllocator<T>::ms_pkBlockHeader = NULL; \
        NiTAbstractPoolAllocator<T>::AllocNode* \
            NiTAbstractPoolAllocator<T>::ms_pkFreeMem = NULL; \
        unsigned int NiTAbstractPoolAllocator<T>::ms_uiBlockSize = BLOCKSIZE; \
        NiCriticalSection NiTAbstractPoolAllocator<T>::ms_kCriticalSection;
#endif

#define NiAllocatorSetBlockSize(T, BLOCKSIZE) \
    NiTAbstractPoolAllocator<T>::SetBlockSize(BLOCKSIZE);
#define NiAllocatorEnsureFreeMem(T) \
    NiTAbstractPoolAllocator<T>::EnsureFreeMem();
                           
template <class T> class NiTAbstractPoolAllocator
{
public: 

    // Virtuals are not used because they add additional memory for each
    // class derived. This class can be thought of as abstract with the
    // following commented classes as pure virtuals.
    // virtual void* Allocate() = 0;
    // virtual void Deallocate (void* p) = 0; 
  
  static void _SDMShutdown();
  static void SetBlockSize(unsigned int uiBlockSize);
  static void EnsureFreeMem();
  static void CreateFreeMem();

protected:
    // list is doubly-linked
  class AllocNode 
  {
    public:
        AllocNode* m_pkNext;
        void* m_pkData;
        T m_element;
  };

  static AllocNode* ms_pkBlockHeader;
  static AllocNode* ms_pkFreeMem;
  static unsigned int ms_uiBlockSize;

  static NiCriticalSection ms_kCriticalSection;

#ifdef _DEBUG
  static unsigned int ms_uiAllocated;
  static unsigned int ms_uiMaxAllocated;
#endif
};

//---------------------------------------------------------------------------
// Inline include
#include "NiTAbstractPoolAllocator.inl"
//---------------------------------------------------------------------------

#endif