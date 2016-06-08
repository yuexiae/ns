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

#ifndef NISTANDARDSHAREDDATALIBTYPE_H
#define NISTANDARDSHAREDDATALIBTYPE_H

#ifdef NISTANDARDSHAREDDATA_EXPORT
    // DLL library project uses this
    #define NISTANDARDSHAREDDATA_ENTRY __declspec(dllexport)
#else
    // client of DLL uses this
    #define NISTANDARDSHAREDDATA_ENTRY __declspec(dllimport)
#endif

#endif  // #ifndef NISTANDARDSHAREDDATALIBTYPE_H
