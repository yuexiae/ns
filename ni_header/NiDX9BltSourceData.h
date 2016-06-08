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
#ifndef NIDX9BLTSOURCEDATA_H
#define NIDX9BLTSOURCEDATA_H

#include "NiDX9Headers.h"
#include "NiDX9PixelFormat.h"
#include "NiBltSource.h"

class NiDX9Renderer;

class NIDX9RENDERER_ENTRY NiDX9BltSourceData : public NiBltSource::RendererData
{
public:
    virtual ~NiDX9BltSourceData();

    static NiDX9BltSourceData* Create(NiBltSource* pkBlt, 
        NiDX9Renderer* pkRenderer);

    LPDIRECT3DSURFACE9 GetSurface()     {   return m_pkSurf;    };

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

    static void ClearBltData(NiDX9Renderer* pkRenderer);

protected:
    NiDX9BltSourceData(NiBltSource* pkBlt, NiDX9Renderer* pkRenderer);

    bool CreateSurf(const NiPixelData& kPixels, 
        const NiDX9PixelFormat& kFormat);

    NiDX9Renderer* m_pkRenderer;
    LPDIRECT3DSURFACE9 m_pkSurf;
    unsigned int m_uiRevID;

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
};
//---------------------------------------------------------------------------
#endif  //#ifndef NIDX9BLTSOURCEDATA_H
