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

#ifndef NIBILLBOARDNODE_H
#define NIBILLBOARDNODE_H

#include "NiNode.h"
#include "NiStream.h"
class NiCamera;

class NIMAIN_ENTRY NiBillboardNode : public NiNode
{
    NiDeclareRTTI;
    NiDeclareClone(NiBillboardNode);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    // construction
    NiBillboardNode();

    // mode selection
    enum FaceMode
    {
        ALWAYS_FACE_CAMERA,
        ROTATE_ABOUT_UP,
        RIGID_FACE_CAMERA,
        ALWAYS_FACE_CENTER,
        RIGID_FACE_CENTER
    };

    void SetMode(FaceMode eMode);
    FaceMode GetMode() const;

    // *** begin NDL internal use only ***

    // updates
    virtual void UpdateDownwardPass(float fTime, bool bUpdateControllers);
    virtual void UpdateSelectedDownwardPass(float fTime);
    virtual void UpdateRigidDownwardPass(float fTime);
    virtual void UpdateWorldBound();

    static char* GetViewerString(const char* pcPrefix, FaceMode eMode);

    // *** end NDL internal use only ***

protected:
    void RotateToCamera(NiCamera* pkCamera);
    bool RotateToCenter(NiCamera* pkCamera, NiPoint3 kWorldTranslate, 
        NiPoint3& kCamD, NiPoint3& kCamU, NiPoint3& kCamR);

    // scene graph traversal (controls billboard motion)
    virtual void Display(NiCamera* pkCamera);

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 11
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        FACE_MODE_MASK  = 0x0007,
        FACE_MODE_POS   = 0
    };

    float m_fSavedTime;
    bool m_bUpdateControllers;
};


typedef NiPointer<NiBillboardNode> NiBillboardNodePtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiBillboardNode.inl"

//---------------------------------------------------------------------------

#endif
