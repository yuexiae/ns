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

#ifndef NICRITICALSECTION_H
#define NICRITICALSECTION_H

#include "NiSystemLibType.h"
#include "NiRTLib.h"

#define NI_MULTITHREADED

class NISYSTEM_ENTRY NiCriticalSection
{
public:
    /// Default constructor.
    NiCriticalSection();
    /// Destructor.
    ~NiCriticalSection();

    /// Locks the critical section.
    void Lock();

    /// Unlocks the critical section.
    void Unlock();

    /// Gets the ID of the thread that last locked the critical section.
    /// @return The ID of the last thread to lock the critical section or
    ///         0 if the critical section is not locked.
    unsigned int GetOwningThreadID() const;

    /// Gets the current count of calls to Lock by the same thread. The
    /// critical section will not be unlocked until Unlock has been called
    /// this many times.
    /// @return The number of times the critical section has been locked by
    ///         the same thread.
    unsigned int GetCurrentLockCount() const;

protected:
#if defined (NI_MULTITHREADED)
#if defined (WIN32) || defined(_XBOX)
    CRITICAL_SECTION m_kCriticalSection;
    /// The ID of the last thread to lock the critical section.
    unsigned long m_ulThreadOwner;
#elif defined (NGC)
    OSMutex m_kCriticalSection;
#elif defined (PS2)
    int m_iCriticalSema;
    int m_iThreadOwner;
    int m_iCount;
#endif // #ifdef for platforms

    /// The count of how many times the critical section has been locked by
    /// the same thread.
    unsigned int m_uiLockCount;
#endif // #if defined (NI_MULTITHREADED)
};

class NISYSTEM_ENTRY NiFastCriticalSection
{
public:
    /// Default constructor.
    NiFastCriticalSection();
    /// Destructor.
    ~NiFastCriticalSection();

    /// Locks the critical section.
    void Lock();

    /// Unlocks the critical section.
    void Unlock();
    
protected:
#if defined (NI_MULTITHREADED)
#if defined (WIN32) || defined(_XBOX)
    CRITICAL_SECTION m_kCriticalSection;
#elif defined (NGC)
    bool m_bRestoreInterrupts;
#elif defined (PS2)
    int m_iCriticalSema;
    int m_iCount;
#endif // #ifdef for platforms

#if defined (_DEBUG)
    bool m_bLocked;
#endif // #if defined (_DEBUG)

#endif // #if defined (NI_MULTITHREADED)
};

#include "NiCriticalSection.inl"

#endif // #ifndef NICRITICALSECTION_H
