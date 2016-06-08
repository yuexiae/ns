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
//  NiTriShapeData inline functions

//---------------------------------------------------------------------------
inline unsigned short* NiTriShapeData::GetTriList()
{
    return m_pusTriList;
}
//---------------------------------------------------------------------------
inline const unsigned short* NiTriShapeData::GetTriList() const
{
    return m_pusTriList;
}
//---------------------------------------------------------------------------
inline unsigned int NiTriShapeData::GetTriListLength() const
{
    return m_uiTriListLength;
}
//---------------------------------------------------------------------------
inline NiTriShapeData::SharedNormalArray::SharedNormalArray()
{
    m_usNumSharedNormals = 0;
    m_pusSharedNormalIndexArray = 0;
}
//---------------------------------------------------------------------------
inline unsigned short NiTriShapeData::SharedNormalArray::GetCount()
{
    return m_usNumSharedNormals;
}
//---------------------------------------------------------------------------
inline unsigned short* NiTriShapeData::SharedNormalArray::GetArray()
{
    return m_pusSharedNormalIndexArray;
}
//---------------------------------------------------------------------------
inline void NiTriShapeData::SharedNormalArray::SetArray(
    unsigned short usCount, unsigned short* aArray)
{
    if(!usCount || !aArray)
    {
        m_usNumSharedNormals = 0;
        m_pusSharedNormalIndexArray = NULL;
    }
    else
    {
        m_usNumSharedNormals = usCount;
        m_pusSharedNormalIndexArray = aArray;
    }
}
//---------------------------------------------------------------------------
inline NiTriShapeData::SNAMemBlock::SNAMemBlock()
{
    m_pusBlock = 0;
    m_pusFreeBlock = 0;
    m_uiBlockSize = 0;
    m_uiFreeBlockSize = 0;
    m_pkNext = 0;
}
//---------------------------------------------------------------------------
inline NiTriShapeData::SNAMemBlock::SNAMemBlock(unsigned int uiSize)
{
    m_pusBlock = new unsigned short[uiSize];
    m_pusFreeBlock = m_pusBlock;
    m_uiBlockSize = uiSize;
    m_uiFreeBlockSize = uiSize;
    m_pkNext = 0;
}
//---------------------------------------------------------------------------
inline NiTriShapeData::SNAMemBlock::~SNAMemBlock()
{
    delete[] m_pusBlock;

    // Iterate to next block
    delete m_pkNext;
}
//---------------------------------------------------------------------------
