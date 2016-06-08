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
#ifndef NIDX8RENDEREDCUBEMAPDATA_H
#define NIDX8RENDEREDCUBEMAPDATA_H

#include "NiDX8RenderedTextureData.h"
#include <NiRenderedCubeMap.h>

class NiDX8Renderer;
class NiDX8TextureRenderTarget;

//---------------------------------------------------------------------------
class NIDX8RENDERER_ENTRY NiDX8RenderedCubeMapData : public NiDX8RenderedTextureData
{
public:
    static NiDX8RenderedCubeMapData* Create(NiRenderedCubeMap* pkTexture, 
        NiDX8Renderer* pkRenderer);
    virtual ~NiDX8RenderedCubeMapData();

    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const;

    virtual bool IsLoaded() const;

    virtual NiDX8TextureRenderTarget* GetTarget();

protected:
    NiDX8RenderedCubeMapData(NiRenderedCubeMap* pkTexture, 
        NiDX8Renderer* pkRenderer);
    NiDX8PixelFormat* CreateSurf(const NiRenderedCubeMap* pkTexture);

    LPDIRECT3DCUBETEXTURE8 m_pkD3DCubeMap;

    NiDX8TextureRenderTarget* 
        m_apkFaces[NiRenderedCubeMap::FACE_NUM];
};

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX8RENDEREDEXTUREDATA_H
