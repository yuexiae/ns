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
inline NiRotKey::NiRotKey ()
    :
    m_quat(0.0f,0.0f,0.0f,0.0f)
{
}
//---------------------------------------------------------------------------
inline NiRotKey::NiRotKey (float fTime, const NiQuaternion& quat)
    :
    NiAnimationKey(fTime),
    m_quat(quat)
{
}
//---------------------------------------------------------------------------
inline NiRotKey::NiRotKey (float fTime, float fAngle, const NiPoint3& axis)
    :
    NiAnimationKey(fTime),
    m_quat(fAngle, axis)
{
}
//---------------------------------------------------------------------------
inline void NiRotKey::SetQuaternion (const NiQuaternion& quat)
{
    m_quat = quat;
}
//---------------------------------------------------------------------------
inline const NiQuaternion& NiRotKey::GetQuaternion () const
{
    return m_quat;
}
//---------------------------------------------------------------------------
inline void NiRotKey::Copy (NiAnimationKey*, const NiAnimationKey*)
{
    // This routine should never be called.
    assert(false);
}
//---------------------------------------------------------------------------
inline NiAnimationKey* NiRotKey::CreateArray(unsigned int uiNumKeys)
{
    // This routine should never be called.
    assert(false);
    return 0;
}
//---------------------------------------------------------------------------
inline void NiRotKey::DeleteArray(NiAnimationKey* pkKeyArray)
{
    // This routine should never be called.
    assert(false);
}
//---------------------------------------------------------------------------
inline void NiRotKey::InterpolateD1 (float, const NiAnimationKey*, 
    const NiAnimationKey*, void* pResult)
{
    // This routine should never be called.
    assert( false );
    *(NiQuaternion*)pResult = NiQuaternion::IDENTITY;
}
//---------------------------------------------------------------------------
inline void NiRotKey::InterpolateD2 (float, const NiAnimationKey*, 
    const NiAnimationKey*, void* pResult)
{
    // This routine should never be called.
    assert( false );
    *(NiQuaternion*)pResult = NiQuaternion::IDENTITY;
}
//---------------------------------------------------------------------------
inline float NiRotKey::ComputeMaxCurvature (NiAnimationKey*, unsigned int)
{
    // This routine should never be called.
    assert( false );
    return 0.0f;
}
//---------------------------------------------------------------------------
inline NiRotKey* NiRotKey::GetKeyAt(unsigned int uiIndex, unsigned char
    ucKeySize)
{
    return (NiRotKey*) NiAnimationKey::GetKeyAt(uiIndex, ucKeySize);
}
//---------------------------------------------------------------------------
inline unsigned char NiRotKey::GetKeySize(KeyType eType) 
{
     return NiAnimationKey::GetKeySize(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::CreateFunction NiRotKey::GetCreateFunction (KeyType eType)
{
    return NiAnimationKey::GetCreateFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::InterpFunction NiRotKey::GetInterpFunction (KeyType eType)
{
    return NiAnimationKey::GetInterpFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::FillDerivedValsFunction NiRotKey::GetFillDerivedFunction (
    KeyType eType)
{
    return NiAnimationKey::GetFillDerivedFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::SaveFunction NiRotKey::GetSaveFunction (KeyType eType)
{
    return NiAnimationKey::GetSaveFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::EqualFunction NiRotKey::GetEqualFunction (KeyType eType)
{
    return NiAnimationKey::GetEqualFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::CopyFunction NiRotKey::GetCopyFunction (KeyType eType)
{
    return NiAnimationKey::GetCopyFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::ArrayFunction NiRotKey::GetArrayFunction (KeyType eType)
{
    return NiAnimationKey::GetArrayFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::DeleteFunction NiRotKey::GetDeleteFunction (KeyType eType)
{
    return NiAnimationKey::GetDeleteFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
inline NiRotKey::InsertFunction NiRotKey::GetInsertFunction (KeyType eType)
{
    return NiAnimationKey::GetInsertFunction(ROTKEY, eType);
}
//---------------------------------------------------------------------------
