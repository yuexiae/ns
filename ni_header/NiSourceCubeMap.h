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

#ifndef NISOURCECUBEMAP_H
#define NISOURCECUBEMAP_H

#include "NiSourceTexture.h"

class NiRenderer;

class NIMAIN_ENTRY NiSourceCubeMap : public NiSourceTexture
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // Create from a cubemap filename
    static NiSourceCubeMap* Create(const char* pcFilename,
        FormatPrefs& kPrefs = ms_kDefaultPrefs);
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

    // Create from a filename
    static NiSourceCubeMap* Create(const char* pcPosXFilename,
        const char* pcNegXFilename, const char* pcPosYFilename,
        const char* pcNegYFilename, const char* pcPosZFilename,
        const char* pcNegZFilename, NiRenderer* pkRenderer,
        FormatPrefs& kPrefs = ms_kDefaultPrefs);

    // Create from application pixel data
    static NiSourceCubeMap* Create(NiPixelData* pkPosXRaw, 
        NiPixelData* pkNegXRaw, NiPixelData* pkPosYRaw, 
        NiPixelData* pkNegYRaw, NiPixelData* pkPosZRaw, 
        NiPixelData* pkNegZRaw, NiRenderer* pkRenderer,
        FormatPrefs& kPrefs = ms_kDefaultPrefs);

    FaceID GetCurrentCubeFace() const;
    void SetCurrentCubeFace(FaceID eFace);

    // Create the application level backing store for an image
    // loaded from file.  By default this backing store is not 
    // created, instead only the renderer specific store is built.
    virtual void LoadPixelDataFromFile();

    // Destroy the application level backing store -- this can be done
    // if an application has no need to retain access to a version of
    // the pixel data for its own modification or otherwise.
    virtual void DestroyAppPixelData();

    /*** begin NDL internal use only ***/

    const char* GetFaceFilename(FaceID eFace) const;
    const char* GetFacePlatformFilename(FaceID eFace) const;
    NiPixelData* GetFaceSourcePixelData(FaceID eFace) const;

    // streaming support
    virtual void PostLinkObject(NiStream& kStream);

    /*** end NDL internal use only ***/

protected:
    NiSourceCubeMap();
    virtual ~NiSourceCubeMap();

    virtual bool CreateRendererData();

    FaceID m_eFace;

    char* m_apcFaceFilenames[FACE_NUM];
    char* m_apcFacePlatformFilenames[FACE_NUM];
    NiPixelDataPtr m_aspFaceSrcPixelDatas[FACE_NUM];
};

typedef NiPointer<NiSourceCubeMap> NiSourceCubeMapPtr;

//---------------------------------------------------------------------------
//  Inline include

#include "NiSourceCubeMap.inl"
//---------------------------------------------------------------------------

#endif
