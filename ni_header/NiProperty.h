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

#ifndef NIPROPERTY_H
#define NIPROPERTY_H

#include "NiObjectNET.h"

class NIMAIN_ENTRY NiProperty : public NiObjectNET
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiProperty);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    NiProperty();

    enum 
    { 
        ALPHA,
        DITHER,
        FOG,
        MATERIAL,
        REND_SPEC,
        SHADE,
        SPECULAR,
        STENCIL,
        TEXTURING,
        VERTEX_COLOR,
        WIREFRAME,
        ZBUFFER,
        MAX_TYPES
    };  
    virtual int Type() const = 0;
    
    virtual void Update(float fTime);

protected:
    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 0
    };
    // --- End NIF conversion code
};

typedef NiPointer<NiProperty> NiPropertyPtr;
typedef NiTPointerList<NiPropertyPtr> NiPropertyList;

#include "NiProperty.inl"

#endif

