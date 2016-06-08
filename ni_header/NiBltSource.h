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

#ifndef NIBLTSOURCE_H
#define NIBLTSOURCE_H

#include "NiObject.h"
#include "NiPixelData.h"

class NiBltSource;

class NIMAIN_ENTRY NiBltSource : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;
public:

    // Create from a filename
    static NiBltSource* Create(const char* pcFilename);

    // Create from application pixel data
    static NiBltSource* Create(NiPixelData* pkRaw);

    // Filename will be null if created from pixel data
    const char* GetFilename() const;

    // This is the filename that is actually used to read from disk
    const char* GetPlatformSpecificFilename() const;

    // PixelData will be null if the image was created from a file 
    const NiPixelData* GetSourcePixelData() const;

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

    /*** begin NDL internal use only ***/

    // Renderer specific data class
    class RendererData;
    class NIMAIN_ENTRY RendererData
    {
    public:
        RendererData(NiBltSource* pkBlt);
        virtual ~RendererData();

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

    protected:
        NiBltSource* m_pkBlt;
    };

    void SetRendererData(RendererData* pkRendererData);
    RendererData* GetRendererData() const;

    void AddBltToList();
    void RemoveBltFromList();

    NiBltSource* GetListNext();
    NiBltSource* GetListPrev();

    static NiBltSource* GetListHead();
    static NiBltSource* GetListTail();

    /*** end NDL internal use only ***/

protected:
    NiBltSource();
    virtual ~NiBltSource();

    bool CreateRendererData();

    char* m_pcFilename;
    char* m_pcPlatformFilename;
    NiPixelDataPtr m_spSrcPixelData;

    RendererData* m_pkRendererData;

    // Doubly linked list traversal members for list of all textures
    NiBltSource* m_pkPrev;
    NiBltSource* m_pkNext;
    static NiBltSource* ms_pkHead;
    static NiBltSource* ms_pkTail;
    static NiCriticalSection ms_kBltListCriticalSection;
};

typedef NiPointer<NiBltSource> NiBltSourcePtr;

#include "NiBltSource.inl"

#endif
