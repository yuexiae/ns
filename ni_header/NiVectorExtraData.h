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

#ifndef NIVECTOREXTRADATA_H
#define NIVECTOREXTRADATA_H

#include "NiExtraData.h"
#include "NiPoint3.h"

class NIMAIN_ENTRY NiVectorExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiVectorExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiVectorExtraData(const float* pfVector4);
    NiVectorExtraData(const NiPoint3 kVector3);
    ~NiVectorExtraData ();

    void SetValue(const float* pfVector4);  // 4-tuple accessors
    const float* GetValue() const;

    void SetValue(const NiPoint3 kVector3); // 3-tuple accessors
    const NiPoint3 GetValueVector3() const;

    void SetX(const float fX);  // Component accessors
    void SetY(const float fY);
    void SetZ(const float fZ);
    void SetW(const float fW);
    float GetX() const;
    float GetY() const;
    float GetZ() const;
    float GetW() const;

protected:
    
    NiVectorExtraData();    // Support for streaming

    float m_afVector[4];
};

NiSmartPointer(NiVectorExtraData);
//---------------------------------------------------------------------------
//  Inline include
#include "NiVectorExtraData.inl"

//---------------------------------------------------------------------------

#endif

