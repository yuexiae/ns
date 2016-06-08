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
#ifndef NIDX8BLTSOURCEDATA_H
#define NIDX8BLTSOURCEDATA_H

#include "NiDX8Headers.h"
#include "NiDX8PixelFormat.h"
#include "NiBltSource.h"

class NiDX8Renderer;

class NIDX8RENDERER_ENTRY NiDX8BltSourceData : public NiBltSource::RendererData
{
public:
    virtual ~NiDX8BltSourceData();

    static NiDX8BltSourceData* Create(NiBltSource* pkBlt, 
        NiDX8Renderer* pkRenderer);

    LPDIRECT3DSURFACE8 GetSurface()     {   return m_pkSurf;    };

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

    static void ClearBltData(NiDX8Renderer* pkRenderer);

protected:
    NiDX8BltSourceData(NiBltSource* pkBlt, NiDX8Renderer* pkRenderer);

    bool CreateSurf(const NiPixelData& kPixels, 
        const NiDX8PixelFormat& kFormat);

    NiDX8Renderer* m_pkRenderer;
    LPDIRECT3DSURFACE8 m_pkSurf;
    unsigned int m_uiRevID;

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
};
//---------------------------------------------------------------------------
#endif  //#ifndef NIDX8BLTSOURCEDATA_H
