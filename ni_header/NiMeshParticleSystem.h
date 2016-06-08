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

#ifndef NIMESHPARTICLESYSTEM_H
#define NIMESHPARTICLESYSTEM_H

#include "NiParticleSystem.h"
#include <NiNode.h>
#include "NiMeshPSysData.h"


class NIPARTICLE_ENTRY NiMeshParticleSystem : public NiParticleSystem
{
    NiDeclareRTTI;
    NiDeclareClone(NiMeshParticleSystem);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiMeshParticleSystem(unsigned short usMaxNumParticles,
        NiPoint3* pkPositions, NiColorA* pkColors, NiQuaternion* pkRotations,
        NiParticleInfo* pkParticleInfo, bool bWorldSpace = true, 
        unsigned int uiPoolSize = NiMeshPSysData::DEFAULT_POOL_SIZE,
        unsigned int uiNumGenerations = 1, bool bFillPoolsOnLoad = false);

    NiMeshParticleSystem(NiMeshPSysData* pkData, bool bWorldSpace = true);

    virtual void SetModelData(NiGeometryData* pkModelData);

    // *** begin NDL internal use only ***

    virtual void UpdateDownwardPass(float fTime, bool bUpdateControllers);
    virtual void UpdateSelectedDownwardPass(float fTime);
    virtual void UpdateRigidDownwardPass(float fTime);
    virtual void UpdatePropertiesDownward(NiPropertyState* pkParentState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);

    virtual void Display(NiCamera* pkCamera);

    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, 
        bool bSelectiveUpdateTransforms, bool& bRigid);

    // renderer data
    virtual void PurgeRendererData(NiRenderer* pkRenderer);

    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiMeshParticleSystem();

    virtual void UpdateWorldData();
    virtual void UpdateWorldBound();

    void UpdateMeshes(NiMeshPSysData* pkMeshData);

    float m_fTime;
    bool m_bUpdateControllers;
};

NiSmartPointer(NiMeshParticleSystem);

#endif  // #ifndef NIMESHPARTICLESYSTEM_H
