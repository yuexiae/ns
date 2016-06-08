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

#ifndef NIFLOATKEY_H
#define NIFLOATKEY_H

// The NiFloatKey represents animation keys whose values are floating point
// numbers.  This class serves as a base class for various specialized types
// of keys.  One might consider making NiFloatKey a base class with virtual
// function support, but the presence of virtual functions forces each object
// to have a pointer to the virtual function table.  Since an animation
// typically contains a large number of keys, the additional memory for the
// virtual function table pointers can be a burden to the application.  The
// virtual functions for the class are "manually" maintained to avoid having
// virtual function table pointers.  The functions themselves are stored as
// an array whose index is one of the NiFloatKey::KeyType enumerated values.

#include "NiAnimationKey.h"

class NIANIMATION_ENTRY NiFloatKey : public NiAnimationKey
{
    NiDeclareAnimationStream;
public:
    ~NiFloatKey();

    // attributes
    void SetValue(float fValue);
    float GetValue() const;

    static float GenInterp(float fTime, NiFloatKey* pkKeys,
        KeyType eType, unsigned int uiNumKeys, unsigned int& uiLastIdx,
        unsigned char ucSize);
    
    // *** begin NDL internal use only ***

    NiFloatKey* GetKeyAt(unsigned int uiIndex, unsigned char ucKeySize);
    static unsigned char GetKeySize(KeyType eType);
    
    static CreateFunction GetCreateFunction(KeyType eType);
    static InterpFunction GetInterpFunction(KeyType eType);
    static EqualFunction GetEqualFunction(KeyType eType);
    static SaveFunction GetSaveFunction(KeyType eType);
    static CopyFunction GetCopyFunction(KeyType eType);
    static ArrayFunction GetArrayFunction(KeyType eType);
    static DeleteFunction GetDeleteFunction(KeyType eType);
    static InsertFunction GetInsertFunction(KeyType eType);
    static FillDerivedValsFunction GetFillDerivedFunction(KeyType eType);

    static void SetDefault(float fDefault);

    // *** end NDL internal use only ***

protected:
    NiFloatKey();
    NiFloatKey(float fTime, float fValue);

    float m_fValue;

    static float ms_fDefault;
    static float GenInterpDefault(float fTime, NiFloatKey* pkKeys,
        KeyType eType, unsigned int uiNumKeys, unsigned char ucSize);
};

NiRegisterAnimationStream(NiFloatKey);

#include "NiFloatKey.inl"

#endif
