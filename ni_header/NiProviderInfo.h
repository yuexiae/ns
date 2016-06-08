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

#ifndef NIPROVIDERINFO_H
#define NIPROVIDERINFO_H

#include "NiAudioSystem.h"

class NIAUDIO_ENTRY NiProviderInfo
{
public:
    // *** begin NDL internal use only ***
   
    NiProviderInfo(const char* cName, const unsigned int uiNumber);
    ~NiProviderInfo();
    
    const char* GetProviderName();
    const unsigned int GetProviderNumber();
    const bool GetIsOpen();
    const unsigned int GetNumberActiveSamples();
    bool OpenProvider();
    bool CloseProvider();

    // *** end NDL internal use only ***

protected:
    char* m_cProviderString;
    unsigned int m_uiProviderNumber;
    bool m_bIsOpen;
};

//---------------------------------------------------------------------------
inline const char* NiProviderInfo::GetProviderName() 
{ 
    return m_cProviderString; 
}
//---------------------------------------------------------------------------
inline const unsigned int NiProviderInfo::GetProviderNumber() 
{ 
    return m_uiProviderNumber; 
}
//---------------------------------------------------------------------------
inline const bool NiProviderInfo::GetIsOpen() 
{ 
    return m_bIsOpen; 
}
//---------------------------------------------------------------------------

#endif
