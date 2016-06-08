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

#ifndef NIPS2READBACKSHAREDDATA_H
#define NIPS2READBACKSHAREDDATA_H

#include "NiStandardSharedDataLibType.h"
#include "NiSharedData.h"
#include "NiPSX2CBData.h"
#include <NiPS2GeometryStreamer.h>

/// A shared data object to contain a PS2 ReadBackData pointer.
class NISTANDARDSHAREDDATA_ENTRY NiPS2ReadBackSharedData : public NiSharedData
{
public:
    NiDeclareRTTI;

    /// Default constructor.
    NiPS2ReadBackSharedData(NiPSX2ReadBackData* pkReadBackData,
        unsigned int uiNumEntries);

    /// Virtual destructor.
    virtual ~NiPS2ReadBackSharedData();

    /// Gets a pointer to the ReadBackData.
    /// @return A pointer to the current ReadBackData.
    NiPSX2ReadBackData* GetReadBackData();

    /// Gets the number of entries
    unsigned int GetNumEntries();

    void SetReadBackData(NiPSX2ReadBackData* pkReadBackData, 
        unsigned int uiNumEntries);

    NiPS2GeometryStreamer* GetPS2Geometry() const;
    void SetPS2Geometry(NiPS2GeometryStreamer* pkPS2Geom);

protected:
    NiPSX2ReadBackData* m_pkReadBackData;
    unsigned int m_uiNumEntries;
    NiPS2GeometryStreamerPtr m_spPS2Geom;
};

NiSmartPointer(NiPS2ReadBackSharedData);

#endif  // #ifndef NIPS2READBACKSHAREDDATA_H
