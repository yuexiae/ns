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
//---------------------------------------------------------------------------
#ifndef NIDX8TEXTUREMANAGER_H
#define NIDX8TEXTUREMANAGER_H

#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"
#include "NiDX8Resource.h"
#include <NiTexture.h>
#include <NiRefObject.h>

class NiDX8Renderer;

class NIDX8RENDERER_ENTRY NiDX8TextureManager : public NiRefObject
{
public:
    NiDX8TextureManager(NiDX8Renderer* pkRenderer);
    ~NiDX8TextureManager();

    virtual LPDIRECT3DTEXTURE8 GetTexture(unsigned int uiWidth, 
        unsigned int uiHeight, unsigned int uiLevels, 
        unsigned int uiUsage, D3DFORMAT eFormat, D3DPOOL ePool);

    virtual LPDIRECT3DBASETEXTURE8 PrepareTextureForRendering(
        NiTexture* pNewTexIm, bool &bChanged, bool &bMipmap);

    virtual bool PrecacheTexture(NiTexture* pkIm, bool bForceLoad, 
        bool bLocked);

    virtual unsigned int GetFormatFromTexture(NiTexture& kIm);

protected:
    LPDIRECT3DDEVICE8 m_pkD3DDevice8;
    NiDX8Renderer* m_pkRenderer;
};

typedef NiPointer<NiDX8TextureManager> NiDX8TextureManagerPtr;

#endif  //#ifndef NIDX8TEXTUREMANAGER_H
