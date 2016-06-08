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

#ifndef NICOLLISIONGROUP_H
#define NICOLLISIONGROUP_H

#include "NiCollisionLibType.h"
#include <NiPoint3.h>
#include <NiTArray.h>

class NiAVObject;

class NICOLLISION_ENTRY NiCollisionGroup
{
public:
    // construction and destruction
    NiCollisionGroup();
    ~NiCollisionGroup();

    // for application to add/remove objects
    void AddCollider(NiAVObject* pkObject, 
        bool bCreateCollisionData = true, int iMaxDepth = -1,
        int iBinSize = 1);
    void AddCollidee(NiAVObject* pkObject,
        bool bCreateCollisionData = true, int iMaxDepth = -1,
        int iBinSize = 1);
    void RemoveCollider(NiAVObject* pkObject);
    void RemoveCollidee(NiAVObject* pkObject);
    void Remove(NiAVObject* pkObject);
    void RemoveAll();

    // collisions
    void UpdateWorldData();
    bool TestCollisions(float fDeltaTime);
    void FindCollisions(float fDeltaTime);

    // return values for FindCollisions
    enum {CONTINUE_COLLISIONS, TERMINATE_COLLISIONS, BREAKOUT_COLLISIONS};

    // information about the intersection of two bounding boxes or triangles
    class NICOLLISION_ENTRY Intersect
    {
    public:
        NiAVObject* pkRoot0;
        NiAVObject* pkRoot1;
        NiAVObject* pkObj0;
        NiAVObject* pkObj1;
        float fTime;
        NiPoint3 kPoint;
        NiPoint3 kNormal0;
        NiPoint3 kNormal1;

        // Values for appkTri1 & appkTri2 are not valid outside of callback.
        const NiPoint3** appkTri1;
        const NiPoint3** appkTri2;

        Intersect() { appkTri1 = NULL; appkTri2 = NULL; }
        Intersect(NiAVObject* a, NiAVObject* b, NiAVObject* c, NiAVObject* d)
        {
            pkRoot0 = a; pkRoot1 = b, pkObj0 = c, pkObj1 = d;
            appkTri1 = NULL; appkTri2 = NULL;
        }
    };

    // callback prototype that application must use for collision handling
    typedef int (*Callback)(Intersect&);

    // *** begin NDL internal use only ***

    class NICOLLISION_ENTRY Record
    {
    public:
        bool m_bLocked;

        enum IntersectCacheMode {NO_INTERSECT = 0, INTERSECT, NEED_TEST }; 
        IntersectCacheMode m_eIntersectCache;

        Record(NiAVObject* pkRoot, NiAVObject* pkObject, int iMaxDepth,
            int iBinSize)
        {
            m_pkRoot = pkRoot;
            m_pkObject = pkObject;
            m_iMaxDepth = iMaxDepth;
            m_iBinSize = iBinSize;
            m_bLocked = false;
            m_eIntersectCache = NEED_TEST;
        }

        NiAVObject* GetRoot() { return m_pkRoot; }
        void SetAVObject(NiAVObject* pkObject) { m_pkObject = pkObject; }
        NiAVObject* GetAVObject() { return m_pkObject; }
        int GetMaxDepth() { return m_iMaxDepth; }
        int GetBinSize() { return m_iBinSize; }

    protected:
        NiAVObject* m_pkRoot;
        NiAVObject* m_pkObject;
        int m_iMaxDepth;
        int m_iBinSize;
    };

    // *** end NDL internal use only ***

protected:
    // add colliders or collidees
    void Add(NiAVObject* pkObject, NiTArray<Record*>& kBin, 
        bool bCreateCollisionData, int iMaxDepth, int iBinSize);
    NiTArray<Record*> m_kColliders;
    NiTArray<Record*> m_kCollidees;
};

#endif

