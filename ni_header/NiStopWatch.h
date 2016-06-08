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

#ifndef NISTOPWATCH_H
#define NISTOPWATCH_H

class NiStopWatch
{
public:
    NiStopWatch();
    
    void Start();                   // start timing if not already started
    void Stop();                    // stop timing if no other counts pending

    void Hold();                    // temporarily stop timing
    void Unhold();                  // resume timing

    void Reset();
    unsigned int GetTime() const;   // GetTime() returns timing data in Release
                                    // builds, 1 in Debug builds.

protected:
    unsigned int m_uiCount;         // # times started - # times stopped
    unsigned int m_uiTime;          // time when Start() was first called
    unsigned int m_uiHoldTime;      // time when Hold() was called
    bool m_bHold;                   // true if currently holding
};

#include "NiStopWatch.inl"

#endif // #ifndef NISTOPWATCH_H
