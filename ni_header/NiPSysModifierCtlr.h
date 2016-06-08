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

#ifndef NIPSYSMODIFIERCTLR_H
#define NIPSYSMODIFIERCTLR_H

#include <NiSingleInterpController.h>
#include "NiParticleLibType.h"
#include "NiParticleSystem.h"

class NiPSysModifier;

class NIPARTICLE_ENTRY NiPSysModifierCtlr : public NiSingleInterpController
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysModifierCtlr);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiPSysModifierCtlr();

    virtual void SetTarget(NiObjectNET* pkTarget);

    // This function is called when the particle system is reset.
    virtual void HandleReset();

    // Gets controller's copy of the modifier name (used to find modifier
    // pointer).
    const char* GetModifierName() const;

    // Gets a pointer to the modifier object that this controller animates.
    // If the controller has no target, NULL is returned.
    NiPSysModifier* GetModifierPointer() const;

    // *** begin NDL internal use only ***
    // Cloning support.
    virtual const char* GetCtlrID();
    virtual void ProcessClone(NiCloningProcess& kCloning);
    void PostLinkObject(NiStream& kStream);
    // *** end NDL internal use only ***

protected:
    NiPSysModifierCtlr(const char* pcModifierName);

    // For cloning and streaming only.
    NiPSysModifierCtlr();

    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;

    char* m_pcModifierName;
    NiPSysModifier* m_pkModifier;

private:
    // Sets m_pkModifier to point to the correct modifier, using the stored
    // name.
    void GetModifierPointerFromName();

    // Sets the m_pcModifierName pointer, making its own copy of the string.
    void SetModifierName(const char* pcName);
};

NiSmartPointer(NiPSysModifierCtlr);

#include "NiPSysModifierCtlr.inl"

#endif  // #ifndef NIPSYSMODIFIERCTLR_H
