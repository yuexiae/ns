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
inline const char* NiPSysModifierCtlr::GetModifierName() const
{
    return m_pcModifierName;
}
//---------------------------------------------------------------------------
inline NiPSysModifier* NiPSysModifierCtlr::GetModifierPointer() const
{
    return m_pkModifier;
}
//---------------------------------------------------------------------------
inline void NiPSysModifierCtlr::GetModifierPointerFromName()
{
    assert(m_pTarget && m_pcModifierName);
    m_pkModifier = ((NiParticleSystem*) m_pTarget)->GetModifierByName(
        m_pcModifierName);
    assert(m_pkModifier);
}
//---------------------------------------------------------------------------
inline void NiPSysModifierCtlr::SetModifierName(const char* pcName)
{
    assert(pcName);
    delete[] m_pcModifierName;
    m_pcModifierName = new char[strlen(pcName) + 1];
    strcpy(m_pcModifierName, pcName);
}
//---------------------------------------------------------------------------
