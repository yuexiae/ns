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

#ifndef NIAUDIOLIBTYPE_H
#define NIAUDIOLIBTYPE_H

#include <NiOS.h>

#ifdef NIAUDIO_EXPORT
    // DLL library project uses this
    #define NIAUDIO_ENTRY __declspec(dllexport)
#else
#ifdef NIAUDIO_IMPORT
    // client of DLL uses this
    #define NIAUDIO_ENTRY __declspec(dllimport)
#else
    // static library project uses this
    #define NIAUDIO_ENTRY
#endif
#endif

// Disable warning C4251.  Template classes cannot be exported for the obvious
// reason that the code is not generated until an instance of the class is
// declared.  With this warning enabled, you get thousands of complaints about
// class data members that are of template type.  For example, a member such
// as 'NiTArray<NiAVObject*> m_array' generates the warning.
#pragma warning( disable : 4251 )
                                      
#endif
