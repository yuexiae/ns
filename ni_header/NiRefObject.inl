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

#include <NiOS.h>

//---------------------------------------------------------------------------
inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
    InterlockedIncrement((LONG*)&ms_uiObjects);
#else
    ++ms_uiObjects;
#endif
}
//---------------------------------------------------------------------------
inline NiRefObject::~NiRefObject()
{
#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
    InterlockedDecrement((LONG*)&ms_uiObjects);
#else
    --ms_uiObjects;
#endif
}
//---------------------------------------------------------------------------
inline void NiRefObject::IncRefCount()
{
#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
    InterlockedIncrement((LONG*)&m_uiRefCount);
#else
    ++m_uiRefCount;
#endif
}
//---------------------------------------------------------------------------
inline void NiRefObject::DecRefCount()
{
#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
    if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
        delete this;
#else
    if (--m_uiRefCount == 0)
        delete this;
#endif
}
//---------------------------------------------------------------------------
inline unsigned int NiRefObject::GetRefCount() const
{
    return m_uiRefCount;
}
//---------------------------------------------------------------------------
inline unsigned int NiRefObject::GetTotalObjectCount()
{
    return ms_uiObjects;
}
