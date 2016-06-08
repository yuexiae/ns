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

#ifndef NIPSYSDATA_H
#define NIPSYSDATA_H

#include "NiParticleLibType.h"
#include <NiParticlesData.h>
#include "NiParticleInfo.h"

class NIPARTICLE_ENTRY NiPSysData : public NiParticlesData
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    static const unsigned short INVALID_PARTICLE;

    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiPSysData(unsigned short usMaxNumParticles,
        NiPoint3* pkPositions, NiColorA* pkColors, NiQuaternion* pkRotations,
        NiParticleInfo* pkParticleInfo);
    virtual ~NiPSysData();

    NiParticleInfo* GetParticleInfo();
    void Replace(NiParticleInfo* pkParticleInfo);

    virtual void RemoveParticle(unsigned short usParticle);

    // AddParticle returns the index to the new particle.
    // ResolveAddedParticles must be called by the NiParticleSystem object
    // to actually add the particles to the particle array. Particles are
    // only added to the active particle count after all modifiers have been
    // updated.
    unsigned short AddParticle();
    virtual void ResolveAddedParticles();

    // Removes all particles and clears any new particles waiting to be added.
    void ClearAllParticles();

    unsigned short GetMaxNumParticles() const;
    unsigned short GetNumParticles() const;

    // *** begin NDL internal use only ***

    // For temporarily using data only. This call is like Replace(), 
    // but does not delete any pointers. Be careful to call this only 
    // on objects created by the default (empty) constructor to prevent 
    // memory leaks. These pointers will be owned (and deleted upon 
    // destruction) by this object so use this call carefully.
    void SetData(NiParticleInfo* pkParticleInfo);

    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysData();

    NiParticleInfo* m_pkParticleInfo;

    unsigned short m_usNumAddedParticles;
    unsigned short m_usAddedParticlesBase;
};

NiSmartPointer(NiPSysData);

#include "NiPSysData.inl"

#endif  // #ifndef NIPSYSDATA_H
