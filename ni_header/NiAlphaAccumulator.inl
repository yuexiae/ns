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
//---------------------------------------------------------------------------
//  NiAlphaAccumulator inline functions
//---------------------------------------------------------------------------
#include "NiAlphaProperty.h"

//---------------------------------------------------------------------------
inline void NiAlphaAccumulator::SetObserveNoSortHint(bool bObserve)
{
    m_bObserveNoSortHint = bObserve;
}
//---------------------------------------------------------------------------
inline bool NiAlphaAccumulator::GetObserveNoSortHint() const
{
    return m_bObserveNoSortHint;
}
//---------------------------------------------------------------------------
inline void NiAlphaAccumulator::SetSortByClosestPoint(bool bClosest)
{
    m_bSortByClosestPoint = bClosest;
}
//---------------------------------------------------------------------------
inline bool NiAlphaAccumulator::GetSortByClosestPoint() const
{
    return m_bSortByClosestPoint;
}
//---------------------------------------------------------------------------
inline bool NiAlphaAccumulator::RegisterObject (NiGeometry* pkObject)
{
    assert(m_pkCamera);

    assert(pkObject);

    const NiPropertyState* pkState = pkObject->GetPropertyState();

    assert(pkState);

    const NiAlphaProperty *pkAlpha = pkState->GetAlpha();

    // Every property state should have a valid alpha property
    assert(pkAlpha);

    if (pkAlpha->GetAlphaBlending() && 
       !(m_bObserveNoSortHint && pkAlpha->GetNoSorter()) )
    {
        m_kItems.AddTail(pkObject);
        return true;
    }
    else
        return false;
}
//---------------------------------------------------------------------------
