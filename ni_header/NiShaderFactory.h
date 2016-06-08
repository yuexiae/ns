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

#ifndef NISHADERFACTORY_H
#define NISHADERFACTORY_H

#include "NiRefObject.h"
#include "NiShaderError.h"
#include "NiShaderLibrary.h"
#include "NiTStringMap.h"
#include "NiTListBase.h"

class NiRenderer;
class NiGeometry;

// NiShaderFactory
class NIMAIN_ENTRY NiShaderFactory : public NiRefObject
{
protected:
    NiShaderFactory();

public:
    virtual ~NiShaderFactory();

    static void Shutdown();

    static NiShaderFactory* GetInstance();

    static bool AttachShader(NiGeometry* pkGeometry, const char* pacName, 
        unsigned int uiImplementation);
    static bool AttachShader(NiGeometry* pkGeometry, NiShader* pkShader);
    static bool DetachShader(NiGeometry* pkGeometry);

    static void ReleaseAllShaders();

    static void RegisterLibrary(NiShaderLibrary* pkLibrary);
    static void UnregisterLibrary(NiShaderLibrary* pkLibrary);
    static void UnregisterAllLibraries();

    // Class Creation function - used for loading shader libraries
    typedef bool (*NISHADERFACTORY_CLASSCREATIONCALLBACK)(const char*, 
        NiRenderer*, int, char*[], bool, NiShaderLibrary**);
    static bool RegisterClassCreationCallback(
        NISHADERFACTORY_CLASSCREATIONCALLBACK pfnCallback);
    static bool LoadAndRegisterShaderLibrary(const char* pacLibName,
        int iDirectoryCount, char* pacDirectories[], 
        bool bRecurseSubFolders);

    // Run Parser function - used for parsing text files into shader libraries
    typedef unsigned int (*NISHADERFACTORY_RUNPARSERCALLBACK)(const char*, 
        NiRenderer*, const char*, bool);
    static bool RegisterRunParserCallback(
        NISHADERFACTORY_RUNPARSERCALLBACK pfnCallback);
    static unsigned int LoadAndRunParserLibrary(const char* pacLibName, 
        const char* pacDirectory, bool bRecurseSubFolders);

    // Error Reporting function - used to report errors loading shaders
    typedef unsigned int (*NISHADERFACTORY_ERRORCALLBACK)(const char*,
        NiShaderError eErr, bool);
    static bool RegisterErrorCallback(
        NISHADERFACTORY_ERRORCALLBACK pfnCallback);
    static unsigned int ReportError(NiShaderError eErr, bool bRecoverable, 
        const char* pacFmt, ...);

    // *** begin NDL internal use only ***
    virtual bool Geometry_AttachShader(NiGeometry* pkGeometry, 
        const char* pacName, unsigned int uiImplementation);
    virtual bool Geometry_AttachShader(NiGeometry* pkGeometry, 
        NiShader* pkShader);
    virtual bool Geometry_DetachShader(NiGeometry* pkGeometry);

    virtual NiShader* RetrieveShader(const char* pacName, 
        unsigned int uiImplementation, bool bReportNotFound = true);
    virtual void InsertShader(NiShader* pkShader, 
        unsigned int uiImplementation);
    virtual NiShader* FindShader(const char* pacName, 
        unsigned int uiImplementation);
    virtual void RemoveShader(const char* pacName,
        unsigned int uiImplementation);
    virtual void RemoveAllShaders();

    virtual void InsertLibrary(NiShaderLibrary* pkLibrary);
    virtual NiShaderLibrary* FindLibrary(const char* pacName);
    virtual void RemoveLibrary(const char* pacName);
    virtual void RemoveAllLibraries();
    virtual NiShaderLibrary* GetFirstLibrary();
    virtual NiShaderLibrary* GetNextLibrary();

    // Indicate subdirectory for any supporting shader program files
    static const char* GetFirstShaderProgramFileDirectory(
        NiTListIterator& kIter);
    static const char* GetNextShaderProgramFileDirectory(
        NiTListIterator& kIter);
    static void AddShaderProgramFileDirectory(const char* pacDirectory);
    static void RemoveShaderProgramFileDirectory(const char* pacDirectory);
    static void RemoveAllShaderProgramFileDirectories();

    // Shader version conversion
    virtual const unsigned int GetMinorPixelShaderVersion(
        const unsigned int uiVersion) = 0;
    virtual const unsigned int GetMajorPixelShaderVersion(
        const unsigned int uiVersion) = 0;
    virtual const unsigned int CreatePixelShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion)
        = 0;
    virtual const unsigned int GetMinorVertexShaderVersion(
        const unsigned int uiVersion) = 0;
    virtual const unsigned int GetMajorVertexShaderVersion(
        const unsigned int uiVersion) = 0;
    virtual const unsigned int CreateVertexShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion)
        = 0;

    virtual const char* GetRendererString() const = 0;

    // *** end NDL internal use only ***

protected:
    // Pass on directory to whoever needs it.
    virtual const char* GetFirstProgramDirectory(NiTListIterator& kIter) = 0;
    virtual const char* GetNextProgramDirectory(NiTListIterator& kIter) = 0;
    virtual void AddProgramDirectory(const char* pacDirectory) = 0;
    virtual void RemoveProgramDirectory(const char* pacDirectory) = 0;
    virtual void RemoveAllProgramDirectories() = 0;

    static NiShaderFactory* ms_pkShaderFactory;

    NISHADERFACTORY_CLASSCREATIONCALLBACK m_pfnClassCreate;
    NISHADERFACTORY_RUNPARSERCALLBACK m_pfnRunParser;

    NISHADERFACTORY_ERRORCALLBACK m_pfnErrorCallback;

//    NiTStringPointerMap<NiShaderPtr>* m_pkShaderMap;
//    NiTStringPointerMap<NiShaderLibraryPtr>* m_pkLibraryMap;
//    NiTMapIterator m_kLibraryIter;
};

typedef NiPointer<NiShaderFactory> NiShaderFactoryPtr;

#endif  //#ifndef NISHADERFACTORY_H
