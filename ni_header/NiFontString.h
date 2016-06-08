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

#ifndef NIFONTSTRING_H
#define NIFONTSTRING_H

#include <NiRTTI.h>
#include <NiRefObject.h>
#include <NiColor.h>

#include "NiFontLibType.h"

NiSmartPointer(NiFont);

class NIFONT_ENTRY NiFontString : public NiRefObject
{
    NiDeclareRootRTTI(NiFontString);

public:
    enum Flags
    {
        COLORED     = 0x00000001,
        CENTERED    = 0x00000002
    };

protected:
    NiFontString(NiFont* pkFont, unsigned int uiFlags,
        unsigned int uiMaxStringLen, const char* pcString,
        const NiColorA& kColor);

public:
    virtual ~NiFontString();

    // Text
    void SetText(const char* pcText, unsigned int uiFlags = 0xffffffff);
    const char* GetText();

    // Color
    void SetColor(const NiColorA& kColor);
    const NiColorA& GetColor() const;

    //*** begin NDL internal use only
    void SplitString();
    void ShutdownString();
    //*** end NDL internal use only

protected:
    NiFontPtr m_spFont;
    unsigned int m_uiFlags;
    unsigned int m_uiMaxStringLen;
    unsigned int m_uiStringLen;
    char* m_pcString;
    NiColorA m_kColor;
    
    // *** begin NDL internal use only *** //
    unsigned int m_uiStringCount;   // Used to handle '\n'
    float m_fStringWidth;
    float m_fStringHeight;
    unsigned int* m_puiStringLens;
    unsigned int* m_puiStringSizes;
    char** m_ppcStrings;

    bool m_bModified;

    // Be careful with threading when using the working string!
    static char ms_acWorkingString[NI_MAX_PATH];

    // *** end NDL internal use only *** //
};

typedef NiPointer<NiFontString> NiFontStringPtr;

#include "NiFontString.inl"

#endif //#ifndef NIFONTSTRING_H
