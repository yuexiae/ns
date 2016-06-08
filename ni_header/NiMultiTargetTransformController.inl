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
inline NiMultiTargetTransformController::NiMultiTargetTransformController() : 
m_pkBlendInterps(NULL), m_ppkTargets(NULL), m_usNumInterps(0)
{
}
//---------------------------------------------------------------------------
inline NiMultiTargetTransformController::NiMultiTargetTransformController(
    unsigned short usCount) : m_pkBlendInterps(NULL), m_ppkTargets(NULL),
    m_usNumInterps(0)
{
    AllocateStorage(usCount);
}
//---------------------------------------------------------------------------
inline unsigned short NiMultiTargetTransformController::GetArrayCount()
{
    return m_usNumInterps;
}
//---------------------------------------------------------------------------
inline NiBlendTransformInterpolator* NiMultiTargetTransformController::
    GetBlendInterpolator(unsigned short usIndex)
{
    assert(usIndex < m_usNumInterps);
    return &m_pkBlendInterps[usIndex];
}
//---------------------------------------------------------------------------
inline NiAVObject* NiMultiTargetTransformController::GetInterpolatorTarget(
    unsigned short usIndex)
{
    assert(usIndex < m_usNumInterps);
    return m_ppkTargets[usIndex];
}
//---------------------------------------------------------------------------
inline void NiMultiTargetTransformController::SetInterpolatorTarget(
    unsigned short usIndex, NiAVObject* pkTarget)
{
    assert(usIndex < m_usNumInterps);
    m_ppkTargets[usIndex] = pkTarget;
}
//---------------------------------------------------------------------------
inline unsigned short NiMultiTargetTransformController
    ::GetInterpolatorTargetIndex(NiAVObject* pkObj)
{
    for (unsigned short us = 0; us < m_usNumInterps; us++)
    {
        if (m_ppkTargets[us] == pkObj)
        {
            return us;
        }
    }

    return INVALID_INDEX;
}
//---------------------------------------------------------------------------
inline unsigned short NiMultiTargetTransformController::AddInterpolatorTarget(
    NiAVObject* pkTarget)
{
    unsigned short usIndex;
    for (usIndex = 0; usIndex < m_usNumInterps; usIndex++)
    {
        if (m_ppkTargets[usIndex] == NULL)
        {
            m_ppkTargets[usIndex] = pkTarget;
            return usIndex;
        }
    }

    return INVALID_INDEX;
}
//---------------------------------------------------------------------------
