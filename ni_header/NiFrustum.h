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

#ifndef NIFRUSTUM_H
#define NIFRUSTUM_H

#include "NiMainLibType.h"

// view frustum and view port
class NIMAIN_ENTRY NiFrustum
{
public:
    NiFrustum(bool bOrtho = false);
    NiFrustum(float fLeft, float fRight, float fTop,
        float fBottom, float fNear, float fFar,
        bool bOrtho = false);

    float m_fLeft;
    float m_fRight;
    float m_fTop;
    float m_fBottom;
    float m_fNear;
    float m_fFar;
    bool  m_bOrtho;

    char* GetViewerString(const char* pcPrefix) const;
};

#endif
