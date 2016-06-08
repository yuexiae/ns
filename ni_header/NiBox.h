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

#ifndef NIBOX_H
#define NIBOX_H

#include "NiCollisionLibType.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiBox
{
public:
    // Box is B(s0,s1,s2) = C + s0*e0*A0 + s1*e0*A1 + s2*e2*A2 for
    // |s_i| <= 1 for i = 0,1,2.  Also, matrix [A0|A1|A2] is orthonormal
    // with determinant 1.
    NiPoint3 m_kCenter;    // C
    NiPoint3 m_akAxis[3];  // A0, A1, A2
    float m_afExtent[3];   // e0, e1, e2


    // generates point C + p0*A0 + p1*A1 + p2*A2
    NiPoint3 GetPoint(float fP0, float fP1, float fP2) const;

    // comparison
    bool operator==(const NiBox& kBox) const;
    bool operator!=(const NiBox& kBox) const;

    void CreateFromData(unsigned short usQuantity, const NiPoint3* pkVertex);

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif

