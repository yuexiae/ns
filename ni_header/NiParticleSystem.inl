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
inline void NiParticleSystem::RemoveModifier(NiPSysModifier* pkModifier)
{
    assert(pkModifier && pkModifier->GetName());

    // Remove target of modifier.
    pkModifier->SetSystemPointer(NULL);

    m_kNameToModifierMap.RemoveAt(pkModifier->GetName());
    m_kModifierList.Remove(pkModifier);
}
//---------------------------------------------------------------------------
inline void NiParticleSystem::RemoveModifierByName(const char* pcName)
{
    assert(pcName);

    NiPSysModifier* pkModifier;
    if (m_kNameToModifierMap.GetAt(pcName, pkModifier))
    {
        RemoveModifier(pkModifier);
    }
}
//---------------------------------------------------------------------------
inline NiPSysModifier* NiParticleSystem::GetModifierByName(
    const char* pcName)
{
    assert(pcName);

    NiPSysModifier* pkModifier;
    if (m_kNameToModifierMap.GetAt(pcName, pkModifier))
    {
        return pkModifier;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline unsigned int NiParticleSystem::GetModifierCount() const
{
    return m_kModifierList.GetSize();
}
//---------------------------------------------------------------------------
inline NiPSysModifier* NiParticleSystem::GetModifierAt(unsigned int uiIndex)
{
    if (uiIndex >= m_kModifierList.GetSize())
    {
        return NULL;
    }

    unsigned int uiCount = 0;
    NiTListIterator kIter = m_kModifierList.GetHeadPos();
    while (kIter)
    {
        NiPSysModifier* pkModifier = m_kModifierList.GetNext(kIter);
        if (uiCount++ == uiIndex)
        {
            return pkModifier;
        }
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystem::GetWorldSpace() const
{
    return m_bWorldSpace;
}
//---------------------------------------------------------------------------
inline void NiParticleSystem::SetWorldSpace(bool bWorldSpace)
{
    m_bWorldSpace = bWorldSpace;
}
//---------------------------------------------------------------------------
inline float NiParticleSystem::GetLastTime() const
{
    return m_fLastTime;
}
//---------------------------------------------------------------------------
inline unsigned short NiParticleSystem::GetMaxNumParticles() const
{
    assert(NiIsKindOf(NiPSysData, m_spModelData));
    NiPSysData* pkData = NiSmartPointerCast(NiPSysData, m_spModelData);
    return pkData->GetMaxNumParticles();
}
//---------------------------------------------------------------------------
inline unsigned short NiParticleSystem::GetNumParticles() const
{
    assert(NiIsKindOf(NiPSysData, m_spModelData));
    NiPSysData* pkData = NiSmartPointerCast(NiPSysData, m_spModelData);
    return pkData->GetNumParticles();
}
//---------------------------------------------------------------------------
inline float NiParticleSystem::GetMinBeginKeyTime(NiAVObject* pkScene)
{
    float fMinBeginKeyTime = NI_INFINITY;
    FindMinBeginKeyTimeRecursive(pkScene, fMinBeginKeyTime);
    return fMinBeginKeyTime;
}
//---------------------------------------------------------------------------
inline void NiParticleSystem::ResetParticleSystem()
{
    m_bResetSystem = true;
}
//---------------------------------------------------------------------------
