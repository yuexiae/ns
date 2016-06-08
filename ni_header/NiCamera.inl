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
//---------------------------------------------------------------------------
//  NiCamera inline functions

//---------------------------------------------------------------------------
inline const NiPoint3& NiCamera::GetWorldLocation() const
{
    return m_kWorld.m_Translate;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiCamera::GetWorldDirection() const
{
    return m_kWorldDir;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiCamera::GetWorldUpVector() const
{ 
    return m_kWorldUp;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiCamera::GetWorldRightVector() const
{
    return m_kWorldRight;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetViewFrustum(const NiFrustum& kFrustum)
{
    float fNear = kFrustum.m_fNear;

    if (fNear < (kFrustum.m_fFar / ms_fMaxFarNearRatio))
        fNear = kFrustum.m_fFar / ms_fMaxFarNearRatio;

    if (fNear < ms_fMinNearPlaneDist)
        fNear = ms_fMinNearPlaneDist;

    m_kViewFrustum.m_fLeft   = kFrustum.m_fLeft;
    m_kViewFrustum.m_fRight  = kFrustum.m_fRight;
    m_kViewFrustum.m_fTop    = kFrustum.m_fTop;
    m_kViewFrustum.m_fBottom = kFrustum.m_fBottom;
    m_kViewFrustum.m_fNear   = fNear;
    m_kViewFrustum.m_fFar    = kFrustum.m_fFar;
    m_kViewFrustum.m_bOrtho  = kFrustum.m_bOrtho;

    MarkScreenPolysAsChanged();
}
//---------------------------------------------------------------------------
inline const NiFrustum& NiCamera::GetViewFrustum() const
{
    return m_kViewFrustum;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetMinNearPlaneDist(const float fMin)
{
    ms_fMinNearPlaneDist = fMin;
}
//---------------------------------------------------------------------------
inline float NiCamera::GetMinNearPlaneDist() 
{
    return ms_fMinNearPlaneDist;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetMaxFarNearRatio(const float fMax)
{
    ms_fMaxFarNearRatio = fMax;
}
//---------------------------------------------------------------------------
inline float NiCamera::GetMaxFarNearRatio() 
{
    return ms_fMaxFarNearRatio; 
}
//---------------------------------------------------------------------------
inline void NiCamera::SetViewPort(const NiRect<float>& kPort)
{
    m_kPort = kPort;
}
//---------------------------------------------------------------------------
inline const NiRect<float>& NiCamera::GetViewPort() const
{
    return m_kPort;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetScene(NiNode* pkScene)
{
    m_spScene = pkScene;
}
//---------------------------------------------------------------------------
inline NiNode* NiCamera::GetScene() const
{
    return m_spScene;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetRenderer(NiRenderer* pkRenderer)
{
    m_spRenderer = pkRenderer;
}
//---------------------------------------------------------------------------
inline NiRenderer* NiCamera::GetRenderer() const
{
    return m_spRenderer;
}
//---------------------------------------------------------------------------
inline void NiCamera::AttachScreenPoly(NiScreenPolygon* pkPoly)
{
    assert(pkPoly);
    m_kScreenPolygons.AddFirstEmpty(pkPoly);
    pkPoly->MarkAsChanged(NiScreenPolygon::VERTEX_MASK);
}
//---------------------------------------------------------------------------
inline NiScreenPolygonArray& NiCamera::GetScreenPolyArray()
{
    return m_kScreenPolygons;
}
//---------------------------------------------------------------------------
inline void NiCamera::AttachScreenTexture(NiScreenTexture* pkTexture)
{
    m_kScreenTextures.AddFirstEmpty(pkTexture);
}
//---------------------------------------------------------------------------
inline NiScreenTextureArray& NiCamera::GetScreenTextureArray()
{
    return m_kScreenTextures;
}
//---------------------------------------------------------------------------
inline NiPlane* NiCamera::GetCullingPlanes()
{
    return m_akCullingPlanes;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetActiveCullingPlaneFlags(unsigned int uiActive)
{
    m_uiActivePlaneFlags = uiActive;
}
//---------------------------------------------------------------------------
inline int NiCamera::GetActiveCullingPlaneFlags() const
{
    return m_uiActivePlaneFlags;
}
//---------------------------------------------------------------------------
inline bool NiCamera::PlaneIsActive(unsigned int uiPlane) const
{
    return (m_uiActivePlaneFlags & (1 << uiPlane)) ? true : false;
}
//---------------------------------------------------------------------------
inline void NiCamera::ActivatePlane(unsigned int uiPlane)
{
    m_uiActivePlaneFlags = m_uiActivePlaneFlags | (1 << uiPlane);
}
//---------------------------------------------------------------------------
inline void NiCamera::DeactivatePlane(unsigned int uiPlane)
{
    m_uiActivePlaneFlags = m_uiActivePlaneFlags & (~(1 << uiPlane));
}
//---------------------------------------------------------------------------
inline void NiCamera::SetLODAdjust(float fLODAdjust)
{
    m_fLODAdjust = fLODAdjust;
}
//---------------------------------------------------------------------------
inline float NiCamera::GetLODAdjust() const
{
    return m_fLODAdjust;
}
//---------------------------------------------------------------------------
inline void NiCamera::SetVpRightNeedsUpdate(bool bUpdate)
{
    SetBit(bUpdate, VP_RIGHT_NEEDS_UPDATE_MASK);
}
//---------------------------------------------------------------------------
inline bool NiCamera::GetVpRightNeedsUpdate() const
{
    return GetBit(VP_RIGHT_NEEDS_UPDATE_MASK);
}
//---------------------------------------------------------------------------
inline const float* NiCamera::GetWorldToCameraMatrix() const
{
    return &m_aafWorldToCam[0][0];
}
//---------------------------------------------------------------------------
