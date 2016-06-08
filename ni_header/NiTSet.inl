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
//  NiTSet inline functions

//---------------------------------------------------------------------------
template <class T> inline
NiTSet<T>::NiTSet(unsigned int uiInitialSize)
{
    if (uiInitialSize > 0)
    {
        m_pBase = new T[uiInitialSize];
        assert(m_pBase != NULL);
    }
    else
    {
        m_pBase = NULL;
    }
    m_uiAlloced = uiInitialSize;
    m_uiUsed = 0;
}

//---------------------------------------------------------------------------
template <class T> inline
NiTSet<T>::~NiTSet()
{
    delete[] m_pBase;
}

//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTSet<T>::GetSize() const
{
    return m_uiUsed;
}

//---------------------------------------------------------------------------
template <class T> inline
T* NiTSet<T>::GetBase() const
{
    return m_pBase;
}

//---------------------------------------------------------------------------
template <class T> inline
const T& NiTSet<T>::GetAt(unsigned int uiIndex) const
{
    assert(uiIndex < m_uiUsed);
    return m_pBase[uiIndex];
}

//---------------------------------------------------------------------------
template <class T> inline
T& NiTSet<T>::GetAt(unsigned int uiIndex)
{
    assert(uiIndex < m_uiUsed);
    return m_pBase[uiIndex];
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::Add(const T& element)
{
    assert(m_uiUsed <= m_uiAlloced);

    if (m_uiUsed == m_uiAlloced)
    {
        Realloc(m_uiAlloced > 0 ? (2 * m_uiAlloced) : 1);
    }

    assert(m_uiUsed < m_uiAlloced);
    m_pBase[m_uiUsed++] = element;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::AddUnique(const T& element)
{
    assert(m_uiUsed <= m_uiAlloced);

    if (Find(element) == -1)
    {
        Add(element);
    }
}

//---------------------------------------------------------------------------
template <class T> inline
int NiTSet<T>::Find(const T& element) const
{
    // If the element is in the list, the index is returned, else -1.

    assert(m_uiUsed <= m_uiAlloced);

    unsigned int i;

    for (i = 0; i < m_uiUsed; i++)
    {
        if (m_pBase[i] == element)
            return i;
    }
    return -1;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::RemoveAt(unsigned int uiIndex)
{
    assert(uiIndex < m_uiUsed);

    m_pBase[uiIndex] = m_pBase[--m_uiUsed];
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::OrderedRemoveAt(unsigned int uiIndex)
{
    assert(uiIndex < m_uiUsed);

    for (unsigned int ui = uiIndex; ui < m_uiUsed - 1; ui++)
    {
        m_pBase[ui] = m_pBase[ui + 1];
    }
    m_uiUsed--;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::ReplaceAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_uiUsed)
    {
        return;
    }

    m_pBase[uiIndex] = element;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::RemoveAll()
{
    m_uiUsed = 0;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::Realloc()
{
    Realloc(m_uiUsed);
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTSet<T>::Realloc(unsigned int uiNewSize)
{
    assert(uiNewSize >= m_uiUsed);

    if (uiNewSize != m_uiAlloced)
    {
        T *pNewBase;
        unsigned int i;

        if (uiNewSize > 0)
        {
            pNewBase = new T[uiNewSize];
            assert(pNewBase != NULL);

            for (i = 0; i < m_uiUsed; i++)
            {
                pNewBase[i] = m_pBase[i];
            }
        }
        else
        {
            pNewBase = NULL;
        }
        
        delete[] m_pBase;
        m_pBase = pNewBase;
        m_uiAlloced = uiNewSize;
    }
}
