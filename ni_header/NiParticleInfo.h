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

#ifndef NIPARTICLEINFO_H
#define NIPARTICLEINFO_H

#include "NiParticleLibType.h"
#include <NiPoint3.h>

class NiStream;

class NIPARTICLE_ENTRY NiParticleInfo
{
public:
    NiParticleInfo();

    // *** begin NDL internal use only ***
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    bool IsEqual(const NiParticleInfo& kData);
    // *** end NDL internal use only ***

    NiPoint3 m_kVelocity;
    NiPoint3 m_kRotationAxis;

    float m_fAge;
    float m_fLifeSpan;

    float m_fLastUpdate;

    unsigned short m_usGeneration;
    unsigned short m_usCode;
};

#endif // NIPARTICLEINFO_H
