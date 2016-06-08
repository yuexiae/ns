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

#ifndef NIEXTRADATA_H
#define NIEXTRADATA_H

#include "NiObject.h"
#include "NiStream.h"
NiSmartPointer(NiExtraData);


class NIMAIN_ENTRY NiExtraData : public NiObject
{
    NiDeclareRTTI;
    //NiDeclareClone(NiExtraData);
    NiDeclareAbstractClone(NiExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // construction and destruction
    NiExtraData();  // support for streaming
    NiExtraData(const char* pcName);
    virtual ~NiExtraData ();

    // streaming (the char* pointer is copied, not the data)
    ////void SetSizeAndChunk (unsigned int uiSize, char* pChunk);
    ////unsigned int GetSize () const;
    ////char* GetChunk () const;

    const char* GetName() const;
    void SetName(const char* pcName);   // Used for cloning.

    // The following members dictate whether or not the extra data should be
    // streamed or cloned which can be useful in the case of extra data that
    // holds temporary values during execution.
    virtual bool IsStreamable() const;
    virtual bool IsCloneable() const;

    // *** begin NDL internal use only ***

    // The following INTERNAL function is used specifically in streaming Nif
    //    files prior to Nif version 5.0.0.11.  In that case, the m_pcName
    //    member variable initially holds a "next" pointer for the old style
    //    ExtraData linked list.  Thus, it's important NOT to delete the name,
    //    which is really a pointer to the "next" ExtraData instance.  Note
    //    that SetName() and SetNameNoDelete() differ by only the single line:
    //    "delete m_pcName;".
    void ClearName();

    // *** end NDL internal use only ***

protected:
    // data is an array of bytes
    ////unsigned int m_uiSize;
    ////char* m_pChunk;

    char* m_pcName; // Every extra data instance has a unique name; if one is
                    //    not provided, a unique name will be generated.
                    // For legacy Nif files prior to Nif version 5.0.0.11,
                    //    this pointer is cast as (NiExtraData*) during
                    //    streaming and used for the legacy NiExtraData linked
                    //    list, since there is no name.  NiObjectNET's
                    //    post-link step converts the legacy linked list to an
                    //    array of NiExtraData pointers, and then generates
                    //    unique names.
};

NiSmartPointer(NiExtraData);

#endif

