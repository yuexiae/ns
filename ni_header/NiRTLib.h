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

#ifndef NIRTLIB_H
#define NIRTLIB_H


// WIN32 system headers demote/disable some useful warnings, so push
// warning state here and pop it at after includes.
#pragma warning(push, 3)

#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <io.h>
#include <sys/stat.h>

#pragma warning(pop)

#define NI_DATA_ALIGMENT(size)

#include "NiMemManager.h"

#endif // NIRTLIB_H
