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

#ifndef NIPSYSMODIFIERACTIVECTLR_H
#define NIPSYSMODIFIERACTIVECTLR_H

#include "NiPSysModifierBoolCtlr.h"
#include <NiBoolData.h>

class NIPARTICLE_ENTRY NiPSysModifierActiveCtlr : public NiPSysModifierBoolCtlr
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysModifierActiveCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysModifierActiveCtlr(const char* pcModifierName);

protected:
    // For cloning and streaming only.
    NiPSysModifierActiveCtlr();

    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;

    virtual void GetTargetBoolValue(bool& bValue);
    virtual void SetTargetBoolValue(bool bValue);
};

NiSmartPointer(NiPSysModifierActiveCtlr);

#endif  // #ifndef NIPSYSMODIFIERACTIVECTLR_H
