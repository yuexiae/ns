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

#ifndef NIPARTICLE_H
#define NIPARTICLE_H

// DLL support
#include "NiParticleLibType.h"

#include "NiMeshParticleSystem.h"
#include "NiMeshPSysData.h"
#include "NiParticleInfo.h"
#include "NiParticleSystem.h"
#include "NiPSysAirFieldAirFrictionCtlr.h"
#include "NiPSysAirFieldInheritVelocityCtlr.h"
#include "NiPSysAirFieldModifier.h"
#include "NiPSysAirFieldSpreadCtlr.h"
#include "NiPSysAgeDeathModifier.h"
#include "NiPSysBombModifier.h"
#include "NiPSysBoxEmitter.h"
#include "NiPSysBoundUpdateModifier.h"
#include "NiPSysCollider.h"
#include "NiPSysColliderManager.h"
#include "NiPSysColorModifier.h"
#include "NiPSysCylinderEmitter.h"
#include "NiPSysData.h"
#include "NiPSysDragModifier.h"
#include "NiPSysDragFieldModifier.h"
#include "NiPSysEmitter.h"
#include "NiPSysEmitterCtlr.h"
#include "NiPSysEmitterCtlrData.h"
#include "NiPSysEmitterDeclinationCtlr.h"
#include "NiPSysEmitterInitialRadiusCtlr.h"
#include "NiPSysEmitterLifeSpanCtlr.h"
#include "NiPSysEmitterPlanarAngleCtlr.h"  
#include "NiPSysEmitterSpeedCtlr.h"
#include "NiPSysFieldAttenuationCtlr.h"
#include "NiPSysFieldMagnitudeCtlr.h"
#include "NiPSysFieldMaxDistanceCtlr.h"
#include "NiPSysGravityFieldModifier.h"
#include "NiPSysGravityModifier.h"
#include "NiPSysGravityStrengthCtlr.h"
#include "NiPSysGrowFadeModifier.h"
#include "NiPSysMeshEmitter.h"
#include "NiPSysMeshUpdateModifier.h"
#include "NiPSysModifier.h"
#include "NiPSysModifierActiveCtlr.h"
#include "NiPSysModifierCtlr.h"
#include "NiPSysModifierFloatCtlr.h"
#include "NiPSysPlanarCollider.h"
#include "NiPSysPositionModifier.h"
#include "NiPSysRadialFieldModifier.h"
#include "NiPSysResetOnLoopCtlr.h"
#include "NiPSysRotationModifier.h"
#include "NiPSysSpawnModifier.h"
#include "NiPSysSphereEmitter.h"
#include "NiPSysSphericalCollider.h"
#include "NiPSysTurbulenceFieldModifier.h"
#include "NiPSysUpdateCtlr.h"
#include "NiPSysVolumeEmitter.h"
#include "NiPSysVortexFieldModifier.h"

#include "NiParticleSDM.h"
static NiParticleSDM NiParticleSDMObject;

#endif  // #ifndef NIPARTICLE_H
