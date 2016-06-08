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
//  NiTPointerAllocator inline functions

//---------------------------------------------------------------------------
template <class T> inline
void* NiTPointerAllocator<T>::Allocate()
{
    ms_kCriticalSection.Lock();
#ifdef _DEBUG
    ms_uiAllocated++;
    if (ms_uiAllocated > ms_uiMaxAllocated)
        ms_uiMaxAllocated = ms_uiAllocated;
#endif

    if (!ms_pkFreeMem)
        CreateFreeMem();

    AllocNode* pTmp = ms_pkFreeMem;
    ms_pkFreeMem = ms_pkFreeMem->m_pkNext;
    pTmp->m_element = 0;
    pTmp->m_pkNext = 0;
    pTmp->m_pkData = 0;
    ms_kCriticalSection.Unlock();
    return pTmp;
} 
//---------------------------------------------------------------------------
template <class T> inline
void NiTPointerAllocator<T>::Deallocate (void* pkDel) 
{
    ms_kCriticalSection.Lock();
#ifdef _DEBUG
    ms_uiAllocated--;
#endif

    // Node being freed - Just set the freepointer
    // here and the next to the previous free
    // In debug, memset(0).
    AllocNode* pDel = (AllocNode*)pkDel;

    pDel->m_pkData = 0;
    pDel->m_pkNext = ms_pkFreeMem;
    ms_pkFreeMem = pDel;
    ms_kCriticalSection.Unlock();
}
//---------------------------------------------------------------------------