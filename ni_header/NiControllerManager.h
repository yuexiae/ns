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

#ifndef NICONTROLLERMANAGER_H
#define NICONTROLLERMANAGER_H

#include <NiTimeController.h>
#include "NiAnimationLibType.h"
#include <NiAVObject.h>
#include "NiControllerSequence.h"
#include "NiBlendTransformInterpolator.h"

class NiAVObjectPalette;
class NiQuatTransform;

class NIANIMATION_ENTRY NiControllerManager : public NiTimeController
{
public:
    NiDeclareRTTI;
    NiDeclareClone(NiControllerManager);
    NiDeclareStream;

    // Constructor and destructor.
    NiControllerManager(NiAVObject* pkTarget,
        bool bCumulativeAnimations = false);
    virtual ~NiControllerManager();

    // Virtual functions inherited from NiTimeController.
    virtual void Start(float fTime){}
    virtual void Start(){}
    virtual void Stop(){}
    virtual void SetTarget(NiObjectNET* pkTarget){}
    virtual void Update(float fTime);

    // Function to return the object palette.
    NiAVObjectPalette* GetObjectPalette() const;

    // Functions for adding sequences to the manager.
    NiControllerSequence* AddSequenceFromFile(const char* pcFilename,
        unsigned int uiIndex, const char* pcName = NULL);
    NiControllerSequence* AddSequenceFromFile(const NiStream& kStream,
        unsigned int uiIndex, const char* pcName = NULL);
    bool AddAllSequencesFromFile(const char* pcFilename);
    bool AddSequence(NiControllerSequence* pkSequence,
        const char* pcName = NULL, bool bStoreTargets = true);

    // Functions for removing sequences from the manager.
    NiControllerSequencePtr RemoveSequence(const char* pcName);
    NiControllerSequencePtr RemoveSequence(NiControllerSequence* pkSequence);
    void RemoveAllSequences();

    // Functions for retrieving sequences from the manager.
    unsigned int GetSequenceCount() const;
    NiControllerSequence* GetSequenceByName(const char* pcName);
    NiControllerSequence* GetSequenceAt(unsigned int uiIndex);

    // Functions for activating sequences.
    bool ActivateSequence(const char* pcSequenceName, int iPriority = 0,
        bool bStartOver = false, float fWeight = 1.0f,
        float fEaseInTime = 0.0f, NiControllerSequence* pkTimeSyncSeq = NULL);
    bool ActivateSequence(NiControllerSequence* pkSequence,
        int iPriority = 0, bool bStartOver = false, float fWeight = 1.0f,
        float fEaseInTime = 0.0f, NiControllerSequence* pkTimeSyncSeq = NULL);

    // Functions for deactivating sequences.
    bool DeactivateSequence(const char* pcSequenceName,
        float fEaseOutTime = 0.0f);
    bool DeactivateSequence(NiControllerSequence* pkSequence,
        float fEaseOutTime = 0.0f);
    void DeactivateAll(float fEaseOutTime = 0.0f);

    // Functions for setting sequence weight.
    bool SetSequenceWeight(const char* pcSequenceName, float fWeight);
    bool SetSequenceWeight(NiControllerSequence* pkSequence, float fWeight);

    // Functions for cross-fading two sequences.
    bool CrossFade(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fDuration,
        int iPriority = 0, bool bStartOver = false, float fWeight = 1.0f,
        const char* pcTimeSyncSeqName = NULL);
    bool CrossFade(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fDuration,
        int iPriority = 0, bool bStartOver = false, float fWeight = 1.0f,
        NiControllerSequence* pkTimeSyncSeq = NULL);

    // Functions for performing blend transitions from one sequence to
    // another sequence.
    bool BlendFromSequence(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fDuration,
        const char* pcDestTextKey, int iPriority = 0,
        float fSourceWeight = 1.0f, float fDestWeight = 1.0f,
        const char* pcTimeSyncSeqName = NULL);
    bool BlendFromSequence(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fDuration,
        float fDestFrame = 0.0f, int iPriority = 0,
        float fSourceWeight = 1.0f, float fDestWeight = 1.0f,
        const char* pcTimeSyncSeqName = NULL);
    bool BlendFromSequence(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fDuration,
        const char* pcDestTextKey, int iPriority = 0,
        float fSourceWeight = 1.0f, float fDestWeight = 1.0f,
        NiControllerSequence* pkTimeSyncSeq = NULL);
    bool BlendFromSequence(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fDuration,
        float fDestFrame = 0.0f, int iPriority = 0,
        float fSourceWeight = 1.0f, float fDestWeight = 1.0f,
        NiControllerSequence* pkTimeSyncSeq = NULL);
    bool StopBlendFromSequence(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fEaseOutTime = 0.0f);
    bool StopBlendFromSequence(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fEaseOutTime = 0.0f);

    // Functions for performing morph transitions between two sequences.
    bool Morph(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fDuration, int iPriority = 0,
        float fSourceWeight = 1.0f, float fDestWeight = 1.0f);
    bool Morph(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fDuration,
        int iPriority = 0, float fSourceWeight = 1.0f,
        float fDestWeight = 1.0f);
    bool StopMorph(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fEaseOutTime = 0.0f);
    bool StopMorph(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fEaseOutTime = 0.0f);

    // Functions pertaining to transformation accumulation.
    bool GetCumulativeAnimations() const;
    NiAVObject* GetAccumRoot() const;
    void ClearCumulativeAnimations();
    bool GetAccumulatedTransform(NiQuatTransform& kTransform) const;
    void SetAccumulatedTransform(const NiQuatTransform& kTransform);

    // *** Begin deprecated functions ***
    // Functions for performing blend transitions from the current state of
    // the scene graph to a destination sequence. This function is the
    // equivalent of the old Blend function in previous Gamebryo versions.
    // When possible, BlendFromSequence should be used instead of this, as
    // BlendFromPose is not as efficient at runtime.
    bool BlendFromPose(const char* pcSequenceName, const char* pcDestTextKey,
        float fDuration, int iPriority = 0,
        const char* pcSequenceToSynchronize = NULL);
    bool BlendFromPose(const char* pcSequenceName, float fDestFrame,
        float fDuration, int iPriority = 0,
        const char* pcSequenceToSynchronize = NULL);
    bool BlendFromPose(NiControllerSequence* pkSequence,
        const char* pcDestTextKey, float fDuration, int iPriority = 0,
        NiControllerSequence* pkSequenceToSynchronize = NULL);
    bool BlendFromPose(NiControllerSequence* pkSequence, float fDestFrame,
        float fDuration, int iPriority = 0,
        NiControllerSequence* pkSequenceToSynchronize = NULL);
    bool StopBlendFromPose(const char* pcSequenceName);
    bool StopBlendFromPose(NiControllerSequence* pkSequence);

    // Functions for performing sums between two animations. ActivateSequence
    // should instead be called on both sequences with the appropriate weight
    // values.
    bool Sum(const char* pcSourceSequenceName, const char* pcDestSequenceName,
        float fWeight, int iPriority = 0, float fEaseInTime = 0.0f);
    bool Sum(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fWeight,
        int iPriority = 0, float fEaseInTime = 0.0f);
    bool SetSumWeight(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fWeight);
    bool SetSumWeight(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fWeight);
    bool StopSum(const char* pcSourceSequenceName,
        const char* pcDestSequenceName, float fEaseOutTime = 0.0f);
    bool StopSum(NiControllerSequence* pkSourceSequence,
        NiControllerSequence* pkDestSequence, float fEaseOutTime = 0.0f);
    // *** End deprecated functions ***

    // *** Begin NDL internal use only ***
    // cloning support
    virtual void ProcessClone(
        NiCloningProcess& kCloning);

    // streaming support
    virtual void PostLinkObject(NiStream& kStream);
    // *** End NDL internal use only ***

protected:
    // Default constructor for use in cloning and streaming only.
    NiControllerManager();

    // Virtual functions inherited from NiTimeController.
    virtual bool TargetIsRequiredType() const;

    NiControllerSequence* CreateTempBlendSequence(
        NiControllerSequence* pkSequence,
        NiControllerSequence* pkSequenceToSynchronize);

    NiTArray<NiControllerSequencePtr> m_kSequenceArray;
    NiTStringPointerMap<unsigned int> m_kIndexMap;
    bool m_bCumulative;

    // Set of temporary sequences to support Blend.
    NiTSet<NiControllerSequence*> m_kTempBlendSeqs;

    // NiAVObject palette for aiding in target lookup.
    NiAVObjectPalettePtr m_spObjectPalette;
};

NiSmartPointer(NiControllerManager);

#include "NiControllerManager.inl"

#endif  // #ifndef NICONTROLLERMANAGER_H
