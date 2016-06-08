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

#ifndef NITRANSFORM_H
#define NITRANSFORM_H

#include "NiMatrix3.h"
#include "NiPoint3.h"

class NIMAIN_ENTRY NiTransform
{
public:
    // NOTE: Variable declaration order effects assembly language code.
    // Do not change.
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;

    void MakeIdentity();
    bool operator!=(const NiTransform &xform) const;
    NiTransform operator*(const NiTransform &xform) const;
    void Invert(NiTransform& kDest) const;
    NiPoint3 operator*(const NiPoint3 &kPoint) const;

    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);

    // *** end NDL internal use only ***
};

#include "NiTransform.inl"

#endif // NITRANSFORM_H
