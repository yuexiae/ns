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

#ifndef NIPSYSRESETONLOOPCTLR_H
#define NIPSYSRESETONLOOPCTLR_H

#include "NiParticleLibType.h"
#include <NiTimeController.h>

class NIPARTICLE_ENTRY NiPSysResetOnLoopCtlr : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysResetOnLoopCtlr);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysResetOnLoopCtlr();

    virtual void Update(float fTime);

protected:
    virtual bool TargetIsRequiredType() const;

    float m_fLastScaledTime;
};

#endif  // #ifndef NIPSYSRESETONLOOPCTLR_H
