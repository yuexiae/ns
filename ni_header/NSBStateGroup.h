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

#ifndef NSBSTATEGROUP_H
#define NSBSTATEGROUP_H

#include <NiD3DDefines.h>
#include "NiBinaryShaderLibLibType.h"
#include <NiTPointerList.h>
#include <NiBinaryStream.h>

class NiD3DRenderStateGroup;
class NiD3DTextureStageGroup;

//
class NIBINARYSHADERLIB_ENTRY NSBStateGroup
{
public:
    NSBStateGroup();
    ~NSBStateGroup();

    class NIBINARYSHADERLIB_ENTRY NSBSGEntry
    {
    public:
        enum
        {
            NSBSG_SAVE      = 0x00000001,
            NSBSG_ATTRIBUTE = 0x00000002
        };

        NSBSGEntry();
        ~NSBSGEntry();

        const unsigned int GetFlags() const;
        const bool IsSaved() const;
        const bool UsesAttribute() const;
        const unsigned int GetState() const;
        const unsigned int GetValue() const;
        const char* GetAttribute() const;

        void SetFlags(unsigned int uiFlags);
        void SetSaved(bool bSave);
        void SetUseAttribute(bool bUse);
        void SetState(unsigned int uiState);
        void SetValue(unsigned int uiValue);
        void SetAttribute(const char* pszAttribute);

        bool SaveBinary(NiBinaryStream& kStream);
        bool LoadBinary(NiBinaryStream& kStream);

    protected:
        unsigned int m_uiFlags;
        unsigned int m_uiState;
        unsigned int m_uiValue;
        char* m_pszAttribute;
    };

    void SetState(unsigned int uiState, unsigned int uiValue, bool bSave);
    void SetState(unsigned int uiState, const char* pszAttribute, 
        bool bSave);

    unsigned int GetStateCount();
    NSBSGEntry* GetFirstState();
    NSBSGEntry* GetNextState();

    bool SetupRenderStateGroup(NiD3DRenderStateGroup& kRSGroup);
    bool SetupTextureStageGroup(NiD3DTextureStageGroup& kTSGroup);
    bool SetupTextureSamplerGroup(NiD3DTextureStageGroup& kTSGroup);

    // ***
    bool SaveBinary(NiBinaryStream& kStream);
    bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    enum DumpMode
    {
        DUMP_RENDERSTATES = 0,
        DUMP_STAGESTATES,
        DUMP_SAMPLERSTATES
    };
    void Dump(FILE* pf, DumpMode eMode);
    void DumpEntryAsUnknown(FILE* pf, NSBSGEntry* pkEntry);
    void DumpEntryAsRenderState(FILE* pf, NSBSGEntry* pkEntry);
    void DumpEntryAsStageState(FILE* pf, NSBSGEntry* pkEntry);
    void DumpEntryAsSamplerState(FILE* pf, NSBSGEntry* pkEntry);
#endif  //#if defined(_DEBUG)
    // ***

protected:
    NSBSGEntry* FindStateInList(unsigned int uiState);

    bool SetupRenderStateGroup_DX9(NiD3DRenderStateGroup& kRSGroup);
    bool SetupTextureStageGroup_DX9(NiD3DTextureStageGroup& kTSGroup);
    bool SetupTextureSamplerGroup_DX9(NiD3DTextureStageGroup& kTSGroup);
    bool SetupRenderStateGroup_DX8(NiD3DRenderStateGroup& kRSGroup);
    bool SetupTextureStageGroup_DX8(NiD3DTextureStageGroup& kTSGroup);
    bool SetupTextureSamplerGroup_DX8(NiD3DTextureStageGroup& kTSGroup);
    bool SetupRenderStateGroup_XBox(NiD3DRenderStateGroup& kRSGroup);
    bool SetupTextureStageGroup_XBox(NiD3DTextureStageGroup& kTSGroup);
    bool SetupTextureSamplerGroup_XBox(NiD3DTextureStageGroup& kTSGroup);

    NiTListIterator m_kStateIter;
    NiTPointerList<NSBSGEntry*> m_kStateList;
};

#include "NSBStateGroup.inl"

#endif  //NSBSTATEGROUP_H
