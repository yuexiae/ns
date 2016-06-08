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
// NiKFMTool constructor and destructor.
//---------------------------------------------------------------------------
inline NiKFMTool::NiKFMTool(const char* pcBaseKFMPath) :
    m_pcBaseKFMPath(NULL), m_pcFullPathBuffer(NULL), m_pcModelPath(NULL),
    m_pcModelRoot(NULL), m_eDefaultSyncTransType(TYPE_MORPH),
    m_eDefaultNonSyncTransType(TYPE_CROSSFADE),
    m_fDefaultSyncTransDuration(0.1f), m_fDefaultNonSyncTransDuration(0.1f)
{
    SetBaseKFMPath(pcBaseKFMPath);
}
//---------------------------------------------------------------------------
inline NiKFMTool::~NiKFMTool()
{
    delete[] m_pcBaseKFMPath;
    delete[] m_pcFullPathBuffer;
    delete[] m_pcModelPath;
    delete[] m_pcModelRoot;

    unsigned int uiSequenceID;
    Sequence* pkSequence;
    NiTMapIterator pos = m_mapSequences.GetFirstPos();
    while (pos)
    {
        m_mapSequences.GetNext(pos, uiSequenceID, pkSequence);
        delete pkSequence;
    }

    unsigned int uiGroupID;
    SequenceGroup* pkGroup;
    pos = m_mapSequenceGroups.GetFirstPos();
    while (pos)
    {
        m_mapSequenceGroups.GetNext(pos, uiGroupID, pkGroup);
        delete pkGroup;
    }
}
//---------------------------------------------------------------------------
// NiKFMTool::Sequence class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::Sequence::Sequence() : m_uiSequenceID(0), m_pcName(NULL),
    m_pcFilename(NULL), m_iAnimIndex(0)
{
}
//---------------------------------------------------------------------------
inline NiKFMTool::Sequence::Sequence(unsigned int uiSequenceID,
    const char* pcName, const char* pcFilename, int iAnimIndex) :
    m_uiSequenceID(uiSequenceID), m_pcName(NULL), m_pcFilename(NULL),
    m_iAnimIndex(iAnimIndex)
{
    SetName(pcName);
    SetFilename(pcFilename);
}
//---------------------------------------------------------------------------
inline NiKFMTool::Sequence::~Sequence()
{
    delete[] m_pcName;
    delete[] m_pcFilename;

    unsigned int uiSequenceID;
    Transition* pkTransition;
    NiTMapIterator pos = m_mapTransitions.GetFirstPos();
    while (pos)
    {
        m_mapTransitions.GetNext(pos, uiSequenceID, pkTransition);
        delete pkTransition;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::Sequence::GetSequenceID() const
{
    return m_uiSequenceID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Sequence::SetSequenceID(unsigned int uiSequenceID)
{
    m_uiSequenceID = uiSequenceID;
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::Sequence::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Sequence::SetName(const char* pcName)
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
inline const char* NiKFMTool::Sequence::GetFilename() const
{
    return m_pcFilename;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Sequence::SetFilename(const char* pcFilename)
{
    delete[] m_pcFilename;
    m_pcFilename = NULL;
    if (pcFilename)
    {
        m_pcFilename = new char[strlen(pcFilename) + 1];
        strcpy(m_pcFilename, pcFilename);
    }
}
//---------------------------------------------------------------------------
inline int NiKFMTool::Sequence::GetAnimIndex() const
{
    return m_iAnimIndex;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Sequence::SetAnimIndex(int iAnimIndex)
{
    m_iAnimIndex = iAnimIndex;
}
//---------------------------------------------------------------------------
inline NiTPointerMap<unsigned int, NiKFMTool::Transition*>&
    NiKFMTool::Sequence::GetTransitions()
{
    return m_mapTransitions;
}
//---------------------------------------------------------------------------
// NiKFMTool::Transition class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::Transition(NiKFMTool* pkKFMTool) : m_uiSrcID(0),
    m_uiDesID(0), m_eType(TYPE_BLEND), m_fDuration(0.0f),
    m_pkKFMTool(pkKFMTool)
{
    assert(m_pkKFMTool);
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::Transition(NiKFMTool* pkKFMTool,
    unsigned int uiSrcID, unsigned int uiDesID, TransitionType eType,
    float fDuration) : m_uiSrcID(uiSrcID), m_uiDesID(uiDesID), m_eType(eType),
    m_fDuration(fDuration), m_pkKFMTool(pkKFMTool)
{
    assert(m_pkKFMTool);
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::~Transition()
{
    ClearBlendPairs();
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::Transition::GetSrcID() const
{
    return m_uiSrcID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::SetSrcID(unsigned int uiSrcID)
{
    m_uiSrcID = uiSrcID;
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::Transition::GetDesID() const
{
    return m_uiDesID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::SetDesID(unsigned int uiDesID)
{
    m_uiDesID = uiDesID;
}
//---------------------------------------------------------------------------
inline NiKFMTool::TransitionType NiKFMTool::Transition::GetType() const
{
    TransitionType eType;
    switch (m_eType)
    {
        case TYPE_DEFAULT_SYNC:
            eType = m_pkKFMTool->GetDefaultSyncTransType();
            break;
        case TYPE_DEFAULT_NONSYNC:
            eType = m_pkKFMTool->GetDefaultNonSyncTransType();
            break;
        default:
            eType = m_eType;
            break;
    }

    return eType;
}
//---------------------------------------------------------------------------
inline NiKFMTool::TransitionType NiKFMTool::Transition::GetStoredType() const
{
    return m_eType;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::SetStoredType(TransitionType eType)
{
    if (m_eType == eType)
    {
        return;
    }

    ClearBlendPairs();
    ClearChainInfo();

    float fDuration = GetDuration();
    m_eType = eType;
    SetDuration(fDuration);
}
//---------------------------------------------------------------------------
inline float NiKFMTool::Transition::GetDuration() const
{
    float fDuration;
    switch (m_eType)
    {
        case TYPE_DEFAULT_SYNC:
            fDuration = m_pkKFMTool->GetDefaultSyncTransDuration();
            break;
        case TYPE_DEFAULT_NONSYNC:
            fDuration = m_pkKFMTool->GetDefaultNonSyncTransDuration();
            break;
        default:
            fDuration = m_fDuration;
            break;
    }
    return fDuration;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::SetDuration(float fDuration)
{
    m_fDuration = fDuration;
}
//---------------------------------------------------------------------------
inline NiTSet<NiKFMTool::Transition::BlendPair*>& NiKFMTool::Transition::
    GetBlendPairs()
{
    return m_aBlendPairs;
}
//---------------------------------------------------------------------------
inline NiTSet<NiKFMTool::Transition::ChainInfo>& NiKFMTool::Transition::
    GetChainInfo()
{
    return m_aChainInfo;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::ClearBlendPairs()
{
    for (unsigned int ui = 0; ui < m_aBlendPairs.GetSize(); ui++)
    {
        delete m_aBlendPairs.GetAt(ui);
    }
    m_aBlendPairs.RemoveAll();
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::ClearChainInfo()
{
    m_aChainInfo.RemoveAll();
}
//---------------------------------------------------------------------------
// NiKFMTool::Transition::BlendPair class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::BlendPair::BlendPair() : m_pcStartKey(NULL),
    m_pcTargetKey(NULL)
{
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::BlendPair::BlendPair(const char* pcStartKey,
    const char* pcTargetKey) : m_pcStartKey(NULL), m_pcTargetKey(NULL)
{
    assert(pcStartKey || pcTargetKey);
    SetStartKey(pcStartKey);
    SetTargetKey(pcTargetKey);
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::BlendPair::~BlendPair()
{
    delete[] m_pcStartKey;
    delete[] m_pcTargetKey;
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::Transition::BlendPair::GetStartKey() const
{
    return m_pcStartKey;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::BlendPair::SetStartKey(
    const char* pcStartKey)
{
    delete[] m_pcStartKey;
    m_pcStartKey = NULL;
    if (pcStartKey)
    {
        m_pcStartKey = new char[strlen(pcStartKey) + 1];
        strcpy(m_pcStartKey, pcStartKey);
    }
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::Transition::BlendPair::GetTargetKey() const
{
    return m_pcTargetKey;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::BlendPair::SetTargetKey(
    const char* pcTargetKey)
{
    delete[] m_pcTargetKey;
    m_pcTargetKey = NULL;
    if (pcTargetKey)
    {
        m_pcTargetKey = new char[strlen(pcTargetKey) + 1];
        strcpy(m_pcTargetKey, pcTargetKey);
    }
}
//---------------------------------------------------------------------------
// NiKFMTool::Transition::ChainInfo class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::ChainInfo::ChainInfo() : m_uiSequenceID(0),
    m_fDuration(0.0f)
{
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition::ChainInfo::ChainInfo(unsigned int uiSequenceID,
    float fDuration) : m_uiSequenceID(uiSequenceID), m_fDuration(fDuration)
{
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::Transition::ChainInfo::GetSequenceID() const
{
    return m_uiSequenceID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::ChainInfo::SetSequenceID(
    unsigned int uiSequenceID)
{
    m_uiSequenceID = uiSequenceID;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::Transition::ChainInfo::GetDuration() const
{
    return m_fDuration;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::Transition::ChainInfo::SetDuration(float fDuration)
{
    m_fDuration = fDuration;
}
//---------------------------------------------------------------------------
// NiKFMTool::SequenceGroup class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup::SequenceGroup() : m_uiGroupID(0),
    m_pcName(NULL)
{
}
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup::SequenceGroup(unsigned int uiGroupID,
    const char* pcName) : m_uiGroupID(uiGroupID), m_pcName(NULL)
{
    SetName(pcName);
}
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup::~SequenceGroup()
{
    delete[] m_pcName;
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::SequenceGroup::GetGroupID() const
{
    return m_uiGroupID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SetGroupID(unsigned int uiGroupID)
{
    m_uiGroupID = uiGroupID;
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::SequenceGroup::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SetName(const char* pcName)
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
inline NiTSet<NiKFMTool::SequenceGroup::SequenceInfo>& NiKFMTool::
    SequenceGroup::GetSequenceInfo()
{
    return m_aSequenceInfo;
}
//---------------------------------------------------------------------------
// NiKFMTool::SequenceGroup::SequenceInfo class implementation.
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup::SequenceInfo::SequenceInfo() :
    m_uiSequenceID(0), m_iPriority(0), m_fWeight(0.0f), m_fEaseInTime(0.0f),
    m_fEaseOutTime(0.0f), m_uiSynchronizeSequenceID(SYNC_SEQUENCE_ID_NONE)
{
}
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup::SequenceInfo::SequenceInfo(
    unsigned int uiSequenceID, int iPriority, float fWeight,
    float fEaseInTime, float fEaseOutTime, 
    unsigned uiSynchronizedSequenceID) : m_uiSequenceID(uiSequenceID),
    m_iPriority(iPriority), m_fWeight(fWeight), m_fEaseInTime(fEaseInTime),
    m_fEaseOutTime(fEaseOutTime), 
    m_uiSynchronizeSequenceID(uiSynchronizedSequenceID)
{
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::SequenceGroup::SequenceInfo::GetSequenceID()
    const
{
    return m_uiSequenceID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetSequenceID(
    unsigned int uiSequenceID)
{
    m_uiSequenceID = uiSequenceID;
}
//---------------------------------------------------------------------------
inline int NiKFMTool::SequenceGroup::SequenceInfo::GetPriority() const
{
    return m_iPriority;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetPriority(int iPriority)
{
    m_iPriority = iPriority;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::SequenceGroup::SequenceInfo::GetWeight() const
{
    return m_fWeight;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetWeight(float fWeight)
{
    m_fWeight = fWeight;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::SequenceGroup::SequenceInfo::GetEaseInTime() const
{
    return m_fEaseInTime;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetEaseInTime(
    float fEaseInTime)
{
    m_fEaseInTime = fEaseInTime;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::SequenceGroup::SequenceInfo::GetEaseOutTime() const
{
    return m_fEaseOutTime;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetEaseOutTime(
    float fEaseOutTime)
{
    m_fEaseOutTime = fEaseOutTime;
}
//---------------------------------------------------------------------------
inline unsigned int NiKFMTool::SequenceGroup::SequenceInfo::
    GetSynchronizeSequenceID() const
{
    return m_uiSynchronizeSequenceID;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SequenceGroup::SequenceInfo::SetSynchronizeSequenceID(
    unsigned int uiSynchronizeSequenceID)
{
    m_uiSynchronizeSequenceID = uiSynchronizeSequenceID;
}
//---------------------------------------------------------------------------
// Functions for retrieving components.
//---------------------------------------------------------------------------
inline NiKFMTool::Sequence* NiKFMTool::GetSequence(unsigned int uiSequenceID)
    const
{
    // Get specified sequence.
    return GetSequenceFromID(uiSequenceID);
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition* NiKFMTool::GetTransition(unsigned int uiSrcID,
    unsigned int uiDesID) const
{
    // Get specified sequence.
    Sequence* pkSequence = GetSequenceFromID(uiSrcID);
    if (!pkSequence)
    {
        return NULL;
    }

    // Get specified transition.
    return GetTransitionFromID(uiDesID, pkSequence);
}
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup* NiKFMTool::GetSequenceGroup(
    unsigned int uiGroupID) const
{
    // Get specified sequence group.
    return GetSequenceGroupFromID(uiGroupID);
}
//---------------------------------------------------------------------------
// Functions for accessing model data.
//---------------------------------------------------------------------------
inline const char* NiKFMTool::GetModelPath() const
{
    return m_pcModelPath;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SetModelPath(const char* pcModelPath)
{
    delete[] m_pcModelPath;
    m_pcModelPath = NULL;
    if (pcModelPath)
    {
        m_pcModelPath = new char[strlen(pcModelPath) + 1];
        strcpy(m_pcModelPath, pcModelPath);
    }
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::GetModelRoot() const
{
    return m_pcModelRoot;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SetModelRoot(const char* pcModelRoot)
{
    delete[] m_pcModelRoot;
    m_pcModelRoot = NULL;
    if (pcModelRoot)
    {
        m_pcModelRoot = new char[strlen(pcModelRoot) + 1];
        strcpy(m_pcModelRoot, pcModelRoot);
    }
}
//---------------------------------------------------------------------------
// Functions for accessing default transition information.
//---------------------------------------------------------------------------
inline NiKFMTool::TransitionType NiKFMTool::GetDefaultSyncTransType() const
{
    return m_eDefaultSyncTransType;
}
//---------------------------------------------------------------------------
inline NiKFMTool::KFM_RC NiKFMTool::SetDefaultSyncTransType(
    TransitionType eType)
{
    if (eType != TYPE_MORPH)
    {
        return KFM_ERR_SYNC_TRANS_TYPE;
    }

    m_eDefaultSyncTransType = eType;
    return KFM_SUCCESS;
}
//---------------------------------------------------------------------------
inline NiKFMTool::TransitionType NiKFMTool::GetDefaultNonSyncTransType() const
{
    return m_eDefaultNonSyncTransType;
}
//---------------------------------------------------------------------------
inline NiKFMTool::KFM_RC NiKFMTool::SetDefaultNonSyncTransType(
    TransitionType eType)
{
    if (eType != TYPE_BLEND && eType != TYPE_CROSSFADE)
    {
        return KFM_ERR_NONSYNC_TRANS_TYPE;
    }

    m_eDefaultNonSyncTransType = eType;
    return KFM_SUCCESS;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::GetDefaultSyncTransDuration() const
{
    return m_fDefaultSyncTransDuration;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SetDefaultSyncTransDuration(
    float fDuration)
{
    m_fDefaultSyncTransDuration = fDuration;
}
//---------------------------------------------------------------------------
inline float NiKFMTool::GetDefaultNonSyncTransDuration() const
{
    return m_fDefaultNonSyncTransDuration;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SetDefaultNonSyncTransDuration(
    float fDuration)
{
    m_fDefaultNonSyncTransDuration = fDuration;
}
//---------------------------------------------------------------------------
// Functions for performing lookups on components or component data.
//---------------------------------------------------------------------------
inline NiKFMTool::KFM_RC NiKFMTool::IsTransitionAllowed(unsigned int uiSrcID,
    unsigned int uiDesID, bool& bAllowed) const
{
    // Get specified sequence.
    Sequence* pkSequence = GetSequenceFromID(uiSrcID);
    if (!pkSequence)
    {
        return KFM_ERR_SEQUENCE;
    }

    // Check whether or not specified transition is present.
    Transition* pkTransition = GetTransitionFromID(uiDesID, pkSequence);
    if (pkTransition)
    {
        bAllowed = true;
    }
    else
    {
        bAllowed = false;
    }

    return KFM_SUCCESS;
}
//---------------------------------------------------------------------------
inline const char* NiKFMTool::LookupReturnCode(NiKFMTool::KFM_RC eReturnCode)
{
    switch (eReturnCode)
    {
        case KFM_SUCCESS:
            return "The operation completed successfully.";
            break;
        case KFM_ERROR:
            return "An unspecified error occurred.";
            break;
        case KFM_ERR_SEQUENCE:
            return "The specified sequence does not exist.";
            break;
        case KFM_ERR_TRANSITION:
            return "The specified transition does not exist.";
            break;
        case KFM_ERR_TRANSITION_TYPE:
            return "The specified transition is not of the correct type for "
                "this operation.";
            break;
        case KFM_ERR_BLEND_PAIR:
            return "The specified blend pair does not exist.";
            break;
        case KFM_ERR_NULL_TEXT_KEYS:
            return "Both of the specified text keys are null pointers.";
            break;
        case KFM_ERR_BLEND_PAIR_INDEX:
            return "The index specified for the blend pair is invalid.";
            break;
        case KFM_ERR_CHAIN_SEQUENCE:
            return "The ID specified for the chain sequence is invalid.";
            break;
        case KFM_ERR_SEQUENCE_IN_CHAIN:
            return "The specified sequence already exists in the specified "
                "chain.";
            break;
        case KFM_ERR_INFINITE_CHAIN:
            return "Adding the specified sequence to the chain would result "
                "in an infinite chain.";
            break;
        case KFM_ERR_SEQUENCE_GROUP:
            return "The specified sequence group does not exist.";
            break;
        case KFM_ERR_SEQUENCE_IN_GROUP:
            return "The specified sequence does not exist in the group.";
            break;
        case KFM_ERR_FILE_IO:
            return "A file I/O error occurred.";
            break;
        case KFM_ERR_FILE_FORMAT:
            return "The file is not in the correct format.";
            break;
        case KFM_ERR_FILE_VERSION:
            return "The file does not have a compatible version number.";
            break;
        case KFM_ERR_SYNC_TRANS_TYPE:
            return "The transition type specified is not a synchronized "
                "transition type.";
            break;
        case KFM_ERR_NONSYNC_TRANS_TYPE:
            return "The transition type specified is not a non-synchronized "
                "transition type.";
            break;
        default:
            return "";
            break;
    }
}
//---------------------------------------------------------------------------
// Functions for getting fully qualified paths.
//---------------------------------------------------------------------------
inline const char* NiKFMTool::GetBaseKFMPath() const
{
    return m_pcBaseKFMPath;
}
//---------------------------------------------------------------------------
inline void NiKFMTool::SetBaseKFMPath(const char* pcBaseKFMPath)
{
    delete[] m_pcBaseKFMPath;
    m_pcBaseKFMPath = NULL;
    if (pcBaseKFMPath)
    {
        m_pcBaseKFMPath = new char[strlen(pcBaseKFMPath) + 1];
        strcpy(m_pcBaseKFMPath, pcBaseKFMPath);
    }
}
//---------------------------------------------------------------------------
// Protected helper functions.
//---------------------------------------------------------------------------
inline NiKFMTool::Sequence* NiKFMTool::GetSequenceFromID(
    unsigned int uiSequenceID) const
{
    Sequence* pkSequence;
    if (m_mapSequences.GetAt(uiSequenceID, pkSequence))
    {
        return pkSequence;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiKFMTool::Transition* NiKFMTool::GetTransitionFromID(
    unsigned int uiSequenceID, Sequence* pkSequence) const
{
    assert(pkSequence);
    Transition* pkTransition;
    if (pkSequence->GetTransitions().GetAt(uiSequenceID, pkTransition))
    {
        return pkTransition;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiKFMTool::SequenceGroup* NiKFMTool::GetSequenceGroupFromID(
    unsigned int uiGroupID) const
{
    SequenceGroup* pkGroup;
    if (m_mapSequenceGroups.GetAt(uiGroupID, pkGroup))
    {
        return pkGroup;
    }

    return NULL;
}
//---------------------------------------------------------------------------
