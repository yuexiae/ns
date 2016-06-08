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

#ifndef NIDX8DIRECT3DTEXTURE_H
#define NIDX8DIRECT3DTEXTURE_H

#include "NiTexture.h"

#include "NiDX8RendererLibType.h"
class NiRenderer;

class NIDX8RENDERER_ENTRY NiDX8Direct3DTexture : public NiTexture
{
    NiDeclareRTTI;

public:
    static NiDX8Direct3DTexture* Create(NiRenderer* pkRenderer);

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

    // *** begin NDL internal use only ***
    void SetWidth(unsigned int uiWidth);
    void SetHeight(unsigned int uiHeight);
    // *** end NDL internal use only ***

protected:
    NiDX8Direct3DTexture();

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
};

typedef NiPointer<NiDX8Direct3DTexture> NiDX8Direct3DTexturePtr;

#include "NiDX8Direct3DTexture.inl"

#endif //NIDX8DIRECT3DTEXTURE_H
