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
inline bool NiDX8DeviceDesc::DisplayFormatInfo::CanRenderFullscreen() const
{
    return m_bFullscreen;
}
//---------------------------------------------------------------------------
inline bool NiDX8DeviceDesc::DisplayFormatInfo::CanRenderWindowed() const
{
    return m_bWindowed;
}
//---------------------------------------------------------------------------
inline D3DFORMAT NiDX8DeviceDesc::DisplayFormatInfo::GetFormat() const
{
    return m_eFormat;
}
//---------------------------------------------------------------------------
inline bool NiDX8DeviceDesc::IsDeviceValid() const
{
    return m_kD3DCaps8.DeviceType ? true : false;
}
//---------------------------------------------------------------------------
inline D3DDEVTYPE NiDX8DeviceDesc::GetDeviceType() const
{
    return m_kD3DDevType;
}
//---------------------------------------------------------------------------
inline const D3DCAPS8& NiDX8DeviceDesc::GetCaps() const
{
    return m_kD3DCaps8;
}
//---------------------------------------------------------------------------
inline bool NiDX8DeviceDesc::CanRenderWindowed() const
{
    return m_bRenderWindowed;
}
//---------------------------------------------------------------------------
inline const NiDX8DeviceDesc::DisplayFormatInfo* 
    NiDX8DeviceDesc::GetFormatInfo(D3DFORMAT eFormat) const
{
    NiTListIterator pkIter = m_kScreenFormats.GetHeadPos();
    while (pkIter)
    {
        DisplayFormatInfo* pkMode = m_kScreenFormats.GetNext(pkIter);
        if (pkMode->GetFormat() == eFormat)
            return pkMode;
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8AdapterDesc::ModeDesc::GetClosestRefreshRate(
    unsigned int uiRefreshRate) const
{
    if ((uiRefreshRate != D3DPRESENT_RATE_UNLIMITED) && 
        (uiRefreshRate != D3DPRESENT_RATE_DEFAULT))
    {
        NiTListIterator pkIter = m_kRefreshRates.GetHeadPos();

        assert(pkIter);

        unsigned int uiTestRefreshRate = m_kRefreshRates.GetNext(pkIter);

        unsigned int uiBestRefreshDiff 
            = abs((int)uiTestRefreshRate - (int)uiRefreshRate);

        while (pkIter)
        {
            uiTestRefreshRate = m_kRefreshRates.GetNext(pkIter);

            unsigned int uiRefreshDiff 
                = abs((int)uiTestRefreshRate - (int)uiRefreshRate);

            if (uiRefreshDiff < uiBestRefreshDiff)
            {
                uiBestRefreshDiff = uiRefreshDiff;
                uiRefreshRate = uiTestRefreshRate;
            }
        }
    }

    return uiRefreshRate;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8AdapterDesc::GetAdapterIndex() const
{
    return m_uiAdapter;
}
//---------------------------------------------------------------------------
inline const char* NiDX8AdapterDesc::GetStringDescription() const
{
    return m_kAdapterIdentifier.Description;
}
//---------------------------------------------------------------------------
inline const D3DADAPTER_IDENTIFIER8& NiDX8AdapterDesc::GetAdapterIdentifier()
    const
{
    return m_kAdapterIdentifier;
}
//---------------------------------------------------------------------------
inline const NiDX8DeviceDesc* NiDX8AdapterDesc::GetDevice(
    D3DDEVTYPE devType) const
{
    if(devType == D3DDEVTYPE_HAL)
    {
        if (m_pkHALDeviceDesc->IsDeviceValid())
            return m_pkHALDeviceDesc;
        else
            return NULL;
    }
    else
    {
        if (m_pkREFDeviceDesc->IsDeviceValid())
            return m_pkREFDeviceDesc;
        else
            return NULL;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8AdapterDesc::GetModeCount() const
{
    return m_kModeList.GetSize();
}
//---------------------------------------------------------------------------
inline const NiDX8AdapterDesc::ModeDesc* NiDX8AdapterDesc::GetMode(
    unsigned int uiMode) const
{
    return m_kModeList.GetAt(uiMode);
}
//---------------------------------------------------------------------------
inline bool NiDX8AdapterDesc::CanDeviceRenderWindowed(
    D3DDEVTYPE devType) const
{
    const NiDX8DeviceDesc* pkDevice = GetDevice(devType);

    if (!pkDevice)
        return false;

    // if the current display mode is supported by the hardware as a windowed
    // mode, return true

    return pkDevice->CanRenderWindowed();
}
//---------------------------------------------------------------------------
inline const D3DCAPS8* NiDX8AdapterDesc::GetDeviceCaps(
    D3DDEVTYPE devType) const
{
    const NiDX8DeviceDesc* pkDevice = GetDevice(devType);

    if (pkDevice)
        return &(pkDevice->GetCaps());
    else
        return NULL;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8SystemDesc::GetAdapterCount() const
{
    return m_uiAdapterCount;
}
//---------------------------------------------------------------------------
inline const NiDX8AdapterDesc* NiDX8SystemDesc::GetAdapter(
    unsigned int uiAdapter) const
{
    return m_kAdapterList.GetAt(uiAdapter);
}
//---------------------------------------------------------------------------

