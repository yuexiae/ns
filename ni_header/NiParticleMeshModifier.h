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

#ifndef NIPARTICLEMESHMODIFIER_H
#define NIPARTICLEMESHMODIFIER_H

#include "NiParticleModifier.h"
#include <NiAVObject.h>

class NIOLDPARTICLE_ENTRY NiParticleMeshModifier : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleMeshModifier);
    NiDeclareStream;
public:
    // construction
    NiParticleMeshModifier();
    ~NiParticleMeshModifier();

    NiAVObjectPtr SetMeshAt(unsigned int uiIndex, NiAVObject* pkMesh);
    NiAVObject* GetMeshAt(unsigned int uiIndex) const;

    // *** begin NDL internal use only ***
    // Cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);

    // Modify particle
    virtual void Initialize(NiPerParticleData* pkCurrentParticle);

    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    NiTArray<NiAVObjectPtr> m_kMeshes;
};

NiSmartPointer(NiParticleMeshModifier);

#include "NiParticleMeshModifier.inl"

#endif // NIPARTICLEMESHMODIFIER_H
