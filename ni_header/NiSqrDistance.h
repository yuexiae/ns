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

#ifndef NISQRDISTANCE_H
#define NISQRDISTANCE_H

#include "NiParallelepiped.h"
#include "NiParallelogram.h"
#include "NiPoint3.h"
#include "NiSegment.h"
#include "NiTrigon.h"

class NICOLLISION_ENTRY NiSqrDistance
{
public:
    // point - point
    static float Compute(const NiPoint3& kPnt0, const NiPoint3& kPoint1);

    // point - segment
    static float Compute(const NiPoint3& kPnt, const NiSegment& kSeg,
        float& fSegParam);

    // point - triangle
    static float Compute(const NiPoint3& kPnt, const NiTrigon& kTri,
        float& fTriParam0, float& fTriParam1);

    // point - parallelogram
    static float Compute(const NiPoint3& kPoint,
        const NiParallelogram& kPgm, float& fPgmParam0,
        float& fPgmParam1);

    // point - parallelepiped
    static float Compute(const NiPoint3& kPoint,
        const NiParallelepiped& kPpd, float& fPpdParam0,
        float& fPpdParam1, float& fPpdParam2);

    // segment - segment
    static float Compute(const NiSegment& kSeg0, const NiSegment& kSeg1,
        float& fSeg0Param, float& fSeg1Param);

    // segment - triangle
    static float Compute(const NiSegment& kSeg, const NiTrigon& kTri,
        float& fSegParam, float& fTriParam0, float& fTriParam1);

    // segment - parallelogram
    static float Compute(const NiSegment& kSeg,
        const NiParallelogram& kPgm, float& fSegParam,
        float& fPgmParam0, float& fPgmParam1);

    // segment - parallelepiped
    static float Compute(const NiSegment& kSeg,
        const NiParallelepiped& kPpd, float& fSegParam,
        float& fPpdParam0, float& fPpdParam1, float& fPpdParam2);

    // triangle - triangle
    static float Compute(const NiTrigon& kTri0, const NiTrigon& kTri1,
        float& fTri0Param0, float& fTri0Param1, float& fTri1Param0,
        float& fTri1Param1);

    // triangle - parallelogram
    static float Compute(const NiTrigon& kTri,
        const NiParallelogram& kPgm, float& fTriParam0, float& fTriParam1,
        float& fPgmParam0, float& fPgmParam1);
};

//---------------------------------------------------------------------------
//  Inline include
#include "NiSqrDistance.inl"

//---------------------------------------------------------------------------

#endif

