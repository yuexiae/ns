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

#ifndef NITEXTUREPALETTE_H
#define NITEXTUREPALETTE_H

#include "NiRefObject.h"
#include "NiTStringMap.h"

#include "NiSourceTexture.h"

class NIMAIN_ENTRY NiTexturePalette : public NiRefObject
{
public:
    NiTexturePalette() { /* */ }
    ~NiTexturePalette() { /* */ }

    virtual NiTexture* GetTexture(const char* pcPath, NiTexture* pkSelf) const
        = 0;
    virtual void SetTexture(const char* pcPath, NiTexture* pkTex) = 0;
};

class NIMAIN_ENTRY NiDefaultTexturePalette : public NiTexturePalette
{
public:
    NiDefaultTexturePalette(bool bSearchGlobalTextureList = false);
    ~NiDefaultTexturePalette() { /* */ }

    virtual NiTexture* GetTexture(const char* pcPath,
        NiTexture* pkSelf) const;
    virtual void SetTexture(const char* pcPath, NiTexture* pkTex);

    virtual void SetSearchGlobalTextureList(bool bSearch);
    virtual bool GetSearchGlobalTextureList() const;

protected:
    NiTStringPointerMap<NiTexturePtr> m_kHash;
    bool m_bSearchGlobalTextureList;
};

#include "NiTexturePalette.inl"

#endif
