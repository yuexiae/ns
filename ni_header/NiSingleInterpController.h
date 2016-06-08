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

#ifndef NISINGLEINTERPCONTROLLER_H
#define NISINGLEINTERPCONTROLLER_H

#include "NiInterpController.h"
#include "NiInterpolator.h"

class NIANIMATION_ENTRY NiSingleInterpController : public NiInterpController
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiSingleInterpController);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual unsigned short GetInterpolatorCount() const;

    virtual const char* GetInterpolatorID(unsigned short usIndex = 0);
    virtual unsigned short GetInterpolatorIndex(const char* pcID) const;
    
    virtual NiInterpolator* GetInterpolator(unsigned short usIndex = 0) const;
    virtual void SetInterpolator(NiInterpolator* pkInterpolator,
        unsigned short usIndex = 0);

    // This method should be called any time the interpolator changes
    // outside of the SetInterpolator method
    virtual void ResetTimeExtrema();
    
    // *** begin NDL internal use only ***
    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    NiSingleInterpController();
    virtual bool TargetIsRequiredType() const;
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const = 0;

    NiInterpolatorPtr m_spInterpolator;
};

NiSmartPointer(NiSingleInterpController);

#endif  // #ifndef NISINGLEINTERPCONTROLLER_H
