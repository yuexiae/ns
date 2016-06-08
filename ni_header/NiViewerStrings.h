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

#ifndef NIVIEWERSTRINGS_H
#define NIVIEWERSTRINGS_H

#include "NiMainLibType.h"
#include "NiTArray.h"

// Macro for declaring viewer string function
//
// Insert in class declaration (note the start of public scope).  The
// routine GetViewerStrings supports viewers, scene graph printers, and
// other debugging tools that want a readable form of object data.
#define NiDeclareViewerStrings \
    public: \
        virtual void GetViewerStrings (NiTArray<char*>* pStrings)

// viewer string routines for native data
NIMAIN_ENTRY char* NiGetViewerString (const char* pRttiName);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, bool bValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, char cValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix,
                                      unsigned char ucValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, short sValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix,
                                      unsigned short usValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, int iValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix,
                                      unsigned int uiValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, long lValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix,
                                      unsigned long ulValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, float fValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, double dValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, bool bValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix, void* pValue);
NIMAIN_ENTRY char* NiGetViewerString (const char* pPrefix,
                                      const char* pValue);

#endif
