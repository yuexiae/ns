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

#ifndef NISTENCILPROPERTY_H
#define NISTENCILPROPERTY_H

#include "NiBool.h"
#include "NiProperty.h"

NiSmartPointer(NiStencilProperty);

class NIMAIN_ENTRY NiStencilProperty : public NiProperty
{
    NiDeclareRTTI;
    NiDeclareClone(NiStencilProperty);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    enum TestFunc
    {
        TEST_NEVER, 
        TEST_LESS, 
        TEST_EQUAL, 
        TEST_LESSEQUAL, 
        TEST_GREATER, 
        TEST_NOTEQUAL, 
        TEST_GREATEREQUAL, 
        TEST_ALWAYS, 
        TEST_MAX 
    };

    enum Action
    {
        ACTION_KEEP,
        ACTION_ZERO,
        ACTION_REPLACE,
        ACTION_INCREMENT,
        ACTION_DECREMENT,
        ACTION_INVERT,
        ACTION_MAX
    };

    enum DrawMode
    {
        DRAW_CCW_OR_BOTH,
        DRAW_CCW,
        DRAW_CW,
        DRAW_BOTH,
        DRAW_MAX
    };

    NiStencilProperty ();
    ~NiStencilProperty ();

    void SetStencilOn(NiBool bOn);
    NiBool GetStencilOn() const;

    void SetStencilFunction(TestFunc eFunc);
    TestFunc GetStencilFunction() const;

    void SetStencilReference(unsigned int uiRef);
    unsigned int GetStencilReference() const;

    void SetStencilMask(unsigned int uiMask);
    unsigned int GetStencilMask() const;

    void SetStencilPassAction(Action eAct);
    Action GetStencilPassAction() const;

    void SetStencilPassZFailAction(Action eAct);
    Action GetStencilPassZFailAction() const;

    void SetStencilFailAction(Action eAct);
    Action GetStencilFailAction() const;

    void SetDrawMode(DrawMode eDraw);
    DrawMode GetDrawMode() const;

    bool IsEqualFast(const NiStencilProperty& prop) const;

    virtual int Type () const;
    static int GetType ();
    static NiStencilProperty *GetDefault ();

    // *** begin NDL internal use only ***

    static void _SDMInit();
    static void _SDMShutdown();

    // streaming support
    static char* GetViewerString (const char* pPrefix, TestFunc eFunc);
    static char* GetViewerString (const char* pPrefix, Action eAct);
    static char* GetViewerString (const char* pPrefix, DrawMode eMode);


    // *** end NDL internal use only ***

protected:

    NiBool m_bEnable;
    TestFunc m_eTest;
    
    unsigned int m_uiRef;
    unsigned int m_uiMask;

    Action m_eFailAct;
    Action m_eZFailAct;
    Action m_ePassAct;

    DrawMode m_eDrawMode;

    static NiStencilPropertyPtr ms_spDefault;
};


typedef NiPointer<NiStencilProperty> NiStencilPropertyPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiStencilProperty.inl"

//---------------------------------------------------------------------------

#endif

