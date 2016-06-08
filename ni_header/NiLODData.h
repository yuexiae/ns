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

#ifndef NILODDATA_H
#define NILODDATA_H

#include "NiObject.h"

class NiCamera;
class NiLODNode;

class NIMAIN_ENTRY NiLODData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractStream;

public:
    NiLODData();
    virtual ~NiLODData();

        // Determine the LOD Level do be used based on this camera and Node
    virtual int GetLODLevel(NiCamera* pkCamera, 
        NiLODNode* pkLOD) const = 0;

        // Update any internal world data base on this LOD node
    virtual void UpdateWorldData(NiLODNode* pkLOD) = 0;

        // NiLODData are never shared so we need a duplication
        // function for cloning
    virtual NiLODData* Duplicate() = 0;

    virtual int GetLODIndex(int iLODLevel) const = 0;
};


typedef NiPointer<NiLODData> NiLODDataPtr;


#endif  // NILODDATA_H

