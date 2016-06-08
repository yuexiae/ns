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

#ifndef NI_COLLISION_H
#define NI_COLLISION_H

#include "NiCollisionLibType.h"

#include "NiBox.h"
#include "NiBoxBV.h"
#include "NiBoxBVMacros.h"
#include "NiCapsule.h"
#include "NiCapsuleBV.h"
#include "NiCollisionData.h"
#include "NiCollisionGroup.h"
#include "NiCollisionTraversals.h"
#include "NiCollisionSDM.h"
#include "NiCollisionUtils.h"
#include "NiDrawableBV.h"
#include "NiHalfSpaceBV.h"
#include "NiMinimize.h"
#include "NiOBBLeaf.h"
#include "NiOBBNode.h"
#include "NiOBBox.h"
#include "NiOBBRoot.h"
#include "NiParallelepiped.h"
#include "NiParallelogram.h"
#include "NiPick.h"
#include "NiSegment.h"
#include "NiSphere.h"
#include "NiSphereBV.h"
#include "NiSqrDistance.h"
#include "NiTrigon.h"
#include "NiTriIntersect.h"
#include "NiUnionBV.h"

static NiCollisionSDM NiCollisionSDMObject;

class NICOLLISION_ENTRY NiCollisionConvert
{
public:
    static NiBoundingVolume* ConvertToSphereBV(float fRadius,
        const NiPoint3& kCenter);

    static NiBoundingVolume* ConvertToBoxBV(unsigned short usQuantity,
        const NiPoint3* pkVertex);

protected:
    // A static instance of sphereBV used during NiMain's collision testing
    // when converting an NiBound to an NiSphereBV.  Eliminates overhead of
    // memory allocation.
    static NiSphereBV ms_kSphereABV;
};

#endif

