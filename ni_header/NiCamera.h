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

#ifndef NICAMERA_H
#define NICAMERA_H

#include "NiAccumulator.h"
#include "NiAVObject.h"
#include "NiRenderer.h"
#include "NiNode.h"
#include "NiPlane.h"
#include "NiScreenGeometry.h"
#include "NiScreenPolygon.h"
#include "NiScreenTexture.h"
#include "NiFrustum.h"

NiSmartPointer(NiScreenGeometryAccumulator);

class NiPoint2;

class NIMAIN_ENTRY NiCamera : public NiAVObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiCamera);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:

    // the following two enums _must_ match 
    // (i.e. 2^(*_PLANE) = *_PLANE_FLAG)
    enum
    {
        NEAR_PLANE      = 0,
        FAR_PLANE       = 1,
        LEFT_PLANE      = 2,
        RIGHT_PLANE     = 3,
        TOP_PLANE       = 4,
        BOTTOM_PLANE    = 5,
        MAX_PLANES      = 6
    };

    enum
    {
        NEAR_PLANE_FLAG     = 0x00000001,
        FAR_PLANE_FLAG      = 0x00000002,
        LEFT_PLANE_FLAG     = 0x00000004,
        RIGHT_PLANE_FLAG    = 0x00000008,
        TOP_PLANE_FLAG      = 0x00000010,
        BOTTOM_PLANE_FLAG   = 0x00000020,
        ALL_PLANES_FLAG     = 0x0000003f,
        PLANE_FLAG_DWORD    = 0x7fffffff
    };

    typedef NiFrustum Frustum;

    // construction and destruction
    NiCamera();
    virtual ~NiCamera();

    // camera model coordinates:
    //   kOrigin    = (0,0,0)
    //   direction = (1,0,0)
    //   up        = (0,1,0)
    //   right     = (0,0,1)

    // camera world information
    const NiPoint3& GetWorldLocation() const;
    const NiPoint3& GetWorldDirection() const;
    const NiPoint3& GetWorldUpVector() const;
    const NiPoint3& GetWorldRightVector() const;

    void SetViewFrustum(const NiFrustum& kFrustum);
    const NiFrustum& GetViewFrustum() const;
    void SetViewPort(const NiRect<float>& kPort);
    const NiRect<float>& GetViewPort() const;

    bool FitNearAndFarToBound(const NiBound& kBound);

    bool LookAtWorldPoint(const NiPoint3& kWorldPt, 
        const NiPoint3& kWorldUp);

    static void  SetMinNearPlaneDist(const float fMin);
    static float GetMinNearPlaneDist();
    static void  SetMaxFarNearRatio(const float fMax);
    static float GetMaxFarNearRatio();

    // scene graph, display, camera video click
    void SetScene(NiNode* pkScene);
    NiNode* GetScene() const;
    void SetRenderer(NiRenderer* pkRenderer);
    NiRenderer* GetRenderer() const;
    void Clear(unsigned int uiFlags);
    void SwapBuffers();
    virtual void Click();

    // sorted drawing
    void ScreenSpaceBoundBound(const NiBound& kSBound, NiPoint3& kMinBound,
        NiPoint3& kMaxBound) const;
    void ScreenSpaceBoundSize(const NiBound& kSBound, NiPoint2& kBoundSize)
        const;

    // LOD adjustment for NiLODNode
    void SetLODAdjust(float fLODAdjust);
    float GetLODAdjust() const;

    // picking support
    bool WorldPtToScreenPt(const NiPoint3& kPt, float &fBx, float &fBy) const;
    bool WindowPointToRay(long lWx, long lWy, NiPoint3& kOrigin,
        NiPoint3& kDir) const;

    // Support for screen space measurements.  The returned value points
    // to the 4x4 matrix stored in row-major order.
    const float* GetWorldToCameraMatrix() const;

    void AttachScreenPoly(NiScreenPolygon* pkPoly);
    void DetachScreenPoly(NiScreenPolygon* pkPoly);
    NiScreenPolygonArray& GetScreenPolyArray();
    void DrawScreenPolys();

    void AttachScreenTexture(NiScreenTexture* pkTexture);
    void DetachScreenTexture(NiScreenTexture* pkTexture);
    NiScreenTextureArray& GetScreenTextureArray();
    void DrawScreenTextures();

    // *** begin NDL internal use only ***

    // clipping planes
    void SetActiveCullingPlaneFlags(unsigned int uiActive);
    int GetActiveCullingPlaneFlags() const;
    void DeactivatePlane(unsigned int uiPlane);
    void ActivatePlane(unsigned int uiPlane);
    bool PlaneIsActive(unsigned int uiPlane) const;

    // culling planes
    NiPlane* GetCullingPlanes();

    void SetCullingPlanes(NiFrustum& kFrustum);
    
    void SetOrthoLeftCullingPlane(float fLeft);
    void SetOrthoRightCullingPlane(float fRight);
    void SetOrthoTopCullingPlane(float fTop);
    void SetOrthoBottomCullingPlane(float fBottom);

    void SetNearCullingPlane(float fNear);
    void SetFarCullingPlane(float fFar);
    void SetLeftCullingPlane(float fLeft);
    void SetRightCullingPlane(float fRight);
    void SetTopCullingPlane(float fTop);
    void SetBottomCullingPlane(float fBottom);

    // picking support (called by WindowPointToRay)
    bool MapBufferPointToViewPoint(float fBx, float fBy, float& fVx,
        float& fVy) const;
    bool ViewPointToRay(float fVx,float fVy, NiPoint3& kOrigin,
        NiPoint3& kDir) const;

    // renderer data
    virtual void PurgeRendererData(NiRenderer* pkRenderer);

    // cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // remapping to guarantee view plane is the near plane
    void MapViewPlaneToNearPlane(NiFrustum& kFrustum, NiPoint3& kWorldVRP) 
        const;

    // instancing
    virtual void UpdateWorldData();
    virtual void UpdateWorldBound();

    // when near/far plane values change, or screen polys are attached, 
    // must mark them as changed:
    void MarkScreenPolysAsChanged();

    // world-to-camera matrix
    float m_aafWorldToCam[4][4];
    float m_fViewDist;
    float m_fTwoDivRmL;  // = 2/(right-left)
    float m_fTwoDivTmB;  // = 2/(top-bottom)
    void WorldToCameraMatrix();

    // camera world direction, up, right
    NiPoint3 m_kWorldDir;
    NiPoint3 m_kWorldUp;
    NiPoint3 m_kWorldRight;

    // view frustum
    NiFrustum m_kViewFrustum;
    static float ms_fMinNearPlaneDist;
    static float ms_fMaxFarNearRatio;

    // view port
    NiRect<float> m_kPort;

    // scene graph of camera
    NiNodePtr m_spScene;
     
    // screen-space objects of camera
    NiScreenPolygonArray m_kScreenPolygons;
    NiScreenTextureArray m_kScreenTextures;

    // display of camera
    NiRendererPtr m_spRenderer;

    // culling planes
    NiPlane m_akCullingPlanes[MAX_PLANES];
    unsigned int m_uiActivePlaneFlags;

    static const float ms_fProjEps;

    // LOD adjustment for NiLODNode
    float m_fLODAdjust;

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 9
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        VP_RIGHT_NEEDS_UPDATE_MASK  = 0x0001
    };

    void SetVpRightNeedsUpdate(bool bUpdate);
    bool GetVpRightNeedsUpdate() const;
};

typedef NiPointer<NiCamera> NiCameraPtr;

#include "NiCamera.inl"

#endif
