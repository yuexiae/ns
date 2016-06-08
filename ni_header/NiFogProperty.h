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

#ifndef NIFOGPROPERTY_H
#define NIFOGPROPERTY_H

#include "NiColor.h"
#include "NiProperty.h"
#include "NiFlags.h"

NiSmartPointer(NiFogProperty);

class NIMAIN_ENTRY NiFogProperty : public NiProperty
{
    NiDeclareRTTI;
    NiDeclareClone(NiFogProperty);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    // fog attenuation function
    enum FogFunction
    {
        FOG_Z_LINEAR,
        FOG_RANGE_SQ,
        FOG_VERTEX_ALPHA
    };

    NiFogProperty();

    void SetFog(bool bFog);
    bool GetFog() const;

    void SetFogFunction(FogFunction eFunc);
    FogFunction GetFogFunction() const;

    void SetFogColor(const NiColor& kColor);
    const NiColor& GetFogColor() const;

    // depth = 0, no fogging
    // depth = 1, fog starts at near plane
    // depth > 1, gives fog starting in front of near plane
    void SetDepth(float fDepth);
    float GetDepth() const;

    bool IsEqualFast(const NiFogProperty& kProp) const;

    virtual int Type() const;
    static int GetType();
    static NiFogProperty* GetDefault();

    // *** begin NDL internal use only ***

    static char* GetViewerString(const char* pcPrefix, FogFunction eFunc);
    static void _SDMInit();
    static void _SDMShutdown();

    // *** end NDL internal use only ***

protected:
    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 3
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        FOG_MASK        = 0x0001,
        FOG_FUNC_MASK   = 0x0006,
        FOG_FUNC_POS    = 1
    };

    float m_fDepth;
    NiColor m_kColor;

    static NiFogPropertyPtr ms_spDefault;
};

#include "NiFogProperty.inl"

#endif // NIFOGPROPERTY_H