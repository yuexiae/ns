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

#ifndef NID3DRENDERSTATEGROUP_H
#define NID3DRENDERSTATEGROUP_H

#include <NiTMap.h>
#include <NiTPool.h>

#include "NiD3DDefines.h"

class NiD3DRenderState;
class NiD3DRenderStateGroup;

class NID3D_ENTRY NiD3DRenderStateGroup
{
    // *** begin NDL internal use only ***
protected:
    // Do not set these to anything. Use them only for accessing required
    // functionality. You may assume they will ALWAYS be valid.
    static NiD3DRenderer* ms_pkD3DRenderer;
    static NiD3DRenderState* ms_pkD3DRenderState;
    static void SetD3DRenderState(NiD3DRenderState* pkRS);

public:
    static void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    static void InitializePools();
    static void ShutdownPools();

    // *** end NDL internal use only ***

public:
    NiD3DRenderStateGroup();
    ~NiD3DRenderStateGroup();

    // Add and remove render states
    void SetRenderState(unsigned int uiRenderState, unsigned int uiValue,
        bool bSave = false);
    void RemoveRenderState(unsigned int uiRenderState);
    bool GetRenderState(unsigned int uiRenderState, unsigned int& uiValue,
        bool& bSave);

    // Set and restore render states
    NiD3DError SetRenderStates();
    NiD3DError RestoreRenderStates();

    // Access to pools
    static NiD3DRenderStateGroup* GetFreeRenderStateGroup();
    static void ReleaseRenderStateGroup(NiD3DRenderStateGroup* pkGroup);

    // *** begin NDL internal use only ***
    unsigned int GetTotalRenderStateCount();
    unsigned int GetNoSaveRenderStateCount();
    unsigned int GetSavedRenderStateCount();

    // Utility function to release all entries in the free pool.
    // This is useful for when several objects have been freed, a
    // level change has occured, etc.
    static void PurgeFreePool();

protected:
    class NID3D_ENTRY NiD3DRSEntry
    {
    public:
        NiD3DRSEntry();
        NiD3DRSEntry(unsigned int uiRenderState, unsigned int uiValue);

        //*** Access functions
        unsigned int GetRenderState();
        unsigned int GetValue();
        void SetRenderState(unsigned int uiRenderState);
        void SetValue(unsigned int uiValue);

        NiD3DRSEntry* GetNext();
        void SetNext(NiD3DRSEntry* pkEntry);
        NiD3DRSEntry* GetPrev();
        void SetPrev(NiD3DRSEntry* pkEntry);

    protected:
        unsigned int m_uiRenderState;
        unsigned int m_uiValue;

        NiD3DRSEntry* m_pkNext;
        NiD3DRSEntry* m_pkPrev;
    };        

    void InsertRSEntryIntoNoSaveList(NiD3DRSEntry* pkEntry);
    void RemoveRSEntryFromNoSaveList(NiD3DRSEntry* pkEntry);
    void InsertRSEntryIntoSavedList(NiD3DRSEntry* pkEntry);
    void RemoveRSEntryFromSavedList(NiD3DRSEntry* pkEntry);

    NiD3DRSEntry* FindRenderStateEntry(unsigned int uiState, 
        bool& bInSaveList);

    bool m_bRendererOwned;

    static NiTPool<NiD3DRenderStateGroup>* ms_pkRenderStateGroupPool;
    static NiTPool<NiD3DRSEntry>* 
        ms_pkRenderStateEntryPool;

    unsigned int m_uiStateCount;
    NiD3DRSEntry* m_pkRenderStates;
    unsigned int m_uiSavedStateCount;
    NiD3DRSEntry* m_pkSavedRenderStates;
    // *** end NDL internal use only ***
};

#include "NiD3DRenderStateGroup.inl"

#endif  //#ifndef NID3DRENDERSTATEGROUP_H
