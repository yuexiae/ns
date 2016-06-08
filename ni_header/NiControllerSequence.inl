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

#include <NiAVObject.h>

//---------------------------------------------------------------------------
inline NiControllerSequence::InterpArrayItem::InterpArrayItem() :
    m_spInterpolator(NULL), m_spInterpCtlr(NULL), m_pkBlendInterp(NULL),
    m_ucBlendIdx(NiBlendInterpolator::INVALID_INDEX)
{
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::InterpArrayItem::ClearValues()
{
    m_spInterpolator = NULL;
    m_spInterpCtlr = NULL;
    m_pkBlendInterp = NULL;
    m_ucBlendIdx = NiBlendInterpolator::INVALID_INDEX;
}
//---------------------------------------------------------------------------
inline NiControllerSequence::IDTag::IDTag()
{
    ClearValues();
}
//---------------------------------------------------------------------------
inline NiControllerSequence::IDTag::IDTag(NiStringPalette* pkStringPalette,
    const char* pcAVObjectName, const char* pcPropertyType,
    const char* pcCtlrType, const char* pcCtlrID,
    const char* pcInterpolatorID) : m_spStringPalette(pkStringPalette)
{
    assert(m_spStringPalette);
    ClearValues();
    SetAVObjectName(pcAVObjectName);
    SetPropertyType(pcPropertyType);
    SetCtlrType(pcCtlrType);
    SetCtlrID(pcCtlrID);
    SetInterpolatorID(pcInterpolatorID);
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::IDTag::GetAVObjectName() const
{
    assert(m_spStringPalette);
    if (m_uiAVObjectName != NiControllerSequence::INVALID_INDEX)
    {
        return m_spStringPalette->GetBasePointer() + m_uiAVObjectName;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetAVObjectName(
    const char* pcAVObjectName)
{
    assert(m_spStringPalette);
    if (pcAVObjectName == NULL)
    {
        m_uiAVObjectName = NiControllerSequence::INVALID_INDEX;
    }
    else
    {
        m_uiAVObjectName = m_spStringPalette->AddString(pcAVObjectName);
    }
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::IDTag::GetPropertyType() const
{
    assert(m_spStringPalette);
    if (m_uiPropertyType != NiControllerSequence::INVALID_INDEX)
    {
        return m_spStringPalette->GetBasePointer() + m_uiPropertyType;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetPropertyType(
    const char* pcPropertyType)
{
    assert(m_spStringPalette);
    if (pcPropertyType == NULL)
    {
        m_uiPropertyType = NiControllerSequence::INVALID_INDEX;
    }
    else
    {
        m_uiPropertyType = m_spStringPalette->AddString(pcPropertyType);
    }
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::IDTag::GetCtlrType() const
{
    assert(m_spStringPalette);
    if (m_uiCtlrType != NiControllerSequence::INVALID_INDEX)
    {
        return m_spStringPalette->GetBasePointer() + m_uiCtlrType;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetCtlrType(const char* pcCtlrType)
{
    assert(m_spStringPalette);
    if (pcCtlrType == NULL)
    {
        m_uiCtlrType = NiControllerSequence::INVALID_INDEX;
    }
    else
    {
        m_uiCtlrType = m_spStringPalette->AddString(pcCtlrType);
    }
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::IDTag::GetCtlrID() const
{
    assert(m_spStringPalette);
    if (m_uiCtlrID != NiControllerSequence::INVALID_INDEX)
    {
        return m_spStringPalette->GetBasePointer() + m_uiCtlrID;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetCtlrID(const char* pcCtlrID)
{
    assert(m_spStringPalette);
    if (pcCtlrID == NULL)
    {
        m_uiCtlrID = NiControllerSequence::INVALID_INDEX;
    }
    else
    {
        m_uiCtlrID = m_spStringPalette->AddString(pcCtlrID);
    }
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::IDTag::GetInterpolatorID() const
{
    assert(m_spStringPalette);
    if (m_uiInterpolatorID != NiControllerSequence::INVALID_INDEX)
    {
        return m_spStringPalette->GetBasePointer() + m_uiInterpolatorID;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetInterpolatorID(
    const char* pcInterpolatorID)
{
    assert(m_spStringPalette);
    if (pcInterpolatorID == NULL)
    {
        m_uiInterpolatorID = NiControllerSequence::INVALID_INDEX;
    }
    else
    {
        m_uiInterpolatorID = m_spStringPalette->AddString(pcInterpolatorID);
    }
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::ClearValues()
{
    m_uiAVObjectName = NiControllerSequence::INVALID_INDEX;
    m_uiPropertyType = NiControllerSequence::INVALID_INDEX;
    m_uiCtlrType = NiControllerSequence::INVALID_INDEX;
    m_uiCtlrID = NiControllerSequence::INVALID_INDEX;
    m_uiInterpolatorID = NiControllerSequence::INVALID_INDEX;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::IDTag::SetStringPalette(
    NiStringPalette* pkStringPalette)
{
    assert(pkStringPalette);
    m_spStringPalette = pkStringPalette;
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetName(const char* pcName)
{
    assert(pcName);

    delete[] m_pcName;
    m_pcName = new char[strlen(pcName) + 1];
    strcpy(m_pcName, pcName);
}
//---------------------------------------------------------------------------
inline NiTextKeyExtraData* NiControllerSequence::GetTextKeys() const
{
    return m_spTextKeys;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetTextKeys(NiTextKeyExtraData* pkKeys)
{
    m_spTextKeys = pkKeys;
}
//---------------------------------------------------------------------------
inline unsigned int NiControllerSequence::GetArraySize() const
{
    return m_uiArraySize;
}
//---------------------------------------------------------------------------
inline unsigned int NiControllerSequence::GetArrayGrowBy() const
{
    return m_uiArrayGrowBy;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetArrayGrowBy(unsigned int uiArrayGrowBy)
{
    m_uiArrayGrowBy = uiArrayGrowBy;
}
//---------------------------------------------------------------------------
inline NiInterpController* NiControllerSequence::GetControllerAt(
    unsigned int uiIndex) const
{
    assert(uiIndex < m_uiArraySize);
    return m_pkInterpArray[uiIndex].m_spInterpCtlr;
}
//---------------------------------------------------------------------------
inline NiObjectNET* NiControllerSequence::GetTargetAt(unsigned int uiIndex)
    const
{
    assert(uiIndex < m_uiArraySize);
    if (m_pkInterpArray[uiIndex].m_spInterpCtlr)
    {
        return m_pkInterpArray[uiIndex].m_spInterpCtlr->GetTarget();
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiInterpolator* NiControllerSequence::GetInterpolatorAt(
    unsigned int uiIndex) const
{
    assert(uiIndex < m_uiArraySize);
    return m_pkInterpArray[uiIndex].m_spInterpolator;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::GetInterpInfoAt(unsigned int uiIndex,
    const char*& pcAVObjectName, const char*& pcPropertyType,
    const char*& pcCtlrType, const char*& pcCtlrID,
    const char*& pcInterpolatorID)
{
    assert(uiIndex < m_uiArraySize);
    IDTag& kTag = m_pkIDTagArray[uiIndex];
    pcAVObjectName = kTag.GetAVObjectName();
    pcPropertyType = kTag.GetPropertyType();
    pcCtlrType = kTag.GetCtlrType();
    pcCtlrID = kTag.GetCtlrID();
    pcInterpolatorID = kTag.GetInterpolatorID();
}
//---------------------------------------------------------------------------
inline NiBlendInterpolator* NiControllerSequence::GetBlendInterpolatorAt(
    unsigned int uiIndex) const
{
    assert(uiIndex < m_uiArraySize);
    return m_pkInterpArray[uiIndex].m_pkBlendInterp;
}
//---------------------------------------------------------------------------
inline unsigned char NiControllerSequence::GetBlendIdxAt(
    unsigned int uiIndex)
{
    assert(uiIndex < m_uiArraySize);
    return m_pkInterpArray[uiIndex].m_ucBlendIdx;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetSequenceWeight() const
{
    return m_fSeqWeight;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetSequenceWeight(float fWeight)
{
    m_fSeqWeight = fWeight;
    if (m_fSeqWeight < 0.0f)
    {
        m_fSeqWeight = 0.0f;
    }
}
//---------------------------------------------------------------------------
inline NiTimeController::CycleType NiControllerSequence::GetCycleType()
    const
{
    return m_eCycleType;
}
//---------------------------------------------------------------------------
inline bool NiControllerSequence::SetCycleType(
    NiTimeController::CycleType eCycleType)
{
    if (eCycleType == NiTimeController::CLAMP ||
        eCycleType == NiTimeController::LOOP)
    {
        m_eCycleType = eCycleType;
        return true;
    }

    return false;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetFrequency() const
{
    return m_fFrequency;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetFrequency(float fFrequency)
{
    m_fFrequency = fFrequency;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetPhase() const
{
    return m_fPhase;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetPhase(float fPhase)
{
    m_fPhase = fPhase;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::AdjustTime(float fTime) const
{
    return ((fTime - m_fPhase) / m_fFrequency);
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::InvAdjustTime(float fTime) const
{
    return ((fTime * m_fFrequency) + m_fPhase);
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetAdjustedBeginKeyTime() const
{
    return AdjustTime(m_fBeginKeyTime);
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetBeginKeyTime() const
{
    return m_fBeginKeyTime;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetBeginKeyTime(float fBeginKeyTime)
{
    m_fBeginKeyTime = fBeginKeyTime;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetAdjustedEndKeyTime() const
{
    return AdjustTime(m_fEndKeyTime);
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetEndKeyTime() const
{
    return m_fEndKeyTime;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetEndKeyTime(float fEndKeyTime)
{
    m_fEndKeyTime = fEndKeyTime;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetLength()
{
    assert(m_fFrequency != 0.0f);
    return ((m_fEndKeyTime - m_fBeginKeyTime) / m_fFrequency);
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetLastTime() const
{
    return m_fLastTime;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetLastScaledTime() const
{
    return m_fLastScaledTime;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::ResetSequence()
{
    m_fOffset = -NI_INFINITY;
}
//---------------------------------------------------------------------------
inline NiControllerSequence::AnimState NiControllerSequence::GetState() const
{
    return m_eState;
}
//---------------------------------------------------------------------------
inline float NiControllerSequence::GetOffset() const
{
    return m_fOffset;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetOffset(float fOffset)
{
    m_fOffset = fOffset;
}
//---------------------------------------------------------------------------
inline NiControllerManager* NiControllerSequence::GetOwner() const
{
    return m_pkOwner;
}
//---------------------------------------------------------------------------
inline bool NiControllerSequence::SetOwner(NiControllerManager* pkOwner)
{
    if (pkOwner && m_pkOwner)
    {
        return false;
    }

    m_pkOwner = pkOwner;
    return true;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetAccumRootName(const char* pcAccumRoot)
{
    delete[] m_pcAccumRoot;
    m_pcAccumRoot = NULL;
    if (pcAccumRoot)
    {
        m_pcAccumRoot = new char[strlen(pcAccumRoot) + 1];
        strcpy(m_pcAccumRoot, pcAccumRoot);
    }
}
//---------------------------------------------------------------------------
inline const char* NiControllerSequence::GetAccumRootName() const
{
    return m_pcAccumRoot;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiControllerSequence::GetAccumRoot() const
{
    return m_pkAccumRoot;
}
//---------------------------------------------------------------------------
inline void NiControllerSequence::SetControllerAt(
    NiInterpController* pkInterpCtlr, unsigned int uiIndex)
{
    assert(uiIndex < m_uiArraySize);
    m_pkInterpArray[uiIndex].m_spInterpCtlr = pkInterpCtlr;
}
//---------------------------------------------------------------------------
inline unsigned int NiControllerSequence::GetIDTagCount()
{
    return m_uiArraySize;
}
//---------------------------------------------------------------------------
inline NiControllerSequence::IDTag* NiControllerSequence::GetIDTag(
    unsigned int uiTagIndex)
{
    assert(uiTagIndex < m_uiArraySize);
    return &m_pkIDTagArray[uiTagIndex];
}