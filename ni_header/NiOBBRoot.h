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

#ifndef NIOBBROOT_H
#define NIOBBROOT_H

#include "NiCollisionGroup.h"
#include <NiMatrix3.h>
#include "NiPick.h"
#include <NiPoint3.h>

class NiNode;
class NiOBBNode;

class NICOLLISION_ENTRY NiOBBRoot
{
public:
    // construction and destruction
    NiOBBRoot (unsigned short usTriangles, const unsigned short* pTriList,
        const NiPoint3* pVertex, const NiPoint3* pWVertex, int iBinSize);
    virtual ~NiOBBRoot ();

    // attributes
    NiOBBNode* GetOBBTree ();
    void SetDeltaTime (float fDeltaTime);
    float GetDeltaTime () const;
    void SetVelocity (const NiPoint3& velocity);
    const NiPoint3& GetVelocity () const;

    // update bounding boxes of obb tree
    void Transform (const NiTransform& xform);

    // collisions
    virtual bool TestCollision (NiOBBRoot* pTestRoot, NiAVObject* pThisObj,
        NiAVObject* pOtherObj, int iMaxDepth, int iTestMaxDepth);

    virtual int FindCollisions (NiOBBRoot* pTestRoot, NiAVObject* pThisRoot,
        NiAVObject* pOtherRoot, NiAVObject* pThisObj, NiAVObject* pOtherObj,
        int iMaxDepth, int iTestMaxDepth, bool& bCollision);

    void SetChangeStamp (unsigned int uiChangeStamp);
    unsigned int GetChangeStamp () const;

    virtual int FindIntersections (const NiPoint3& origin, 
        const NiPoint3& dir, NiPick& pick, bool& bIntersects,
        NiAVObject* pObj, unsigned int uiChangeStamp);

protected:
    float m_fDeltaTime;
    NiOBBNode* m_pTree;
    bool m_bTransformChanged;

    // world quantities
    NiPoint3 m_velocity;
    NiTransform m_xform;

    unsigned int m_uiChangeStamp;
};

#include "NiOBBRoot.inl"

#endif

