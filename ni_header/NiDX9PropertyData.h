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
#ifndef NIDX9PROPERTYDATA_H
#define NIDX9PROPERTYDATA_H

#include <NiRendererSpecificProperty.h>
#include "NiDX9RendererLibType.h"
#include "NiDX9Renderer.h"
#include "NiRendererExtraData.h"
#include "NiDX9ShaderDeclaration.h"

class NIDX9RENDERER_ENTRY NiDX9PropertyData : 
    public NiRendererSpecificProperty::RendererData
{
public:
    NiDX9PropertyData();
    virtual ~NiDX9PropertyData();

    virtual unsigned int GetRendererTypeID() const;

    NiRendererExtraData* GetExtraData() const;
    void SetExtraData(NiRendererExtraData* pkExtraData);

    // *** begin NDL internal use only ***
    NiRendererSpecificProperty::RendererData* CreateClone(
        NiCloningProcess& kCloning) const;
    void CopyMembers(NiDX9PropertyData* pkDest,
        NiCloningProcess& kCloning) const;
    // *** end NDL internal use only ***

protected:
    NiRendererExtraDataPtr m_spExtraData;
};

//---------------------------------------------------------------------------
#include "NiDX9PropertyData.inl"

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX9PROPERTYDATA_H
