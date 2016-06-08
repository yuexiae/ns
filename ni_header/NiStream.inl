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

//---------------------------------------------------------------------------
// Inline load/save routines for native data.
//---------------------------------------------------------------------------
template <class T>
void NiStreamLoadBinary(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.Istr(), &value, 1);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamLoadBinary(NiStream& kStream, T* pValue, unsigned int uiNumEls)
{
    NiBinaryStreamLoad(kStream.Istr(), pValue, uiNumEls);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamLoadEnum(NiStream& kStream, T& value)
{
    NiBinaryStreamLoadEnum(kStream.Istr(), &value);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamSaveBinary(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(kStream.Ostr(), &value, 1);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamSaveBinary(NiStream& kStream, const T* pValue,
    unsigned int uiNumEls)
{
    NiBinaryStreamSave(kStream.Ostr(), pValue, uiNumEls);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamSaveEnum(NiStream& kStream, const T& value)
{
    NiBinaryStreamSaveEnum(kStream.Ostr(), value);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  NiStream inline functions
//---------------------------------------------------------------------------
inline unsigned int NiStream::GetObjectCount() const
{
    return m_kTopObjects.GetSize();
}
//---------------------------------------------------------------------------
inline NiObject* NiStream::GetObjectAt(unsigned int i) const
{
    return m_kTopObjects.GetAt(i);
}
//---------------------------------------------------------------------------
inline unsigned int NiStream::GetFileVersion() const
{
    return m_uiNifFileVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiStream::GetFileUserDefinedVersion() const
{
    return m_uiNifFileUserDefinedVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiStream::GetLastError() const
{
    return m_uiLastError;
}
//---------------------------------------------------------------------------
inline const char* NiStream::GetLastErrorMessage() const
{
    return m_acLastErrorMessage;
}
//---------------------------------------------------------------------------
inline void NiStream::ResetLastErrorInfo()
{
    m_uiLastError = STREAM_OKAY;
    m_acLastErrorMessage[0] = 0;
}
//---------------------------------------------------------------------------
inline const char* NiStream::GetLastLoadedRTTI() const
{
    return m_acLastErrorMessage;
}
//---------------------------------------------------------------------------
inline void NiStream::SaveLinkID(const NiObject* pkObject)
{
    unsigned int uiLinkID = GetLinkIDFromObject(pkObject);
    NiStreamSaveBinary(*this, uiLinkID);
}
//---------------------------------------------------------------------------
inline bool NiStream::BackgroundLoadGetExitStatus() const
{
    return m_bBackgroundLoadExitStatus;
}
//---------------------------------------------------------------------------
inline NiBinaryStream& NiStream::Istr()
{
    return *m_pkIstr;
}
//---------------------------------------------------------------------------
inline NiBinaryStream& NiStream::Ostr()
{
    return *m_pkOstr;
}
//---------------------------------------------------------------------------
inline NiSearchPath* NiStream::GetSearchPath() const
{
    return m_pkSearchPath;
}
//---------------------------------------------------------------------------
inline void NiStream::LockCleanupSection()
{
    ms_kCleanupCriticalSection.Lock();
}
//---------------------------------------------------------------------------
inline void NiStream::UnlockCleanupSection()
{
    ms_kCleanupCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
// Flag Conversion Functions
//---------------------------------------------------------------------------
inline unsigned short NiStream::GetLastNiAVObjectFlags() const
{
    return m_usNiAVObjectFlags;
}
//---------------------------------------------------------------------------
inline void NiStream::SetLastNiAVObjectFlags(unsigned short usFlags)
{
    m_usNiAVObjectFlags = usFlags;
}
//---------------------------------------------------------------------------
inline unsigned short NiStream::GetLastNiTimeControllerFlags() const
{
    return m_usNiTimeControllerFlags;
}
//---------------------------------------------------------------------------
inline void NiStream::SetLastNiTimeControllerFlags(unsigned short usFlags)
{
    m_usNiTimeControllerFlags = usFlags;
}
//---------------------------------------------------------------------------
inline unsigned short NiStream::GetLastNiPropertyFlags() const
{
    return m_usNiPropertyFlags;
}
//---------------------------------------------------------------------------
inline void NiStream::SetLastNiPropertyFlags(unsigned short usFlags)
{
    m_usNiPropertyFlags = usFlags;
}
//---------------------------------------------------------------------------
// End flag conversion functions.
//---------------------------------------------------------------------------
inline unsigned int NiStream::GetVersion(unsigned int uiMajor,
    unsigned int uiMinor, unsigned int uiPatch, unsigned int uiInternal)
{
    assert(uiMajor < 256);
    assert(uiMinor < 256);
    assert(uiPatch < 256);
    assert(uiInternal < 256);

    return (uiMajor << 24) | (uiMinor << 16) | (uiPatch << 8) | uiInternal;
}
//---------------------------------------------------------------------------
#if defined(NGC) && defined(_DEBUG)
inline void NiStream::CheckConsistency()
{
    if (m_pkOSBackgroundThread)
    {
        //This assert checks if you have blown the stack on the background
        //loading thread.  By default it is 8K.  You can change the value
        //in NiStream.h.
        if (*(m_pkOSBackgroundThread->stackEnd) != OS_THREAD_STACK_MAGIC)
            OSCheckActiveThreads();
    }
}
#else
inline void NiStream::CheckConsistency()
{
}
#endif
