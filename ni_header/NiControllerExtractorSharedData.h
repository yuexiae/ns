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

#ifndef NICONTROLLEREXTRACTORSHAREDDATA_H
#define NICONTROLLEREXTRACTORSHAREDDATA_H

#include "NiStandardSharedDataLibType.h"
#include "NiSharedData.h"
#include <NiControllerExtractor.h>

/// This shared data class contains information necessary for the
/// controller extractor plug-in.
class NISTANDARDSHAREDDATA_ENTRY NiControllerExtractorSharedData :
    public NiSharedData
{
public:
    NiDeclareRTTI;

    /// Default constructor.
    NiControllerExtractorSharedData();

    /// Destructor.
    ~NiControllerExtractorSharedData();

    /// Get the SequenceInfo array.
    NiControllerExtractor::InfoArray& GetInfoArray();

    /// Add a SequenceInfo object to the array.
    void AddInfo(NiControllerExtractor::SequenceInfo* pkInfo);

protected:
    /// The array of sequence info objects.
    NiControllerExtractor::InfoArray m_kInfoArray;
};

NiSmartPointer(NiControllerExtractorSharedData);

#endif  // #ifndef NICONTROLLEREXTRACTORSHAREDDATA_H
