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

#ifndef NIDX9DIRECT3DTEXTUREDATA_H
#define NIDX9DIRECT3DTEXTUREDATA_H

#include "NiDX9TextureData.h"
class NiDX9Direct3DTexture;

class NIDX9RENDERER_ENTRY NiDX9Direct3DTextureData : public NiDX9TextureData
{
public:
    static NiDX9Direct3DTextureData* Create(NiDX9Direct3DTexture* pkTexture, 
        NiDX9Renderer* pkRenderer, LPDIRECT3DBASETEXTURE9 pkD3DTexture);
    virtual ~NiDX9Direct3DTextureData();

    virtual bool IsLoaded() const;

    virtual LPDIRECT3DBASETEXTURE9 GetD3DTexture() const;

protected:
    NiDX9Direct3DTextureData(NiDX9Direct3DTexture* pkTexture, 
        NiDX9Renderer* pkRenderer);

    LPDIRECT3DBASETEXTURE9 m_pkD3DTexture;
};

#endif  //#ifndef NIDX9DIRECT3DTEXTUREDATA_H
