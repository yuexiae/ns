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

#ifndef NIFILE_H
#define NIFILE_H

#include "NiRTLib.h"
#include "NiBinaryStream.h"

#if !defined(NGC) && !defined(PS2) && !defined(WIN32) && \
    !defined(_XBOX) && !defined(_XENON)
#error One of these macros must be defined: NGC, PS2, WIN32, _XBOX, _XENON
#endif

#if defined(NGC)
struct DVDFileInfo;
#elif defined(PS2)
#include <libcdvd.h>
#include "NiCriticalSection.h"
#endif

class NISYSTEM_ENTRY NiFile : public NiBinaryStream
{
public:
    typedef enum
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    } OpenMode;
    
    NiFile(const char* pcName, OpenMode eMode,
        unsigned int uiBufferSize = 32768);
    virtual ~NiFile();

    // GetFile is used throughout Gamebryo to create NiFile objects. Use 
    // SetFileCreateFunc to override its behavior (to create an instance of 
    // an NiFile-derived class rather than an NiFile).
    static NiFile* GetFile(const char *pcName, OpenMode eMode,
        unsigned int uiBufferSize = 32768);

    typedef NiFile* (*FILECREATEFUNC)(const char *pcName, 
        OpenMode eMode, unsigned int uiBufferSize);

    // Set the file creation function or restore to default
    // if pfnFunc is NULL.
    static void SetFileCreateFunc(FILECREATEFUNC pfnFunc);
    
    // Check if a file exists with permissions defined by eMode.
    static bool Access(const char* pcName, OpenMode eMode);

    // Override the behavior of NiFile::Access in the same way that
    // NiFile::SetFileCreateFunc overrides NiFile::GetFile:
    typedef bool (*FILEACCESSFUNC)(const char* pcName, OpenMode eMode);
    static void SetFileAccessFunc(FILEACCESSFUNC pfnFunc);

    virtual operator bool() const;

    virtual void Seek(int iOffset, int iWhence);
    static const int ms_iSeekSet;
    static const int ms_iSeekCur;
    static const int ms_iSeekEnd;

    virtual unsigned int Read(void* pvBuffer, unsigned int uiBytes);
    virtual unsigned int Write(const void* pvBuffer, unsigned int uiBytes);

#if defined(WIN32) && !defined(_XBOX)
    unsigned int GetFileSize() const;

#elif defined(_XBOX)
    enum FileMethod
    {
        FILE_USE_POINTER = 0x00,
        FILE_USE_HANDLE = 0x01,
        FILE_USE_MASK   = 0x0f,
        FILE_USE_DOUBLEBUFFER = 0x80
    };

    static void SetFileMethod(unsigned int uiFileMethod);
    static unsigned int GetFileMethod(void);

#elif defined(PS2)

    NiFile(unsigned int uiSector, unsigned int uiBufferSectors,
        sceCdRMode* pkMode = NULL);

    static bool CacheTOC();

    enum
    {
        MAX_PREFIX_LEN = 256,
        MAX_SUFFIX_LEN = 3
    };
    // The default prefix is "host:"
    // Other possible values: "cdrom0:", "atfile:192.168.1.1,"
    static void SetFileLoadingPrefix(const char* pcPrefix);
    static const char* GetFileLoadingPrefix(); // default: "host:"

    // The default suffix is the empty string: ""
    // Only other useful value would be ";1" (for CD access)
    static void SetFileLoadingSuffix(const char* pcSuffix);
    static const char* GetFileLoadingSuffix();

    struct FileEntry;

    static void _SDMInit();
    static void _SDMShutdown();
#endif

protected:
    
    NiFile() { /* */ };
    bool Flush();
    unsigned int DiskWrite(const void* pvBuffer, unsigned int uiBytes);

    static FILECREATEFUNC ms_pfnFileCreateFunc;
    static FILEACCESSFUNC ms_pfnFileAccessFunc;

    static NiFile* DefaultFileCreateFunc(const char *pcName,
        OpenMode eMode, unsigned int uiBufferSize);
    static bool DefaultFileAccessFunc(const char *pcName, OpenMode eMode);

    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
#if defined(NGC)
    unsigned int DiskRead(void* pvBuffer, unsigned int uiBytes);

    char* m_pBuffer;
    unsigned int m_uiBufferLocation;
    unsigned int m_uiFileSize;
    DVDFileInfo* m_pFile;
#elif defined(PS2)
    unsigned int FillReadBuffer();
    void Open(unsigned int uiSector, unsigned int uiBufferSectors,
        sceCdRMode* pkMode = NULL);
    static bool BuildFileTable();
    static int CompareFileEntry(const void* v0, const void* v1);

    char* m_apcBuffer[2];
    unsigned int m_uiFullBuffer;
    int m_iFile;
    unsigned int m_uiReadSkip;

    // The next 5 values are only used when using sceCdRead.
    unsigned int m_uiStartSector;
    unsigned int m_uiFullSector;
    unsigned int m_uiReadingSector;
    unsigned int m_uiAbsolutePos;
    sceCdRMode m_kMode;

    static char ms_acFilePrefix[MAX_PREFIX_LEN];
    static char ms_acFileSuffix[MAX_SUFFIX_LEN];
    static NiFile* ms_pkActive;
    static FileEntry* ms_pkFileTable;
    static unsigned int ms_uiFiles;
    static NiCriticalSection ms_kCDDVDCriticalSection;
#elif defined(_XBOX)
    unsigned int DiskRead(void* pvBuffer, unsigned int uiBytes);
    void StartDiskRead(void);
    bool CompleteDiskRead(void);

    char* m_pBuffer;
    unsigned int m_uiFileSize;
    unsigned int m_uiAbsolutePos;
    unsigned int m_uiReadingSector;
    LARGE_INTEGER m_liFileSize;

    // Global method. Used when opening a file...
    static unsigned int ms_uiFileMethodFlags;
    // Local method. Once a file is open, the method can't change. However,
    // the global can change, so we have to track which method creation
    // occured with!
    FileMethod m_eFileMethod;
    bool m_bUseDoubleBuffer;
    FILE* m_pFile;
    HANDLE m_hFile;
    static DWORD ms_dwMoveMethods[3][2];

    // Double-buffer members
    enum
    {
        NIFILE_BUFFER_COUNT     = 2
    };
    unsigned int m_uiStreamBuffer;
    unsigned int m_uiReadBuffer;
    unsigned char* m_apBuffers[NIFILE_BUFFER_COUNT];
    unsigned int m_uiDiskReads;

    class OverlappedContext
    {
    public:
        // Overlapped IO doesn't move the file pointer!
        unsigned int m_uiFilePointer;
        unsigned int m_uiBytesExpected;
        bool m_bIOPending;
        OVERLAPPED m_kOverlapped;
    };
    OverlappedContext m_kOLContext;
#elif defined(WIN32)
    unsigned int DiskRead(void* pvBuffer, unsigned int uiBytes);

    char* m_pBuffer;
    FILE* m_pFile;
#endif
    OpenMode m_eMode;
    bool m_bGood;
};

#if defined(PS2)
#include "NiFile.inl"
#endif

#endif // NIFILE_H

