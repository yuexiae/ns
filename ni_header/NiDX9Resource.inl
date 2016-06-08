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
// NiDX9Resource.inl
//---------------------------------------------------------------------------
inline const unsigned int NiDX9Resource::GetResourceID()
{
    return m_uiResID;
}
//---------------------------------------------------------------------------
inline const NiDX9Resource::Type NiDX9Resource::GetType()
{
    return m_eType;
}
//---------------------------------------------------------------------------
inline const D3DPOOL NiDX9Resource::GetPool()
{
    return m_ePool;
}
//---------------------------------------------------------------------------
inline const unsigned int NiDX9Resource::GetUsage()
{
    return m_uiUsage;
}
//---------------------------------------------------------------------------
inline const LPDIRECT3DRESOURCE9 NiDX9Resource::GetResource()
{
    return m_pkD3DResource;
}
//---------------------------------------------------------------------------
