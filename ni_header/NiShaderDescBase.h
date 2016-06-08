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

#ifndef NISHADERDESCBASE_H
#define NISHADERDESCBASE_H

// These classes and functions are used for DLL-based shader libraries
#include "NiRefObject.h"
#include "NiSmartPointer.h"

class NiBinaryStream;

// Description of a shader implementation
class NIMAIN_ENTRY NiShaderDescBase : public NiRefObject
{
public:
    NiShaderDescBase();
    virtual ~NiShaderDescBase();

    virtual const char* GetName() const;
    virtual const char* GetDescription() const;

    // *** begin NDL internal use only ***
    virtual void SetName(const char* pszName);
    virtual void SetDescription(const char* pszDesc);

    // Not actual NIF/NiStream streaming code - only for reading from/
    // writing to a generic NiBinaryStream.
    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);
    // *** end NDL internal use only ***

protected:
    char* m_pszName;
    char* m_pszDesc;

    // Streaming helper code - belongs somewhere else?
    // Write to stream
    static bool WriteString(NiBinaryStream& kStream, const char* pszString);
    static bool WriteUInt(NiBinaryStream& kStream, unsigned int uiValue);
    static bool WriteUInts(NiBinaryStream& kStream, unsigned int* puiValue, 
        unsigned int uiCount);
    static bool WriteFloat(NiBinaryStream& kStream, float fValue);
    static bool WriteFloats(NiBinaryStream& kStream, float* pfValue, 
        unsigned int uiCount);
    static bool WriteData(NiBinaryStream& kStream, void* pvData,
        unsigned int uiSize);

    // Read from stream
    static bool ReadString(NiBinaryStream& kStream, char* pszString,
        unsigned int& uiMaxLen);
    static bool AllocateAndReadString(NiBinaryStream& kStream, 
        char*& pszString);
    static bool ReadUInt(NiBinaryStream& kStream, unsigned int& uiValue);
    static bool ReadUInts(NiBinaryStream& kStream, unsigned int* puiValue, 
        unsigned int uiCount);
    static bool ReadFloat(NiBinaryStream& kStream, float& fValue);
    static bool ReadFloats(NiBinaryStream& kStream, float* pfValue, 
        unsigned int uiCount);
    static bool ReadData(NiBinaryStream& kStream, void*& pvData,
        unsigned int& uiSize);
    static bool AllocateAndReadData(NiBinaryStream& kStream, void*& pvData);
};

typedef NiPointer<NiShaderDescBase> NiShaderDescBasePtr;

#endif  //#ifndef NISHADERDESCBASE_H
