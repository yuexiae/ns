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

#ifndef NIPROPERTYSTATE_H
#define NIPROPERTYSTATE_H

#include "NiProperty.h"

class NiAlphaProperty;
class NiDitherProperty;
class NiFogProperty;
class NiMaterialProperty;
class NiRendererSpecificProperty;
class NiShadeProperty;
class NiSpecularProperty;
class NiStencilProperty;
class NiTexturingProperty;
class NiVertexColorProperty;
class NiWireframeProperty;
class NiZBufferProperty;

class NIMAIN_ENTRY NiPropertyState : public NiRefObject
{
public:
    NiPropertyState();
    NiPropertyState(const NiPropertyState& kState);
    ~NiPropertyState();

    NiPropertyState& operator=(const NiPropertyState& kState);
    NiPropertyPtr &operator[](int iType);

    void Reset();
    void SetProperty(NiProperty* pkProp);
    void GetProperties(NiProperty* apkProps[NiProperty::MAX_TYPES]);
    void SwapProperties(NiPropertyList& kProplist);

    NiAlphaProperty* GetAlpha() const;
    NiDitherProperty* GetDither() const;
    NiFogProperty* GetFog() const;
    NiMaterialProperty* GetMaterial() const;
    NiRendererSpecificProperty* GetRendererSpecific() const;
    NiShadeProperty* GetShade() const;
    NiSpecularProperty* GetSpecular() const;
    NiStencilProperty* GetStencil() const;
    NiTexturingProperty* GetTexturing() const;
    NiVertexColorProperty* GetVertexColor() const;
    NiWireframeProperty* GetWireframe() const;
    NiZBufferProperty* GetZBuffer() const;

protected:
    NiPropertyPtr m_aspProps[NiProperty::MAX_TYPES];
};

typedef NiPointer<NiPropertyState> NiPropertyStatePtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiPropertyState.inl"

//---------------------------------------------------------------------------

#endif
