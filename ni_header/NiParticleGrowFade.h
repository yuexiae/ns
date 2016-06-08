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

#ifndef NIPARTICLEGROWFADE_H
#define NIPARTICLEGROWFADE_H

#include "NiParticleModifier.h"

NiSmartPointer(NiParticleGrowFade);

class NIOLDPARTICLE_ENTRY NiParticleGrowFade : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleGrowFade);
    NiDeclareStream;
public:
    // construction
    NiParticleGrowFade();

    float GetGrowFor() const;
    void SetGrowFor(float fGrowTime);

    float GetFadeFor() const;
    void SetFadeFor(float fFadeTime);

    // *** begin NDL internal use only ***

    // Modify particle
    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    float m_fGrowFor;
    float m_fFadeFor;
};

#include "NiParticleGrowFade.inl"

#endif // NIPARTICLEGROWFADE_H
