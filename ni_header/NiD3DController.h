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

#ifndef NID3DCONTROLLER_H
#define NID3DCONTROLLER_H

#include "NiD3DDefines.h"
#include <NiTimeController.h>
#include <NiTPointerList.h>
#include <NiObjectNET.h>

NiSmartPointer(NiD3DController);

class NID3D_ENTRY NiD3DController : public NiTimeController
{
    NiDeclareRTTI;

public:
    NiD3DController();
    virtual ~NiD3DController();

    static void RemoveBeforeStreaming(NiObjectNET* pkRoot);
    static void AddAfterStreaming();
protected:
    static NiTPointerList<NiObjectNETPtr>* ms_pkObjectsList;
    static NiTPointerList<NiD3DControllerPtr>* ms_pkControllersList;
};

typedef NiPointer<NiD3DController> NiD3DControllerPtr;

#endif  // #ifndef NID3DCONTROLLER_H
