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

#ifndef NIMILESAUDIOSYSTEM_H
#define NIMILESAUDIOSYSTEM_H

#include <NiAudioSystem.h>
#include "NiAudioLibType.h"
#include "NiAudioListener.h"
#include "NiProviderInfo.h"
#include <NiObject.h>
#include <NiStream.h>
#include <NiTPointerList.h>

class NiMilesSource;
class NiProviderInfo;
class NiMilesListener;
NiSmartPointer(NiAudioListener);

class NIAUDIO_ENTRY NiMilesAudioSystem : public NiAudioSystem
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareFlags(unsigned char);
    
public:
    

    //
    // Access to the unique sound system
    //
    static NiMilesAudioSystem* GetAudioSystem();

    //
    // Set window handle
    //
    virtual void SetHWnd(HWND hWnd);
    virtual HWND GetHWnd();
    
    virtual bool Startup(const char* pcDirectoryname);
    virtual void Shutdown();

    //
    // Access to the single sound system's unique listener.  
    // Note, the application cannot "Set" the listener, 
    // it can only get it. Overload to cast to the correct type
    //
    NiMilesListener* GetListener();

    // 
    // The NiAudioSystem contains a factory for creating sources
    // Sources can be created manually but the factory will abstract
    // creation of sources of the current implementation. ie. NiMileSource, 
    // NiSensauraSource
    virtual NiAudioSource* CreateSource(unsigned int uiType = NiAudioSource::TYPE_DEFAULT);


    //
    // SetSpeakerType - returns true if the provider did set the speaker 
    //   type (it is unclear whether this means the underlying provider 
    //   actually uses the new type or not)
    //
    virtual SpeakerType GetSpeakerType();

    SpeakerType GetSpeakerType(NiProviderInfo* pProvider);

    virtual bool SetSpeakerType(unsigned int uiType = TYPE_3D_2_SPEAKER);

    bool SetSpeakerType(NiProviderInfo* pProvider, 
            unsigned int uiType = TYPE_3D_2_SPEAKER);

    virtual bool SetBestSpeakerTypeAvailable();
    bool SetBestSpeakerTypeAvailable(NiProviderInfo* pProvider);

    // a pointer to a string describing last error. First byte 0 if no error
    virtual char* GetLastError();  
    

        // Overload to cast directly to the correcty type
    NiMilesSource* GetFirstSource(NiTListIterator& iter);
    NiMilesSource* GetNextSource(NiTListIterator& iter);   

    NiMilesSource* FindDuplicateSource(NiAudioSource* pkOriginal);

    bool IsUniqueSource(NiMilesSource* pkOriginal);
    virtual bool SetUnitsPerMeter(float fUnits);

    //
    // 3D audio require that a source and the listener be
    // associated with the same provider.  When the AudioSystem
    // is started a list of available providers is created and stored
    // internally, this list can be accessed with an iterator (see
    // example above).
    // Specific provider names are (these may change): 
    //  "Aureal A3D 2.0 (TM)", "Aureal A3D Interactive (TM)", 
    //  "Creative Labs EAX (TM)", "Creative Labs EAX 2 (TM)", 
    //  "DirectSound3D 7+ Software - Full HRTF", 
    //  "DirectSound3D 7+ Software - Light HRTF", 
    //  "DirectSound3D 7+ Software - Pan and Volume",
    //  "DirectSound3D Hardware Support", "DirectSound3D Software Emulation",
    //  "Dolby Surround", "Miles Fast 2D Positional Audio", 
    //  "RAD Game Tools RSX 3D Audio"
    //
    // ** see the Miles documentation for details on the providers **

    NiProviderInfo* GetFirstProvider(NiTListIterator& iter);
    NiProviderInfo* GetNextProvider(NiTListIterator& iter); 
    
    NiProviderInfo* GetDefaultProvider();
    void SetDefaultProvider(NiProviderInfo* pkDefault);

    //
    // Provider-specific preferences - see Miles manual
    //

    void SetProviderPreference(NiProviderInfo * pProvider, 
        char * cPreferenceName, void * PreferenceValue);

    void GetProviderPreference(NiProviderInfo * pProvider, 
        char * cPreferenceName, void * PreferenceValue);

    /////////////////////////////////////////////////////////
    // BEGIN REVERB SPECIFIC FUNCTIONS.
    //

    // returns true if reverb is available with the provider
    //  
    virtual bool GetReverbAvailable(NiProviderInfo * pProvider);
    virtual bool GetReverbAvailable();
    
     //
    // Reverb functions - if reverb is supported by the specified provider
    //  then SetCurrentRoomReverb will return true.. it will return false
    //  if the provider pointer is zero or if reverb is not supported.
    
    bool  SetCurrentRoomReverb(NiProviderInfo *pProvider, DWORD dwPreset);
    virtual bool  SetCurrentRoomReverb(unsigned int dwPreset);

    DWORD GetCurrentRoomReverb(NiProviderInfo *pProvider);
    virtual unsigned int GetCurrentRoomReverb();

    void* GetDigitalDriver();
    
protected:       
    NiMilesAudioSystem();
    ~NiMilesAudioSystem();
    

    HWND m_hWnd;
    void* m_pDIG;            // digital driver for Miles
        
    NiTPointerList<NiProviderInfo*>* m_pProviders;
    NiProviderInfo* m_pkDefaultProvider;
        
    friend class NiMilesAudioSDM;
    friend class NiMilesSource;
};


#endif
