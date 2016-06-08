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

#ifndef NIALPHAACCUMULATOR_H
#define NIALPHAACCUMULATOR_H

#include "NiBackToFrontAccumulator.h"
#include "NiCamera.h"
#include "NiGeometry.h"

class NIMAIN_ENTRY NiAlphaAccumulator : public NiBackToFrontAccumulator
{
    NiDeclareRTTI;
    NiDeclareClone(NiAlphaAccumulator);
    NiDeclareStream;

public:
    // creation and destruction
    NiAlphaAccumulator ();
    virtual ~NiAlphaAccumulator ();

    // Observe the "no sort" NiAlphaProperty hint flags?
    void SetObserveNoSortHint(bool bObserve);
    bool GetObserveNoSortHint() const;

    void SetSortByClosestPoint(bool bClosest);
    bool GetSortByClosestPoint() const;

    // *** begin NDL internal use only ***

    virtual bool RegisterObject (NiGeometry* pkObject);

    // *** end NDL internal use only ***

protected:
    virtual void Sort ();

    bool m_bObserveNoSortHint;
    bool m_bSortByClosestPoint;

};

typedef NiPointer<NiAlphaAccumulator> NiAlphaAccumulatorPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiAlphaAccumulator.inl"

//---------------------------------------------------------------------------

#endif

