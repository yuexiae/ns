
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

#ifndef NIRENDEREDTEXTURE_H
#define NIRENDEREDTEXTURE_H

#include "NiTexture.h"

class NiRenderer;

class NIMAIN_ENTRY NiRenderedTexture : public NiTexture
{
    NiDeclareRTTI;

protected:
    static FormatPrefs ms_kDefaultPrefs;
public:
    static NiRenderedTexture* Create(
        unsigned int uiWidth, unsigned int uiHeight, 
        NiRenderer* pkRenderer, FormatPrefs& kPrefs = ms_kDefaultPrefs);

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

protected:
    NiRenderedTexture();

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
};

typedef NiPointer<NiRenderedTexture> NiRenderedTexturePtr;

//---------------------------------------------------------------------------
#include "NiRenderedTexture.inl"
//---------------------------------------------------------------------------

#endif
