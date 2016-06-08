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

#ifndef NIDRAWABLEBV_H
#define NIDRAWABLEBV_H

#include "NiCollisionLibType.h"
#include "NiAVObject.h"
#include "NiColor.h"
class NiBoundingVolume;
class NiBox;
class NiCapsule;
class NiHalfSpaceBV;
class NiNode;
class NiSphere;
class NiUnionBV;
class NiTriShape;

class NICOLLISION_ENTRY NiDrawableBV
{
    // cloning: no cloning necessary, as this creates a NiTriShape and 
    // attaches it to the scene graph as a regular node, which will have its
    // own cloning functionality
public:
    // for creation of wireframe representation of the bounding volume
    static NiNode* CreateWireframeBV(const NiBoundingVolume* pkBound,
        const NiColor& kColor = NiColor::BLACK, const float fMult = 1.0f, 
        NiAVObject* pkObject = 0);


    // *** begin NDL internal use only ***

    // the following do not attach any properties
    static NiTriShape* CreateFromBox(const NiBox& kBox, 
        const float fMult);
    static NiTriShape* CreateFromCapsule(const NiCapsule& kCapsule,
        const float fMult);
    static NiTriShape* CreateFromSphere(const NiSphere& kSphere,
        const float fMult);
    static NiTriShape* CreateFromHalfSpaceBV(const NiHalfSpaceBV* pkBound, 
        const float fMult, const NiAVObject* pkObject);
    static void CreateFromUnion(const NiUnionBV* pkUnion, NiNode* pkParent,
        const float fMult);

    static NiTriShape* CreateTubeFromCapsule(const NiCapsule& kCapsule,
        const float fMult, const unsigned int uiNumSides);

    // *** end NDL internal use only ***
};

#endif
