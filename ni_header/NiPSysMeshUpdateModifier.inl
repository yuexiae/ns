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
inline NiAVObject* NiPSysMeshUpdateModifier::GetMeshAt(unsigned int uiIndex)
    const
{
    if (uiIndex < m_kMeshes.GetSize())
    {
        return m_kMeshes.GetAt(uiIndex);
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiPSysMeshUpdateModifier::SetMeshAt(unsigned int uiIndex,
    NiAVObject* pkMesh)
{
    if (uiIndex < m_kMeshes.GetSize())
    {
        NiAVObjectPtr spFormerMesh = m_kMeshes.GetAt(uiIndex);
        m_kMeshes.SetAt(uiIndex, pkMesh);
        return spFormerMesh;
    }

    m_kMeshes.SetAtGrow(uiIndex, pkMesh);
    return NULL;
}
//---------------------------------------------------------------------------
inline unsigned int NiPSysMeshUpdateModifier::GetMeshCount() const
{
    return m_kMeshes.GetSize();
}
//---------------------------------------------------------------------------
