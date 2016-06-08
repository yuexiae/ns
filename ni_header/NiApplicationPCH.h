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

#ifndef NIAPPLICATIONPCH_H
#define NIAPPLICATIONPCH_H

#if defined(NI_USE_PCH)

#include <NiMainPCH.h>
#include <NiInput.h>

#if defined(_XBOX)
    #if defined(_XBOX_PROFILE_BUILD_)
        #pragma message(">>>>>>>>       Xbox Profile Build       <<<<<<<<")
        // Make sure structure packing is set properly
        #pragma pack(push, 8)
        #include <D3D8Perf.h>
        #pragma pack(pop)
    #endif  //#if defined(_XBOX_PROFILE_BUILD_)
#include "NiAppWindow.h"
#include "NiApplication.h"
#include "NiCommand.h"
#include "NiFrameRate.h"
#include "NiTurret.h"
#else   //#if defined(_XBOX)
#include "NiAppWindow.h"
#include "NiApplication.h"
#include "NiCommand.h"
#include "NiDX8Select.h"
#include "NiDX9Select.h"
#include "NiFrameRate.h"
#include "NiTurret.h"
#endif  //#if defined(_XBOX)

#endif //#if defined(NI_USE_PCH)

#endif // #ifndef NIAPPLICATIONPCH_H
