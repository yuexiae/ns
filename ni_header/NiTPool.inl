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
template <class T> inline
NiTPoolContainer<T>::NiTPoolContainer(unsigned int uiSize) :
    m_uiSize(uiSize),
    m_pkNext(NULL)
{
    if (uiSize > 0)
    {
        m_pkObjectArray = new T[uiSize];
        assert(m_pkObjectArray != NULL);
    }
    else
    {
        m_pkObjectArray = NULL;
    }
}
//---------------------------------------------------------------------------
template <class T> inline
NiTPoolContainer<T>::~NiTPoolContainer()
{
    delete[] m_pkObjectArray;
    delete m_pkNext;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTPoolContainer<T>::GetObject(unsigned int uiIndex)
{
    if (uiIndex >= m_uiSize)
        return NULL;
    return &m_pkObjectArray[uiIndex];
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPoolContainer<T>::SetNext(NiTPoolContainer<T>* pkNext)
{
    m_pkNext = pkNext;
}
//---------------------------------------------------------------------------
template <class T> inline
NiTPool<T>::NiTPool(unsigned int uiInitialSize) :
    m_uiInitialSize(uiInitialSize),
    m_uiCurrentSize(uiInitialSize),
    m_pkContainers(NULL)
{
    assert (uiInitialSize > 0);
}
//---------------------------------------------------------------------------
template <class T> inline
NiTPool<T>::~NiTPool()
{
    m_kFreeObjects.RemoveAll();
    delete m_pkContainers;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTPool<T>::GetFreeObject()
{
    if (m_kFreeObjects.GetSize() == 0)
    {
        CreateNewObjects(m_uiCurrentSize);
        m_uiCurrentSize *= 2;
    }

    T* pkReturn = m_kFreeObjects.GetAt(0);
    m_kFreeObjects.RemoveAt(0);
    return pkReturn;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPool<T>::ReleaseObject(T* pkObject)
{
    m_kFreeObjects.AddUnique(pkObject);
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPool<T>::CreateNewObjects(unsigned int uiSize)
{
    NiTPoolContainer<T>* pkNewContainer = new NiTPoolContainer<T>(uiSize);
    for (unsigned int i = 0; i < uiSize; i++)
    {
        m_kFreeObjects.Add(pkNewContainer->GetObject(i));
    }

    pkNewContainer->SetNext(m_pkContainers);
    m_pkContainers = pkNewContainer;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPool<T>::PurgeAllObjects()
{
    m_kFreeObjects.RemoveAll();
    delete m_pkContainers;
    m_uiCurrentSize = m_uiInitialSize;
}
//---------------------------------------------------------------------------
