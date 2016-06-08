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

#ifndef NIACTORMANAGER_H
#define NIACTORMANAGER_H

#include <NiRefObject.h>
#include <NiNode.h>
#include <NiTObjectList.h>
#include "NiKFMTool.h"
#include "NiControllerManager.h"
#include "NiBoneLODController.h"

class NIANIMATION_ENTRY NiActorManager : public NiRefObject
{
public:
    typedef unsigned int SequenceID;

    // Deprecated typedef.
    typedef SequenceID EventCode;

    class NIANIMATION_ENTRY CallbackObject
    {
    public:
        virtual void AnimActivated(NiActorManager* pkManager,
            SequenceID eSequenceID, float fCurrentTime, float fEventTime){}
        virtual void AnimDeactivated(NiActorManager* pkManager,
            SequenceID eSequenceID, float fCurrentTime, float fEventTime){}
        virtual void TextKeyEvent(NiActorManager* pkManager,
            SequenceID eSequenceID, const char* pcTextKey, float fCurrentTime,
            float fEventTime){}
        virtual void EndOfSequence(NiActorManager* pkManager,
            SequenceID eSequenceID, float fCurrentTime, float fEventTime){}

    protected:
        // This object should never be instantiated directly, so constructor
        // is protected.
        CallbackObject(){}
    };

    enum EventType
    {
        ANIM_ACTIVATED,
        ANIM_DEACTIVATED,
        TEXT_KEY_EVENT,
        END_OF_SEQUENCE
    };

    enum TransitionState
    {
        NO_TRANSITION,
        BLENDING,
        MORPHING,
        CROSSFADING
    };

    // Static constants.
    static const SequenceID ANY_SEQUENCE_ID;
    static const SequenceID INVALID_SEQUENCE_ID;
    static const float INVALID_TIME;

    // Deprecated static constants.
    static const SequenceID ANY_EVENT_CODE;
    static const SequenceID INVALID_EVENT_CODE;

    // Static creation functions.
    static NiActorManager* Create(const char* pcKFMFilename,
        bool bCumulativeAnimations = false, bool bLoadSequences = true,
        NiStream* pkStream = NULL);
    static NiActorManager* Create(NiKFMTool* pkKFMTool,
        const char* pcKFMFilePath, bool bCumulativeAnimations = false,
        bool bLoadSequences = true, NiStream* pkStream = NULL);

    // Destructor.
    ~NiActorManager();

    // Cloning function. Creates a clone of the NiActorManager and all of
    // its contents.
    NiActorManager* Clone();

    // Reloads the NIF file using the info in the NiKFMTool class.
    bool ReloadNIFFile(NiStream* pkStream = NULL);

    // Loads the specified sequence using the info in the NiKFMTool class.
    // If bLoadKFFile is false, the sequence will be loaded directly from
    // pkStream without loading a KF file. pkStream cannot be NULL if
    // bLoadKFFile is false.
    bool LoadSequence(SequenceID eSequenceID, bool bLoadKFFile = true,
        NiStream* pkStream = NULL);

    // Unloads the specified sequence from the actor manager, removing it
    // from the NiControllerManager in the process. If there is no other
    // smart pointer referencing this sequence, it will be deleted.
    void UnloadSequence(SequenceID eSequenceID);

    // Update function. Must be called with the current time periodically to
    // update the state machine.
    void Update(float fTime);

    // Functions for setting/getting the next target animation.
    SequenceID GetTargetAnimation() const;
    bool SetTargetAnimation(SequenceID eSequenceID);
    void Reset();

    // Functions for getting the current state of the actor manager.
    SequenceID GetCurAnimation() const;
    TransitionState GetTransitionState() const;
    SequenceID GetNextAnimation() const;

    // Functions for setting/getting the callback object.
    void SetCallbackObject(CallbackObject* pkCallbackObject);
    CallbackObject* GetCallbackObject() const;

    // Gets the root of the NIF file that was loaded.
    NiAVObject* GetNIFRoot() const;

    // Gets the actor root (the target of the NiControllerManager).
    NiAVObject* GetActorRoot() const;

    // Accessor functions.
    NiKFMTool* GetKFMTool() const;
    NiControllerManager* GetControllerManager() const;
    NiBoneLODController* GetBoneLODController() const;
    NiControllerSequence* GetSequence(SequenceID eSequenceID) const;

    // Gets the accumulation root of the actor, if there is one.
    NiAVObject* GetAccumRoot() const;

    // Functions for registering and unregistering callback events to occur
    // within some advance notification time.
    void RegisterCallback(EventType eEventType, SequenceID eSequenceID,
        const char* pcTextKey = NULL);
    void UnregisterCallback(EventType eEventType, SequenceID eSequenceID,
        const char* pcTextKey = NULL);
    void ClearAllRegisteredCallbacks();

    // Gets the time of the next event. If the next time cannot be predicted,
    // INVALID_TIME is returned.
    float GetNextEventTime(EventType eEventType, SequenceID eSequenceID,
        const char* pcTextKey = NULL);

    // Activate a sequence separately from the internal state machine. This
    // is useful for layering animations on top of a base animation that is
    // controlled by the state machine. Callbacks are available for these
    // animations.
    bool ActivateSequence(SequenceID eSequenceID, int iPriority = 0,
        bool bStartOver = false, float fWeight = 1.0f,
        float fEaseInTime = 0.0f,
        SequenceID eTimeSyncSeqID = NiKFMTool::SYNC_SEQUENCE_ID_NONE);
    bool DeactivateSequence(SequenceID eSequenceID,
        float fEaseOutTime = 0.0f);

    // *** begin NDL internal use only ***
    NiKFMTool::KFM_RC ChangeSequenceID(SequenceID eOldID, SequenceID eNewID);

    class ChainCompletionInfo : public NiRefObject
    {
    public:
        ChainCompletionInfo();
        ~ChainCompletionInfo();

        void SetName(const char* pcName);
        void SetNextName(const char* pcNextName);

        float m_fSeqStart;
        float m_fTransStart;
        float m_fTransEnd;
        float m_fInSeqBeginFrame;
        char* m_pcName;
        char* m_pcNextName;
        NiKFMTool::Transition* m_pkTransition;
    };
    typedef NiPointer<ChainCompletionInfo> ChainCompletionInfoPtr;

    class CompletionInfo : public NiRefObject
    {
    public:
        float m_fFrameInDestWhenTransitionCompletes;
        float m_fTimeToCompleteTransition;
        float m_fFrameTransitionOccursInSrc;
        float m_fTimeForChainToComplete;
        NiKFMTool::Transition::BlendPair* m_pkBlendPair;
        NiTSet<ChainCompletionInfoPtr> m_kChainCompletionInfoSet;
    };
    typedef NiPointer<CompletionInfo> CompletionInfoPtr;

    CompletionInfoPtr FindTimeForAnimationToCompleteTransition(
        NiKFMTool::Transition* pkTransition, float fBeginSQTime,
        float fDesiredTransitionSQTime);
    
    protected:
    ChainCompletionInfo* FillChainComplete( unsigned int uiSrcID,
        unsigned int uiDesID, float fDuration, 
        float& fSrcBeginFrame, float& fTotalTime);
    // *** end NDL internal use only ***

protected:
    class CallbackData : public NiRefObject
    {
    public:
        CallbackData(EventType eEventType, SequenceID eSequenceID,
            const char* pcTextKey = NULL);
        ~CallbackData();

        EventType m_eEventType;
        SequenceID m_eSequenceID;

        const char* GetTextKey() const;
        void SetTextKey(const char* pcTextKey);

    protected:
        char* m_pcTextKey;
    };
    typedef NiPointer<CallbackData> CallbackDataPtr;

public:
    class TimelineData
    {
    public:
        void SetValues(float fEventTime, EventType eEventType,
            SequenceID eSequenceID, const char* pcTextKey);

        float m_fEventTime;
        EventType m_eEventType;
        SequenceID m_eSequenceID;
        const char* m_pcTextKey;
    };

protected:
    NiActorManager(NiKFMTool* pkKFMTool);

    bool Initialize(bool bCumulativeAnimations, bool bLoadSequences,
        NiStream& kStream);
    bool LoadNIFFile(bool bCumulativeAnimations, NiStream& kStream);
    void LoadSequences(NiStream& kStream);
    bool AddSequence(SequenceID eSequenceID, NiStream& kStream,
        bool bLoadKFFile);

    NiControllerManager* FindControllerManager(NiAVObject* pkObject);
    NiBoneLODController* FindBoneLODController(NiAVObject* pkObject);

    float GetNextAnimActivatedTime(SequenceID eSequenceID);
    float GetNextAnimDeactivatedTime(SequenceID eSequenceID);
    float GetNextTextKeyEventTime(SequenceID eSequenceID,
        const char* pcTextKey);
    float GetNextEndOfSequenceTime(SequenceID eSequenceID);

    void BuildTimeline();
    void AddTimelineDataObject(EventType eEventType, SequenceID eSequenceID,
        const char* pcTextKey);
    void ProcessCallbacks();
    void RemoveCallbacksForSequence(SequenceID eSequenceID);

    NiKFMTool::Transition::BlendPair* GetNextBlendPair(
        NiKFMTool::Transition* pkTransition, float fFrameTime,
        float& fActualUnboundedFrame);

    NiKFMToolPtr m_spKFMTool;
    NiAVObjectPtr m_spNIFRoot;
    NiControllerManagerPtr m_spManager;

    NiBoneLODControllerPtr m_spBoneLOD;
    CallbackObject* m_pkCallbackObject;

    SequenceID m_eTargetID;
    float m_fTime;
    bool m_bBuildTimeline;
    float m_fTimelineRefreshTime;
    
    TransitionState m_eTransitionState;
    bool m_bStartTransition;
    float m_fTransStartTime;
    float m_fTransEndTime;
    float m_fTransStartFrameTime;
    const char* m_pcTargetKey;
    SequenceID m_eCurID;
    NiControllerSequence* m_pkCurSequence;
    SequenceID m_eNextID;
    NiControllerSequence* m_pkNextSequence;
    bool m_bChainActive;
    float m_fNextChainTime;
    NiTPointerList<unsigned int> m_kChainIDs;
    NiTPointerList<float> m_kChainDurations;

    NiTPointerMap<SequenceID, NiControllerSequence*> m_kSequenceMap;

    NiTArray<CallbackDataPtr> m_kCallbacks;
    NiTObjectList<TimelineData> m_kTimeline;

    NiTSet<SequenceID> m_kExtraSequences;
};

NiSmartPointer(NiActorManager);

#include "NiActorManager.inl"

#endif  // #ifndef NIACTORMANAGER_H
