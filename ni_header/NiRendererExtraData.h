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
#ifndef NIRENDEREREXTRADATA_H
#define NIRENDEREREXTRADATA_H

#include "NiD3DDefines.h"
#include "NiObject.h"

//---------------------------------------------------------------------------
class NID3D_ENTRY NiRendererExtraData : public NiObject
{
public:
    //  Data types
    enum
    {
        RED_NITYPE_INVALID  = 0,    //  Invalid - place holder...
        RED_NITYPE_FLOAT1   = 1,    //  Data is 1 float
        RED_NITYPE_FLOAT2,          //          2 floats
        RED_NITYPE_FLOAT3,          //          3
        RED_NITYPE_FLOAT4,          //          4
        RED_NITYPE_LONG1,           //  Data is 1 long
        RED_NITYPE_LONG2,           //          2 longs
        RED_NITYPE_LONG3,           //          2
        RED_NITYPE_LONG4,           //          2
        RED_NITYPE_ULONG1,          //  Data is 1 unsigned long
        RED_NITYPE_ULONG2,          //          2 unsigned longs
        RED_NITYPE_ULONG3,          //          2
        RED_NITYPE_ULONG4,          //          2
        RED_NITYPE_SHORT1,          //  Data is 1 short
        RED_NITYPE_SHORT2,          //          2 shorts
        RED_NITYPE_SHORT3,          //          3
        RED_NITYPE_SHORT4,          //          4
        RED_NITYPE_USHORT1,         //  Data is 1 unsigned short
        RED_NITYPE_USHORT2,         //          2 unsigned shorts
        RED_NITYPE_USHORT3,         //          3
        RED_NITYPE_USHORT4,         //          4
        RED_NITYPE_BYTE1,           //  Data is 1 byte
        RED_NITYPE_BYTE2,           //          2 bytes
        RED_NITYPE_BYTE3,           //          3
        RED_NITYPE_BYTE4,           //          4
        RED_NITYPE_UBYTE1,          //  Data is 1 unsigned byte
        RED_NITYPE_UBYTE2,          //          2 unsigned bytes
        RED_NITYPE_UBYTE3,          //          3
        RED_NITYPE_UBYTE4,          //          4
        RED_NITYPE_BLEND1,          //  Data is 1 blend weight
        RED_NITYPE_BLEND2,          //          2 blend weights
        RED_NITYPE_BLEND3,          //          3
        RED_NITYPE_BLEND4,          //          4
        //  NOTE: Do NOT use the RED_NITYPE_COUNT
        RED_NITYPE_COUNT,           //  Count of NiTypes for data...
        RED_TYPE_CUSTOM     = RED_NITYPE_COUNT + 1,
    };

    virtual ~NiRendererExtraData();

    static NiRendererExtraData* Create(unsigned int uiDataStreamCount);

    bool SetDataBlock(unsigned int uiIndex, unsigned char* pucData, 
        unsigned int uiTotalSize);
    const unsigned char* GetDataBlock(unsigned int uiIndex, 
        unsigned int& uiBlockSize);
    bool RemoveDataBlock(unsigned int uiIndex);

    virtual bool SetDataStream(unsigned int uiStreamIndex, 
        unsigned char* pucData, unsigned int uiType, 
        unsigned int uiCount, unsigned int uiUnitSize, 
        unsigned int uiStride);
    virtual unsigned int GetDataStreamType(unsigned int uiStreamIndex);
    virtual unsigned int GetDataStreamCount(unsigned int uiStreamIndex);
    virtual unsigned int GetDataStreamUnitSize(unsigned int uiStreamIndex);
    virtual unsigned int GetDataStreamTotalSize(unsigned int uiStreamIndex);
    virtual unsigned int GetDataStreamStride(unsigned int uiStreamIndex);
    virtual unsigned char* GetDataStreamData(unsigned int uiStreamIndex);
    virtual bool GetDataStream(unsigned int uiStreamIndex, 
        unsigned char*& pucData, unsigned int uiType, 
        unsigned int& uiCount, unsigned int& uiTotalSize, 
        unsigned int& uiUnitSize, unsigned int& uiStride);
    virtual bool RemoveDataStream(unsigned int uiStreamIndex);


    // *** begin NDL internal use only ***

    // Bookkeeping
    void IncRevisionID();
    unsigned int GetRevisionID() const;
    void SetRevisionID(unsigned int uiRevID);

    // *** end NDL internal use only ***

protected:
    NiRendererExtraData();

    class NID3D_ENTRY NiREDDataStream
    {
    public:
        unsigned int m_uiType;      //  Type of data
        unsigned int m_uiCount;     //  Total 'members' of data
        unsigned int m_uiUnitSize;  //  Size of 'member' of data (in bytes)
        unsigned int m_uiTotalSize; //  Total size of data (in bytes)
        unsigned int m_uiStride;    //  Stride between data (in bytes)
        unsigned char* m_pucData;   //  Pointer to data

        NiREDDataStream();
    };

    class NID3D_ENTRY NiREDDataBlock
    {
    public:
        unsigned int m_uiDataBlockSize; //  Size of data block
        unsigned char* m_pucDataBlock;  //  Actual block of data.

        NiREDDataBlock();
    };

    unsigned int m_uiRevID;

    unsigned int m_uiDataStreamCount;
    NiREDDataStream* m_pkDataStreamEntries;

    NiTArray<NiREDDataBlock*> m_aDataBlocks;
};

NiSmartPointer(NiRendererExtraData);

//---------------------------------------------------------------------------
#include "NiRendererExtraData.inl"

//---------------------------------------------------------------------------

#endif  //#ifndef NIRENDEREREXTRADATA_H
