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

#include <NiGeometry.h>
//---------------------------------------------------------------------------
inline void NiGeomMorpherController::SetMorphData(NiMorphData* pkData,
    bool bCalculateMorphBound)
{
    m_spMorphData = pkData;
    if (m_spMorphData && m_spMorphData->GetNumTargets() > 0)
    {
        AllocateInterpArray(m_spMorphData->GetNumTargets());
    }
    else
    {
        AllocateInterpArray(0);
    }

    if (bCalculateMorphBound)
    {
        CalculateMorphBound();
    }
}
//---------------------------------------------------------------------------
inline NiMorphData* NiGeomMorpherController::GetMorphData() const
{
    return m_spMorphData;
}
//---------------------------------------------------------------------------
inline unsigned int NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphData ? m_spMorphData->GetNumTargets() : 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiGeomMorpherController::GetNumVertsPerTarget() const
{
    return m_spMorphData ? m_spMorphData->GetNumVertsPerTarget() : 0;
}
//---------------------------------------------------------------------------
inline void NiGeomMorpherController::SetUpdateNormals(bool bUpdateNormals)
{
    SetBit(bUpdateNormals, UPDATENORMAL_MASK);
}
//---------------------------------------------------------------------------
inline bool NiGeomMorpherController::GetUpdateNormals() const
{
    return GetBit(UPDATENORMAL_MASK);
}
//---------------------------------------------------------------------------
inline void NiGeomMorpherController::SetAlwaysUpdate(bool bAlwaysUpdate)
{
    m_bAlwaysUpdate = bAlwaysUpdate;
}
//---------------------------------------------------------------------------
inline void NiGeomMorpherController::SetAlwaysUpdateClone(
    bool bAlwaysUpdateClone)
{
    ms_bAlwaysUpdateClone = bAlwaysUpdateClone;
}
//---------------------------------------------------------------------------
inline NiMorphData::MorphTarget* NiGeomMorpherController::GetTargets()
    const
{
    return m_spMorphData->GetTargets();
}
//---------------------------------------------------------------------------
inline NiMorphData::MorphTarget* NiGeomMorpherController::GetTarget(
    unsigned int uiIndex) const
{
    return m_spMorphData->GetTarget(uiIndex);
}
//---------------------------------------------------------------------------
inline void NiGeomMorpherController::SetIncrementalUpdate(bool bIncrement)
{
    if (m_bIgnoreBaseTarget != bIncrement)
    {
        if (bIncrement)
            m_spMorphData->SetAndAdjustRelativeTargets(bIncrement);

        m_bIgnoreBaseTarget = bIncrement;
    }
}
//---------------------------------------------------------------------------
inline bool NiGeomMorpherController::GetIncrementalUpdate() const
{
    return m_bIgnoreBaseTarget;
}
//---------------------------------------------------------------------------
inline bool NiGeomMorpherController::IsVertexController() const
{
    return true;
}
//---------------------------------------------------------------------------
inline bool NiGeomMorpherController::TargetIsRequiredType() const
{
    return NiIsKindOf(NiGeometry,m_pTarget);
}
//---------------------------------------------------------------------------
inline NiPoint3* NiGeomMorpherController::GetVertexData()
{
    assert(m_pTarget);
    return ((NiGeometry*)m_pTarget)->GetVertices();
}
//---------------------------------------------------------------------------
