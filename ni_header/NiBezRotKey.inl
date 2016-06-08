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
inline NiBezRotKey::NiBezRotKey ()
{
    // for streaming, members will be filled in by LoadBinary
}
//---------------------------------------------------------------------------
inline NiBezRotKey::NiBezRotKey (float fTime, float fAngle,
    const NiPoint3& axis)
    :
    NiRotKey(fTime,fAngle,axis)
{
    // additional members filled in by FillDerivedVals
}
//---------------------------------------------------------------------------
inline NiBezRotKey::NiBezRotKey (float fTime, const NiQuaternion& quat)
    :
    NiRotKey(fTime,quat)
{
    // additional members filled in by FillDerivedVals
}
//---------------------------------------------------------------------------
