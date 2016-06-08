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
#ifndef NIPACKERMACROS_H
#define NIPACKERMACROS_H

#include "NiD3DUtils.h"

//---------------------------------------------------------------------------
// Converters to float
//  LONG_TO_FLOAT
//  Assumes that the range will be -1.0 to 1.0
#define NIPACKER_LONG_TO_FLOAT(lIn, fOut)               \
    {                                                   \
        fOut = ((float)(lIn) / 2147483647.0f) - 1.0f;   \
    }

//  ULONG_TO_FLOAT
//  Assumes that the range will be 0.0 to 1.0
#define NIPACKER_ULONG_TO_FLOAT(lIn, fOut)              \
    {                                                   \
        fOut = ((float)(lIn) / 4294967295.0f);          \
    }

//  SHORT_TO_FLOAT
//  Assumes that the range will be -1.0 to 1.0
#define NIPACKER_SHORT_TO_FLOAT(sIn, fOut)              \
    {                                                   \
        fOut = ((float)(sIn) / 32767.0f) - 1.0f;        \
    }

//  USHORT_TO_FLOAT
//  Assumes that the range will be 0.0 to 1.0
#define NIPACKER_USHORT_TO_FLOAT(sIn, fOut)             \
    {                                                   \
        fOut = ((float)(sIn) / 65535.0f);               \
    }

//  BYTE_TO_FLOAT
//  Assumes that the range will be -1.0 to 1.0
#define NIPACKER_BYTE_TO_FLOAT(byIn, fOut)              \
    {                                                   \
        fOut = ((float)(byIn) / 127.0f) - 1.0f;         \
    }

//  UBYTE_TO_FLOAT
//  Assumes that the range will be 0.0 to 1.0
#define NIPACKER_UBYTE_TO_FLOAT(byIn, fOut)             \
    {                                                   \
        fOut = (float)(byIn) / 255.0f;                  \
    }

//---------------------------------------------------------------------------
//  Converters to UBYTECOLOR
#define NIPACKER_FLOAT_TO_UBYTECOLOR(fA, fR, fG, fB, uiOut) \
    {                                                       \
        uiOut =                                             \
            ((FastFloatToInt(fA * 255.0f)) << 24) |         \
            ((FastFloatToInt(fR * 255.0f)) << 16) |         \
            ((FastFloatToInt(fG * 255.0f)) << 8)  |         \
             (FastFloatToInt(fB * 255.0f));                 \
    }

#define NIPACKER_LONG_TO_UBYTECOLOR(lIn, uiOut)             \
    {                                                       \
        uiOut = (unsigned int)lIn;                          \
    }

#define NIPACKER_ULONG_TO_UBYTECOLOR(lIn, uiOut)            \
    {                                                       \
        uiOut = (unsigned int)lIn;                          \
    }

#define NIPACKER_SHORT_TO_UBYTECOLOR(sInA, sInR, sInG, sInB, uiOut)  \
    {                                                           \
        uiOut =                                                 \
            ((((sInA & 0xFF00) >> 4) << 24)     |               \
             (((sInR & 0xFF00) >> 4) << 16)     |               \
             (((sInG & 0xFF00) >> 4) <<  8)     |               \
             (((sInB & 0xFF00) >> 4) <<  0));                   \
    }

#define NIPACKER_USHORT_TO_UBYTECOLOR(sInA, sInR, sInG, sInB, uiOut) \
    {                                                           \
        uiOut =                                                 \
            ((((sInA & 0xFF00) >> 4) << 24)     |               \
             (((sInR & 0xFF00) >> 4) << 16)     |               \
             (((sInG & 0xFF00) >> 4) <<  8)     |               \
             (((sInB & 0xFF00) >> 4) <<  0));                   \
    }

#define NIPACKER_BYTE_TO_UBYTECOLOR(byInA, byInR, byInG, byInB, uiOut)  \
    {                                          \
        uiOut =                                \
            ((byInA << 24)     |               \
             (byInR << 16)     |               \
             (byInG <<  8)     |               \
             (byInB <<  0));                   \
    }

#define NIPACKER_UBYTE_TO_UBYTECOLOR(byInA, byInR, byInG, byInB, uiOut)  \
    {                                          \
        uiOut =                                \
            ((byInA << 24)     |               \
             (byInR << 16)     |               \
             (byInG <<  8)     |               \
             (byInB <<  0));                   \
    }

//---------------------------------------------------------------------------
//  Converters to SHORT
#define NIPACKER_FLOAT_TO_SHORT(fIn, sOut)              \
    {                                                   \
        sOut = (SHORT)fIn;                              \
    }

#define NIPACKER_LONG_TO_SHORT(lIn, sOut)               \
    {                                                   \
        sOut = (SHORT)lIn;                              \
    }

#define NIPACKER_ULONG_TO_SHORT(lIn, sOut)              \
    {                                                   \
        sOut = (SHORT)lIn;                              \
    }

#define NIPACKER_BYTE_TO_SHORT(byIn, sOut)              \
    {                                                   \
        sOut = (SHORT)byIn;                             \
    }

#define NIPACKER_UBYTE_TO_SHORT(byIn, sOut)             \
    {                                                   \
        sOut = (SHORT)byIn;                             \
    }

//---------------------------------------------------------------------------
//  Converters to NORMSHORT
#define NIPACKER_FLOAT_TO_NORMSHORT(fIn, sOut)          \
    {                                                   \
        sOut = (SHORT)fIn;                              \
    }

#define NIPACKER_LONG_TO_NORMSHORT(lIn, sOut)           \
    {                                                   \
        sOut = (SHORT)lIn;                              \
    }

#define NIPACKER_ULONG_TO_NORMSHORT(lIn, sOut)          \
    {                                                   \
        sOut = (SHORT)lIn;                              \
    }

#define NIPACKER_BYTE_TO_NORMSHORT(byIn, sOut)          \
    {                                                   \
        sOut = (SHORT)byIn;                             \
    }

#define NIPACKER_UBYTE_TO_NORMSHORT(byIn, sOut)         \
    {                                                   \
        sOut = (SHORT)byIn;                             \
    }

//---------------------------------------------------------------------------
//  Converters to PACKEDNORM (float to unsigned int)
#define NIPACKER_FLOAT3_TO_NORMPACKED3(f0, f1, f2, uiOut)       \
    {                                                           \
        uiOut = ((DWORD)(((DWORD)(f0 *  511) & 0x3ff) << 22) |  \
                 (DWORD)(((DWORD)(f1 * 1023) & 0x7ff) << 11) |  \
                 (DWORD)(((DWORD)(f2 * 1023) & 0x7ff)));        \
    }

//---------------------------------------------------------------------------
//  Converters to PBYTE (Packed byte)
#define NIPACKER_FLOAT_TO_PBYTE(fIn, byOut)             \
    {                                                   \
        byOut = (BYTE)fIn;                              \
    }

#define NIPACKER_LONG_TO_PBYTE(lIn, byOut)              \
    {                                                   \
        byOut = (BYTE)lIn;                              \
    }

#define NIPACKER_ULONG_TO_PBYTE(lIn, byOut)             \
    {                                                   \
        byOut = (BYTE)lIn;                              \
    }
           
#define NIPACKER_SHORT_TO_PBYTE(sIn, byOut)             \
    {                                                   \
        byOut = (BYTE)sIn;                              \
    }

#define NIPACKER_USHORT_TO_PBYTE(sIn, byOut)            \
    {                                                   \
        byOut = (BYTE)sIn;                              \
    }

//---------------------------------------------------------------------------
//  Converters to UBYTE (Unsigned byte)
#define NIPACKER_FLOAT_TO_UBYTE(fIn, byOut)             \
    {                                                   \
        byOut = (BYTE)fIn;                              \
    }

#define NIPACKER_LONG_TO_UBYTE(lIn, byOut)              \
    {                                                   \
        byOut = (BYTE)lIn;                              \
    }

#define NIPACKER_ULONG_TO_UBYTE(lIn, byOut)             \
    {                                                   \
        byOut = (BYTE)lIn;                              \
    }
           
#define NIPACKER_SHORT_TO_UBYTE(sIn, byOut)             \
    {                                                   \
        byOut = (BYTE)sIn;                              \
    }

#define NIPACKER_USHORT_TO_UBYTE(sIn, byOut)            \
    {                                                   \
        byOut = (BYTE)sIn;                              \
    }

//---------------------------------------------------------------------------
//  Converters to BYTE
#define NIPACKER_FLOAT_TO_BYTE(fIn, ucOut)              \
    {                                                   \
        ucOut = (BYTE)fIn;                              \
    }


//---------------------------------------------------------------------------

#endif  //#ifndef NIPACKERMACROS_H
