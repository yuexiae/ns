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

#ifndef NIPLUGINTOOLKITLIBTYPE_H
#define NIPLUGINTOOLKITLIBTYPE_H

#ifdef NIPLUGINTOOLKIT_EXPORT
    // DLL library project uses this
    #define NIPLUGINTOOLKIT_ENTRY __declspec(dllexport)
#else
    // client of DLL uses this
    #define NIPLUGINTOOLKIT_ENTRY __declspec(dllimport)
#endif

#ifdef WIN32
    #pragma warning( disable : 4786 )
#endif            

#endif  // #ifndef NIPLUGINTOOLKITLIBTYPE_H
