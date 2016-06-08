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

#ifndef NIPARTICLEBOMB_H
#define NIPARTICLEBOMB_H

#include "NiParticleModifier.h"
#include <NiPoint3.h>

class NIOLDPARTICLE_ENTRY NiParticleBomb : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleBomb);
    NiDeclareStream;
public:
    // construction
    NiParticleBomb();

    // attributes
    void SetDecay(float fDecay);
    float GetDecay() const;

    void SetDeltaV(float fDeltaV);
    float GetDeltaV() const;

    void SetDuration(float fDuration);
    float GetDuration() const;

    void SetStart(float fStart);
    float GetStart() const;

    enum DecayType {NONE, LINEAR, EXPONENTIAL};
    void SetDecayType(DecayType eDecayType);
    DecayType GetDecayType() const;

    enum SymmType {SPHERICAL, CYLINDRICAL, PLANAR};
    void SetSymmetry(SymmType eSymmType);
    SymmType GetSymmetry() const;

    void SetPos(const NiPoint3& kPos);
    const NiPoint3& GetPos() const;

    void SetDir(const NiPoint3& kDir);
    const NiPoint3& GetDir() const;

    // *** begin NDL internal use only ***

    // apply force
    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***
    
protected:
    float m_fDecay;
    float m_fDuration;
    float m_fDeltaV;  // specified in units/seconds^2
    float m_fStart;
    DecayType m_eDecayType;
    SymmType m_eSymmType;
    NiPoint3 m_kPosition;
    NiPoint3 m_kDirection;
};

NiSmartPointer(NiParticleBomb);

#include "NiParticleBomb.inl"

#endif // NIPARTICLEBOMB_H
