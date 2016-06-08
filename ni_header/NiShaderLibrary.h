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

#ifndef NISHADERLIBRARY_H
#define NISHADERLIBRARY_H

#include "NiRefObject.h"
#include "NiSmartPointer.h"

NiSmartPointer(NiShader);

class NiRenderer;
class NiShaderLibraryDesc;

// NiShaderLibrary
class NIMAIN_ENTRY NiShaderLibrary : public NiRefObject
{
public:
    NiShaderLibrary(char* pszName);
    virtual ~NiShaderLibrary();

    const char* GetName();
    void SetName(char* pszName);

    virtual NiShader* GetShader(NiRenderer* pkRenderer, const char* pszName, 
        unsigned int uiImplementation);

    virtual NiShaderLibraryDesc* GetShaderLibraryDesc() = 0;

    // *** begin NDL internal use only ***
    virtual void SetShaderLibraryDesc(NiShaderLibraryDesc* pkLibDesc) = 0;
    // *** end NDL internal use only ***

protected:
    char* m_pszName;
};

typedef NiPointer<NiShaderLibrary> NiShaderLibraryPtr;

#endif  //#ifndef NISHADERLIBRARY_H
