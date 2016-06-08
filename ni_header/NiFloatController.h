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

#ifndef NIFLOATCONTROLLER_H
#define NIFLOATCONTROLLER_H

#include "NiTimeController.h"
#include "NiFloatKey.h"
#include "NiFloatData.h"

// This class has been deprecated as of Gamebryo 1.2. 
// Equivalent functionality can be found in NiFloatInterpController.

class NIANIMATION_ENTRY NiFloatController : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiFloatController);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    NiFloatController (NiFloatData* pData = 0);
    virtual ~NiFloatController ();

    // updates
    virtual void Update (float fTime) = 0;

    // shared data access
    void SetFloatData (NiFloatData* pData);
    NiFloatData* GetFloatData ();

    // float key access
    NiFloatKey* GetAnim (unsigned int& uiNumKeys,
        NiFloatKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping animation sequences at runtime. The NiFloatData object 
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.
    void ReplaceAnim (unsigned int uiNumKeys, NiFloatKey* pkKeys,
        NiFloatKey::KeyType eType);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only

protected:
    unsigned int m_uiLastIdx;
    NiFloatDataPtr m_spFloatData;
};

NiSmartPointer(NiFloatController);

#include "NiFloatController.inl"

#endif
