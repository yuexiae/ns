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

#ifndef NIGRAVITY_H
#define NIGRAVITY_H

#include "NiParticleModifier.h"
#include <NiPoint3.h>

class NIOLDPARTICLE_ENTRY NiGravity : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiGravity);
    NiDeclareStream;
public:
    // construction
    NiGravity();

    // attributes
    void SetDecay(float fDecay);
    float GetDecay() const;

    void SetStrength(float fStrength);
    float GetStrength() const;

    enum ForceType {FORCE_PLANAR, FORCE_SPHERICAL};

    void SetType(ForceType eType);
    ForceType GetType() const;

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
    float m_fStrength;  // specified in units/seconds^2
    ForceType m_eType;
    NiPoint3 m_kPosition;
    NiPoint3 m_kDirection;
};

NiSmartPointer(NiGravity);

#include "NiGravity.inl"

#endif // NIGRAVITY_H

