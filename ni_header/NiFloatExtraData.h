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

#ifndef NIFLOATEXTRADATA_H
#define NIFLOATEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiFloatExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiFloatExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiFloatExtraData (const float fValue);
    ~NiFloatExtraData ();

    void SetValue (const float fValue);
    float GetValue () const;

protected:
    // support for streaming
    NiFloatExtraData ();

    float m_fValue;
};

NiSmartPointer(NiFloatExtraData);

//---------------------------------------------------------------------------
//  Inline include
#include "NiFloatExtraData.inl"

//---------------------------------------------------------------------------

#endif

