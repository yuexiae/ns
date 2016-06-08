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

#ifndef NIPSYSUPDATECTLR_H
#define NIPSYSUPDATECTLR_H

#include "NiParticleLibType.h"
#include <NiTimeController.h>
#include "NiParticleSystem.h"

class NIPARTICLE_ENTRY NiPSysUpdateCtlr : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysUpdateCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysUpdateCtlr();

    virtual void Update(float fTime);
    virtual void SetTarget(NiObjectNET* pkTarget);

protected:
    virtual bool TargetIsRequiredType() const;
};

NiSmartPointer(NiPSysUpdateCtlr);

#endif  // #ifndef NIPSYSUPDATECTLR_H
