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

#ifndef NISCMEXTRADATA_H
#define NISCMEXTRADATA_H

#include "NiExtraData.h"

class NIMAIN_ENTRY NiSCMExtraData : public NiExtraData
{
    NiDeclareRTTI;

public:
  	class SCMExtraDataEntry
	{
	public:
		unsigned int m_uiIndex;
		NiExtraData* m_pkExtraData;
	};

    enum ShaderProgramType
    {
        VERTEX = 0x00000000,
        PIXEL = 0x00000001,
        NUM_TYPES
    };

    NiSCMExtraData(const char* pcName, unsigned int uiNumVertexEntries,
        unsigned int uiNumPixelEntries);
    virtual ~NiSCMExtraData();

    virtual bool IsStreamable() const;
    virtual bool IsCloneable() const;

    void AddEntry(unsigned int uiConstantIndex, unsigned int uiPass,
        ShaderProgramType eType, NiExtraData* pkExtraData,
        bool bGlobal = false);
    NiExtraData* GetNextEntry(unsigned int uiConstantIndex, unsigned int uiPass,
        ShaderProgramType eType, bool bGlobal = false);
    void Reset();

protected:
    static const unsigned int m_uiPassShift;

    // Using matched arrays here. 0 holds vertex info and 1 holds pixel info.
	unsigned int m_auiNumEntries[NUM_TYPES];
	unsigned int m_auiCurrentEntry[NUM_TYPES];
    SCMExtraDataEntry* m_apkEntries[NUM_TYPES];
};

NiSmartPointer(NiSCMExtraData);

#include "NiSCMExtraData.inl"

#endif

