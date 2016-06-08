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

#ifndef NIEXTRADATACONTROLLER_H
#define NIEXTRADATACONTROLLER_H

#include "NiSingleInterpController.h"
#include <NiExtraData.h>

class NiObjectNET;

class NIANIMATION_ENTRY NiExtraDataController :
    public NiSingleInterpController
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiExtraDataController);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiExtraDataController();
    
    // Gets controller's copy of the extra data name (used to find extra data
    // pointer).
    const char* GetExtraDataName();

    // Gets a pointer to the extra data object that this controller animates.
    // If the controller has no target, NULL is returned.
    NiExtraData* GetExtraDataPointer();

    // Overridden from NiTimeController so that m_spExtraData can be set
    // appropriately.
    virtual void SetTarget(NiObjectNET* pkTarget);

    // *** begin NDL internal use only ***
    // Cloning support.
    virtual void ProcessClone(NiCloningProcess& kCloning);
    void PostLinkObject(NiStream& kStream);

    // Interpolator support
    virtual const char* GetCtlrID();
    // *** end NDL internal use only ***

protected:
    NiExtraDataController(const char* pcExtraDataName);

    // For cloning and streaming only.
    NiExtraDataController();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;

    char* m_pcExtraDataName;
    NiExtraDataPtr m_spExtraData;

private:
    // Sets m_spExtraData to point to the correct extra data, using the
    // stored name.
    void GetExtraDataPointerFromName();

    // Sets the m_pcExtraDataName pointer, making its own copy of the string.
    void SetExtraDataName(const char* pcName);
};

NiSmartPointer(NiExtraDataController);

#include "NiExtraDataController.inl"

#endif  // #ifndef NIEXTRADATACONTROLLER_H
