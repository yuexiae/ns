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

#ifndef NIPARALLELEPIPED_H
#define NIPARALLELEPIPED_H

#include "NiCollisionLibType.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiParallelepiped
{
public:
    // parallelepiped is P(t) = B + s0*E0 + s1*E1 + s2*E2 for (s0,s1,s2)
    // in [0,1]^3
    NiPoint3 m_kOrigin;  // B
    NiPoint3 m_kEdge0;   // E0
    NiPoint3 m_kEdge1;   // E1
    NiPoint3 m_kEdge2;   // E2


    NiPoint3 GetPoint(float fS0, float fS1, float fS2) const;

    // comparison
    bool operator==(const NiParallelepiped& kPpd) const;
    bool operator!=(const NiParallelepiped& kPpd) const;

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif

