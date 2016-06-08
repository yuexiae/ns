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

#ifndef NISTRINGSEXTRADATA_H
#define NISTRINGSEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiStringsExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiStringsExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiStringsExtraData(const unsigned int uiSize, const char** ppcValue);
    ~NiStringsExtraData();

    void SetArray(const unsigned int uiSize, const char** ppcValue);
    void GetArray(unsigned int &uiSize, char** &ppcValue) const;

    bool SetValue(const unsigned int uiIndex, char* pcValue);
    char* GetValue(const unsigned int uiIndex) const;

protected:
    // support for streaming
    NiStringsExtraData ();

    unsigned int m_uiSize;
    char** m_ppcValue;
};

NiSmartPointer(NiStringsExtraData);
//---------------------------------------------------------------------------
//  Inline include
#include "NiStringsExtraData.inl"

//---------------------------------------------------------------------------

#endif

