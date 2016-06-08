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
inline void NiPSysModifier::UpdateModifier(float fTime, NiPSysData* pkData)
{
    if (m_bActive)
    {
        Update(fTime, pkData);
    }
}
//---------------------------------------------------------------------------
inline const char* NiPSysModifier::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline void NiPSysModifier::SetName(const char* pcName)
{
    assert(pcName);
    delete[] m_pcName;
    m_pcName = new char[strlen(pcName) + 1];
    strcpy(m_pcName, pcName);
}
//---------------------------------------------------------------------------
inline unsigned int NiPSysModifier::GetOrder() const
{
    return m_uiOrder;
}
//---------------------------------------------------------------------------
inline NiParticleSystem* NiPSysModifier::GetSystemPointer() const
{
    return m_pkTarget;
}
//---------------------------------------------------------------------------
inline void NiPSysModifier::SetSystemPointer(NiParticleSystem* pkTarget)
{
    m_pkTarget = pkTarget;
}
//---------------------------------------------------------------------------
inline bool NiPSysModifier::GetActive() const
{
    return m_bActive;
}
//---------------------------------------------------------------------------
inline void NiPSysModifier::SetActive(bool bActive)
{
    m_bActive = bActive;
}
//---------------------------------------------------------------------------
