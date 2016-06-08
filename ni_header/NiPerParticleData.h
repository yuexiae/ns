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

#ifndef NIPERPARTICLEDATA_H
#define NIPERPARTICLEDATA_H

#include "NiOldParticleLibType.h"
#include <NiPoint3.h>
#include <NiTriShape.h>

class NIOLDPARTICLE_ENTRY NiPerParticleData
{
public:
    NiPoint3 m_kVelocity;
    NiPoint3 m_kRotationAxis;

    float m_fAge;
    float m_fLifeSpan;

    float m_fLastUpdate;

    unsigned short m_usGeneration;
    unsigned short m_usIndex;
};

#endif // NIPERPARTICLEDATA_H
