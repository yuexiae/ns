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

#ifndef NITRIGON_H
#define NITRIGON_H

#include "NiCollisionLibType.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiTrigon
{
public:
    // trigon is P(t) = B + s0*E0 + s1*E1 for 0 <= s0 < = 1, 0 <= s1 <= 1,
    // 0 <= s0 + s1 <= 1.
    NiPoint3 m_kOrigin;  // B
    NiPoint3 m_kEdge0;   // E0
    NiPoint3 m_kEdge1;   // E1


    NiPoint3 GetPoint(float fS0, float fS1) const;
    NiPoint3 GetNormal() const;

    // comparison
    bool operator==(const NiTrigon& kTri) const;
    bool operator!=(const NiTrigon& kTri) const;

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif
