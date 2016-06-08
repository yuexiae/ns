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
inline unsigned int NiSkinPartition::GetPartitionCount() const
{
    return m_uiPartitions;
}
//---------------------------------------------------------------------------
inline NiSkinPartition::Partition* NiSkinPartition::GetPartitions()
{
    return m_pkPartitions;
}
//---------------------------------------------------------------------------
inline const NiSkinPartition::Partition* NiSkinPartition::GetPartitions() const
{
    return m_pkPartitions;
}
//---------------------------------------------------------------------------

#ifdef PS2
//---------------------------------------------------------------------------
inline NiPS2PrePackedBuffers* NiSkinPartition::GetRendererData(
    unsigned int i) const
{
    return m_apkBuffers[i];
}

//---------------------------------------------------------------------------
inline void NiSkinPartition::SetRendererData(
    NiPS2PrePackedBuffers* pkBuffers, unsigned int i)
{
    m_apkBuffers[i] = pkBuffers;
}
//---------------------------------------------------------------------------
inline unsigned char& NiSkinPartition::GetRendererIndex()
{
    return m_ucIndex;
}
#endif
