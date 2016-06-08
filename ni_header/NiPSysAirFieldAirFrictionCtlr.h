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

#ifndef NIPSYSAIRFIELDAIRFRICTIONCTLR_H
#define NIPSYSAIRFIELDAIRFRICTIONCTLR_H

#include "NiPSysModifierFloatCtlr.h"

class NIPARTICLE_ENTRY NiPSysAirFieldAirFrictionCtlr :
    public NiPSysModifierFloatCtlr
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysAirFieldAirFrictionCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysAirFieldAirFrictionCtlr(const char* pcModifierName);

protected:
    // For cloning and streaming only.
    NiPSysAirFieldAirFrictionCtlr();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
    virtual void SetTargetFloatValue(float fValue);
};

NiSmartPointer(NiPSysAirFieldAirFrictionCtlr);

#endif  // #ifndef NIPSYSAIRFIELDAIRFRICTIONCTLR_H
