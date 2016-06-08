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
#ifndef NIDX9RENDEREDCUBEMAPDATA_H
#define NIDX9RENDEREDCUBEMAPDATA_H

#include "NiDX9RenderedTextureData.h"
#include <NiRenderedCubeMap.h>

class NiDX9Renderer;
class NiDX9TextureRenderTarget;

//---------------------------------------------------------------------------
class NIDX9RENDERER_ENTRY NiDX9RenderedCubeMapData : public NiDX9RenderedTextureData
{
public:
    static NiDX9RenderedCubeMapData* Create(NiRenderedCubeMap* pkTexture, 
        NiDX9Renderer* pkRenderer);
    virtual ~NiDX9RenderedCubeMapData();

    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const;

    virtual bool IsLoaded() const;

    virtual NiDX9TextureRenderTarget* GetTarget();

protected:
    NiDX9RenderedCubeMapData(NiRenderedCubeMap* pkTexture, 
        NiDX9Renderer* pkRenderer);
    NiDX9PixelFormat* CreateSurf(const NiRenderedCubeMap* pkTexture);

    LPDIRECT3DCUBETEXTURE9 m_pkD3DCubeMap;

    NiDX9TextureRenderTarget* 
        m_apkFaces[NiRenderedCubeMap::FACE_NUM];
};

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX9RENDEREDEXTUREDATA_H
