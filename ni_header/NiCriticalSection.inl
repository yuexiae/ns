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
#if defined(NI_MULTITHREADED)
inline NiCriticalSection::NiCriticalSection() : 
    m_ulThreadOwner(0), m_uiLockCount(0)
{
    InitializeCriticalSection(&m_kCriticalSection);
}
#else 
inline NiCriticalSection::NiCriticalSection()
{
}
#endif // #if !defined(NI_MULTITHREADED)
//---------------------------------------------------------------------------
inline NiCriticalSection::~NiCriticalSection()
{ 
#if defined(NI_MULTITHREADED)
    DeleteCriticalSection(&m_kCriticalSection);
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline void NiCriticalSection::Lock()
{
#if defined(NI_MULTITHREADED)
    EnterCriticalSection(&m_kCriticalSection);
    m_ulThreadOwner =  GetCurrentThreadId();
    m_uiLockCount++;
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline void NiCriticalSection::Unlock()
{ 
#if defined(NI_MULTITHREADED)
    m_uiLockCount--;
    if (m_uiLockCount == 0)
        m_ulThreadOwner = 0;
    LeaveCriticalSection(&m_kCriticalSection);
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline unsigned int NiCriticalSection::GetOwningThreadID() const
{ 
#if defined(NI_MULTITHREADED)
    return m_ulThreadOwner;
#else
    return 0;
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline unsigned int NiCriticalSection::GetCurrentLockCount() const
{ 
#if defined(NI_MULTITHREADED)
    return m_uiLockCount;
#else
    return 0;
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Fast Critical Section Methods
//---------------------------------------------------------------------------
inline NiFastCriticalSection::NiFastCriticalSection()
{
#if defined(NI_MULTITHREADED)
#if defined(_DEBUG)
    m_bLocked = false;
#endif  //#if defined(_DEBUG)

    InitializeCriticalSection(&m_kCriticalSection);
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline NiFastCriticalSection::~NiFastCriticalSection()
{ 
#if defined(NI_MULTITHREADED)
    DeleteCriticalSection(&m_kCriticalSection);
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline void NiFastCriticalSection::Lock()
{
#if defined(NI_MULTITHREADED)
    EnterCriticalSection(&m_kCriticalSection);
#if defined(_DEBUG)
    assert(m_bLocked == false);
    m_bLocked = true;
#endif  //#if defined(_DEBUG)
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
inline void NiFastCriticalSection::Unlock()
{ 
#if defined(NI_MULTITHREADED)
#if defined(_DEBUG)
    m_bLocked = false;
#endif  //#if defined(_DEBUG)

    LeaveCriticalSection(&m_kCriticalSection);
#endif // #if !defined(NI_MULTITHREADED)
}
//---------------------------------------------------------------------------
