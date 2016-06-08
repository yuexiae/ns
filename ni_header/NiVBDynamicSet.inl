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
//  NiVBDynamicSet Inline Functions
//---------------------------------------------------------------------------
inline NiVBDynamicSet::NiVBDynamicSet()
{
    m_uiIndex = 0;
    m_uiFVF = 0;
    m_uiBlockSize = 0;
    m_pkD3DDevice = 0;
    m_pkVB = 0;
}
//---------------------------------------------------------------------------
inline NiVBDynamicSet::~NiVBDynamicSet()
{
    //  Free the vertex buffer, and the D3DDevice
    if (m_pkVB)
        D3D_POINTER_RELEASE(m_pkVB);
    if (m_pkD3DDevice)
        D3D_POINTER_RELEASE(m_pkD3DDevice);
}
//---------------------------------------------------------------------------
inline NiVBDynamicSet* NiVBDynamicSet::Create(unsigned int uiBlockSize, 
    D3DDevicePtr pkD3DDevice, unsigned int uiFVF, unsigned int uiIndex)
{
    NiVBDynamicSet* pkSet = new NiVBDynamicSet();
    if (pkSet)
    {
        pkSet->SetBlockSize(uiBlockSize);
        pkSet->SetD3DDevice(pkD3DDevice);
        pkSet->SetFVF(uiFVF);
        pkSet->SetIndex(uiIndex);
    }
    return pkSet;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBDynamicSet::GetBlockSize(void)
{
    return m_uiBlockSize;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBDynamicSet::GetFVF(void)
{
    return m_uiFVF;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBDynamicSet::GetIndex(void)
{
    return m_uiIndex;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBDynamicSet::GetCurrOffset(void)
{
    return m_uiCurrOffset;
}
//---------------------------------------------------------------------------
inline void NiVBDynamicSet::SetBlockSize(unsigned int uiBlockSize)
{
    if ((uiBlockSize & 0x0000000f) != 0)
    {
        uiBlockSize = (uiBlockSize & 0xfffffff0) + 32;
    }

    m_uiBlockSize = uiBlockSize;
}
//---------------------------------------------------------------------------
inline void NiVBDynamicSet::SetD3DDevice(D3DDevicePtr pkD3DDevice)
{
    assert(pkD3DDevice);
    if (m_pkD3DDevice)
        D3D_POINTER_RELEASE(m_pkD3DDevice);
    
    if (pkD3DDevice)
    {
        m_pkD3DDevice = pkD3DDevice;
        D3D_POINTER_REFERENCE(m_pkD3DDevice);
    }
    else
    {
        m_pkD3DDevice = 0;
    }
}      
//---------------------------------------------------------------------------
inline void NiVBDynamicSet::SetFVF(unsigned int uiFVF)
{
    m_uiFVF = uiFVF;
}
//---------------------------------------------------------------------------
inline void NiVBDynamicSet::SetIndex(unsigned int uiIndex)
{
    m_uiIndex = uiIndex;
}
//---------------------------------------------------------------------------
