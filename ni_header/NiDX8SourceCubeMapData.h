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
#ifndef NIDX8SOURCECUBEMAPDATA_H
#define NIDX8SOURCECUBEMAPDATA_H

#include "NiDX8SourceTextureData.h"
#include <NiSourceCubeMap.h>

//---------------------------------------------------------------------------
class NIDX8RENDERER_ENTRY NiDX8SourceCubeMapData : public NiDX8SourceTextureData
{
public:
    static NiDX8SourceCubeMapData* Create(NiSourceCubeMap* pkTexture, 
        NiDX8Renderer* pkRenderer);
    virtual ~NiDX8SourceCubeMapData();

    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const;

    virtual bool IsLoaded() const;

    virtual void Update();

protected:
    NiDX8SourceCubeMapData(NiSourceCubeMap* pkTexture, 
        NiDX8Renderer* pkRenderer);
    bool CreateCubeMap();
    void CopyDataToCubeMapFace(const NiPixelData& kPixels,
        NiSourceCubeMap::FaceID eFace);

    LPDIRECT3DCUBETEXTURE8 m_pkD3DCubeMap;

    unsigned int m_auiSourceRevID[NiSourceCubeMap::FACE_NUM];
};
//---------------------------------------------------------------------------

#endif  //#ifndef NIDX8SOURCETEXTUREDATA_H
