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

#ifndef NIPARTICLEROTATION_H
#define NIPARTICLEROTATION_H

#include "NiParticleModifier.h"
#include <NiPoint3.h>

NiSmartPointer(NiParticleRotation);

class NIOLDPARTICLE_ENTRY NiParticleRotation : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleRotation);
    NiDeclareStream;
public:
    // construction
    NiParticleRotation();

    bool GetRandomInitialAxis() const;
    void SetRandomInitialAxis(bool bRandom);

    NiPoint3 GetInitialAxis() const;
    void SetInitialAxis(NiPoint3 kAxis);

    float GetRotationSpeed() const;
    void SetRotationSpeed(float fSpeed);

    // *** begin NDL internal use only ***

    // Modify particle
    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    virtual void Initialize(NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    bool m_bRandomInitialAxis;
    NiPoint3 m_kInitialAxis;
    float m_fRotationSpeed;
};

#include "NiParticleRotation.inl"

#endif // NIPARTICLEROTATION_H
