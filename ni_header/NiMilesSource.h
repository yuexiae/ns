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

#ifndef NIMILESSOURCE_H
#define NIMILESSOURCE_H

#include <NiAudioSource.h>

class NiProviderInfo;

class NIAUDIO_ENTRY NiMilesSource : public NiAudioSource
{
    NiDeclareRTTI;
    NiDeclareClone(NiMilesSource);
    NiDeclareStream;

public:
 
    NiMilesSource(unsigned int uiType = TYPE_DEFAULT);
    virtual ~NiMilesSource();

    //    
    // Wave loading and unloading
    //

    virtual void SetAllowSharing(bool bAllowSharing);
    
    virtual void SetStreamed(bool bStream);

    virtual void SetFilename(const char* pcFilename);

    void SetFilename(const char* pcFilename, NiProviderInfo* pkProvider);

    virtual bool Load();
    virtual bool Unload();
    
    //
    // Audio parameters --
    // Many of these functions access the SoundSystem interface directly.  
    // Those that do will have corresponding "Set" functions 
    // return a boolean indicating if it was possible to set the 
    // value. However, in most cases the return value only indicates
    // if we were able to make a call to the SoundSystem (valid sound handle)
    // as opposed to if the SoundSystem actually set the values correctly.
    //
   
    //
    //  Sound Cones - May not work with all providers.. see Miles documentation
    //
    virtual bool SetConeData(float fAngle1Deg, float fAngle2Deg, float fGain);
    virtual void GetConeData(float& fAngle1Deg, 
        float& fAngle2Deg, float& fGain);

    //
    //  Distances work differently on different providers
    //
    virtual bool SetMinMaxDistance(float fMin, float fMax);
    virtual void GetMinMaxDistance(float& fMin, float& fMax);
    
    virtual bool SetGain(float fGain);
    virtual float GetGain();

    virtual bool SetPlaybackRate(long lRate);
    virtual long GetPlaybackRate();
    
    //
    // Special audio parameters-
    //   Some providers let samples have special values.. 
    //   see Miles documentation
    //

    virtual void SetSamplePreference(char* pcPreferenceName, 
        void* pvPreferenceValue);
    virtual void GetSamplePreference(char* pcPreferenceName, 
        void* pvPreferenceValue);
           
    //
    // Playback control
    //
    virtual void SetLoopCount(int iLoopCount);
    
    virtual bool Play();
    virtual bool Stop();
    virtual void Rewind();
    
    virtual Status GetStatus();
    
    virtual bool SetPlayTime(float fTime);
    virtual float GetPlayTime();
    virtual bool GetPlayLength(float& fTime);
    
    virtual bool SetPlayPosition(unsigned int dwPos);
    virtual unsigned int GetPlayPosition();   
    
    //
    // Update
    //
    virtual void Update(float fTime);
    
    //
    // Occlusion, obstruction and room effect
    //

    virtual bool SetRoomEffectLevel(float fLevel);
    virtual float GetRoomEffectLevel();

    virtual bool SetOcclusionFactor(float fLevel);
    virtual float GetOcclusionFactor();

    virtual bool SetObstructionFactor(float fLevel);
    virtual float GetObstructionFactor();
    
    //
    // Query the internal SoundSystem renderer state.  Typically
    // theGamebryo state information should be sufficient,
    // but these methods give the SoundSystem's internal values.
    // Note: These return values are intentionally 
    // NOT references.
    //
    virtual NiPoint3 GetPosition();
    virtual void GetOrientation(NiPoint3& kDir, NiPoint3& kUp);
    virtual NiPoint3 GetVelocity();
    virtual NiPoint3 GetWorldVelocity() { return m_kLocalVelocity; };

    // Access to Miles structures for advanced application usage
    // or features unsupported by Gamebryo
    //
    // get source handle
    void* GetHandle();
    // get pointer to the sound data
    void* GetFileImage();            

protected:
    //
    // Stop and release the source
    //
    virtual void Release();
    void CreateHandle();


    NiProviderInfo* m_pkProvider;
    void* m_pvSource;
    void* m_pvMemPtr;    // need to remember where this sample is in memory

    Status m_eDoneStatus;
   
    friend class NiMilesAudioSystem;
};

typedef NiPointer<NiMilesSource> NiMilesSourcePtr;


#endif
