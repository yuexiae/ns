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
#ifndef NIDX8PROPERTYDATA_H
#define NIDX8PROPERTYDATA_H

#include <NiRendererSpecificProperty.h>
#include "NiDX8RendererLibType.h"
#include "NiDX8Renderer.h"
#include "NiRendererExtraData.h"
#include "NiDX8ShaderDeclaration.h"

class NIDX8RENDERER_ENTRY NiDX8PropertyData : 
    public NiRendererSpecificProperty::RendererData
{
public:
    NiDX8PropertyData();
    virtual ~NiDX8PropertyData();

    // *** begin NDL internal use only ***

    virtual unsigned int GetRendererTypeID() const;

    NiRendererExtraData* GetExtraData() const;
    void SetExtraData(NiRendererExtraData* pkExtraData);

    NiRendererSpecificProperty::RendererData* CreateClone(
        NiCloningProcess& kCloning) const;
    void CopyMembers(NiDX8PropertyData* pkDest,
        NiCloningProcess& kCloning) const;

    // *** end NDL internal use only ***

protected:
    NiRendererExtraDataPtr m_spExtraData;
};

//---------------------------------------------------------------------------
#include "NiDX8PropertyData.inl"

//---------------------------------------------------------------------------
#endif  //#ifndef NIDX8PROPERTYDATA_H
