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

#include <NiFloatInterpolator.h>
#include <NiBlendFloatInterpolator.h>
#include <NiBoolInterpolator.h>
#include <NiBlendBoolInterpolator.h>

//---------------------------------------------------------------------------
inline NiFloatInterpolator* NiPSysEmitterCtlr::GetBirthRateInterpolator()
    const
{
    NiFloatInterpolator* pkFloatInterp = NiDynamicCast(NiFloatInterpolator,
        m_spInterpolator);
    if (pkFloatInterp)
    {
        return pkFloatInterp;
    }

    NiBlendFloatInterpolator* pkBlendInterp = NiDynamicCast(
        NiBlendFloatInterpolator, m_spInterpolator);
    if (pkBlendInterp)
    {
        unsigned char ucIndex = pkBlendInterp->GetHighestWeightedIndex();
        if (ucIndex != NiBlendInterpolator::INVALID_INDEX)
        {
            return (NiFloatInterpolator*) pkBlendInterp->GetInterpolator(
                ucIndex);
        }
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiBoolInterpolator* NiPSysEmitterCtlr::GetEmitterActiveInterpolator()
    const
{
    NiBoolInterpolator* pkBoolInterp = NiDynamicCast(NiBoolInterpolator,
        m_spEmitterActiveInterpolator);
    if (pkBoolInterp)
    {
        return pkBoolInterp;
    }

    NiBlendBoolInterpolator* pkBlendInterp = NiDynamicCast(
        NiBlendBoolInterpolator, m_spEmitterActiveInterpolator);
    if (pkBlendInterp)
    {
        unsigned char ucIndex = pkBlendInterp->GetHighestWeightedIndex();
        if (ucIndex != NiBlendInterpolator::INVALID_INDEX)
        {
            return (NiBoolInterpolator*) pkBlendInterp->GetInterpolator(
                ucIndex);
        }
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitterCtlr::SetBirthRateInterpolator(NiFloatInterpolator* 
    pkInterpolator)
{
    m_spInterpolator = pkInterpolator;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitterCtlr::SetEmitterActiveInterpolator(
    NiBoolInterpolator* pkInterpolator)
{
    m_spEmitterActiveInterpolator = pkInterpolator;
}
//---------------------------------------------------------------------------
