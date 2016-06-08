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

#ifndef NITEXTUREACCUMULATOR_H
#define NITEXTUREACCUMULATOR_H

#include <NiAlphaAccumulator.h>

class NIMAIN_ENTRY NiTextureAccumulator : public NiAlphaAccumulator
{
    NiDeclareRTTI;
    NiDeclareClone(NiTextureAccumulator);
    NiDeclareStream;

public:
    // creation and destruction
    NiTextureAccumulator ();
    virtual ~NiTextureAccumulator ();

    // *** begin NDL internal use only ***

    virtual bool RegisterObject (NiGeometry* pkObject);
    virtual void FinishAccumulating ();

    // *** end NDL internal use only ***

protected:
    void InsertObject(NiGeometry* pkObj);

    NiGeometry* RemoveNextObject();

    class Node
    {
    public:
        NiGeometry* m_pkObj;
        NiTexture* m_pkTex;

        // used as free list pointer as well
        Node* m_pkHashNext;

        Node* m_pkObjNext;
    };

    unsigned int HashID(NiTexture* pkTex);

    Node** m_ppkHashTable;
    unsigned int m_uiHashSlots;

    unsigned int m_uiGrowBy;
    Node* m_pkFreeList;
    NiTList<Node*> m_kFreeBlocks;

    unsigned int m_uiCurrentSlot;
};

typedef NiPointer<NiTextureAccumulator> NiTextureAccumulatorPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiTextureAccumulator.inl"

//---------------------------------------------------------------------------

#endif

