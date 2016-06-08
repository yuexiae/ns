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

#ifndef NIDX8DEFINES_H
#define NIDX8DEFINES_H

// Contains some helper mappings/definitions for cross-D3D development.
//*** This header file is intended for DX8 only! ***//
// This will cause an error to flag when a build attempts to include this 
// file on any platform besides DX8.
#if defined(_XBOX) || defined(_DX9)
    #error This header is for DX8 builds only!
#endif  //#if defined(_XBOX) || defined(_DX9)

#include <NiNewUndef.h>

#include <D3D8.h>
#include <D3D8Types.h>
#include <D3DX8Math.h>

#include <NiNewRedef.h>

#include "NiD3DError.h"

#include <NiOS.h>
#include <NiRTLib.h>
#include <NiSmartPointer.h>

#include "NiDX8RendererLibType.h"
#define NID3D_ENTRY NIDX8RENDERER_ENTRY

//*** Class Declarations
class NiDX8Renderer;
class NiDX8VertexBufferManager;
class NiDX8PaletteData;
class NiDX8TextureData;
class NiDX8SourceTextureData;
class NiDX8MaterialManager;
class NiDX8PixelFormat;

//*** Mappings for platform agnostic code
// D3D Mappings
typedef LPDIRECT3DDEVICE8 D3DDevicePtr;
typedef LPDIRECT3DSURFACE8 D3DSurfacePtr;
typedef LPDIRECT3DBASETEXTURE8 D3DBaseTexturePtr;
typedef LPDIRECT3DTEXTURE8 D3DTexturePtr;
typedef LPDIRECT3DVERTEXBUFFER8 D3DVertexBufferPtr;
typedef LPDIRECT3DINDEXBUFFER8 D3DIndexBufferPtr;

// Gamebryo Mappings
typedef NiDX8Renderer NiD3DRenderer;
typedef NiDX8VertexBufferManager NiD3DVBManager;
typedef NiDX8PaletteData NiD3DPaletteData;
typedef NiDX8TextureData NiD3DTextureData;
typedef NiDX8SourceTextureData NiD3DSourceTextureData;
typedef NiDX8MaterialManager NiD3DMaterialManager;
typedef NiDX8PixelFormat NiD3DPixelFormat;

// Shader 'handle'
typedef DWORD* NiD3DVertexDeclaration;
typedef DWORD NiD3DVertexShaderHandle;
typedef DWORD NiD3DPixelShaderHandle;

// This is to hide the Xbox implementation of D3DVECTOR4
#ifndef D3DVECTOR4_DEFINED
typedef struct _D3DVECTOR4 {
    float x;
    float y;
    float z;
    float w;
} D3DVECTOR4;
#define D3DVECTOR4_DEFINED
#endif  //#ifndef D3DVECTOR4_DEFINED

// Align D3DXMATRIX
typedef __declspec(align(16)) D3DXMATRIX    D3DXALIGNEDMATRIX;

#endif  //#ifndef NIDX8DEFINES_H
