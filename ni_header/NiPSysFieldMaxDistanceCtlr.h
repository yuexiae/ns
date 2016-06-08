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

#ifndef NIPSYSFIELDMAXDISTANCECTLR_H
#define NIPSYSFIELDMAXDISTANCECTLR_H

#include "NiPSysModifierFloatCtlr.h"

class NIPARTICLE_ENTRY NiPSysFieldMaxDistanceCtlr :
    public NiPSysModifierFloatCtlr
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysFieldMaxDistanceCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysFieldMaxDistanceCtlr(const char* pcModifierName);

protected:
    // For cloning and streaming only.
    NiPSysFieldMaxDistanceCtlr();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
    virtual void SetTargetFloatValue(float fValue);
};

NiSmartPointer(NiPSysFieldMaxDistanceCtlr);

#endif  // #ifndef NIPSYSFIELDMAXDISTANCECTLR_H
