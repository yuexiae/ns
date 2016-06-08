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

#include "NiRTLib.h"

//---------------------------------------------------------------------------
inline NiFloatKey::NiFloatKey ()
{
}
//---------------------------------------------------------------------------
inline NiFloatKey::NiFloatKey(float fTime, float fValue)
    :
    NiAnimationKey(fTime)
{
    m_fValue = fValue;
}
//---------------------------------------------------------------------------
inline NiFloatKey::~NiFloatKey ()
{
}
//---------------------------------------------------------------------------
inline void NiFloatKey::SetValue(float fValue)
{
    m_fValue = fValue;
}
//---------------------------------------------------------------------------
inline float NiFloatKey::GetValue() const
{
    return m_fValue;
}
//---------------------------------------------------------------------------
inline float NiFloatKey::ComputeMaxCurvature(NiAnimationKey*, unsigned int)
{
    // function should never be called
    assert (0);
    return 0.0f;
}
//---------------------------------------------------------------------------
inline void NiFloatKey::InterpolateD1(float, const NiAnimationKey*,
    const NiAnimationKey*, void*)
{
    // function should never be called
    assert (0);
}
//---------------------------------------------------------------------------
inline void NiFloatKey::InterpolateD2(float, const NiAnimationKey*,
    const NiAnimationKey*, void*)
{
    // function should never be called
    assert (0);
}
//---------------------------------------------------------------------------
inline void NiFloatKey::FillDerivedVals(NiAnimationKey*, unsigned int, 
    unsigned char)
{
    // This routine should never be called.
    assert(false);
}
//---------------------------------------------------------------------------
inline void NiFloatKey::Copy(NiAnimationKey*, const NiAnimationKey*)
{
    // This routine should never be called.
    assert(false);
}
//---------------------------------------------------------------------------
inline NiAnimationKey* NiFloatKey::CreateArray(unsigned int uiNumKeys)
{
    // This routine should never be called.
    assert(false);
    return 0;
}
//---------------------------------------------------------------------------
inline void NiFloatKey::DeleteArray(NiAnimationKey* pkKeyArray)
{
    // This routine should never be called.
    assert(false);
}
//---------------------------------------------------------------------------
inline NiFloatKey* NiFloatKey::GetKeyAt(unsigned int uiIndex,
                                        unsigned char ucKeySize)
{
    return (NiFloatKey*) NiAnimationKey::GetKeyAt(uiIndex, ucKeySize);
}
//---------------------------------------------------------------------------
inline unsigned char NiFloatKey::GetKeySize(KeyType eType) 
{
     return NiAnimationKey::GetKeySize(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::CreateFunction NiFloatKey::GetCreateFunction(KeyType eType)
{
    return NiAnimationKey::GetCreateFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::InterpFunction NiFloatKey::GetInterpFunction(KeyType eType)
{
    return NiAnimationKey::GetInterpFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::EqualFunction NiFloatKey::GetEqualFunction(KeyType eType)
{
    return NiAnimationKey::GetEqualFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::SaveFunction NiFloatKey::GetSaveFunction(KeyType eType)
{
    return NiAnimationKey::GetSaveFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::FillDerivedValsFunction NiFloatKey::GetFillDerivedFunction(
    KeyType eType)
{
    return NiAnimationKey::GetFillDerivedFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::CopyFunction NiFloatKey::GetCopyFunction(KeyType eType)
{
    return NiAnimationKey::GetCopyFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::ArrayFunction NiFloatKey::GetArrayFunction(KeyType eType)
{
    return NiAnimationKey::GetArrayFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::DeleteFunction NiFloatKey::GetDeleteFunction(KeyType eType)
{
    return NiAnimationKey::GetDeleteFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
inline NiFloatKey::InsertFunction NiFloatKey::GetInsertFunction(KeyType eType)
{
    return NiAnimationKey::GetInsertFunction(FLOATKEY, eType);
}
//---------------------------------------------------------------------------
