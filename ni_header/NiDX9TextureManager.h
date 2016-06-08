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
#ifndef NIDX9TEXTUREMANAGER_H
#define NIDX9TEXTUREMANAGER_H

#include "NiDX9Headers.h"
#include "NiDX9RendererLibType.h"
#include "NiDX9Resource.h"
#include <NiTexture.h>
#include <NiRefObject.h>

class NiDX9Renderer;

class NIDX9RENDERER_ENTRY NiDX9TextureManager : public NiRefObject
{
public:
    NiDX9TextureManager(NiDX9Renderer* pkRenderer);
    ~NiDX9TextureManager();

    virtual LPDIRECT3DTEXTURE9 GetTexture(unsigned int uiWidth, 
        unsigned int uiHeight, unsigned int uiLevels, 
        unsigned int uiUsage, D3DFORMAT eFormat, D3DPOOL ePool);

    virtual LPDIRECT3DBASETEXTURE9 PrepareTextureForRendering(
        NiTexture* pNewTexIm, bool &bChanged, bool &bMipmap);

    virtual bool PrecacheTexture(NiTexture* pkIm, bool bForceLoad, 
        bool bLocked);

    virtual unsigned int GetFormatFromTexture(NiTexture& kIm);

protected:
    LPDIRECT3DDEVICE9 m_pkD3DDevice9;
    NiDX9Renderer* m_pkRenderer;
};

typedef NiPointer<NiDX9TextureManager> NiDX9TextureManagerPtr;

#endif  //#ifndef NIDX9TEXTUREMANAGER_H
