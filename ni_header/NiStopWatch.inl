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

// NiStopWatch inline files

#include "NiSystem.h"

//---------------------------------------------------------------------------
inline NiStopWatch::NiStopWatch() :
m_uiCount(0), m_uiTime(0), m_uiHoldTime(0), m_bHold(false)
{
    /* */
}
//---------------------------------------------------------------------------
inline void NiStopWatch::Start()
{
    if (m_uiCount == 0)
        m_uiTime = NiGetPerformanceCounter();
    m_uiCount++;
}
//---------------------------------------------------------------------------
inline void NiStopWatch::Stop()
{
    assert (m_uiCount > 0);
    m_uiCount--;

    if (m_uiCount == 0)
    {
        m_uiTime = NiGetPerformanceCounter() - m_uiTime;
    }
}
//---------------------------------------------------------------------------
inline void NiStopWatch::Reset()
{
    m_uiCount = m_uiTime = 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiStopWatch::GetTime() const
{
    // Timing data is not relevant in Debug mode and thus can be misleading.
#ifdef _DEBUG
    assert(m_uiCount == 0);
    return 1;
#else
    return m_uiTime;
#endif
}
//---------------------------------------------------------------------------
inline void NiStopWatch::Hold()
{
    m_uiHoldTime = NiGetPerformanceCounter();
    m_bHold = true;
}
//---------------------------------------------------------------------------
inline void NiStopWatch::Unhold()
{
    assert(m_bHold);

    // add hold time to start time
    m_uiTime += NiGetPerformanceCounter() - m_uiHoldTime;
    m_uiHoldTime = 0;
    m_bHold = false;
}
//---------------------------------------------------------------------------
