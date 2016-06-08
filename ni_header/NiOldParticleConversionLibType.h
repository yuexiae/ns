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

#ifndef NIOLDPARTICLECONVERSIONLIBTYPE_H
#define NIOLDPARTICLECONVERSIONLIBTYPE_H

#ifdef NIOLDPARTICLECONVERSION_EXPORT
    // DLL library project uses this
    #define NIOLDPARTICLECONVERSION_ENTRY __declspec(dllexport)
#else
#ifdef NIOLDPARTICLECONVERSION_IMPORT
    // client of DLL uses this
    #define NIOLDPARTICLECONVERSION_ENTRY __declspec(dllimport)
#else
    // static library project uses this
    #define NIOLDPARTICLECONVERSION_ENTRY
#endif
#endif

// Disable warning C4251.  Template classes cannot be exported for the obvious
// reason that the code is not generated until an instance of the class is
// declared.  With this warning enabled, you get thousands of complaints about
// class data members that are of template type.  For example, a member such
// as 'NiTArray<NiAVObject*> m_array' generates the warning.
//
// When maintaining the DLL code itself, you might want to enable the warning
// to check for cases where you might have failed to put the
// NIPARTICLE_ENTRY after the class keyword.  In particular, nested classes
// must have NIPARTICLE_ENTRY.  Also, friend functions must be tagged with
// NIPARTICLE_ENTRY.

#ifdef WIN32
    #pragma warning( disable : 4251 )
#endif
                                      
#endif  // #ifndef NIOLDPARTICLECONVERSIONLIBTYPE_H