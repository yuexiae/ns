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
inline NiPSysCollider* NiPSysColliderManager::GetColliders()
{
    return m_spColliders;
}
//---------------------------------------------------------------------------
inline void NiPSysColliderManager::SetColliders(NiPSysCollider* pkColliders)
{
    m_spColliders = pkColliders;
}
//---------------------------------------------------------------------------
inline void NiPSysColliderManager::AddCollider(NiPSysCollider* pkCollider)
{
    pkCollider->SetNext(m_spColliders);
    m_spColliders = pkCollider;
    pkCollider->SetManager(this);
}
//---------------------------------------------------------------------------
