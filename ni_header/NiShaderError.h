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

#ifndef NISHADERERROR_H
#define NISHADERERROR_H

typedef unsigned int NiShaderError;

// Upper 16 bits of error indicate which shader system a given error belongs to
// Lower 16 bits used by each shader system to specify error

enum NiShaderErrorPrefix
{
    // Errors in the global shader system have this prefix
    NISHADERERR_GLOBALPREFIX        = 0x0000,

    // Generic D3D errors will have this prefix
    NISHADERERR_D3DPREFIX           = 0x8000,

    // DX8 Shader errors will have this prefix
    NISHADERERROR_DX8PREFIX         = 0x4000,

    // DX9 Shader errors will have this prefix
    NISHADERERROR_DX9PREFIX         = 0x2000,

    // XBox Shader errors will have this prefix
    NISHADERERROR_XBOXPREFIX        = 0x1000

    // As new shader systems are added, they can be enumerated here
};

#define NiDeclareShaderError(name, prefix, value) \
    const NiShaderError name = (NiShaderError)(((prefix) << 16) | (value))

#define NiDeclareGenericShaderError(name, value) \
    NiDeclareShaderError(name, NISHADERERR_GLOBALPREFIX, (value))

NiDeclareGenericShaderError(NISHADERERR_OK,             0x0000);
NiDeclareGenericShaderError(NISHADERERR_UNKNOWN,        0x0001);
NiDeclareGenericShaderError(NISHADERERR_SHADERNOTFOUND, 0x0100);

#endif  //#ifndef NISHADERERROR_H
