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

#ifndef NIPARTICLECOLORMODIFIER_H
#define NIPARTICLECOLORMODIFIER_H

#include "NiParticleModifier.h"
#include <NiColorData.h>

NiSmartPointer(NiParticleColorModifier);

class NIOLDPARTICLE_ENTRY NiParticleColorModifier : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleColorModifier);
    NiDeclareStream;
public:
    // construction
    NiParticleColorModifier();

    NiColorData* GetColorData() const;
    void SetColorData(NiColorData* pkColorData);

    void ResetKeyTimeExtrema(); // called automatically by SetColorData

    // *** begin NDL internal use only ***

    // Modify particle
    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    NiColorDataPtr m_spColorData;

    float m_fLoKeyTime;
    float m_fHiKeyTime;
};

#include "NiParticleColorModifier.inl"

#endif // NIPARTICLECOLORMODIFIER_H
