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

#ifndef NSBCONSTANTMAP_H
#define NSBCONSTANTMAP_H

#include <NiBinaryStream.h>
#include <NiTPointerList.h>
#include <NiD3DDefines.h>

#include <NiShader.h>
#include <NiD3DShaderConstantMapEntry.h>

#include "NiBinaryShaderLibLibType.h"

class NiD3DSCM_Pixel;
class NiD3DSCM_Vertex;
class NiShaderDesc;

class NIBINARYSHADERLIB_ENTRY NSBConstantMap : public NiRefObject
{
public:
    NSBConstantMap();
    virtual ~NSBConstantMap();

    // Usage
    unsigned int GetUsage();
    void SetUsage(unsigned int uiUsage);
    // Entry
    class NSBCM_Entry : public NiD3DShaderConstantMapEntry
    {
    public:
        NSBCM_Entry();
        ~NSBCM_Entry();

        // *** begin NDL internal use only
        bool SaveBinary(NiBinaryStream& kStream);
        bool LoadBinary(NiBinaryStream& kStream);
        // *** end NDL internal use only
    };

    unsigned int GetGlobalEntryCount();
    unsigned int GetPlatformEntryCount(NiShader::Platform ePlatform);
    unsigned int GetTotalEntryCount();

    virtual bool AddEntry(char* pszKey, unsigned int uiFlags, 
        unsigned int uiExtra, unsigned int uiReg, unsigned int uiCount,
        char* pszVariableName, unsigned int uiSize = 0, 
        unsigned int uiStride = 0, void* pvSource = 0, 
        bool bCopyData = false);
    virtual bool AddPlatformSpecificEntry(unsigned int uiPlatformFlags, 
        char* pszKey, unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiReg, unsigned int uiCount, char* pszVariableName, 
        unsigned int uiSize = 0, unsigned int uiStride = 0, 
        void* pvSource = 0, bool bCopyData = false);

    NSBCM_Entry* GetFirstEntry();
    NSBCM_Entry* GetNextEntry();

    NSBCM_Entry* GetFirstPlatformEntry(NiShader::Platform ePlatform);
    NSBCM_Entry* GetNextPlatformEntry(NiShader::Platform ePlatform);

    NSBCM_Entry* GetEntryByKey(char* pszKey);
    unsigned int GetEntryIndexByKey(char* pszKey);

    NSBCM_Entry* GetPlatformEntryByKey(NiShader::Platform ePlatform, 
        char* pszKey);
    unsigned int GetPlatformEntryIndexByKey(NiShader::Platform ePlatform, 
        char* pszKey);

    virtual NiD3DSCM_Pixel* GetD3DSCM_Pixel(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc);
    virtual NiD3DSCM_Vertex* GetD3DSCM_Vertex(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc);

    // *** begin NDL internal use only
    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    virtual void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    NSBCM_Entry* CreateEntry(char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiReg, unsigned int uiCount, 
        char* pszVariableName, unsigned int uiSize = 0, 
        unsigned int uiStride = 0, void* pvSource = 0, 
        bool bCopyData = false);
    bool AddPlatformSpecificEntry_DX8(char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiReg, unsigned int uiCount, 
        char* pszVariableName, unsigned int uiSize = 0, 
        unsigned int uiStride = 0, void* pvSource = 0, 
        bool bCopyData = false);
    bool AddPlatformSpecificEntry_DX9(char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiReg, unsigned int uiCount, 
        char* pszVariableName, unsigned int uiSize = 0, 
        unsigned int uiStride = 0, void* pvSource = 0, 
        bool bCopyData = false);
    bool AddPlatformSpecificEntry_XBox(char* pszKey, 
        unsigned int uiFlags, unsigned int uiExtra, 
        unsigned int uiReg, unsigned int uiCount, 
        char* pszVariableName, unsigned int uiSize = 0, 
        unsigned int uiStride = 0, void* pvSource = 0, 
        bool bCopyData = false);

    bool GetPlatformListPointers(NiShader::Platform ePlatform,
        NiTListIterator*& pkIter, 
        NiTPointerList<NSBCM_Entry*>*& pkEntryList);

    bool ProcessPixelMapEntry(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc, NSBCM_Entry* pkEntry, 
        NiD3DSCM_Pixel* pkSCMP);
    bool ProcessVertexMapEntry(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc, NSBCM_Entry* pkEntry, 
        NiD3DSCM_Vertex* pkSCMV);

    virtual bool SaveBinaryEntries(NiBinaryStream& kStream);
    virtual bool LoadBinaryEntries(NiBinaryStream& kStream);

    unsigned int m_uiUsage;
    NiTListIterator m_kListIter;
    NiTPointerList<NSBCM_Entry*> m_kEntryList;
    NiTListIterator m_kListIter_DX8;
    NiTPointerList<NSBCM_Entry*> m_kEntryList_DX8;
    NiTListIterator m_kListIter_DX9;
    NiTPointerList<NSBCM_Entry*> m_kEntryList_DX9;
    NiTListIterator m_kListIter_XBox;
    NiTPointerList<NSBCM_Entry*> m_kEntryList_XBox;
};

NiSmartPointer(NSBConstantMap);

#include "NSBConstantMap.inl"

#endif  //NSBCONSTANTMAP_H
