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
#ifndef NIDX9SOURCECUBEMAPDATA_H
#define NIDX9SOURCECUBEMAPDATA_H

#include "NiDX9SourceTextureData.h"
#include <NiSourceCubeMap.h>

//---------------------------------------------------------------------------
class NIDX9RENDERER_ENTRY NiDX9SourceCubeMapData : public NiDX9SourceTextureData
{
public:
    static NiDX9SourceCubeMapData* Create(NiSourceCubeMap* pkTexture, 
        NiDX9Renderer* pkRenderer);
    virtual ~NiDX9SourceCubeMapData();

    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const;

    virtual bool IsLoaded() const;

    virtual void Update();

protected:
    NiDX9SourceCubeMapData(NiSourceCubeMap* pkTexture, 
        NiDX9Renderer* pkRenderer);
    bool CreateCubeMap();
    void CopyDataToCubeMapFace(const NiPixelData& kPixels,
        NiSourceCubeMap::FaceID eFace);

    LPDIRECT3DCUBETEXTURE9 m_pkD3DCubeMap;

    unsigned int m_auiSourceRevID[NiSourceCubeMap::FACE_NUM];
};
//---------------------------------------------------------------------------

#endif  //#ifndef NIDX9SOURCETEXTUREDATA_H
