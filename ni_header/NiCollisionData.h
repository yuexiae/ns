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

#ifndef NICOLLISIONDATA_H
#define NICOLLISIONDATA_H

#include <NiCollisionObject.h> 
#include "NiCollisionLibType.h"
#include "NiCollisionGroup.h"
#include <NiPoint3.h>
#include <NiNode.h>

class NiBoundingVolume;
class NiOBBRoot;
class NiPick;

#define NiGetCollisionData(pkNode) \
    ((NiCollisionData*)(pkNode->GetCollisionObject()))

class NICOLLISION_ENTRY NiCollisionData : public NiCollisionObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiCollisionData);
    NiDeclareStream;
    NiDeclareViewerStrings;


public:
    NiCollisionData(NiAVObject* pkSceneObject);
    virtual ~NiCollisionData();

    virtual void SetSceneGraphObject(NiAVObject* pkSceneObject);

    // World geometry access
    // - vertices
    void CreateWorldVertices();
    void UpdateWorldVertices();
    void DestroyWorldVertices();
    const NiPoint3* GetWorldVertices() const;

    unsigned short GetTriangleCount();

    void MarkVerticesAsChanged();

    // - normals
    void CreateWorldNormals();
    void UpdateWorldNormals();
    void DestroyWorldNormals();
    const NiPoint3* GetWorldNormals() const;

    void MarkNormalsAsChanged();

    // Velocity access
    void SetLocalVelocity(const NiPoint3& kLocalVelocity);
    const NiPoint3& GetLocalVelocity() const;

    void SetWorldVelocity(const NiPoint3& kWorldVelocity);
    const NiPoint3& GetWorldVelocity() const;
    
    // Enable and disable world velocity computation
    static void SetEnableVelocity(bool bEnable);
    static bool GetEnableVelocity();
    enum PropagationMode
    {
        // A change here will effect the GetCollisionTestType fn.
        PROPAGATE_ON_SUCCESS,
        PROPAGATE_ON_FAILURE,
        PROPAGATE_ALWAYS,
        PROPAGATE_NEVER,
        PROPAGATIONMODE_POS
    };

    enum CollisionMode
    {
        // A change here will effect the GetCollisionTestType fn.
        USE_OBB,
        USE_TRI,
        USE_ABV,
        NOTEST,
        USE_NIBOUND,
        COLLISIONMODE_POS
    };

    enum CollisionTest
    {
        // A change here will effect the GetCollisionTestType fn.
        OBB_OBB,
        OBB_TRI,
        OBB_ABV,
        OBB_NIBOUND,
        TRI_TRI,
        TRI_ABV,
        TRI_NIBOUND,
        ABV_ABV,
        ABV_NIBOUND,
        NIBOUND_NIBOUND,
        NOTEST_NOTEST
    };
    // Propagation control

    void SetPropagationMode(PropagationMode ePropagation);
    PropagationMode GetPropagationMode() const;

    void SetCollisionMode(CollisionMode eCollision);
    CollisionMode GetCollisionMode() const;
    virtual void Initialize(void *pkData); 
    virtual void Convert(unsigned int uiVersion, void *pkData=NULL);

    void SetEnableAuxCallbacks(bool bEnable);
    bool GetEnableAuxCallbacks();

    // Alternate Bounding Volume (ABV) Access
    //
    // The NiCollisionData object assumes ownership of the input 
    // bounding volume.  The application must therefore pass in 
    // dynamically allocated bounding volumes.  These should not 
    // be deleted by the application.
    void SetModelSpaceABV(NiBoundingVolume* pkABV);

    NiBoundingVolume* GetModelSpaceABV() const;
    NiBoundingVolume* GetWorldSpaceABV() const;

    // Collision Callback function and data access
    void SetCollideCallback(NiCollisionGroup::Callback pfnCollideCallback);
    NiCollisionGroup::Callback GetCollideCallback();
    void SetCollideCallbackData(void* pvCollideCallbackData);
    void* GetCollideCallbackData();

    // *** begin NDL internal use only ***
    virtual void AddViewerStrings(NiTArray<char*>* pkStrings);

    int FindCollisionProcessing(NiCollisionGroup::Intersect& kIntr,
        PropagationMode ePropagationMode1,PropagationMode ePropagationMode2);
    int TestCollisionProcessing(PropagationMode ePropagationMode1,
        PropagationMode ePropagationMode2);


    virtual void UpdateWorldData();
    virtual void RecreateWorldData();

    void CreateOBB(int iBinSize = 1);
    void DestroyOBB();

    bool TestOBBCollisions(float fDeltaTime, NiCollisionData* pkTestData,
        NiAVObject* pThisObject, NiAVObject* pOtherObj, int iMaxDepth,
        int iTestMaxDepth);

    int FindOBBCollisions(float fDeltaTime, NiCollisionData* pTestData, 
        NiAVObject* pThisRoot, NiAVObject* pOtherRoot, NiAVObject* 
        pThisObj, NiAVObject* pOtherObj, int iMaxDepth, int iTestMaxDepth,
        bool& bCollision);

    bool GetWorldTriangle(unsigned short usTriangle,
        NiPoint3*& pkP0, NiPoint3*& pkP1, NiPoint3*& pkP2);
    static CollisionTest GetCollisionTestType(
        NiAVObject* pkObj1, NiAVObject* pkObj2); 

    // *** end NDL internal use only ***

protected:
    // To prevent public access to a constructor with no scene association
    NiCollisionData();

    NiNode* FindAncestorWithCollisionData(NiAVObject* pkObj);

    char* GetViewerString(const char* pcPrefix, PropagationMode eMode);
    char* GetViewerString(const char* pcPrefix, CollisionMode eMode);

    NiPoint3 m_kLocalVelocity;
    NiPoint3 m_kWorldVelocity;

    PropagationMode m_ePropagationMode;
    CollisionMode m_eCollisionMode;

    NiBoundingVolume* m_pkModelABV;
    NiBoundingVolume* m_pkWorldABV;

    NiOBBRoot* m_pkOBBRoot;

    NiCollisionGroup::Callback m_pfnCollideCallback;
    void* m_pvCollideCallbackData;

    // world geometry data
    NiPoint3* m_pkWorldVertex;
    NiPoint3* m_pkWorldNormal;
    bool m_bWorldVerticesNeedUpdate;
    bool m_bWorldNormalsNeedUpdate;
    unsigned short m_usNumVertices;
    unsigned short m_usNumTriangles;
    bool m_bAuxCallbacks;

    static bool ms_bComputeWorldVelocity;

    static void SetPrecacheAttributes(NiAVObject* pkObj, CollisionMode eMode);
};

#include "NiCollisionData.inl"

#endif

