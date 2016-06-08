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

#ifndef NIDX9RENDERERPCH_H
#define NIDX9RENDERERPCH_H

#if defined(NI_USE_PCH)

#if !defined(_DX9)
#error NiDX9RendererPCH.h should only be included in DX9 builds!
#endif  //#if !defined(_DX9)

#include "NiDX9Defines.h"
#include "NiDX9RendererHeaders.h"
#include "NiDX9BltSourceData.h"
#include "NiDX9Error.h"
#include "NiDX9Headers.h"
#include "NiDX9IBManager.h"
#include "NiDX9LightManager.h"
#include "NiDX9MaterialManager.h"
#include "NiDX9PixelFormat.h"
#include "NiDX9PropertyData.h"
#include "NiDX9RenderedCubeMapData.h"
#include "NiDX9RenderedTextureData.h"
#include "NiDX9Renderer.h"
#include "NiDX9RendererLibType.h"
#include "NiDX9RendererSDM.h"
#include "NiDX9RenderState.h"
#include "NiDX9RenderTarget.h"
#include "NiDX9Resource.h"
#include "NiDX9ShaderDeclaration.h"
#include "NiDX9SourceCubeMapData.h"
#include "NiDX9SourceTextureData.h"
#include "NiDX9StringMacros.h"
#include "NiDX9SystemDesc.h"
#include "NiDX9TextureData.h"
#include "NiDX9TextureManager.h"
#include "NiDX9VBManager.h"

#include "NiD3DHLSLPixelShader.h"
#include "NiD3DHLSLVertexShader.h"
#include "NiD3DShaderProgramCreatorHLSL.h"

#endif //#if defined(NI_USE_PCH)

#endif // #ifndef NIDX9RENDERERPCH_H
