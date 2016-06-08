
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

#ifndef NIRENDEREDCUBEMAP_H
#define NIRENDEREDCUBEMAP_H

#include "NiRenderedTexture.h"

class NIMAIN_ENTRY NiRenderedCubeMap : public NiRenderedTexture
{
    NiDeclareRTTI;

public:
    enum FaceID
    {
        FACE_POS_X,
        FACE_NEG_X,
        FACE_POS_Y,
        FACE_NEG_Y,
        FACE_POS_Z,
        FACE_NEG_Z,
        FACE_NUM
    };

    static NiRenderedCubeMap* Create(unsigned int uiSize, 
        NiRenderer* pkRenderer, FormatPrefs& kPrefs = ms_kDefaultPrefs);

    FaceID GetCurrentCubeFace() const;
    void SetCurrentCubeFace(FaceID eFace);

protected:
    NiRenderedCubeMap();

    FaceID m_eFace;
};

typedef NiPointer<NiRenderedCubeMap> NiRenderedCubeMapPtr;


//---------------------------------------------------------------------------
//  Inline include

#include "NiRenderedCubeMap.inl"
//---------------------------------------------------------------------------

#endif
