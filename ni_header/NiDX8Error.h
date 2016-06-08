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
//---------------------------------------------------------------------------
#ifndef NIDX8ERROR_H
#define NIDX8ERROR_H

//  The IndexBuffer manager is responsible for giving out and tracking index
//  buffers required by the application.
#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"

char* NiDX8ErrorString(unsigned int uiErrorCode);

#endif  //#ifndef NIDX8ERROR_H
