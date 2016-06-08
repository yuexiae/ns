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

#ifndef NIMEMMANAGER_H
#define NIMEMMANAGER_H

#include "NiOS.h"
#include "NiRTLib.h"
#include "NiSystemLibType.h"

#ifdef PS2
#define SMALL_DATA_ALIGNMENT 16
#else
#define SMALL_DATA_ALIGNMENT 4
#endif
#ifdef USE_NI_SMALL_ALLOC_MANAGER
#include "NiSmallAlloc.h"
#endif

#ifdef NGC
class NiNGCMemManager
{
public:
    static void _SDMInit();
    static void _SDMShutdown();

    static int GetThreading();
    static void SetThreading(bool bThreading);

    static bool GetHeapInitialized();
    static void HeapInit();
    static void HeapDestroy();

    static OSHeapHandle GetHeapHandle();

protected:
    static bool ms_bHeapInitialized;
    static int ms_iThreadingCounts;
    static void* ms_pvArenaLo;
    static void* ms_pvArenaHi;
    static OSHeapHandle ms_iHeapHandle;
};
#endif

#ifdef NI_USE_MEMORY_MANAGEMENT
#define NI_MEMORY_DEBUGGER

void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* pvMem);
void operator delete[](void* pvMem);

// file/lineno new is automatically used with NI_MEMORY_DEBUGGER.
// file/lineno delete is not.
void* operator new(size_t size, char* pcFile, int iLine);
void* operator new[](size_t size, char* pcFile, int iLine);
void operator delete(void* pvMem, char* pcFile, int iLine);
void operator delete[](void* pvMem, char* pcFile, int iLine);
void* nimemalign(size_t alignment, size_t size, char* pcFile, int iLine);
void* nimalloc(size_t size, char* pcFile, int iLine);
void* nirealloc(void* pvMem, size_t size, char* pcFile, int iLine);
void nifree(void* pvMem, char* pcFile, int iLine);

#if defined(_XBOX)
// Xbox only
void* NiAllocContiguous_Mem(unsigned int uiSize, unsigned int uiAlignment,
    char* pcFile, int iLine);
void NiFreeContiguous_Mem(void* pvMem, char* pcFile, int iLine);
#endif  //#if defined(_XBOX)

#ifdef NI_MEMORY_DEBUGGER
#define NINEW new(__FILE__, __LINE__)
#define NIDELETE delete(__FILE__, __LINE__)
#define NIMALLOC(a) nimalloc(a, __FILE__, __LINE__)
#define NIMEMALIGN(a, b) nimemalign(a, b, __FILE__, __LINE__)
#define NIFREE(a) nifree(a, __FILE__, __LINE__)
#define NIREALLOC(a, b) nirealloc(a, b, __FILE__, __LINE__)
#if defined(_XBOX)
#define NIALLOCCONTIGUOUS(a, b) \
    NiAllocContiguous_Mem(a, b, __FILE__, __LINE__)
#define NIFREECONTIGUOUS(a)     \
    NiFreeContiguous_Mem(a, __FILE__, __LINE__)
#endif  //#if defined(_XBOX)
#include "NiNewRedef.h"

#endif  //#ifdef NI_MEMORY_DEBUGGER

//  This class should be the GLOBAL memory class. I.e., there should be just
//  one STATIC instance of it.

//  To override the memory management, just replace this class (or derive
//  from it, and replace the static instance w/ a static instance of your 
//  derived class).
class NISYSTEM_ENTRY NiMemManager
{
public:
    enum
    {
        MEMORY_MULT_KB  = (1024),
        MEMORY_MULT_MB  = (1024 * 1024)
    };

    static void _SDMInit();
    static void _SDMShutdown();

    static void CheckMemory();
    static void DumpMemoryStats();
    static void DumpMemory();
    static void AddBytesAllocated(unsigned long ulSize);
    static void AddBytesAllocatedByPointer(void* pvMem, unsigned long ulSize,
        char* pcFile = 0, int iLine = 0);
    static void DeleteBytesAllocated(unsigned long ulSize);
    static void DeleteBytesAllocatedByPointer(void* pvMem, char* pcFile = 0, 
        int iLine = 0);

    static void Timestamp(const char* pcString);

    static unsigned int ms_uiCalls_New;
    static unsigned int ms_uiCalls_Delete;
    static bool ms_bTrackerEnabled;

private:
    static bool ms_bDumpAllocFreesEnabled;
    static unsigned int ms_uiNextID;

    //  Stats tracking...
    static unsigned int ms_uiBytes_Allocated;
    static unsigned int ms_uiBytes_MaxAllocated;
    static unsigned int ms_uiBytes_MaxChunkAllocated;
    static unsigned int ms_uiBytes_RunningTotalAllocated;
    static unsigned int ms_uiBytes_Freed;
    static unsigned int ms_uiTrackersAllocated;
    static float ms_fTime_Init;
    static float ms_fTime_MaxAllocated;
    
    class NiMemTrack
    {
    public:
        NiMemTrack();

        enum
        {
            PATH_LEN = 36
        };

        unsigned int m_uiID;
        void* m_pvMem;
        unsigned long m_ulSize;
        char m_acFile[PATH_LEN];
        int m_iLine;
        NiMemTrack* m_pkNext;
        NiMemTrack* m_pkPrev;
        
        // lifetime
        float m_fNewTime;
        float m_fDeleteTime;

        unsigned int m_uiBytesAllocated; // allows for time-vs-memory graph
    };

    static NiMemTrack* ms_pkTrackerList;
    static NiMemTrack* ms_pkTrackerFree;
#ifndef NIMEM_RECLAIM_TRACKERS
    static NiMemTrack* ms_pkTrackerDeleted;  // may be same as ms_pkTrackerFree, 
                                             // or may be used for history
#endif

    static void AllocateTrackerBlock();
    static NiMemTrack* GrabFreeTracker();
    static void PurgeTrackers();

    class TimeEvent
    {
    public:
        TimeEvent();

        const char* m_pcString;
        float m_fTime;
        TimeEvent* m_pkNext;
    };
    static TimeEvent* ms_pkTimestamps;
};

#else  // #ifndef NI_USE_MEMORY_MANAGEMENT
//---------------------------------------------------------------------------
//  Custom memory manager
//---------------------------------------------------------------------------
#ifdef NGC
// GameCube always defines new and delete
void* operator new (size_t size);
void* operator new[] (size_t size);
void operator delete (void* pvMem);
void operator delete[] (void* pvMem);

#endif // #ifdef NGC

#if defined(_XBOX)
// Xbox only
void* NiAllocContiguous(unsigned int uiSize, unsigned int uiAlignment);
void NiFreeContiguous(void* pvMem);
#endif  //#if defined(_XBOX)

#endif // #ifdef NI_USE_MEMORY_MANAGEMENT

#include "NiMemManager.inl"

#endif  //#ifndef NIMEMMANAGER_H

#if defined(NGC) && defined(SNSYS)

//this function does nothing but is called from application code to force
//the linker to look into NiSystem.lib thus resolving the bug in the SN
//linker that causes new and delete to not be linked in
void fixLinkerErrorFunction();

//Normally, the placement new is an inline function, but because of an
//inconsistency with SN Systems STL port in version 3.8 it must be defined
//here as non-inlined.
void* operator new(size_t size, void* p);

#endif //#ifdef NGC && SNSYS
