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

#ifndef NIIMAGEREADER_H
#define NIIMAGEREADER_H

#include "NiCriticalSection.h"
#include "NiSmartPointer.h"
#include "NiMainLibType.h"

class NiFile;
class NiPixelData;
class NiPixelFormat;

class NIMAIN_ENTRY NiImageReader 
{
public:
    virtual ~NiImageReader() { /* */ }

    virtual bool CanReadFile(const char* pcFileExtension) const = 0;

    virtual NiPixelData* ReadFile(NiFile& kIst, NiPixelData* pkOptDest) = 0;

    virtual bool ReadHeader(NiFile& kIst, 
        unsigned int& uiWidth, unsigned int& uiHeight, 
        NiPixelFormat& kFormat, bool& bMipmap) = 0;
protected:
    NiCriticalSection m_kReadCriticalSection;
};

#endif
