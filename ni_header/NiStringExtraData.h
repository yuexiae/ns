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

#ifndef NISTRINGEXTRADATA_H
#define NISTRINGEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiStringExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiStringExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiStringExtraData (const char* pString);
    ~NiStringExtraData ();

    void SetValue(const char* pString);
    const char* GetValue() const;

protected:
    // support for streaming
    NiStringExtraData ();

    char* m_pString;
};

NiSmartPointer(NiStringExtraData);
//---------------------------------------------------------------------------
//  Inline include
#include "NiStringExtraData.inl"

//---------------------------------------------------------------------------

#endif

