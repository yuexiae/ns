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
//  NiDynamicEffect inline functions

//---------------------------------------------------------------------------
inline void NiDynamicEffect::SetSwitch(bool bOn)
{
    m_bOn = bOn;
}
//---------------------------------------------------------------------------
inline bool NiDynamicEffect::GetSwitch() const
{
    return m_bOn;
}
//---------------------------------------------------------------------------
inline int NiDynamicEffect::GetIndex() const
{
    return m_iIndex;
}
//---------------------------------------------------------------------------
inline void NiDynamicEffect::IncRevisionID()
{
    m_uiRevID++;
}
//---------------------------------------------------------------------------
inline unsigned int NiDynamicEffect::GetRevisionID() const
{
    return m_uiRevID;
}
//---------------------------------------------------------------------------
inline void NiDynamicEffect:: SetRevisionID(unsigned int uiRevID)
{
    m_uiRevID = uiRevID;
}
//---------------------------------------------------------------------------
inline void NiDynamicEffect::IncPushCount()
{
    m_uiPushCount++;
}
//---------------------------------------------------------------------------
inline void NiDynamicEffect::DecPushCount()
{
    m_uiPushCount--;
}
//---------------------------------------------------------------------------
inline int NiDynamicEffect::GetPushCount() const
{
    return m_uiPushCount;
}
//---------------------------------------------------------------------------
inline const NiNodeList& NiDynamicEffect::GetAffectedNodeList()
{
    return m_kAffectedNodeList;
}
//---------------------------------------------------------------------------
inline const NiNodeList& NiDynamicEffect::GetUnaffectedNodeList()
{
    return m_kUnaffectedNodeList;
}
//---------------------------------------------------------------------------
#ifdef PS2
inline u_long128* NiDynamicEffect::GetRenderData()
{
    return &m_aulRenderData[0];
}
#endif
//---------------------------------------------------------------------------