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
//  NiMemManager Inline Functions
//---------------------------------------------------------------------------
#ifdef NI_USE_MEMORY_MANAGEMENT
//---------------------------------------------------------------------------
inline void NiMemManager::CheckMemory()
{
    //  Not available on all platforms
}
//---------------------------------------------------------------------------
inline void NiMemManager::DeleteBytesAllocated(unsigned long ulSize)
{
    ms_uiBytes_Allocated -= ulSize;
    ms_uiBytes_Freed += ulSize;
}
//---------------------------------------------------------------------------
inline NiMemManager::NiMemTrack* NiMemManager::GrabFreeTracker(void)
{
    if (ms_pkTrackerFree == 0)
    {
        AllocateTrackerBlock();
    }

    assert(ms_pkTrackerFree);

    NiMemTrack* pkTrack = ms_pkTrackerFree;

    ms_pkTrackerFree = ms_pkTrackerFree->m_pkNext;

    return pkTrack;
}
//---------------------------------------------------------------------------
inline NiMemManager::TimeEvent::TimeEvent()
{
    m_pcString = 0;
    m_fTime = 0;
    m_pkNext = 0;
}
//---------------------------------------------------------------------------
inline NiMemManager::NiMemTrack::NiMemTrack()
{
    m_uiID = 0xFFFFFFFF;
    m_pvMem = 0;
    m_ulSize = 0;
    memset(m_acFile, 0, PATH_LEN);
    m_iLine = 0;
    m_pkNext = 0;
    m_pkPrev = 0;
}
//---------------------------------------------------------------------------
#else   //#ifndef NI_USE_MEMORY_MANAGEMENT
//---------------------------------------------------------------------------
//  Custom memory manager
//---------------------------------------------------------------------------
#endif  //#ifdef NI_USE_MEMORY_MANAGEMENT
//---------------------------------------------------------------------------
#ifdef NGC
//---------------------------------------------------------------------------
inline int NiNGCMemManager::GetThreading()
{
    return ms_iThreadingCounts;
}
//---------------------------------------------------------------------------
inline void NiNGCMemManager::SetThreading(bool bThreading)
{
    if (bThreading)
    {
        ms_iThreadingCounts++;
    }
    else
    {
        ms_iThreadingCounts = 
            ms_iThreadingCounts > 0 ? ms_iThreadingCounts - 1 : 0;
    }
}
//---------------------------------------------------------------------------
inline bool NiNGCMemManager::GetHeapInitialized()
{
    return ms_bHeapInitialized;
}
//---------------------------------------------------------------------------
inline OSHeapHandle NiNGCMemManager::GetHeapHandle()
{
    return ms_iHeapHandle;
}
//---------------------------------------------------------------------------
#endif
