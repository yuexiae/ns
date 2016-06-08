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

#ifndef NITEXTKEY_H
#define NITEXTKEY_H

#include "NiAnimationLibType.h"
#include "NiBool.h"
class NiStream;

class NIANIMATION_ENTRY NiTextKey
{
public:
    // construction and destruction
    NiTextKey ();
    NiTextKey (float fTime, char* pText);
    ~NiTextKey();    

    // attributes
    void SetTime (float fTime); 
    float GetTime () const;

    void SetText (char *pText);
    char* GetText () const;


    // *** begin NDL internal use only ***

    // copying
    NiTextKey *Copy ();

    // comparison
    bool operator== (const NiTextKey& key);
    bool operator!= (const NiTextKey& key);

    // streaming
    void LoadBinary (NiStream &stream);
    void SaveBinary (NiStream &stream);

    // *** end NDL internal use only ***

protected:
    float m_fTime;
    char* m_pText;
};

#include "NiTextKey.inl"

#endif
