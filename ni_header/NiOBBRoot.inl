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
inline NiOBBNode* NiOBBRoot::GetOBBTree ()
{
    return m_pTree;
}
//---------------------------------------------------------------------------
inline void NiOBBRoot::SetDeltaTime (float fDeltaTime)
{
    m_fDeltaTime = fDeltaTime;
}
//---------------------------------------------------------------------------
inline float NiOBBRoot::GetDeltaTime () const
{
    return m_fDeltaTime;
}
//---------------------------------------------------------------------------
inline void NiOBBRoot::SetVelocity (const NiPoint3& velocity)
{
    m_velocity = velocity;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiOBBRoot::GetVelocity () const
{
    return m_velocity;
}
//---------------------------------------------------------------------------
inline void NiOBBRoot::SetChangeStamp (unsigned int uiChangeStamp)
{
    m_uiChangeStamp = uiChangeStamp;
}
//---------------------------------------------------------------------------
inline unsigned int NiOBBRoot::GetChangeStamp () const
{
    return m_uiChangeStamp;
}
//---------------------------------------------------------------------------
