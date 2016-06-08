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

#ifndef NISTRINGPALETTE_H
#define NISTRINGPALETTE_H

#include "NiAnimationLibType.h"
#include <NiObject.h>

class NIANIMATION_ENTRY NiStringPalette : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;

public:
    NiStringPalette(unsigned int uiAllocatedSize);
    ~NiStringPalette();

    char* GetBasePointer() const;
    unsigned int AddString(const char* pcString);

protected:
    // For streaming only.
    NiStringPalette();

    void ReallocateBuffer();

    char* m_pcBuffer;
    unsigned int m_uiAllocatedSize;
    unsigned int m_uiEndOfBuffer;
};

NiSmartPointer(NiStringPalette);

#include "NiStringPalette.inl"

#endif  // #ifndef NISTRINGPALETTE_H
