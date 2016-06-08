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

#ifndef NISHADERTOOLKITLIBTYPE_H
#define NISHADERTOOLKITLIBTYPE_H

#ifdef NISHADERTOOLKIT_EXPORT
    // DLL library project uses this
    #define NISHADERTOOLKIT_ENTRY __declspec(dllexport)
#elif defined(NISHADERTOOLKIT_IMPORT)
    // client of DLL uses this
    #define NISHADERTOOLKIT_ENTRY __declspec(dllimport)
#else
#error NISHADERTOOLKIT_EXPORT or NISHADERTOOLKIT_IMPORT must be defined.
#endif

#endif  // #ifndef NISHADERTOOLKITLIBTYPE_H
