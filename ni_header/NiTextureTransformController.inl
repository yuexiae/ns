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
inline NiTexturingProperty::Map* NiTextureTransformController::GetMap()
{
    return m_pkMap;
}
//---------------------------------------------------------------------------
inline NiTextureTransformController::TransformMember 
    NiTextureTransformController::GetAffectedMember()
{
    return m_eMember;
}
//---------------------------------------------------------------------------
inline void NiTextureTransformController::SetAffectedMember(TransformMember eMember)
{
    m_eMember = eMember;
    ResetCtlrID();
}
//---------------------------------------------------------------------------
inline bool NiTextureTransformController::SetInternalMap()
{
    // Check if we are already set
    if (m_pkMap)
        return true;

    // Must have a target to set the internal map
    if (m_pTarget == NULL)
        return false;

    if (m_bShaderMap)
    {
        m_pkMap = ((NiTexturingProperty*)m_pTarget)->GetShaderMap(m_uiMapIndex);
    }
    else
    {
        m_pkMap = ((NiTexturingProperty*)m_pTarget)->GetMaps().GetAt(m_uiMapIndex);
    }

    if (m_pkMap == NULL)
    {
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
inline bool NiTextureTransformController::InterpTargetIsCorrectType(
    NiObjectNET* pkTarget) const
{
    return NiIsKindOf(NiTexturingProperty, pkTarget);
}
//---------------------------------------------------------------------------
