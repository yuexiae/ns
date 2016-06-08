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

#ifndef NIBEZFLOATKEY_H
#define NIBEZFLOATKEY_H

#include "NiFloatKey.h"

class NIANIMATION_ENTRY NiBezFloatKey : public NiFloatKey
{
    NiDeclareAnimationStream;
public: 
    // construction
    NiBezFloatKey ();
    NiBezFloatKey (float fTime, float fVal, float fInTan, float fOutTan);
    
    // attributes
    void SetInTan (float fInTan);
    void SetOutTan (float fOutTan);
    float GetInTan () const;
    float GetOutTan () const;

protected:
    float m_fInTan;
    float m_fOutTan;
};

NiRegisterAnimationStream(NiBezFloatKey);

#include "NiBezFloatKey.inl"

#endif

