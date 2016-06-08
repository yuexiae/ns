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

#ifndef NIAMBIENTLIGHT_H
#define NIAMBIENTLIGHT_H

#include "NiLight.h"

class NIMAIN_ENTRY NiAmbientLight : public NiLight
{
    NiDeclareRTTI;
    NiDeclareClone(NiAmbientLight);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiAmbientLight();

    virtual EffectType GetEffectType() const;
};

typedef NiPointer<NiAmbientLight> NiAmbientLightPtr;

#include "NiAmbientLight.inl"

#endif
