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
inline NiRendererExtraData::NiREDDataStream::NiREDDataStream()
{
    m_uiType = RED_NITYPE_INVALID;
    m_uiCount = 0;
    m_uiUnitSize = 0;
    m_uiTotalSize = 0;
    m_uiStride = 0;
    m_pucData = 0;
}
//---------------------------------------------------------------------------
inline NiRendererExtraData::NiREDDataBlock::NiREDDataBlock()
{
    m_uiDataBlockSize = 0;
    m_pucDataBlock = 0;
}
//---------------------------------------------------------------------------
inline void NiRendererExtraData::IncRevisionID()
{
    m_uiRevID++;
}
//---------------------------------------------------------------------------
inline unsigned int NiRendererExtraData::GetRevisionID() const
{
    return m_uiRevID;
}
//---------------------------------------------------------------------------
inline void NiRendererExtraData::SetRevisionID(unsigned int uiRevID)
{
    m_uiRevID = uiRevID;
}
//---------------------------------------------------------------------------
inline NiRendererExtraData::NiRendererExtraData()
{
    m_uiRevID = 0;

    m_uiDataStreamCount = 0;
    m_pkDataStreamEntries = 0;

    m_aDataBlocks.RemoveAll();
}
//---------------------------------------------------------------------------
