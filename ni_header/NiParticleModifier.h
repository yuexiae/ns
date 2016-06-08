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

#ifndef NIPARTICLEMODIFIER_H
#define NIPARTICLEMODIFIER_H

#include "NiOldParticleLibType.h"
#include <NiObject.h>
#include "NiPerParticleData.h"
class NiPoint3;
class NiMatrix3;
class NiParticleSystemController;

NiSmartPointer(NiParticleModifier);

class NIOLDPARTICLE_ENTRY NiParticleModifier : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiParticleModifier);
    NiDeclareAbstractStream;
public:
    // construction
    NiParticleModifier();
    ~NiParticleModifier();

    NiParticleSystemController* GetTarget() const;
    void SetTarget(NiParticleSystemController* pkTarget);

    // *** begin NDL internal use only ***

    virtual void AddToTarget(NiParticleSystemController* pkTarget);
    virtual void RemoveFromTarget(NiParticleSystemController* pkTarget);

    // link manipulation
    void SetNext(NiParticleModifier* pkNext);
    NiParticleModifier* GetNext();
    
    unsigned int GetListSize();
    
    // Modify particle
    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    virtual void Initialize(NiPerParticleData* pkCurrentParticle);

    // cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);
    
    // *** end NDL internal use only ***

protected:
    NiParticleModifierPtr m_spNext;

    NiParticleSystemController* m_pkTarget;
};

#include "NiParticleModifier.inl"

#endif // NIPARTICLEMODIFIER_H
