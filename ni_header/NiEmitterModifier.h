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

#ifndef NIEMITTERMODIFIER_H
#define NIEMITTERMODIFIER_H

#include "NiOldParticleLibType.h"
#include <NiObject.h>
#include "NiPerParticleData.h"
class NiPoint3;
class NiMatrix3;
class NiParticleSystemController;

NiSmartPointer(NiEmitterModifier);

class NIOLDPARTICLE_ENTRY NiEmitterModifier : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiEmitterModifier);
    NiDeclareAbstractStream;
public:
    // construction
    NiEmitterModifier ();
    ~NiEmitterModifier ();

    NiParticleSystemController* GetTarget() const;
    void SetTarget(NiParticleSystemController* pkTarget);

    // *** begin NDL internal use only ***

    virtual void AddToTarget(NiParticleSystemController* pkTarget);
    virtual void RemoveFromTarget(NiParticleSystemController* pkTarget);

    // link manipulation
    void SetNext (NiEmitterModifier* pkNext);
    NiEmitterModifier* GetNext ();
    
    unsigned int GetListSize ();
    
    // Modify Emitter
    virtual bool Update(float fTime) = 0;

    // cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);
    
    // *** end NDL internal use only ***

protected:
    NiEmitterModifierPtr m_spNext;

    NiParticleSystemController* m_pkTarget;
};

#include "NiEmitterModifier.inl"

#endif // NIEMITTERMODIFIER_H
