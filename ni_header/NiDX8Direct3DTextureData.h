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

#ifndef NIDX8DIRECT3DTEXTUREDATA_H
#define NIDX8DIRECT3DTEXTUREDATA_H

#include "NiDX8TextureData.h"
class NiDX8Direct3DTexture;

class NIDX8RENDERER_ENTRY NiDX8Direct3DTextureData : public NiDX8TextureData
{
public:
    static NiDX8Direct3DTextureData* Create(NiDX8Direct3DTexture* pkTexture, 
        NiDX8Renderer* pkRenderer, LPDIRECT3DBASETEXTURE8 pkD3DTexture);
    virtual ~NiDX8Direct3DTextureData();

    virtual bool IsLoaded() const;

    virtual LPDIRECT3DBASETEXTURE8 GetD3DTexture() const;

protected:
    NiDX8Direct3DTextureData(NiDX8Direct3DTexture* pkTexture, 
        NiDX8Renderer* pkRenderer);

    LPDIRECT3DBASETEXTURE8 m_pkD3DTexture;
};

#endif  //#ifndef NIDX8DIRECT3DTEXTUREDATA_H
