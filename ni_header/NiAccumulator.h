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

#ifndef NIACCUMULATOR_H
#define NIACCUMULATOR_H

#include "NiMainLibType.h"
#include "NiObject.h"
#include "NiStream.h"
#include "NiTPointerList.h"

class NiGeometry;
class NiCamera;


class NIMAIN_ENTRY NiAccumulator : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiAccumulator);
    NiDeclareAbstractStream;

public:
    NiAccumulator ();
    virtual ~NiAccumulator () { /**/ }

    // *** begin NDL internal use only ***

    virtual bool StartAccumulating (NiCamera* pkCamera); 
    virtual void FinishAccumulating (); 
    virtual bool RegisterObject (NiGeometry* pkObject) = 0;

    // *** end NDL internal use only ***

protected:
    NiCamera* m_pkCamera;
};

// list of NiAVObjects - most likely to be sorted
typedef NiTPointerList<NiGeometry*> NiSortedObjectList;

typedef NiPointer<NiAccumulator> NiAccumulatorPtr;

#endif

