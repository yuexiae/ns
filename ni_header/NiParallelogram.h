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

#ifndef NIPARALLELOGRAM_H
#define NIPARALLELOGRAM_H

#include "NiCollisionLibType.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiParallelogram
{
public:
    // parallelogram is P(t) = B + s0*E0 + s1*E1 for (s0,s1) in [0,1]^2
    NiPoint3 m_kOrigin;  // B
    NiPoint3 m_kEdge0;   // E0
    NiPoint3 m_kEdge1;   // E1


    NiPoint3 GetPoint(float fS0, float fS1) const;

    // comparison
    bool operator==(const NiParallelogram& kPgm) const;
    bool operator!=(const NiParallelogram& kPgm) const;

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif

