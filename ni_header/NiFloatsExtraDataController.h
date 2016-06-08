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

#ifndef NIFLOATSEXTRADATACONTROLLER_H
#define NIFLOATSEXTRADATACONTROLLER_H

#include "NiExtraDataController.h"

class NIANIMATION_ENTRY NiFloatsExtraDataController :
    public NiExtraDataController
{
    NiDeclareRTTI;
    NiDeclareClone(NiFloatsExtraDataController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiFloatsExtraDataController(const char* pcFloatsExtraDataName,
        int iFloatsExtraDataIndex = -1);
    ~NiFloatsExtraDataController();

    virtual void Update(float fTime);
    
    // Floats index access.
    int GetFloatsExtraDataIndex() const;
    void SetFloatsExtraDataIndex(int iFloatsExtraDataIndex);

    // *** begin NDL internal use only ***
    virtual NiInterpolator* CreatePoseInterpolator(unsigned short usIndex = 0);
    virtual void SynchronizePoseInterpolator(NiInterpolator* pkInterp, 
        unsigned short usIndex = 0);
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f,
        unsigned char ucArraySize = 2)
        const;
    virtual const char* GetCtlrID();   
    // *** begin NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiFloatsExtraDataController();

    // Virtual function overrides from base classes.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator,
        unsigned short usIndex) const;

    int m_iFloatsExtraDataIndex;
    char* m_pcCtlrID;
};

NiSmartPointer(NiFloatsExtraDataController);

#include "NiFloatsExtraDataController.inl"

#endif  // #ifndef NIFLOATSEXTRADATACONTROLLER_H
