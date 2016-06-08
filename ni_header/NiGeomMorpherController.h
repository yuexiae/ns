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

#ifndef NIGEOMMORPHERCONTROLLER_H
#define NIGEOMMORPHERCONTROLLER_H

#include <NiAVObject.h>
#include "NiInterpController.h"
#include "NiAnimationLibType.h"
#include "NiMorphData.h"

NiSmartPointer(NiGeomMorpherController);

class NIANIMATION_ENTRY NiGeomMorpherController : public NiInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiGeomMorpherController);
    NiDeclareStream;
    NiDeclareFlags(unsigned short);

public:
    NiGeomMorpherController(NiMorphData* pkData = 0);
    virtual ~NiGeomMorpherController();

    // shared data access
    void SetMorphData(NiMorphData* pkData, bool bCalculateMorphBound = true);
    NiMorphData* GetMorphData() const;

    // accessors
    unsigned int GetNumTargets() const;
    unsigned int GetNumVertsPerTarget() const;

    NiMorphData::MorphTarget* GetTargets() const;
    NiMorphData::MorphTarget* GetTarget(unsigned int uiIndex) const;

    // For swapping animation sequences at runtime.  The NiMorphData object
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.

    void ReplaceTargets(NiMorphData::MorphTarget* pkMorphTargets, 
        unsigned int uiNumTargets, unsigned int uiNumVertsPerTarget,
        bool bUpdate = true);

    // animation updates
    virtual void Update(float fTime);
    virtual void OnPreDisplay();

    void SetUpdateNormals(bool bUpdateNormals);
    bool GetUpdateNormals() const;

    void SetAlwaysUpdate(bool bAlwaysUpdate);
    static void SetAlwaysUpdateClone(bool bAlwaysUpdateClone);

    // Overridden from NiTimeController so that bounds can be calculated with
    // sequences.
    virtual void SetTarget(NiObjectNET* pkTarget);

    // This method should be called any time the interpolator changes
    // outside of the SetInterpolator method
    virtual void ResetTimeExtrema();

    // *** begin NDL internal use only ***
    virtual NiPoint3* GetVertexData();

    void SetIncrementalUpdate(bool bIncrement);
    bool GetIncrementalUpdate() const;

    virtual bool IsVertexController() const;

    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);

    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    virtual void CalculateMorphBound();

    void GenMorphInterp(float fTime);

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 6
    };
    
    // --- End NIF conversion code

    // flags
    enum
    {
        UPDATENORMAL_MASK   = 0x0001
    };

    NiMorphDataPtr m_spMorphData;
    NiInterpolatorPtr* m_aspInterpolators;

    bool m_bNeedPreDisplay;
    bool m_bIgnoreBaseTarget;

    bool m_bAlwaysUpdate;
    static bool ms_bAlwaysUpdateClone;

    bool m_bBoundCalculated;

    // debugging
    virtual bool TargetIsRequiredType() const;

    //Methods implemented from NiInterpController
public:
    virtual unsigned short GetInterpolatorCount() const;

    virtual const char* GetInterpolatorID(unsigned short usIndex = 0);
    virtual unsigned short GetInterpolatorIndex(const char* pcID) const;
    
    virtual NiInterpolator* GetInterpolator(unsigned short usIndex = 0) const;
    virtual void SetInterpolator(NiInterpolator* pkInterpolator,
        unsigned short usIndex = 0);

    virtual NiInterpolator* CreatePoseInterpolator(unsigned short usIndex = 0);
    virtual void SynchronizePoseInterpolator(NiInterpolator* pkInterp, 
        unsigned short usIndex = 0);
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f,
        unsigned char ucArraySize = 2)
        const;

protected:
    // For debug only.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator,
        unsigned short usIndex) const;
    void AllocateInterpArray(unsigned short usCount);
};

#include "NiGeomMorpherController.inl"

#endif

