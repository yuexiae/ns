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
inline void NiActorManager::SetCallbackObject(
    CallbackObject* pkCallbackObject)
{
    m_pkCallbackObject = pkCallbackObject;
}
//---------------------------------------------------------------------------
inline NiActorManager::CallbackObject* NiActorManager::GetCallbackObject()
    const
{
    return m_pkCallbackObject;
}
//---------------------------------------------------------------------------
inline NiActorManager::SequenceID NiActorManager::GetTargetAnimation() const
{
    return m_eTargetID;
}
//---------------------------------------------------------------------------
inline bool NiActorManager::SetTargetAnimation(SequenceID eSequenceID)
{
    if (m_eTargetID == eSequenceID)
    {
        return true;
    }

    if (eSequenceID != INVALID_SEQUENCE_ID)
    {
        NiControllerSequence* pkSequence;
        if (!m_kSequenceMap.GetAt(eSequenceID, pkSequence))
        {
            return false;
        }
    }

    m_eTargetID = eSequenceID;
    m_bBuildTimeline = true;

    return true;
}
//---------------------------------------------------------------------------
inline void NiActorManager::Reset()
{
    if (m_spManager)
    {
        m_spManager->DeactivateAll();
    }
    m_eTargetID = INVALID_SEQUENCE_ID;
    m_fTime = INVALID_TIME;
    m_bBuildTimeline = false;
    m_fTimelineRefreshTime = NI_INFINITY;
    m_eTransitionState = NO_TRANSITION;
    m_bStartTransition = false;
    m_fTransStartTime = NI_INFINITY;
    m_fTransEndTime = -NI_INFINITY;
    m_fTransStartFrameTime = INVALID_TIME;
    m_pcTargetKey = NULL;
    m_eCurID = INVALID_SEQUENCE_ID;
    m_pkCurSequence = NULL;
    m_eNextID = INVALID_SEQUENCE_ID;
    m_pkNextSequence = NULL;
    m_bChainActive = false;
    m_fNextChainTime = INVALID_TIME;
    m_kChainIDs.RemoveAll();
    m_kChainDurations.RemoveAll();
    m_kExtraSequences.RemoveAll();
}
//---------------------------------------------------------------------------
inline NiActorManager::SequenceID NiActorManager::GetCurAnimation() const
{
    return m_eCurID;
}
//---------------------------------------------------------------------------
inline NiActorManager::TransitionState NiActorManager::GetTransitionState()
    const
{
    return m_eTransitionState;
}
//---------------------------------------------------------------------------
inline NiActorManager::SequenceID NiActorManager::GetNextAnimation() const
{
    return m_eNextID;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiActorManager::GetNIFRoot() const
{
    return m_spNIFRoot;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiActorManager::GetActorRoot() const
{
    assert(m_spManager && NiIsKindOf(NiAVObject, m_spManager->GetTarget()));
    return (NiAVObject*) m_spManager->GetTarget();
}
//---------------------------------------------------------------------------
inline NiKFMTool* NiActorManager::GetKFMTool() const
{
    return m_spKFMTool;
}
//---------------------------------------------------------------------------
inline NiControllerManager* NiActorManager::GetControllerManager() const
{
    return m_spManager;
}
//---------------------------------------------------------------------------
inline NiBoneLODController* NiActorManager::GetBoneLODController() const
{
    return m_spBoneLOD;
}
//---------------------------------------------------------------------------
inline NiControllerSequence* NiActorManager::GetSequence(
    SequenceID eSequenceID) const
{
    NiControllerSequence* pkSequence;
    if (m_kSequenceMap.GetAt(eSequenceID, pkSequence))
    {
        return pkSequence;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiActorManager::GetAccumRoot() const
{
    assert(m_spManager);
    return m_spManager->GetAccumRoot();
}
//---------------------------------------------------------------------------
inline void NiActorManager::ClearAllRegisteredCallbacks()
{
    m_kCallbacks.RemoveAll();
    m_bBuildTimeline = true;
}
//---------------------------------------------------------------------------
inline float NiActorManager::GetNextEventTime(EventType eEventType,
    SequenceID eSequenceID, const char* pcTextKey)
{
    switch (eEventType)
    {
        case ANIM_ACTIVATED:
            return GetNextAnimActivatedTime(eSequenceID);
        case ANIM_DEACTIVATED:
            return GetNextAnimDeactivatedTime(eSequenceID);
        case TEXT_KEY_EVENT:
            return GetNextTextKeyEventTime(eSequenceID, pcTextKey);
        case END_OF_SEQUENCE:
            return GetNextEndOfSequenceTime(eSequenceID);
        default:
            return INVALID_TIME;
    }
}
//---------------------------------------------------------------------------
inline NiActorManager::CallbackData::CallbackData(EventType eEventType,
    SequenceID eSequenceID, const char* pcTextKey) : m_eEventType(eEventType),
    m_eSequenceID(eSequenceID), m_pcTextKey(NULL)
{
    SetTextKey(pcTextKey);
}
//---------------------------------------------------------------------------
inline NiActorManager::CallbackData::~CallbackData()
{
    delete[] m_pcTextKey;
}
//---------------------------------------------------------------------------
inline const char* NiActorManager::CallbackData::GetTextKey() const
{
    return m_pcTextKey;
}
//---------------------------------------------------------------------------
inline void NiActorManager::CallbackData::SetTextKey(const char* pcTextKey)
{
    delete[] m_pcTextKey;
    m_pcTextKey = NULL;
    if (pcTextKey)
    {
        m_pcTextKey = new char[strlen(pcTextKey) + 1];
        strcpy(m_pcTextKey, pcTextKey);
    }
}
//---------------------------------------------------------------------------
inline void NiActorManager::TimelineData::SetValues(float fEventTime,
    EventType eEventType, SequenceID eSequenceID, const char* pcTextKey)
{
    m_fEventTime = fEventTime;
    m_eEventType = eEventType;
    m_eSequenceID = eSequenceID;
    m_pcTextKey = pcTextKey;
}
//---------------------------------------------------------------------------
inline float NiActorManager::GetNextEndOfSequenceTime(SequenceID eSequenceID)
{
    // This function returns the next time that the "end" text key will occur
    // in the specified sequence. This is a convenience function for a
    // commonly desired text key. If the time of the next "end" text key
    // cannot be determined, INVALID_TIME is returned.

    return GetNextTextKeyEventTime(eSequenceID, "end");
}
//---------------------------------------------------------------------------
inline NiActorManager::ChainCompletionInfo::ChainCompletionInfo() :
    m_pcName(NULL), m_pcNextName(NULL)
{
}
//---------------------------------------------------------------------------
inline NiActorManager::ChainCompletionInfo::~ChainCompletionInfo()
{
    delete[] m_pcName;
    delete[] m_pcNextName;
}
//---------------------------------------------------------------------------
inline void NiActorManager::ChainCompletionInfo::SetName(const char* pcName)
{
    delete[] m_pcName;
    m_pcName = NULL;
    if (pcName)
    {
        m_pcName = new char[strlen(pcName) + 1];
        strcpy(m_pcName, pcName);
    }
}
//---------------------------------------------------------------------------
inline void NiActorManager::ChainCompletionInfo::SetNextName(
    const char* pcNextName)
{
    delete[] m_pcNextName;
    m_pcNextName = NULL;
    if (pcNextName)
    {
        m_pcNextName = new char[strlen(pcNextName) + 1];
        strcpy(m_pcNextName, pcNextName);
    }
}
//---------------------------------------------------------------------------
