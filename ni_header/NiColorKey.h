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

#ifndef NICOLORKEY_H
#define NICOLORKEY_H

// The NiColorKey represents animation keys whose values are Gamebryo
// NiColorA's.  This class serves as a base class for various specialized
// types of keys.  One might consider making NiColorKey a base class with
// virtual function support, but the presence of virtual functions forces
// each object to have a pointer to the virtual function table.  Since an
// animation typically contains a large number of keys, the additional memory
// for the virtual function table pointers can be a burden to the application.
// The virtual functions for the class are "manually" maintained to avoid
// having virtual function table pointers.  The functions themselves are
// stored as an array whose index is one of the NiColorKey::KeyType
// enumerated values.

#include "NiAnimationKey.h"
#include "NiColor.h"

class NIANIMATION_ENTRY NiColorKey : public NiAnimationKey
{
    NiDeclareAnimationStream;
public:
    ~NiColorKey();

    // attributes
    void SetColor(const NiColorA& color);
    const NiColorA& GetColor() const;

    static NiColorA GenInterp(float fTime, NiColorKey* pkKeys, KeyType eType, 
        unsigned int uiNumKeys, unsigned int& uiLastIdx,
        unsigned char ucSize);

    // *** begin NDL internal use only ***

    NiColorKey* GetKeyAt(unsigned int uiIndex, unsigned char ucKeySize);
    static unsigned char GetKeySize(KeyType eType);
    
    // the interpolation "manual" virtual function
    static InterpFunction GetInterpFunction(KeyType eType);
    static CreateFunction GetCreateFunction(KeyType eType);
    static SaveFunction GetSaveFunction(KeyType eType);
    static EqualFunction GetEqualFunction(KeyType eType);
    static CopyFunction GetCopyFunction(KeyType eType);
    static ArrayFunction GetArrayFunction(KeyType eType);
    static DeleteFunction GetDeleteFunction(KeyType eType);
    static InsertFunction GetInsertFunction(KeyType eType);

    static void SetDefault(const NiColorA& kDefault);

    // *** end NDL internal use only ***

protected:
    NiColorKey();
    NiColorKey(float fTime, const NiColorA& col);

    NiColorA m_Color;

    static NiColorA ms_kDefault;
    static NiColorA GenInterpDefault(float fTime, NiColorKey* pkKeys,
        KeyType eType, unsigned int uiNumKeys, unsigned char ucSize);
};

NiRegisterAnimationStream(NiColorKey);

#include "NiColorKey.inl"

#endif
