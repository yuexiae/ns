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

#ifndef NIDX8RENDERERPCH_H
#define NIDX8RENDERERPCH_H

#if defined(NI_USE_PCH)

#if !defined(_DX8)
#error NiDX8RendererPCH.h should only be included in DX8 builds!
#endif  //#if !defined(_DX8)

#include "NiDX8Defines.h"
#include "NiDX8RendererHeaders.h"
#include "NiDX8BltSourceData.h"
#include "NiDX8Error.h"
#include "NiDX8Headers.h"
#include "NiDX8IBManager.h"
#include "NiDX8LightManager.h"
#include "NiDX8MaterialManager.h"
#include "NiDX8PixelFormat.h"
#include "NiDX8PropertyData.h"
#include "NiDX8RenderedCubeMapData.h"
#include "NiDX8RenderedTextureData.h"
#include "NiDX8Renderer.h"
#include "NiDX8RendererLibType.h"
#include "NiDX8RendererSDM.h"
#include "NiDX8RenderState.h"
#include "NiDX8RenderTarget.h"
#include "NiDX8Resource.h"
#include "NiDX8ShaderDeclaration.h"
#include "NiDX8SourceCubeMapData.h"
#include "NiDX8SourceTextureData.h"
#include "NiDX8StringMacros.h"
#include "NiDX8SystemDesc.h"
#include "NiDX8TextureData.h"
#include "NiDX8TextureManager.h"
#include "NiDX8VBManager.h"

#endif //#if defined(NI_USE_PCH)

#endif // #ifndef NIDX8RENDERERPCH_H
