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

#ifndef NIZBUFFERPROPERTY_H
#define NIZBUFFERPROPERTY_H

#include "NiProperty.h"
#include "NiFlags.h"

NiSmartPointer(NiZBufferProperty);

class NIMAIN_ENTRY NiZBufferProperty : public NiProperty
{
    NiDeclareRTTI;
    NiDeclareClone(NiZBufferProperty);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    NiZBufferProperty();

    enum TestFunction
    {
        TEST_ALWAYS,
        TEST_LESS,
        TEST_EQUAL,
        TEST_LESSEQUAL,
        TEST_GREATER,
        TEST_NOTEQUAL,
        TEST_GREATEREQUAL,
        TEST_NEVER,
      
        TEST_MAX_MODES
    };

    void SetZBufferTest(bool bZBufferTest);
    bool GetZBufferTest() const;
    void SetZBufferWrite(bool bZBufferWrite);
    bool GetZBufferWrite() const;
    void SetTestFunction(TestFunction eTest);
    TestFunction GetTestFunction() const;

    bool IsEqualFast(const NiZBufferProperty& kProp) const;

    virtual int Type() const;
    static int GetType();
    static NiZBufferProperty* GetDefault();

    // *** begin NDL internal use only ***

    static void _SDMInit();
    static void _SDMShutdown();

    // *** end NDL internal use only ***
    
protected:
    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 2
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        ZBUFFERTEST_MASK    = 0x0001,
        ZBUFFERWRITE_MASK   = 0x0002
    };

    TestFunction m_eTest;

    static NiZBufferPropertyPtr ms_spDefault;
};

#include "NiZBufferProperty.inl"

#endif

