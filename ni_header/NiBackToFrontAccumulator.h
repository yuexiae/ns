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

#ifndef NIBACKTOFRONTACCUMULATOR_H
#define NIBACKTOFRONTACCUMULATOR_H

#include "NiAccumulator.h"
#include "NiCamera.h"
#include "NiGeometry.h"

class NIMAIN_ENTRY NiBackToFrontAccumulator : public NiAccumulator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBackToFrontAccumulator);
    NiDeclareStream;

public:
    // creation and destruction
    NiBackToFrontAccumulator();
    virtual ~NiBackToFrontAccumulator();

    // *** begin NDL internal use only ***

    virtual bool RegisterObject(NiGeometry* pkObject);
    virtual void FinishAccumulating();

    // *** end NDL internal use only ***

protected:
    virtual void Sort();

    void SortObjectsByDepth(int l, int r);
    float ChoosePivot(int l, int r) const;

    NiSortedObjectList m_kItems;

    int m_iNumItems;
    int m_iMaxItems;
    NiGeometry** m_ppkItems;
    float* m_pfDepths;
    int m_iCurrItem;
};

NiSmartPointer(NiBackToFrontAccumulator);

#include "NiBackToFrontAccumulator.inl"

#endif //NIBACKTOFRONTACCUMULATOR_H

