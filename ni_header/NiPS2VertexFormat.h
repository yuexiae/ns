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

#ifndef NIPS2VERTEXFORMAT_H
#define NIPS2VERTEXFORMAT_H

#include <NiRTLib.h>

class NiStream;

class NiPS2VertexFormat
{
public:
    NiPS2VertexFormat();

    unsigned int Configure(unsigned int uiVerts, unsigned int uiTextures,
        bool bNormal, bool bRGBA, bool bWeight, unsigned int uiCompressFlags);

    void AddFloatNormals();
    void AddCompressedNormals();
    void AddFloatTextureCoords();
    void AddCompressedTextureCoords();
    void AddFloatColors();
    void AddCompressedColors();
    void AddFloatWeights();
    void AddCompressedWeights();

    bool HasNormals() const;
    bool HasTextureCoords() const;
    bool HasColors() const;
    bool HasWeights() const;

    bool HasCompressedNormals() const;
    bool HasCompressedTextureCoords() const;
    bool HasCompressedColors() const;
    bool HasCompressedWeights() const;
    bool HasCompressedAny() const;

    unsigned int GetNormalSlices(unsigned int uiVerts) const;
    unsigned int GetTextureSlices(unsigned int uiVerts) const;
    unsigned int GetColorSlices(unsigned int uiVerts) const;
    unsigned int GetWeightSlices(unsigned int uiVerts) const;
    unsigned int GetParamCount() const;

    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);

    void NiPS2VertexFormat::GetPackedOffsets(unsigned int uiVerts,
        unsigned int uiTextures, unsigned int& uiTexOffset,
        unsigned int& uiNormOffset, unsigned int& uiColorOffset,
        unsigned int& uiWeightOffset) const;

    static unsigned int Point2Quads(unsigned int uiVerts);
    static unsigned int Point3Quads(unsigned int uiVerts);
    static unsigned int Point4Quads(unsigned int uiVerts);
    static unsigned int Bit32Slices(unsigned int uiVerts);
    static unsigned int Point2Slices(unsigned int uiVerts);
    static unsigned int Point3Slices(unsigned int uiVerts);
    static unsigned int Point4Slices(unsigned int uiVerts);

protected:

    enum
    {
        TEXTURE_16BIT_MASK = 0x01,
        NORMAL_8BIT_MASK   = 0x02,
        COLOR_8BIT_MASK    = 0x04,
        WEIGHT_8BIT_MASK   = 0x08,

        TEXTURE_32BIT_MASK = 0x10,
        NORMAL_32BIT_MASK  = 0x20,
        COLOR_32BIT_MASK   = 0x40,
        WEIGHT_32BIT_MASK  = 0x80,

        TEXTURE_MASK = TEXTURE_32BIT_MASK | TEXTURE_16BIT_MASK,
        NORMAL_MASK = NORMAL_32BIT_MASK | NORMAL_8BIT_MASK,
        COLOR_MASK = COLOR_32BIT_MASK | COLOR_8BIT_MASK,
        WEIGHT_MASK = WEIGHT_8BIT_MASK | WEIGHT_32BIT_MASK
    };

    unsigned char m_ucFormat;
};

#include "NiPS2VertexFormat.inl"

#endif // NIPS2VERTEXFORMAT_H