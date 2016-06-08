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
//
// Code based on assert section out of Game Programming Gems
// Some portion of code may be Copyrighted (C) Steve Rabin, 2000

#ifndef NIASSERT_H
#define NIASSERT_H

extern bool* g_pbIgnoreAlways;

extern bool NiAssertFn( const char *pcExp, const char *pcDesc, int iLine,
    const char *pcFile, bool *bIgnoreAlways );

#ifdef ONLY_LOG_ON_ASSERT
#define BreakOnNiASSERT 0
#else
#define BreakOnNiASSERT 1
#endif

//---------------------------------------------------------------------------
#ifdef WIN32

#if defined(_DEBUG) || defined(EVAL_RELEASE)

#define NiASSERT( exp ) \
{ \
    static bool s_bIgnoreAlways = false; \
    if( !s_bIgnoreAlways && !( exp ) ) \
    { \
        if( NiAssertFn( #exp, 0, __LINE__, __FILE__, &s_bIgnoreAlways )) \
        { \
            g_pbIgnoreAlways = &s_bIgnoreAlways; \
            if (BreakOnNiASSERT) \
                _asm { int 3 } \
        } \
    } \
}

#define NiASSERTM( exp, desc ) \
{ \
    static bool s_bIgnoreAlways = false; \
    if( !s_bIgnoreAlways && !( exp ) ) \
    { \
        if( NiAssertFn( #exp, desc, __LINE__, __FILE__, &s_bIgnoreAlways ) ) \
        { \
            g_pbIgnoreAlways = &s_bIgnoreAlways; \
            if (BreakOnNiASSERT) \
                _asm { int 3 } \
        } \
    } \
}
#else   // #else not _DEBUG and not EVAL_RELEASE
#define NiASSERT( exp )
#define NiASSERTM( exp, msg )
#endif // #endif _DEBUG or EVAL_RELEASE
//---------------------------------------------------------------------------
#else // #else not WIN32
#if defined(_DEBUG) || defined(EVAL_RELEASE)
#define NiASSERT( exp ) \
{ \
    static bool s_bIgnoreAlways = false; \
    if( !s_bIgnoreAlways && !( exp ) ) \
    { \
        if( NiAssertFn( #exp, 0, __LINE__, __FILE__, &s_bIgnoreAlways ) ) \
        { \
            g_pbIgnoreAlways = &s_bIgnoreAlways; \
        } \
    } \
}

#define NiASSERTM( exp, desc ) \
{ \
    static bool s_bIgnoreAlways = false; \
    if( !s_bIgnoreAlways && !( exp ) ) \
    { \
        if( NiAssertFn( #exp, desc, __LINE__, __FILE__, &s_bIgnoreAlways ) ) \
        { \
            g_pbIgnoreAlways = &s_bIgnoreAlways; \
        } \
    } \
}
#else   // #else not _DEBUG and not EVAL_RELEASE
#define NiASSERT( exp )
#define NiASSERTM( exp, msg )
#endif // #endif _DEBUG or EVAL_RELEASE
//---------------------------------------------------------------------------
#endif // #endif WIN32

#endif