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

#ifndef NISTREAM_H
#define NISTREAM_H

#include "NiMainLibType.h"
#include "NiObject.h"
#include "NiTArray.h"
#include "NiTStringMap.h"
#include "NiTSet.h"
#include "NiObjectGroup.h"
#include "NiTPointerList.h"
#include <NiBinaryStream.h>
#include <NiBinaryLoadSave.h>
#include <NiSystem.h>
#include "NiTPointerMap.h"

NiSmartPointer(NiTexture);
NiSmartPointer(NiTexturePalette);

class NiSearchPath;
class NiAVObject;

class NIMAIN_ENTRY NiStream
{
public:
    NiStream();
    virtual ~NiStream();

    // top-level objects to process
    void InsertObject(NiObject* pkObject);
    void RemoveObject(NiObject* pkObject);
    void RemoveAllObjects();
    unsigned int GetObjectCount() const;
    NiObject* GetObjectAt(unsigned int i) const;

    // file loads and saves
    virtual bool Load(const char* pcFileName);
    virtual bool Save(const char* pcFileName);

    // character stream loads and save
    virtual bool Load(char* pcBuffer, int iBufferSize);
    virtual bool Save(char*& pcBuffer, int& iBufferSize);

    // Direct stream loads and save
    virtual bool Load(NiBinaryStream* pkIstr);
    virtual bool Save(NiBinaryStream* pkOstr);

    // background loading
    enum ThreadStatus
    {
        IDLE,
        LOADING,
        CANCELLING,
        PAUSING,
        PAUSED
    };

    struct LoadState
    {
        float m_fReadProgress; // [0.0f..1.0f]
        float m_fLinkProgress; // [0.0f..1.0f]
    };

    void BackgroundLoadBegin(const char* pcFileName);
    void BackgroundLoadBegin(NiBinaryStream* pkIstr);
    ThreadStatus BackgroundLoadPoll(LoadState* pkState);
    void BackgroundLoadPause();
    void BackgroundLoadResume();
    void BackgroundLoadCancel();
    bool BackgroundLoadFinish();
    bool BackgroundLoadGetExitStatus() const;
    virtual void BackgroundLoadOnExit();

    // version information
    static unsigned int GetVersionFromString(const char* pcVersionString);
    static unsigned int GetVersion(unsigned int uiMajor, unsigned int uiMinor,
        unsigned int uiPatch, unsigned int uiInternal);
    unsigned int GetFileVersion() const;
    unsigned int GetFileUserDefinedVersion() const;

    // error messages
    unsigned int GetLastError() const;
    const char* GetLastErrorMessage() const;
    void ResetLastErrorInfo();

    // optional image palette (allows image sharing across streams)
    void SetTexturePalette(NiTexturePalette* pkTexturePalette);
    NiTexturePalette* GetTexturePalette() const;

    // *** begin NDL internal use only ***

    // string loads and saves
    void LoadCString(char*& pcString);
    void SaveCString(const char* pcString);

    static const unsigned int NULL_LINKID; /* = 0xffffffff */

    virtual bool RegisterSaveObject(NiObject* pkObject);
    virtual void ChangeObject(NiObject* pkNewObject);
    virtual unsigned int GetLinkIDFromObject(const NiObject* pkObject) const;
    virtual void SaveLinkID(const NiObject* pkObject);

    void ReadLinkID();
    unsigned int ReadMultipleLinkIDs();
    NiObject* ResolveLinkID();
    NiObject* GetObjectFromLinkID();
    unsigned int GetNumberOfLinkIDs();
    void SetNumberOfLinkIDs(unsigned int uiLinks);

    NiObjectGroup* GetGroupFromID(unsigned int uiID) const;
    unsigned int GetIDFromGroup(NiObjectGroup* pkGroup) const;

    // for internal read/write of class data members
    NiBinaryStream& Istr();
    NiBinaryStream& Ostr();

    // image palette access
    void SetTexture(char* pcURL, NiTexture* pkTexture);
    NiTexture* GetTexture(char* pcURL, NiTexture* pkSelf) const;

    NiSearchPath* GetSearchPath() const;
    void SetSearchPath(NiSearchPath* pkSearchPath);

    // last loaded RTTI string
    const char* GetLastLoadedRTTI() const;

    // Cached flag values for legacy NIF files.
    unsigned short GetLastNiAVObjectFlags() const;
    void SetLastNiAVObjectFlags(unsigned short usFlags);

    unsigned short GetLastNiTimeControllerFlags() const;
    void SetLastNiTimeControllerFlags(unsigned short usFlags);

    unsigned short GetLastNiPropertyFlags() const;
    void SetLastNiPropertyFlags(unsigned short usFlags);

    // Locking functions to protect cleanup code for threading issues.
    static void LockCleanupSection();
    static void UnlockCleanupSection();

    // support for object loader functions
    typedef NiObject* (*CreateFunction)(void);
    static int RegisterLoader(const char* pcClassName, CreateFunction pfnFunc);
    static void UnregisterLoader(const char* pcClassName);

    // Support for scene graph post-processing functions.
    typedef void (*PostProcessFunction)(NiStream&, NiObject*);
    static void RegisterPostProcessFunction(PostProcessFunction pfnFunc);
    static void UnregisterPostProcessFunction(PostProcessFunction pfnFunc);
    
    static void _SDMInit();
    static void _SDMShutdown();
    static NiObject* CreateObjectByRTTI(const char* pcRTTI);

    // *** end NDL internal use only ***

protected:
    // load and save information
    virtual bool LoadHeader();
    virtual void SaveHeader();
    virtual bool LoadStream();
    virtual bool SaveStream();
    virtual void RegisterObjects();
    virtual void LoadTopLevelObjects();
    virtual void SaveTopLevelObjects();
    virtual bool LoadObject();
    void FreeLoadData();
    void DoThreadPause();

    // automatically set UpdateSelected flags for old NIF files
    // to max functionality
    void SetSelectiveUpdateFlagsForOldVersions();
    void SetSelectiveUpdateFlagsTTTFRecursive(NiAVObject* pkAVObject);

    // RTTI
    void LoadRTTIString(char* pcString);
    bool LoadRTTI();
    void SaveRTTI();
    void RTTIError(const char* pcRTTI);

    // block allocation 
    void LoadObjectGroups();
    void SaveObjectGroups();
    void UpdateObjectGroups();
    NiTArray<NiObjectGroup*> m_kGroups;

    unsigned int m_uiNifFileVersion;
    unsigned int m_uiNifFileUserDefinedVersion;
    char m_acFileName[NI_MAX_PATH];// needed to resolve names of external nifs

    NiSearchPath* m_pkSearchPath;

    NiTArray<NiObjectPtr> m_kObjects;
    NiTArray<NiObjectPtr> m_kTopObjects;
    NiBinaryStream* m_pkIstr;
    NiBinaryStream* m_pkOstr;

    // ordered set of link id's for load-link phase
    NiTSet<unsigned int> m_kLinkIDs;
    unsigned int m_uiLinkIndex;
    NiTSet<unsigned int> m_kLinkIDBlocks;
    unsigned int m_uiLinkBlockIndex;

    // Hash table to convert registered object pointers to IDs at save time.
    NiTPointerMap<const NiObject*, unsigned int> m_kRegisterMap;

    // image palette for sharing NiTexture objects
    NiTexturePalettePtr m_spTexturePalette;

    // Legacy NIF flag conversion variables
    unsigned short m_usNiAVObjectFlags;
    unsigned short m_usNiTimeControllerFlags;
    unsigned short m_usNiPropertyFlags;

    // background loading
    void BackgroundLoadBegin();
    void BackgroundLoadEstimateProgress(LoadState& kLoadState);

    //Called to check things like stream and stack consistency for background
    //loading.  ifdef'd in the .inl file so that it compiles out when not
    //needed.
    void CheckConsistency();

    ThreadStatus m_eBackgroundLoadStatus;
    bool m_bBackgroundLoadExitStatus;
    unsigned int m_uiLoad;
    unsigned int m_uiLink;
    unsigned int m_uiPostLink;

#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
    HANDLE m_hLoadThread;
#if defined(_XBOX) || defined(_XENON)
     static DWORD WINAPI BackgroundLoadEntry(void *pvArg);
#else
     static unsigned __stdcall BackgroundLoadEntry(void *pvArg);
#endif  //#if !defined(_XBOX)
#elif defined(PS2)
    static void BackgroundLoadEntry(void* pvArg);
    void BackgroundLoadCleanup();
    int m_iBackgroundThread;
    int m_iSema;
    u_long128* m_puqBackgroundStack;
#elif defined(NGC)
    static void* BackgroundLoadEntry(void* pvArg);
    void BackgroundLoadCleanup();
    enum { STACK_SIZE = 8192 };
    unsigned char m_aucThreadStack[STACK_SIZE];
    OSThread* m_pkOSBackgroundThread;
    OSSemaphore* m_pkOSBackgroundSema;
#endif

    // error messages
    enum
    {
        STREAM_OKAY,
        FILE_NOT_LOADED,
        NOT_NIF_FILE,
        OLDER_VERSION,
        LATER_VERSION,
        NO_CREATE_FUNCTION
    };

    // static data
    static const unsigned int ms_uiNifMinVersion;
    static const unsigned int ms_uiNifMaxVersion;
    static const unsigned int ms_uiNifMinUserDefinedVersion;
    static const unsigned int ms_uiNifMaxUserDefinedVersion;
    
    //*** TODO. Determine a better length than NI_MAX_PATH
    char m_acLastLoadedRTTI[NI_MAX_PATH];
    unsigned int m_uiLastError;
    char m_acLastErrorMessage[NI_MAX_PATH];

    // support for object loader functions
    static NiTStringPointerMap<CreateFunction>* ms_pkLoaders;

    // Support for scene graph post-processing functions.
    static NiTArray<PostProcessFunction>* ms_pkPostProcessFunctions;

    static NiCriticalSection ms_kCleanupCriticalSection;
};

#include "NiStream.inl"

#endif // NISTREAM_H
