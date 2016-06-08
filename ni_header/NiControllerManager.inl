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
inline unsigned int NiControllerManager::GetSequenceCount() const
{
    return m_kSequenceArray.GetSize();
}
//---------------------------------------------------------------------------
inline NiControllerSequence* NiControllerManager::GetSequenceByName(
    const char* pcName)
{
    assert(pcName);

    unsigned int uiIndex;
    if (m_kIndexMap.GetAt(pcName, uiIndex))
    {
        return m_kSequenceArray.GetAt(uiIndex);
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiControllerSequence* NiControllerManager::GetSequenceAt(
    unsigned int uiIndex)
{
    assert(uiIndex < m_kSequenceArray.GetSize());
    return m_kSequenceArray.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::ActivateSequence(const char* pcSequenceName,
    int iPriority, bool bStartOver, float fWeight, float fEaseInTime,
    NiControllerSequence* pkTimeSyncSeq)
{
    assert(pcSequenceName);

    unsigned int uiIndex;
    if (m_kIndexMap.GetAt(pcSequenceName, uiIndex))
    {
        return ActivateSequence(m_kSequenceArray.GetAt(uiIndex), iPriority,
            bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq);
    }

    return false;
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::ActivateSequence(
    NiControllerSequence* pkSequence, int iPriority, bool bStartOver,
    float fWeight, float fEaseInTime, NiControllerSequence* pkTimeSyncSeq)
{
    assert(pkSequence && pkSequence->GetOwner() == this);
    return pkSequence->Activate(iPriority, bStartOver, fWeight, fEaseInTime,
        pkTimeSyncSeq);
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::DeactivateSequence(
    const char* pcSequenceName, float fEaseOutTime)
{
    assert(pcSequenceName);

    unsigned int uiIndex;
    if (m_kIndexMap.GetAt(pcSequenceName, uiIndex))
    {
        return DeactivateSequence(m_kSequenceArray.GetAt(uiIndex),
            fEaseOutTime);
    }

    return false;
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::DeactivateSequence(
    NiControllerSequence* pkSequence, float fEaseOutTime)
{
    assert(pkSequence && pkSequence->GetOwner() == this);
    return pkSequence->Deactivate(fEaseOutTime);
}
//---------------------------------------------------------------------------
inline void NiControllerManager::DeactivateAll(float fEaseOutTime)
{
    for (unsigned int ui = 0; ui < m_kSequenceArray.GetSize(); ui++)
    {
        NiControllerSequence* pkSequence = m_kSequenceArray.GetAt(ui);
        if (pkSequence)
        {
            DeactivateSequence(pkSequence, fEaseOutTime);
        }
    }
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::SetSequenceWeight(const char* pcSequenceName,
    float fWeight)
{
    assert(pcSequenceName);

    unsigned int uiIndex;
    if (m_kIndexMap.GetAt(pcSequenceName, uiIndex))
    {
        return SetSequenceWeight(m_kSequenceArray.GetAt(uiIndex), fWeight);
    }

    return false;
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::SetSequenceWeight(
    NiControllerSequence* pkSequence, float fWeight)
{
    assert(pkSequence && pkSequence->GetOwner() == this);
    pkSequence->SetSequenceWeight(fWeight);
    return true;
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::BlendFromSequence(
    NiControllerSequence* pkSourceSequence,
    NiControllerSequence* pkDestSequence, float fDuration,
    const char* pcDestTextKey, int iPriority, float fSourceWeight,
    float fDestWeight, NiControllerSequence* pkTimeSyncSeq)
{
    assert(pkSourceSequence && pkSourceSequence->GetOwner() == this &&
        pkDestSequence && pkDestSequence->GetOwner() == this);

    return pkSourceSequence->StartBlend(pkDestSequence, fDuration,
        pcDestTextKey, iPriority, fSourceWeight, fDestWeight, pkTimeSyncSeq);
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::BlendFromSequence(
    NiControllerSequence* pkSourceSequence,
    NiControllerSequence* pkDestSequence, float fDuration, float fDestFrame,
    int iPriority, float fSourceWeight, float fDestWeight,
    NiControllerSequence* pkTimeSyncSeq)
{
    assert(pkSourceSequence && pkSourceSequence->GetOwner() == this &&
        pkDestSequence && pkDestSequence->GetOwner() == this);

    return pkSourceSequence->StartBlend(pkDestSequence, fDuration, fDestFrame,
        iPriority, fSourceWeight, fDestWeight, pkTimeSyncSeq);
}
//---------------------------------------------------------------------------
inline bool NiControllerManager::GetCumulativeAnimations() const
{
    return m_bCumulative;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiControllerManager::GetAccumRoot() const
{
    if (m_bCumulative && m_kSequenceArray.GetSize() > 0 &&
        m_kSequenceArray.GetAt(0) != NULL)
    {
        return m_kSequenceArray.GetAt(0)->GetAccumRoot();
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiAVObjectPalette* NiControllerManager::GetObjectPalette() const
{
    return m_spObjectPalette;
}
//---------------------------------------------------------------------------
