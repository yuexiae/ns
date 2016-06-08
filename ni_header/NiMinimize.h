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

#ifndef NIMINIMIZE_H
#define NIMINIMIZE_H

#include "NiCollisionLibType.h"


#define MAX_ITERATIONS 4    // Default "hint" for max. # iterations.

// You may change this default max. # iterations, which is used for all
// ABV-vs-ABV comparisons (BoxBV, CapsuleBV, SphereBV) by changing this value
// and recompiling.
// Changing this value enables you to trade-off quality of collision results
// for performance, specifically for ABV-vs-ABV comparisons.
// The recommended range of values is:  4 - 6, with 4 representing the fastest
// performance, and 6 representing the best collision results.




//---------------------------------------------------------------------------
// Assign maximum recursion level, based on relative velocity of objects.
// Specific values have been determined via extensive investigation of a large
// number of test cases.
#define ASSIGN_MAX_LEVEL(Velocity, MaxLevel) \
{ \
    if (((MaxLevel) > 2) || ((MaxLevel) < 1)) \
        (MaxLevel) = 2; \
    if (Velocity > 512) \
        (MaxLevel) += 2; \
    else if (Velocity > 256) \
        (MaxLevel) += 1; \
}
//---------------------------------------------------------------------------


class NICOLLISION_ENTRY NiMinimize
{
public:
    typedef float (*Function)(float, void*);

    NiMinimize(Function pfnFunction, unsigned int uiMaxLevel,
        unsigned int uiMaxBracket, void* pvUserData = 0);

    void GetMinimum(float fT0, float fT1, float fTInitial,
        float& fTMin, float& fFMin);

    // Designed for a convex pfnFunction D(t) where D(fT0) > 0.  Return
    // value is true iff there exists fT in (fT0,fT1] such D(fT) = 0
    // and D(t) > 0 for t in [fT0,fT].  The input values are fF0 = D(fT0)
    // and fF1 = D(fT1).
    void SetTolerance(float fTolerance);
    bool FindFirstZero(float fT0, float fF0, float fT1, float fF1,
        float& fT);
    bool BoundTime(unsigned int uiLevel, float fT0, float fF0, 
        float fT1, float fF1);

protected:
    Function m_pfnFunction;
    unsigned int m_uiMaxLevel;
    unsigned int m_uiMaxBracket;
    float m_fTMin;
    float m_fFMin;
    float m_fTolerance;
    void* m_pvUserData;

    void GetMinimum(float fT0, float fF0, float fT1, float fF1,
        unsigned int uiLevel);

    void GetMinimum(float fT0, float fF0, float fTm, float fFm,
        float fT1, float fF1, unsigned int uiLevel);

    void GetBracketedMinimum(float fT0, float fF0, float fTm,
        float fFm, float fT1, float fF1, unsigned int uiLevel);

    bool BoundTime(unsigned int uiLevel, float fT0, float fF0, float fT1,
        float fF1, float& fB0, float& fB1, float& fR0, float& fR1);
};

#endif
