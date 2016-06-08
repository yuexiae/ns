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

#ifndef NIOLDPARTICLECONVERTER_H
#define NIOLDPARTICLECONVERTER_H

#include "NiOldParticleConversionLibType.h"

#include <NiMain.h>
#include <NiAnimation.h>
#include <NiParticle.h>
#include <NiOldParticle.h>

class NIOLDPARTICLECONVERSION_ENTRY NiOldParticleConverter
{
public:
    static void Convert(NiStream& kStream, NiObject* pkObject);

protected:
    static void FindParticlesObjs(NiAVObject* pkObject,
        NiTSet<NiParticles*>& kParticlesObjs);
    static bool ConvertParticleSystem(NiParticles* pkOldParticles);
    static NiBoolKey* BuildActiveKeyArray(float fLoopStart, float fLoopEnd,
        float fActiveStart, float fActiveEnd, unsigned int& uiNumKeys);
    static NiPSysEmitter* AddEmitter(NiParticleSystem* pkNewParticleSystem,
        NiParticles* pkOldParticles,
        NiParticleSystemController* pkOldPSysCtlr);
    static void AddModifiers(NiParticleSystem* pkNewParticleSystem,
        NiParticles* pkOldParticles,
        NiParticleSystemController* pkOldPSysCtlr);
    static void AddColliders(NiParticleSystem* pkNewParticleSystem,
        NiParticles* pkOldParticles,
        NiParticleSystemController* pkOldPSysCtlr,
        NiPSysSpawnModifier* pkSpawnModifier);
    static void RecursiveSetAppCulled(NiAVObject* pkObject, bool bAppCulled);
};

#endif  // #ifndef NIOLDPARTICLECONVERTER_H
