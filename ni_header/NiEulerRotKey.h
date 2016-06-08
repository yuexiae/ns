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

#ifndef NIEULERROTKEY_H
#define NIEULERROTKEY_H

#include "NiFloatKey.h"
#include "NiRotKey.h"


class NIANIMATION_ENTRY NiEulerRotKey : public NiRotKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiEulerRotKey ();
    ~NiEulerRotKey ();

    NiEulerRotKey (NiFloatKey* pkX, unsigned int uiNumX,
        NiFloatKey::KeyType eTypeX, NiFloatKey* pkY, unsigned int uiNumY,
        NiFloatKey::KeyType eTypeY, NiFloatKey* pkZ, unsigned int uiNumZ, 
        NiFloatKey::KeyType eTypeZ);

    void Initialize (NiFloatKey* pkX, unsigned int uiNumX,
        NiFloatKey::KeyType eTypeX, NiFloatKey* pkY, unsigned int uiNumY,
        NiFloatKey::KeyType eTypeY, NiFloatKey* pkZ, unsigned int uiNumZ, 
        NiFloatKey::KeyType eTypeZ);

    void CleanUp ();

    // attributes
    void SetKeys (unsigned char ucIndex, NiFloatKey* pkKeys);
    void SetNumKeys (unsigned char ucIndex, unsigned int uiNumKeys);
    void SetType (unsigned char ucIndex, NiFloatKey::KeyType eType);
    

    // ReplaceKeys will delete the old key data before setting the new data.
    // SetNumKeys should NOT be called before this function. Instead, the
    // number of keys should be specified here in the uiNumKeys parameter.
    void ReplaceKeys(unsigned char ucIndex, unsigned int uiNumKeys,
        NiFloatKey* pkKeys);

    NiFloatKey* GetKeys (unsigned char ucIndex) const;
    unsigned char GetKeySize(unsigned char ucIndex) const;
    unsigned int GetNumKeys (unsigned char ucIndex) const;
    NiFloatKey::KeyType GetType (unsigned char ucIndex) const;
    
      
protected:
    unsigned int m_uiNumKeys[3];
    NiFloatKey::KeyType m_eType[3];
    unsigned char m_ucSizes[3];

    NiFloatKey* m_apkKeys[3];
    unsigned int m_uiLastIdx[3];
};

NiRegisterAnimationStream(NiEulerRotKey);

#include "NiEulerRotKey.inl"

#endif

