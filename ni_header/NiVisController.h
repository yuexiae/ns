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

#ifndef NIVISCONTROLLER_H
#define NIVISCONTROLLER_H

#include "NiBoolInterpController.h"

class NIANIMATION_ENTRY NiVisController : public NiBoolInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiVisController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiVisController();

    virtual void Update(float fTime);
    
protected:
    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetBoolValue(bool& bValue);
};

NiSmartPointer(NiVisController);

#endif  // #ifndef NIVISCONTROLLER_H
