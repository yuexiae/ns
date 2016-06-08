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

#ifndef NIALPHACONTROLLER_H
#define NIALPHACONTROLLER_H

#include "NiFloatInterpController.h"
NiSmartPointer(NiAlphaController);


class NIANIMATION_ENTRY NiAlphaController : public NiFloatInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiAlphaController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiAlphaController();

    virtual void Update(float fTime);
    
protected:
    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
};

#endif

