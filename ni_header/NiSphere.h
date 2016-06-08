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

#ifndef NISPHERE_H
#define NISPHERE_H

#include "NiCollisionLibType.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiSphere
{
public:
    NiPoint3 m_kCenter;
    float m_fRadius;


    // comparision
    bool operator==(const NiSphere& kSphere) const;
    bool operator!=(const NiSphere& kSphere) const;

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
};

#endif

