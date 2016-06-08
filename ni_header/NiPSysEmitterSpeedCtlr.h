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

#ifndef NIPSYSEMITTERSPEEDCTLR_H
#define NIPSYSEMITTERSPEEDCTLR_H

#include "NiPSysModifierFloatCtlr.h"
#include <NiFloatData.h>

class NIPARTICLE_ENTRY NiPSysEmitterSpeedCtlr : public NiPSysModifierFloatCtlr
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysEmitterSpeedCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysEmitterSpeedCtlr(const char* pcModifierName);

protected:
    // For cloning and streaming only.
    NiPSysEmitterSpeedCtlr();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
    virtual void SetTargetFloatValue(float fValue);
};

NiSmartPointer(NiPSysEmitterSpeedCtlr);

#endif  // #ifndef NIPSYSEMITTERSPEEDCTLR_H
