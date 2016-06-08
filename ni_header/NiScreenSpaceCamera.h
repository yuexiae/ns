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

#ifndef NISCREENSPACECAMERA_H
#define NISCREENSPACECAMERA_H

#include "NiCamera.h"
#include "NiScreenGeometry.h"
#include "NiScreenPolygon.h"
#include "NiScreenTexture.h"

NiSmartPointer(NiBackToFrontAccumulator);

class NiPoint2;

class NIMAIN_ENTRY NiScreenSpaceCamera : public NiCamera
{
    NiDeclareRTTI;
    NiDeclareClone(NiScreenSpaceCamera);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:

    // construction and destruction
    NiScreenSpaceCamera();
    virtual ~NiScreenSpaceCamera();

    // scene graph, display, camera video click

    virtual void Click();

    // screen-space geometry
    void AttachScreenGeometry(NiAVObject* pkScreenObject);
    void DetachScreenGeometry(NiAVObject* pkScreenObject);
    void DrawScreenGeometry();

    void UpdateRenderTargetBounds();

    // *** begin NDL internal use only ***

    // renderer data
    virtual void PurgeRendererData(NiRenderer* pkRenderer);

    // cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);

    // *** end NDL internal use only ***

protected:
    virtual void UpdateWorldData();

    NiBackToFrontAccumulatorPtr m_spBackToFrontAccumulator;
};


typedef NiPointer<NiScreenSpaceCamera> NiScreenSpaceCameraPtr;

#include "NiScreenSpaceCamera.inl"

#endif // NISCREENSPACECAMERA_H
