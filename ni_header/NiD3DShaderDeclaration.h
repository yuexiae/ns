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
#ifndef NID3DSHADERDECLARATION_H
#define NID3DSHADERDECLARATION_H

#include "NiD3DDefines.h"
#include "NiRendererExtraData.h"

#include <NiSkinPartition.h>

class NiGeometryData;
class NiRenderer;
class NiSkinInstance;
class NiVBChip;

//---------------------------------------------------------------------------
class NID3D_ENTRY NiD3DShaderDeclaration : public NiObject
{
public:
    // The ShaderParameter tell what data to use for the data fragment.
    // The NI_* values represent the data from the NiGeometryData object that
    // is being packed. 
    // SHADERPARAM_NI_POSITION      represents m_pkVertex
    // SHADERPARAM_NI_BLENDWEIGHT   represents SKINNED weights
    // SHADERPARAM_NI_NORMAL        represents m_pkNormal
    // SHADERPARAM_NI_COLOR         represents m_pkColor
    // SHADERPARAM_NI_TEXCOORD0     represents m_pkTexture set 0
    // SHADERPARAM_NI_TEXCOORD1     represents m_pkTexture set 1
    // SHADERPARAM_NI_TEXCOORD2     represents m_pkTexture set 2
    // SHADERPARAM_NI_TEXCOORD3     represents m_pkTexture set 3
    // SHADERPARAM_NI_TEXCOORD4     represents m_pkTexture set 4
    // SHADERPARAM_NI_TEXCOORD5     represents m_pkTexture set 5
    // SHADERPARAM_NI_TEXCOORD6     represents m_pkTexture set 6
    // SHADERPARAM_NI_TEXCOORD7     represents m_pkTexture set 7
    // SHADERPARAM_NI_TANGENT       represents m_pkNormal set 2
    // SHADERPARAM_NI_BINORMAL      represents m_pkNormal set 1
    // SHADERPARAM_DATA_ZERO        fills data w/ 0.0f (or 0, if not float)
    // SHADERPARAM_DATA_ONE         fills data w/ 1.0f (or 1, if not float)
    // SHADERPARAM_EXTRA_DATA_MASK  used to indicate 'extra data' be used
    enum ShaderParameter
    {
        SHADERPARAM_INVALID     = -1,
        SHADERPARAM_NI_POSITION =  0,   // Gamebryo Position
        SHADERPARAM_NI_BLENDWEIGHT,     // Gamebryo skinning blend weight
        SHADERPARAM_NI_BLENDINDICES,    // Gamebryo skinning blend indices
        SHADERPARAM_NI_NORMAL,          // Gamebryo normal
        SHADERPARAM_NI_COLOR,           // Gamebryo color
        SHADERPARAM_NI_TEXCOORD0,       // Gamebryo UVSet 0
        SHADERPARAM_NI_TEXCOORD1,       // Gamebryo UVSet 1
        SHADERPARAM_NI_TEXCOORD2,       // Gamebryo UVSet 2
        SHADERPARAM_NI_TEXCOORD3,       // Gamebryo UVSet 3
        SHADERPARAM_NI_TEXCOORD4,       // Gamebryo UVSet 4
        SHADERPARAM_NI_TEXCOORD5,       // Gamebryo UVSet 5
        SHADERPARAM_NI_TEXCOORD6,       // Gamebryo UVSet 6
        SHADERPARAM_NI_TEXCOORD7,       // Gamebryo UVSet 7
        SHADERPARAM_NI_TANGENT,         // Gamebryo Tangent Data
        SHADERPARAM_NI_BINORMAL,        // Gamebryo BiNormal Data
        SHADERPARAM_DATA_ZERO,          // Data set to 0
        SHADERPARAM_DATA_ONE,           // Data set to 1
        // NOTE: SkipCount usage is indicated by ANDing the skip count
        // w/ the SKIP_COUNT_MASK. For example, skip data
        // for 8 units would be used with a value of 0x40000008.
        SHADERPARAM_SKIP_COUNT_MASK = 0x40000000,
        // Insert new parameters here!
        // NOTE: ExtraData usage is indicated by ANDing the extra data 
        // stream number w/ the EXTRA_DATA_MASK. For example, extra data
        // stream 1 would be used with a value of 0x80000001.
        SHADERPARAM_EXTRA_DATA_MASK = 0x80000000,
    };

    //  The shader parameter type represents how to output the data
#if defined(_XENON)
    enum ShaderParameterType
    {
        SPTYPE_FLOAT1 = 0,  // 1D float (val,0,0,1)
        SPTYPE_FLOAT2,      // 2D float (val,val,0,1)
        SPTYPE_FLOAT3,      // 3D float (val,val,val,1)
        SPTYPE_FLOAT4,      // 4D float
        SPTYPE_UBYTECOLOR,  // 4D unsigned bytes mapped to 0..1 range
        SPTYPE_UBYTE4,      // 4D unsigned byte (val,val,val,val)
        SPTYPE_SHORT2,      // 2D signed short (val,val,0,1)
        SPTYPE_SHORT4,      // 4D signed short (val,val,val,val)
        SPTYPE_NORMUBYTE4,  // 4D normalized unsigned byte (val,val,val,val)
        SPTYPE_NORMSHORT2,  // 2D normalized signed short (val,val,0,1)
        SPTYPE_NORMSHORT4,  // 4D normalized signed short (val,val,val,val)
        SPTYPE_NORMUSHORT2, // 2D normalized unsigned short (val,val,0,1)
        SPTYPE_NORMUSHORT4, // 4D normalized unigned short (val,val,val,val)
        SPTYPE_UDEC3,       // 3D unsigned 10 10 10 (val,val,val,1)
        SPTYPE_NORMDEC3,    // 3D normalized signed 10 10 10 (val,val,val,1)
        SPTYPE_FLOAT16_2,   // 2D signed 16-bit float (val,val,0,1)
        SPTYPE_FLOAT16_4,   // 4D signed 16-bit float (val,val,val,val)
        SPTYPE_NONE,        // No stream data
        SPTYPE_COUNT        // Count must appear last
    };
#elif defined(_XBOX)
    enum ShaderParameterType
    {
        SPTYPE_FLOAT1 = 0,  // 1D float (val,0,0,1)
        SPTYPE_FLOAT2,      // 2D float (val,val,0,1)
        SPTYPE_FLOAT3,      // 3D float (val,val,val,1)
        SPTYPE_FLOAT4,      // 4D float
        SPTYPE_UBYTECOLOR,  // 4D packed unsigned bytes mapped to 0..1 range
        SPTYPE_SHORT1,      // 1D signed short (val,0,0,1)  
                            // Signed shorts map to the range [-32768, 32767]
        SPTYPE_SHORT2,      // 2D signed short (val,val,0,1)
        SPTYPE_SHORT3,      // 3D signed short (val,val,val,1)
        SPTYPE_SHORT4,      // 4D signed short
        SPTYPE_NORMSHORT1,  // 1D signed normalized short (val,0,0,1)
        SPTYPE_NORMSHORT2,  // 2D signed normalized short (val,val,0,1)
        SPTYPE_NORMSHORT3,  // 3D signed normalized short (val,val,val,1)
        SPTYPE_NORMSHORT4,  // 4D signed normalized short (val,val,val,val)
        SPTYPE_NORMPACKED3, // 3 signed, normalized components packed in 
                            // 32-bits.  (11,11,10).  Each component ranges 
                            // from -1.0 to 1.0.  Expanded to (val,val,val,1)
        SPTYPE_PBYTE1,      // 1D packed byte expanded to (value, 0., 0., 1.)  
                            // Packed bytes map to the range [0, 1]
        SPTYPE_PBYTE2,      // 2D packed byte (val,val,0,1)
        SPTYPE_PBYTE3,      // 3D packed byte (val,val,val,1)
        SPTYPE_PBYTE4,      // 4D packed byte (val,val,val,val) 
        SPTYPE_FLOAT2H,     // 2D homogeneous float (val,val,0,val)
                            // Useful for projective texture coordinates.
        SPTYPE_SKIP_DWORD,  // Skip # dwords...
        SPTYPE_SKIP_BYTES,  // Skip # bytes...
        SPTYPE_NONE,        // No stream data
        SPTYPE_COUNT,       // Count must appear last
    };
#elif defined(_DX9)
    enum ShaderParameterType
    {
        SPTYPE_FLOAT1 = 0,  // 1D float (val,0,0,1)
        SPTYPE_FLOAT2,      // 2D float (val,val,0,1)
        SPTYPE_FLOAT3,      // 3D float (val,val,val,1)
        SPTYPE_FLOAT4,      // 4D float
        SPTYPE_UBYTECOLOR,  // 4D unsigned bytes mapped to 0..1 range
        SPTYPE_UBYTE4,      // 4D unsigned byte (val,val,val,val)
        SPTYPE_SHORT2,      // 2D signed short (val,val,0,1)
        SPTYPE_SHORT4,      // 4D signed short (val,val,val,val)
        SPTYPE_NORMUBYTE4,  // 4D normalized unsigned byte (val,val,val,val)
        SPTYPE_NORMSHORT2,  // 2D normalized signed short (val,val,0,1)
        SPTYPE_NORMSHORT4,  // 4D normalized signed short (val,val,val,val)
        SPTYPE_NORMUSHORT2, // 2D normalized unsigned short (val,val,0,1)
        SPTYPE_NORMUSHORT4, // 4D normalized unigned short (val,val,val,val)
        SPTYPE_UDEC3,       // 3D unsigned 10 10 10 (val,val,val,1)
        SPTYPE_NORMDEC3,    // 3D normalized signed 10 10 10 (val,val,val,1)
        SPTYPE_FLOAT16_2,   // 2D signed 16-bit float (val,val,0,1)
        SPTYPE_FLOAT16_4,   // 4D signed 16-bit float (val,val,val,val)
        SPTYPE_NONE,        // No stream data
        SPTYPE_COUNT        // Count must appear last
    };
#elif defined(_DX8)
    enum ShaderParameterType
    {
        SPTYPE_FLOAT1 = 0,  // 1D float (val,0,0,1)
        SPTYPE_FLOAT2,      // 2D float (val,val,0,1)
        SPTYPE_FLOAT3,      // 3D float (val,val,val,1)
        SPTYPE_FLOAT4,      // 4D float
        SPTYPE_UBYTECOLOR,  // 4D packed unsigned bytes mapped to 0..1 range
        SPTYPE_SHORT2,      // 2D signed short (val,val,0,1)
        SPTYPE_SHORT4,      // 4D signed short
        SPTYPE_UBYTE4,      // 4D packed byte (val,val,val,val) 
        SPTYPE_NONE,        // No stream data
        SPTYPE_COUNT,       // Count must appear last
    };
#else
    #error _XENON, _XBOX, _DX9, or _DX8 must be specified
#endif

    enum ShaderParameterTesselator
    {
        SPTESS_DEFAULT,
        SPTESS_PARTIALU,
        SPTESS_PARTIALV,
        SPTESS_CROSSUV,
        SPTESS_UV,
        SPTESS_LOOKUP,
        SPTESS_LOOKUPPRESAMPLED,
        SPTESS_COUNT
    };

    enum ShaderParameterUsage
    {
        SPUSAGE_POSITION,
        SPUSAGE_BLENDWEIGHT,
        SPUSAGE_BLENDINDICES,
        SPUSAGE_NORMAL,
        SPUSAGE_PSIZE,
        SPUSAGE_TEXCOORD,
        SPUSAGE_TANGENT,
        SPUSAGE_BINORMAL,
        SPUSAGE_TESSFACTOR,
        SPUSAGE_POSITIONT,
        SPUSAGE_COLOR,
        SPUSAGE_FOG,
        SPUSAGE_DEPTH,
        SPUSAGE_SAMPLE,
        SPUSAGE_COUNT
    };

    //  Entry for a shader register
    class ShaderRegisterEntry
    {
    public:
        unsigned int m_uiRegister;
        unsigned int m_uiPackingOffset;
        ShaderParameter m_eInput;
        ShaderParameterType m_eType;
        ShaderParameterTesselator m_eTesselator;
        ShaderParameterUsage m_eUsage;
        unsigned int m_uiUsageIndex;

        ShaderRegisterEntry();
    };

    //  Collection of entries for a single stream
    class ShaderRegisterStream
    {
    public:
        bool m_bValid;
        unsigned int m_uiEntryCount;
        ShaderRegisterEntry* m_pkEntries;
        unsigned int m_uiStride;

        ShaderRegisterStream()
        {
            m_bValid = false;
            m_uiEntryCount = 0;
            m_pkEntries = 0;
            m_uiStride = 0;
        };
    };

    //  Packer function
    //  usCount     - number of elements to process
    //  pvInData    - ptr to data to use as input stream
    //  uiInSize    - size of input element
    //  uiInStride  - stride between input elements
    //  uiOutSize   - size of output element
    //  uiOutStride - stride between output elements
    //  pvOutData   - ptr to data to pack into
    //
    //  Had to put this in a class dues to the usage of NiTArray causing
    //  name overrun problems (limit of 256 characters) - which would hinder
    //  debugging.
    class PackingParameters
    {
    public:
        ShaderParameterType m_ePackType;
        unsigned int m_uiDataType;
        unsigned short m_usCount;
        unsigned short* m_pusVertexMap;
        void* m_pvInData;
        unsigned int m_uiInSize;
        unsigned int m_uiInStride;
        unsigned int m_uiOutSize;
        unsigned int m_uiOutStride;
        void* m_pvOutData;
    };

    //  The Packer function returns the total bytes packed into the stream.
    typedef unsigned int (*Packer)(PackingParameters& kParams);

    class NiPackerEntry
    {
    public:
        unsigned int m_uiShaderParameterType;
        NiTArray<Packer> m_kPackFunctions;

        NiPackerEntry();
        NiPackerEntry(const NiPackerEntry& kSrc);
        ~NiPackerEntry();

        bool operator==(const NiPackerEntry& kSrc);
        bool operator!= (const NiPackerEntry& kSrc);
        NiPackerEntry& operator=(const NiPackerEntry& kSrc);
    };

    virtual ~NiD3DShaderDeclaration();

    static Packer RegisterPackingFunction(ShaderParameterType eType, 
        unsigned int uiREDType, Packer pfnPack);
    static unsigned int GetTypeSize(ShaderParameterType eType);

    //  Entry Access Functions
    virtual bool SetEntry(unsigned int uiEntry, unsigned int uiRegister, 
        ShaderParameter eInput, ShaderParameterType eType, 
        unsigned int uiStream = 0) = 0;
    virtual bool SetEntry(unsigned int uiStream, unsigned int uiEntry, 
        unsigned int uiRegister, ShaderParameter eInput, 
        ShaderParameterType eType, ShaderParameterUsage eUsage,
        unsigned int uiIndex, ShaderParameterTesselator eTess) = 0;
    virtual bool RemoveEntry(unsigned int uiEntry, unsigned int uiStream = 0)
        = 0;
    virtual bool SetConstantData(unsigned int uiStartRegister, 
        unsigned int uiNumRegisters, float* pfData);
    virtual bool ClearAllEntries(unsigned int uiStream = 0) = 0;
    bool ClearAllStreams();

    //  Shader related functions
    virtual unsigned int GetVertexStride(unsigned int uiStream) = 0;
    unsigned int GetStreamCount() const;

    virtual void SetSoftwareVertexProcessing(bool bSoftwareVB);
    virtual bool GetSoftwareVertexProcessing() const;

    // *** begin NDL internal use only ***

    //-----------------------------------------------------------------------
    //  Default data packing functions
    static unsigned int Pack_IllegalCombination(PackingParameters& kParams);
    static unsigned int Pack_DirectMapping(PackingParameters& kParams);
    static unsigned int Pack_DropInFields(PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Float output packers
    //  NOTE #-# packing uses DirectMapping fcn.
    //  In > Out uses DropInFields.
    //  In < Out uses ExtraOutsToZero or ExtraOutsToOne.
    static unsigned int Pack_Float_DropIns(PackingParameters& kParams);
    static unsigned int Pack_Float_ExtraOutsToZero(
        PackingParameters& kParams);
    static unsigned int Pack_Float_ExtraOutsToOne(PackingParameters& kParams);
    static unsigned int Pack_FloatToFloat(PackingParameters& kParams);
    //  Must know input size for skinning...
    static unsigned int Pack_Float4ToFloat(PackingParameters& kParams);
    static unsigned int Pack_Float3ToFloat(PackingParameters& kParams);
    static unsigned int Pack_Float2ToFloat(PackingParameters& kParams);
    static unsigned int Pack_Float1ToFloat(PackingParameters& kParams);
    //  
    static unsigned int Pack_LongToFloat(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToFloat(PackingParameters& kParams);
    static unsigned int Pack_ShortToFloat(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToFloat(PackingParameters& kParams);
    static unsigned int Pack_ByteToFloat(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToFloat(PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  UByteColor output packers
    static unsigned int Pack_FloatToUByteColor(PackingParameters& kParams);
    static unsigned int Pack_LongToUByteColor(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToUByteColor(
        PackingParameters& kParams);
    static unsigned int Pack_ShortToUByteColor(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToUByteColor(
        PackingParameters& kParams);
    static unsigned int Pack_ByteToUByteColor(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToUByteColor(
        PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Short output packers
    static unsigned int Pack_FloatToShort(PackingParameters& kParams);
    static unsigned int Pack_LongToShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToShort(PackingParameters& kParams);
    static unsigned int Pack_ShortToShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToShort(PackingParameters& kParams);
    static unsigned int Pack_ByteToShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToShort(PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Normalized short output packers
    static unsigned int Pack_FloatToNormalizeShort(
        PackingParameters& kParams);
    static unsigned int Pack_LongToNormalizeShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToNormalizeShort(
        PackingParameters& kParams);
    static unsigned int Pack_ShortToNormalizeShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToNormalizeShort(
        PackingParameters& kParams);
    static unsigned int Pack_ByteToNormalizeShort(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToNormalizeShort(
        PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Normalize packed output packers
    static unsigned int Pack_FloatToNormalizedPacked(
        PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Packed byte output packers
    static unsigned int Pack_FloatToPackedByte(PackingParameters& kParams);
    static unsigned int Pack_LongToPackedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToPackedByte(
        PackingParameters& kParams);
    static unsigned int Pack_ShortToPackedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToPackedByte(
        PackingParameters& kParams);
    static unsigned int Pack_ByteToPackedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToPackedByte(
        PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  Unsigned byte output packers
    static unsigned int Pack_FloatToUnsignedByte(PackingParameters& kParams);
    static unsigned int Pack_LongToUnsignedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedLongToUnsignedByte(
        PackingParameters& kParams);
    static unsigned int Pack_ShortToUnsignedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedShortToUnsignedByte(
        PackingParameters& kParams);
    static unsigned int Pack_ByteToUnsignedByte(PackingParameters& kParams);
    static unsigned int Pack_UnsignedByteToUnsignedByte(
        PackingParameters& kParams);
    //-----------------------------------------------------------------------
    //  2D Homogeneous float output packers
    static unsigned int Pack_FloatTo2DHomogenous(PackingParameters& kParams);

    static bool InitializePackingFunctions();

    virtual NiVBChip* PackUntransformedVB(NiGeometryData* pkData, 
        NiSkinInstance* pkSkin, NiSkinPartition::Partition* pkPartition, 
        NiRendererExtraData* pkExtraData, unsigned short usDirtyFlags,
        NiVBChip* pkOldVBChip, unsigned int uiStream, 
        void* pvLockedBuff = NULL) = 0;

    virtual bool GenerateVertexParameters(
        NiD3DVertexDeclaration& kDeclaration, 
        unsigned int& uiNumStreams) = 0;

    virtual NiD3DVertexDeclaration GetD3DDeclaration();

    static void _SDMInit();
    static void _SDMShutdown();
    // *** end NDL internal use only ***

protected:
    NiD3DShaderDeclaration();

    bool Initialize(NiRenderer* pkRenderer, 
        unsigned int uiMaxStreamEntryCount, unsigned int uiStreamCount);

    unsigned int PackEntry(unsigned short usCount, NiGeometryData* pkData, 
        const NiSkinInstance* pkSkin, 
        NiSkinPartition::Partition* pkPartition, 
        NiRendererExtraData* pkExtraData, 
        ShaderRegisterEntry* pkEntry,
        unsigned int uiStride, unsigned char* pucData);

    static void SetDefaultPackingFunctions();
    static void SetDefaultPackingFunction(ShaderParameterType eType, 
        unsigned int uiREDType);

    NiD3DRenderer* m_pkRenderer;
    NiD3DVBManager* m_pkVBManager;
    D3DDevicePtr m_pkD3DDevice;

    unsigned int m_uiDeclSize;
    unsigned int m_uiCurrDeclIndex;
    
    unsigned int m_uiMaxStreamEntryCount;
    unsigned int m_uiStreamCount;
    ShaderRegisterStream* m_pkStreamEntries;

    bool m_bModified;

    static unsigned int ms_auiTypeSizes[SPTYPE_COUNT];
    static NiTArray<NiPackerEntry*>* ms_pkPackFunctions;
};

NiSmartPointer(NiD3DShaderDeclaration);

#include "NiD3DShaderDeclaration.inl"

#endif  //#ifndef NID3DSHADERDECLARATION_H
