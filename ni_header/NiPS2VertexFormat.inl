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
inline NiPS2VertexFormat::NiPS2VertexFormat()
{
    m_ucFormat = 0;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddFloatNormals()
{
    m_ucFormat |= NORMAL_32BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddCompressedNormals()
{
    m_ucFormat |= NORMAL_8BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddFloatTextureCoords()
{
    m_ucFormat |= TEXTURE_32BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddCompressedTextureCoords()
{
    m_ucFormat |= TEXTURE_16BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddFloatColors()
{
    m_ucFormat |= COLOR_32BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddCompressedColors()
{
    m_ucFormat |= COLOR_8BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddFloatWeights()
{
    m_ucFormat |= WEIGHT_32BIT_MASK;
}

//---------------------------------------------------------------------------
inline void NiPS2VertexFormat::AddCompressedWeights()
{
    m_ucFormat |= WEIGHT_8BIT_MASK;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasNormals() const
{
    return (m_ucFormat & NORMAL_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasTextureCoords() const
{
    return (m_ucFormat & TEXTURE_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasColors() const
{
    return (m_ucFormat & COLOR_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasWeights() const
{
    return (m_ucFormat & WEIGHT_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasCompressedNormals() const
{
    return (m_ucFormat & NORMAL_8BIT_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasCompressedTextureCoords() const
{
    return (m_ucFormat & TEXTURE_16BIT_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasCompressedColors() const
{
    return (m_ucFormat & COLOR_8BIT_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasCompressedWeights() const
{
    return (m_ucFormat & WEIGHT_8BIT_MASK) != 0;
}

//---------------------------------------------------------------------------
inline bool NiPS2VertexFormat::HasCompressedAny() const
{
    return (m_ucFormat & (NORMAL_8BIT_MASK | TEXTURE_16BIT_MASK | 
        COLOR_8BIT_MASK | WEIGHT_8BIT_MASK)) != 0;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point2Quads(unsigned int uiVerts)
{
    return (uiVerts + 1) / 2;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point3Quads(unsigned int uiVerts)
{
    return (3 * uiVerts + 3) / 4;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point4Quads(unsigned int uiVerts)
{
    return uiVerts;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Bit32Slices(unsigned int uiVerts)
{
    return (uiVerts + 31) / 32;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point2Slices(unsigned int uiVerts)
{
    return (uiVerts + 15) / 16;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point3Slices(unsigned int uiVerts)
{
    return (3 * uiVerts + 31) / 32;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::Point4Slices(unsigned int uiVerts)
{
    return (uiVerts + 7) / 8;
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::GetNormalSlices(unsigned int uiVerts)
    const
{
    assert(HasNormals());

    return ((m_ucFormat & NORMAL_8BIT_MASK) ? Bit32Slices : Point3Slices)(
        uiVerts);
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::GetTextureSlices(unsigned int uiVerts)
    const
{
    assert(HasTextureCoords());

    return ((m_ucFormat & TEXTURE_16BIT_MASK) ? Bit32Slices : Point2Slices)(
        uiVerts);
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::GetColorSlices(unsigned int uiVerts)
    const
{
    assert(HasColors());

    return ((m_ucFormat & COLOR_8BIT_MASK) ? Bit32Slices : Point4Slices)(
        uiVerts);
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::GetWeightSlices(unsigned int uiVerts)
    const
{
    assert(HasWeights());

    return ((m_ucFormat & WEIGHT_8BIT_MASK) ? Bit32Slices : Point4Slices)(
        uiVerts);
}

//---------------------------------------------------------------------------
inline unsigned int NiPS2VertexFormat::GetParamCount() const
{
    return 1 + HasTextureCoords() + HasNormals() + HasColors() + HasWeights();
}