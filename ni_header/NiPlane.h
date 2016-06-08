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

#ifndef NIPLANE_H
#define NIPLANE_H

#include "NiPoint3.h"
#include "NiTArray.h"
#include "NiStream.h"

class NIMAIN_ENTRY NiPlane
{
public:
    enum {NO_SIDE, POSITIVE_SIDE, NEGATIVE_SIDE};

    NiPlane();
    NiPlane(const NiPoint3& kNormal, float fConstant);
    NiPlane(const NiPoint3& kNormal, const NiPoint3& kPoint);
    NiPlane(const NiPoint3& kP0, const NiPoint3& kP1, const NiPoint3& kP2);

    bool operator==(const NiPlane& kPlane);
    bool operator!=(const NiPlane& kPlane);

    void SetNormal(const NiPoint3& kNormal);
    const NiPoint3& GetNormal() const;
    void SetConstant(float fConstant);
    float GetConstant() const;

    float Distance(const NiPoint3& kPoint) const;
    int WhichSide(const NiPoint3& kPoint) const;

    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    char* GetViewerString(const char* pcPrefix) const;

    // kPlane is m_kNormal*(x,y,z) = m_fConstant
    NiPoint3 m_kNormal;
    float m_fConstant;

    // *** end NDL internal use only ***
} NI_DATA_ALIGMENT(16);

typedef NiTArray<NiPlane*> NiPlaneArray;

//---------------------------------------------------------------------------
//  Inline include
#include "NiPlane.inl"

//---------------------------------------------------------------------------

#endif

