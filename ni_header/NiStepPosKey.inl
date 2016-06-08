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

//---------------------------------------------------------------------------
inline NiStepPosKey::NiStepPosKey ()
{
}
//---------------------------------------------------------------------------
inline NiStepPosKey::NiStepPosKey (float fTime, const NiPoint3& pos)
    :
    NiPosKey(fTime,pos)
{
}
//---------------------------------------------------------------------------
inline bool NiStepPosKey::Equal(const NiAnimationKey& key0, 
    const NiAnimationKey& key1)
{
    return NiPosKey::Equal(key0,key1);
}
//---------------------------------------------------------------------------
inline void NiStepPosKey::FillDerivedVals (NiAnimationKey*, unsigned int,
    unsigned char)
{
    // no derived values to fill in
}
//---------------------------------------------------------------------------
