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

#ifndef NIPSYSFIELDATTENUATIONCTLR_H
#define NIPSYSFIELDATTENUATIONCTLR_H

#include "NiPSysModifierFloatCtlr.h"

class NIPARTICLE_ENTRY NiPSysFieldAttenuationCtlr :
    public NiPSysModifierFloatCtlr
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysFieldAttenuationCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysFieldAttenuationCtlr(const char* pcModifierName);

protected:
    // For cloning and streaming only.
    NiPSysFieldAttenuationCtlr();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
    virtual void SetTargetFloatValue(float fValue);
};

NiSmartPointer(NiPSysFieldAttenuationCtlr);

#endif  // #ifndef NIPSYSFIELDATTENUATIONCTLR_H
