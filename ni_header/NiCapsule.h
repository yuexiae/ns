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

#ifndef NICAPSULE_H
#define NICAPSULE_H

#include "NiCollisionLibType.h"
#include "NiSegment.h"

class NICOLLISION_ENTRY NiCapsule
{
public:
    // A capsule consists of a line segment and a radius.  The capsule
    // surface is the set of all points that are a distance R from the
    // line segment.
    NiSegment m_kSegment;
    float m_fRadius;

    // comparison
    bool operator==(const NiCapsule& kCapsule) const;
    bool operator!=(const NiCapsule& kCapsule) const;

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif

