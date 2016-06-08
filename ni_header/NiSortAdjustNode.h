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

#ifndef NISORTSWITCHNODE_H
#define NISORTSWITCHNODE_H

#include "NiAccumulator.h"
#include "NiNode.h"

class NIMAIN_ENTRY NiSortAdjustNode : public NiNode
{
    NiDeclareRTTI;
    NiDeclareClone(NiSortAdjustNode);
    NiDeclareStream;

public:
    NiSortAdjustNode();
    virtual ~NiSortAdjustNode();

    enum SortingMode
    {
        SORTING_INHERIT,
        SORTING_OFF,
        SORTING_SUBSORT
    };

    void SetSortingMode(SortingMode eMode);
    SortingMode GetSortingMode() const;

    // WARNING - the sub-sorter is not saved or loaded during streaming
    // Applications must set these each time the scene graph is loaded
    // if they are using the mode SORTING_SUBSORT
    void SetSubSorter(NiAccumulator* pkSorter);
    NiAccumulator* GetSubSorter() const;

    virtual void Display(NiCamera* pkCamera);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    SortingMode m_eSortingMode;
    NiAccumulatorPtr m_spAccum;
};


typedef NiPointer<NiSortAdjustNode> NiSortAdjustNodePtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiSortAdjustNode.inl"


#endif
