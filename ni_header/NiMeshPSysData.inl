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
inline NiAVObject* NiMeshPSysData::GetMeshAt(unsigned short usIndex) const
{
    return m_spParticleMeshes->GetAt(usIndex);
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::SetMeshAt(unsigned short usIndex,
    NiAVObject* pkMesh)
{
    assert(usIndex < m_usVertices);
    m_spParticleMeshes->SetAt(usIndex, pkMesh);
}
//---------------------------------------------------------------------------
inline NiNode* NiMeshPSysData::GetContainerNode() const
{
    return m_spParticleMeshes;
}
//---------------------------------------------------------------------------
inline unsigned int NiMeshPSysData::GetNumGenerations()
{
    return m_kPools.GetSize();
}
//---------------------------------------------------------------------------
inline int NiMeshPSysData::GetPoolSize(unsigned int uiGeneration)
{
    return m_kPools.GetAt(uiGeneration)->GetAllocatedSize();
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::SetPoolSize(unsigned int uiGeneration, 
    unsigned int uiSize)
{
    assert(uiGeneration < m_kPools.GetSize());

    m_kPools.GetAt(uiGeneration)->SetSize(uiSize);
}
//---------------------------------------------------------------------------
inline int NiMeshPSysData::GetPoolCount(unsigned int uiGeneration)
{
    assert(uiGeneration < m_kPools.GetSize());

    return m_kPools.GetAt(uiGeneration)->GetSize();
}
//---------------------------------------------------------------------------
inline bool NiMeshPSysData::IsPoolEmpty(unsigned int uiGeneration)
{
    assert(uiGeneration < m_kPools.GetSize());

    return (m_kPools.GetAt(uiGeneration)->GetSize() == 0);
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::EmptyPool(unsigned int uiGeneration)
{
    assert(uiGeneration < m_kPools.GetSize());

    m_kPools.GetAt(uiGeneration)->RemoveAll();
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::FillPool(unsigned int uiGeneration, 
    NiAVObject* pkOriginal)
{
    assert(pkOriginal != NULL);

    // Make sure we have something to fill
    if (uiGeneration >= m_kPools.GetSize() ||
        !m_kPools.GetAt(uiGeneration))
        return;

    NiTArray<NiAVObjectPtr>* pkPool = m_kPools.GetAt(uiGeneration);

    for(unsigned int uiLoop = 0; uiLoop < pkPool->GetAllocatedSize(); uiLoop++)
    {
        pkPool->SetAt(uiLoop, (NiAVObject*)pkOriginal->Clone());
    }
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiMeshPSysData::RemoveFromPool(unsigned int uiGeneration)
{
    // Check if the generation has a pool
    if (uiGeneration >= m_kPools.GetSize())
    {
        return NULL;
    }

    // Check if the generation has a pool allocated
    if (!m_kPools.GetAt(uiGeneration))
        return NULL;

    return m_kPools.GetAt(uiGeneration)->RemoveEnd();
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::AddToPool(unsigned int uiGeneration, 
    NiAVObjectPtr spObject)
{
    // Check if the generation has a pool
    if (uiGeneration >= m_kPools.GetSize())
        return;

    // Check there is a pool to add into
    if (!m_kPools.GetAt(uiGeneration))
        return;

    if (m_kPools.GetAt(uiGeneration)->GetSize() <
        m_kPools.GetAt(uiGeneration)->GetAllocatedSize())
    {
        m_kPools.GetAt(uiGeneration)->Add(spObject);
    }
}
//---------------------------------------------------------------------------
inline bool NiMeshPSysData::GetFillPoolsOnLoad()
{
    return m_bFillPoolsOnLoad;
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::SetFillPoolsOnLoad(bool bFill)
{
    m_bFillPoolsOnLoad = bFill;
}
//---------------------------------------------------------------------------
inline unsigned int NiMeshPSysData::GetDefaultPoolsSize()
{
    return m_uiDefaultPoolSize;
}
//---------------------------------------------------------------------------
inline void NiMeshPSysData::SetDefaultPoolsSize(unsigned int uiSize)
{
    m_uiDefaultPoolSize = uiSize;
}
//---------------------------------------------------------------------------
