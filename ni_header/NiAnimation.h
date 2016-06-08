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

#ifndef NIANIMATION_H
#define NIANIMATION_H

// DLL support
#include "NiAnimationLibType.h"

#include "NiActorManager.h"
#include "NiAlphaController.h"
#include "NiAnimationKey.h"
#include "NiAnimationKeyMacros.h"
#include "NiBezFloatKey.h"
#include "NiBezPosKey.h"
#include "NiBezRotKey.h"
#include "NiBlendAccumTransformInterpolator.h"
#include "NiBlendBoolInterpolator.h"
#include "NiBlendColorInterpolator.h"
#include "NiBlendFloatInterpolator.h"
#include "NiBlendInterpolator.h"
#include "NiBlendPoint3Interpolator.h"
#include "NiBlendQuaternionInterpolator.h"
#include "NiBlendTransformInterpolator.h"
#include "NiBoneLODController.h"
#include "NiBoolData.h"
#include "NiBoolInterpController.h"
#include "NiBoolInterpolator.h"
#include "NiBoolKey.h"
#include "NiBoolTimelineInterpolator.h"
#include "NiColorData.h"
#include "NiColorExtraDataController.h"
#include "NiColorInterpController.h"
#include "NiColorInterpolator.h"
#include "NiColorKey.h"
#include "NiControllerManager.h"
#include "NiControllerSequence.h"
#include "NiEulerRotKey.h"
#include "NiExtraDataController.h"
#include "NiFlipController.h"
#include "NiFloatController.h"
#include "NiFloatData.h"
#include "NiFloatExtraDataController.h"
#include "NiFloatInterpController.h"
#include "NiFloatInterpolator.h"
#include "NiFloatKey.h"
#include "NiFloatsExtraDataController.h"
#include "NiGeomMorpherController.h"
#include "NiInterpController.h"
#include "NiInterpolator.h"
#include "NiInterpScalar.h"
#include "NiKeyBasedInterpolator.h"
#include "NiKeyframeManager.h"
#include "NiKFMTool.h"
#include "NiLightColorController.h"
#include "NiLinColorKey.h"
#include "NiLinFloatKey.h"
#include "NiLinPosKey.h"
#include "NiLinRotKey.h"
#include "NiLookAtController.h"
#include "NiLookAtInterpolator.h"
#include "NiMaterialColorController.h"
#include "NiMorphData.h"
#include "NiMultiTargetTransformController.h"
#include "NiPathController.h"
#include "NiPathInterpolator.h"
#include "NiPoint3InterpController.h"
#include "NiPoint3Interpolator.h"
#include "NiPosData.h"
#include "NiPosKey.h"
#include "NiQuaternionInterpController.h"
#include "NiQuaternionInterpolator.h"
#include "NiQuatTransform.h"
#include "NiRollController.h"
#include "NiRotData.h"
#include "NiRotKey.h"
#include "NiSequence.h"
#include "NiSequenceStreamHelper.h"
#include "NiSingleInterpController.h"
#include "NiSpline.h"
#include "NiStepBoolKey.h"
#include "NiStepColorKey.h"
#include "NiStepFloatKey.h"
#include "NiStepPosKey.h"
#include "NiStepRotKey.h"
#include "NiStringPalette.h"
#include "NiTCBFloatKey.h"
#include "NiTCBPosKey.h"
#include "NiTCBRotKey.h"
#include "NiTextKey.h"
#include "NiTextKeyExtraData.h"
#include "NiTextureTransformController.h"
#include "NiTransformController.h"
#include "NiTransformData.h"
#include "NiTransformInterpolator.h"
#include "NiUVController.h"
#include "NiUVData.h"
#include "NiVisController.h"

#include "NiOldAnimationConverter.h"

#include "NiAnimationSDM.h"
static NiAnimationSDM NiAnimationSDMObject;

#endif  // #ifndef NIANIMATION_H
