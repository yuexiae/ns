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

#ifndef NIINTEGEREXTRADATA_H
#define NIINTEGEREXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiIntegerExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiIntegerExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiIntegerExtraData (const int iValue);
    ~NiIntegerExtraData ();

    void SetValue(const int iValue);
    int GetValue() const;

protected:
    // support for streaming
    NiIntegerExtraData ();

    int m_iValue;
};

NiSmartPointer(NiIntegerExtraData);
//---------------------------------------------------------------------------
//  Inline include
#include "NiIntegerExtraData.inl"

//---------------------------------------------------------------------------

#endif

