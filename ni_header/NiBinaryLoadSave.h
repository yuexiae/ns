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

#ifndef NIBINARYLOADSAVE_H
#define NIBINARYLOADSAVE_H

#include "NiRTLib.h"
#include "NiBinaryStream.h"
#include "NiSystemLibType.h"

//---------------------------------------------------------------------------
// Inline load/save routines for native data.
//---------------------------------------------------------------------------
template <class T>
void NiBinaryStreamLoad (NiBinaryStream& is, T* pValue, 
    unsigned int uiNumEls = 1)
{
    if (uiNumEls == 0)
    {
        
    }
    assert(uiNumEls > 0);

    // If not on a mac, just do the simple read
    is.Read(pValue, sizeof(T) * uiNumEls);
}

//---------------------------------------------------------------------------
template <class T>
void NiBinaryStreamLoadEnum (NiBinaryStream& is, T* pValue)
{
    int iDummy;
    is.Read(&iDummy, sizeof(int));
    *pValue = (T)iDummy;
}

//---------------------------------------------------------------------------
template <class T>
void NiBinaryStreamSave (NiBinaryStream& os, const T* pValue,
    unsigned int uiNumEls = 1)
{
    assert(uiNumEls != 0);
    os.Write(pValue, sizeof(T) * uiNumEls);
}

//---------------------------------------------------------------------------
template <class T>
void NiBinaryStreamSaveEnum (NiBinaryStream& os, const T& value)
{
    os.Write(&value, sizeof(int)); // just do the write
}

#endif // NIBINARYLOADSAVE_H