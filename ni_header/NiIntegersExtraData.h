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

#ifndef NIINTEGERSEXTRADATA_H
#define NIINTEGERSEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiIntegersExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiIntegersExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiIntegersExtraData(const unsigned int uiSize, const int* piValue);
    ~NiIntegersExtraData ();

    void SetArray(const unsigned int uiSize, const int* piValue);
    void GetArray(unsigned int &uiSize, int* &piValue) const;

    bool SetValue(const unsigned int uiIndex, int iValue);
    int GetValue(const unsigned int uiIndex) const;

protected:
    // support for streaming
    NiIntegersExtraData ();

    unsigned int m_uiSize;
    int* m_piValue;
};
NiSmartPointer(NiIntegersExtraData);

//---------------------------------------------------------------------------
//  Inline include
#include "NiIntegersExtraData.inl"

//---------------------------------------------------------------------------

#endif

