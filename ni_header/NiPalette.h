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

#ifndef NIPALETTE_H
#define NIPALETTE_H

#include "NiObject.h"
#include "NiStream.h"

class NIMAIN_ENTRY NiPalette : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    class NIMAIN_ENTRY PaletteEntry
    {
    public:
        PaletteEntry() { /* */ }

        unsigned char m_ucRed;
        unsigned char m_ucGreen;
        unsigned char m_ucBlue;
        unsigned char m_ucAlpha;
    };

    NiPalette();
    NiPalette(bool bHasAlpha, unsigned int uiNumEntries);
    NiPalette(bool bHasAlpha, unsigned int uiNumEntries,
        const PaletteEntry* pkEntries);
    NiPalette(const NiPalette& kPal);
    virtual ~NiPalette();

    bool GetHasAlpha() const;
    unsigned int GetNumEntries() const;

    PaletteEntry* GetEntries();
    const PaletteEntry* GetEntries() const;

    NiPalette& operator=(const NiPalette& kPal);

    void MarkAsChanged();
    unsigned int GetRevisionID() const;

    /*** begin NDL internal use only ***/
    
    class NIMAIN_ENTRY RendererData
    {
    public:
        RendererData(NiPalette* pkPalette);
        virtual ~RendererData();

    protected:
        NiPalette* m_pkPalette;
    };

    void SetRendererData(RendererData* pkRendererData);
    RendererData* GetRendererData() const;

    NiPalette* GetListNext();
    NiPalette* GetListPrev();

    static NiPalette* GetListHead();
    static NiPalette* GetListTail();

    /*** end NDL internal use only ***/

protected:
    void AddPaletteToList();
    void RemovePaletteFromList();

    void CreateRendererData();

    bool m_bAlpha;
    unsigned int m_uiEntries;
    unsigned int m_uiRevID;
    PaletteEntry* m_pkPalette;
    RendererData* m_pkRendererData;

    // Doubly linked list traversal members for list of all textures
    NiPalette* m_pkPrev;
    NiPalette* m_pkNext;
    static NiPalette* ms_pkHead;
    static NiPalette* ms_pkTail;
    static NiCriticalSection ms_kPaletteListCriticalSection;
};

typedef NiPointer<NiPalette> NiPalettePtr;

#include "NiPalette.inl"

#endif
