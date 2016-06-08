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

#ifndef NIBOOLEANEXTRADATA_H
#define NIBOOLEANEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiBooleanExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiBooleanExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBooleanExtraData (const bool bValue);
    ~NiBooleanExtraData ();

    void SetValue(const bool bValue);
    bool GetValue() const;

protected:
    // support for streaming
    NiBooleanExtraData ();

    bool m_bValue;
};

NiSmartPointer(NiBooleanExtraData);

//---------------------------------------------------------------------------
//  Inline include
#include "NiBooleanExtraData.inl"

//---------------------------------------------------------------------------

#endif

