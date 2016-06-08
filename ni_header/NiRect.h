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

#ifndef NIRECT_H
#define NIRECT_H

#include "NiStream.h"

template <class T> class NiRect
{
public:
    NiRect (T left = T(0), T right = T(0), T top = T(0), T bottom = T(0))
    {
        m_left = left;
        m_right = right;
        m_top = top;
        m_bottom = bottom;
    }

    T m_left, m_right, m_top, m_bottom;

    // streaming
    void LoadBinary (NiStream& stream);
    void SaveBinary (NiStream& stream);
    char* GetViewerString (const char* pPrefix) const;
};

//---------------------------------------------------------------------------
//  Inline include
#include "NiRect.inl"

//---------------------------------------------------------------------------

#endif

