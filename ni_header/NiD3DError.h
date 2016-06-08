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

#ifndef NID3DERROR_H
#define NID3DERROR_H

#include <NiShaderError.h>

typedef NiShaderError NiD3DError;

#define NiDeclareD3DShaderError(name, value) \
    NiDeclareShaderError((name), NISHADERERR_D3DPREFIX, (value))

// ConstantMapEntry not found
NiDeclareD3DShaderError(NID3DERR_ENTRYNOTFOUND,        0x0010);

// ConstantMapEntry key exists in map
NiDeclareD3DShaderError(NID3DERR_DUPLICATEENTRYKEY,    0x0020);

// ConstantMapEntry failed to add
NiDeclareD3DShaderError(NID3DERR_ENTRYNOTADDED,        0x0030);

// ConstantMapEntry invalid mapping
NiDeclareD3DShaderError(NID3DERR_INVALIDMAPPING,       0x0040);

// ConstantMapEntry failed to be set on the device
NiDeclareD3DShaderError(NID3DERR_SETCONSTANTFAILED,    0x0050);

#endif  //#ifndef NID3DERROR_H
