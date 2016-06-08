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

#ifndef NID3DRENDERERPCH_H
#define NID3DRENDERERPCH_H

#if defined(NI_USE_PCH)

#include <NiMainPCH.h>

#if defined(_DX8)
    #include "NiDX8RendererPCH.h"
#elif defined(_DX9)
    #include "NiDX9RendererPCH.h"
#elif defined(_XENON)
    #include "NiXenonRendererPCH.h"
#elif defined(_XBOX)
    #include "NiXBoxRendererPCH.h"
#endif

#include "NiD3DController.h"
#include "NiD3DDefaultShader.h"
#include "NiD3DDefines.h"
#include "NiD3DError.h"
#include "NiD3DGeometryGroupManager.h"
#include "NiD3DGlobalConstantEntry.h"
#include "NiD3DMacros.h"
#include "NiD3DPass.h"
#include "NiD3DPixelShader.h"
#include "NiD3DRendererHeaders.h"
#include "NiD3DRenderState.h"
#include "NiD3DRenderStateGroup.h"
#include "NiD3DSCM_Pixel.h"
#include "NiD3DSCM_Vertex.h"
#include "NiD3DShader.h"
#include "NiD3DShaderConstantManager.h"
#include "NiD3DShaderConstantMap.h"
#include "NiD3DShaderConstantMapEntry.h"
#include "NiD3DShaderDeclaration.h"
#include "NiD3DShaderFactory.h"
#include "NiD3DShaderInterface.h"
#include "NiD3DShaderLibrary.h"
#include "NiD3DShaderLibraryInterface.h"
#include "NiD3DShaderLibraryVersion.h"
#include "NiD3DShaderProgram.h"
#include "NiD3DShaderProgramCreator.h"
#include "NiD3DShaderProgramCreatorAsm.h"
#include "NiD3DShaderProgramCreatorObj.h"
#include "NiD3DShaderProgramFactory.h"
#include "NiD3DTextureStage.h"
#include "NiD3DTextureStageGroup.h"
#include "NiD3DTimeSyncController.h"
#include "NiD3DUtility.h"
#include "NiD3DUtils.h"
#include "NiD3DVertexShader.h"
#include "NiDynamicGeometryGroup.h"
#include "NiGeometryBufferData.h"
#include "NiGeometryGroup.h"
#include "NiPackerMacros.h"
#include "NiRendererExtraData.h"
#include "NiStaticGeometryGroup.h"
#include "NiUnsharedGeometryGroup.h"
#include "NiVBBlock.h"
#include "NiVBChip.h"
#include "NiVBDynamicSet.h"
#include "NiVBSet.h"

#endif //#if defined(NI_USE_PCH)

#endif // #ifndef NID3DRENDERERPCH_H
