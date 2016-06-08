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

#ifndef NIBINARYEXTRADATA_H
#define NIBINARYEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiBinaryExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiBinaryExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBinaryExtraData(const unsigned int uiSize, char* pcBinaryData);
    ~NiBinaryExtraData();

    void SetValue(const unsigned int uiSize, char* pcBinaryData);
    void GetValue(unsigned int &uiSize, char* &pcBinaryData) const;

protected:
    // support for streaming
    NiBinaryExtraData();

    char* m_pcBinaryData;
    unsigned int m_uiSize;
};

NiSmartPointer(NiBinaryExtraData);
//---------------------------------------------------------------------------
//  Inline include
#include "NiBinaryExtraData.inl"

//---------------------------------------------------------------------------

#endif

