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

#ifndef NISHADER_H
#define NISHADER_H

#include "NiRTTI.h"
#include "NiRefObject.h"
#include "NiStream.h"

class NiGeometry;

// NiShader - interface class for the implementation of the Shader System.
// This interface is currently empty, as the implementation is 
// platform-specific (D3D-based renderers) in this, it's initial development.
// Once (if) the system spreads to other platforms, common functionality and
// interfaces will be pushed into here.
class NIMAIN_ENTRY NiShader : public NiRefObject
{
    NiDeclareRootRTTI(NiShader);
public:
    enum Platform
    {
        NISHADER_DX8        = 0x00000001,
        NISHADER_DX9        = 0x00000002,
        NISHADER_XBOX       = 0x00000004,
        NISHADER_XENON      = 0x00000008, 
        NISHADER_AGNOSTIC   = NISHADER_DX8 | NISHADER_DX9 | 
            NISHADER_XBOX | NISHADER_XENON
    };

    enum
    {
        DEFAULT_IMPLEMENTATION = 0xffffffff
    };

    NiShader();
    virtual ~NiShader();

    const char* GetName() const;

    // *** begin NDL internal use only ***
    void SetName(const char* pszName);

    unsigned int GetImplementation() const;
    void SetImplementation(unsigned int uiImplementation);

    // This function is called by NiShaderFactory::AttachShader, and
    // is used to verify the geometry is usable for the shader, as well
    // as to 'process' the geometry, adding what is needed.
    virtual bool SetupGeometry(NiGeometry* pkGeometry);

    // These are NOT virtual, as we do not want sub-classes
    // overriding them. The ONLY thing that should be written
    // out for a shader is the name and implementation number.
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    // *** end NDL internal use only ***

protected:
    char* m_pszName;
    unsigned int m_uiImplementation;
};

typedef NiPointer<NiShader> NiShaderPtr;

#endif  //#ifndef NISHADER_H
