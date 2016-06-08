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

#ifndef NIDX9DEFINES_H
#define NIDX9DEFINES_H

// Contains some helper mappings/definitions for cross-D3D development.
//*** This header file is intended for DX9 only! ***//
// This will cause an error to flag when a build attempts to include this 
// file on any platform besides DX9.
#if defined(_XBOX) || defined(_DX8)
    #error This header is for DX9 builds only!
#endif  //#if defined(_XBOX) || defined(_DX8)

#include <NiNewUndef.h>

#include <D3D9.h>
#include <D3D9Types.h>
#include <D3DX9Math.h>

#include <NiNewRedef.h>

#include "NiD3DError.h"

#include <NiOS.h>
#include <NiRTLib.h>
#include <NiSmartPointer.h>

#include "NiDX9RendererLibType.h"
#define NID3D_ENTRY NIDX9RENDERER_ENTRY

//*** Class Declarations
class NiDX9Renderer;
class NiDX9VertexBufferManager;
class NiDX9PaletteData;
class NiDX9TextureData;
class NiDX9SourceTextureData;
class NiDX9MaterialManager;
class NiDX9PixelFormat;

//*** Mappings for platform agnostic code
// D3D Mappings
typedef LPDIRECT3DDEVICE9 D3DDevicePtr;
typedef LPDIRECT3DSURFACE9 D3DSurfacePtr;
typedef LPDIRECT3DBASETEXTURE9 D3DBaseTexturePtr;
typedef LPDIRECT3DTEXTURE9 D3DTexturePtr;
typedef LPDIRECT3DVERTEXBUFFER9 D3DVertexBufferPtr;
typedef LPDIRECT3DINDEXBUFFER9 D3DIndexBufferPtr;

// Gamebryo Mappings
typedef NiDX9Renderer NiD3DRenderer;
typedef NiDX9VertexBufferManager NiD3DVBManager;
typedef NiDX9PaletteData NiD3DPaletteData;
typedef NiDX9TextureData NiD3DTextureData;
typedef NiDX9SourceTextureData NiD3DSourceTextureData;
typedef NiDX9MaterialManager NiD3DMaterialManager;
typedef NiDX9PixelFormat NiD3DPixelFormat;

// Shader 'handle'
typedef LPDIRECT3DVERTEXDECLARATION9 NiD3DVertexDeclaration;
typedef LPDIRECT3DVERTEXSHADER9 NiD3DVertexShaderHandle;
typedef LPDIRECT3DPIXELSHADER9 NiD3DPixelShaderHandle;

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

#endif  //#ifndef NIDX9DEFINES_H
