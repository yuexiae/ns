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

#ifndef NIVERSION_H
#define NIVERSION_H

// VERSION NUMBERS (to be changed by NDL Developers only)
#define NI_MAJOR_VERSION 10
#define NI_MINOR_VERSION 2
#define NI_PATCH_VERSION 0
#define NI_INTERNAL_VERSION 0

// Without the extra level of macro indirection, GAMEBRYOVERSION would
// end up containing the names of the NI_*_VERSION macros instead of their
// values.
#define NI_STR2(A) #A
#define NI_STR(B) NI_STR2(B)

#define GAMEBRYOVERSION NI_STR(NI_MAJOR_VERSION) "." \
    NI_STR(NI_MINOR_VERSION) "." NI_STR(NI_PATCH_VERSION) "." \
    NI_STR(NI_INTERNAL_VERSION)

#define GAMEBRYOVERSIONSTRING(module) \
    #module" Gamebryo Version "GAMEBRYOVERSION

#endif

