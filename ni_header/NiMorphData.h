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

#ifndef NIMORPHDATA_H
#define NIMORPHDATA_H

#include <NiObject.h>
#include <NiPoint3.h>
#include "NiAnimationLibType.h"
#include "NiInterpolator.h"

NiSmartPointer(NiMorphData);

class NIANIMATION_ENTRY NiMorphData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiMorphData ();
    virtual ~NiMorphData ();

    class NIANIMATION_ENTRY MorphTarget
    {
    public:
        MorphTarget();
        ~MorphTarget();

        NiPoint3* GetTargetVerts () const;
        NiPoint3 GetTargetVert(unsigned int uiIndex) const;

        void ReplaceTargetVerts(NiPoint3* aTargetVerts);

        void SetName(const char* pcName);
        const char* GetName();

        float GetWeight();
        void SetWeight(float fWeight);

        void LoadBinary(NiStream& kStream, unsigned int uiNumVerts);
        void SaveBinary(NiStream& kStream, unsigned int uiNumVerts);

        // *** begin NDL internal use only ***
        NiInterpolator* GetLegacyInterpolator();
        void SetLegacyInterpolator(NiInterpolator* pkInterp);
        bool IsEqual(MorphTarget* pkOther, unsigned int uiNumVerts);
        // *** end NDL internal use only ***
    protected:
        NiPoint3* m_aTargetVerts;
        char* m_pcName;
        float m_fWeight;
        NiInterpolatorPtr m_spLegacyInterpolator;
    };

    // target access
    unsigned int GetNumTargets () const;
    unsigned int GetNumVertsPerTarget () const;
    MorphTarget* GetTargets () const;
    MorphTarget* GetTarget (unsigned int uiIndex) const;
    
    void ReplaceTargets (MorphTarget* aMorphTargets, unsigned int uiNumTargets,
        unsigned int uiNumVertsPerTarget);

    NiPoint3* GetTargetVerts (unsigned int uiIndex) const;

    bool GetRelativeTargets () const;
    void SetRelativeTargets (bool bRelativeTargets);
    void SetAndAdjustRelativeTargets (bool bRelativeTargets);

protected:

    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_aMorphTargets;

    bool m_bRelativeTargets;
};

#include "NiMorphData.inl"

#endif
