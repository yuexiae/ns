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
//  NiTAbstractPoolAllocator inline functions

#include <assert.h>

//---------------------------------------------------------------------------
template <class T> inline
void NiTAbstractPoolAllocator<T>::EnsureFreeMem()
{
    if (!ms_pkFreeMem)
        CreateFreeMem();  
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTAbstractPoolAllocator<T>::CreateFreeMem()
{
    assert(ms_pkFreeMem == 0);
    assert(ms_uiBlockSize >= 2);

    ms_pkFreeMem = new AllocNode[ms_uiBlockSize];      

    // Handle end point
    AllocNode *pkCurr = ms_pkFreeMem + ms_uiBlockSize - 1;
    pkCurr->m_pkNext = 0;

    unsigned int i = 1;

    do
    {
        pkCurr = ms_pkFreeMem + i;
        pkCurr->m_pkNext = pkCurr + 1;
    } while(i++ < ms_uiBlockSize - 2);

    if (ms_pkBlockHeader)
    {
        // add block to head of list
        ms_pkFreeMem->m_pkNext = ms_pkBlockHeader;
        ms_pkBlockHeader = ms_pkFreeMem;
    }
    else
    {
        ms_pkBlockHeader = ms_pkFreeMem;
        ms_pkBlockHeader->m_pkNext = 0;
    }

    ms_pkFreeMem = ms_pkFreeMem + 1;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTAbstractPoolAllocator<T>::_SDMShutdown()
{
    NiTAbstractPoolAllocator<T>::AllocNode* pkCurr = ms_pkBlockHeader;

    while (pkCurr)
    {
        NiTAbstractPoolAllocator<T>::AllocNode* pkNext 
          = pkCurr->m_pkNext;
        delete [] pkCurr;
        pkCurr = pkNext;
    }

    ms_pkBlockHeader = NULL;
    ms_pkFreeMem = NULL;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTAbstractPoolAllocator<T>::SetBlockSize(unsigned int uiBlockSize)
{
    assert(uiBlockSize >= 2);
    ms_uiBlockSize = uiBlockSize; 
}
//---------------------------------------------------------------------------
