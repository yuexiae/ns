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
//  NiTArray  inline functions

//---------------------------------------------------------------------------
template <class T> inline
NiTArray<T>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_uiMaxSize = uiMaxSize;
    m_uiGrowBy = uiGrowBy;
    m_uiSize = 0;
    m_uiESize = 0;

    if (m_uiMaxSize > 0)
    {
        m_pBase = new T[m_uiMaxSize];
        assert(m_pBase);
    }
    else
    {
        m_pBase = 0;
    }
}
//---------------------------------------------------------------------------
template <class T> inline
NiTArray<T>::~NiTArray()
{
    delete[] m_pBase;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTArray<T>::GetBase()
{
    return m_pBase;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::GetSize() const
{
    return m_uiSize;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::GetEffectiveSize() const
{
    return m_uiESize;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::GetAllocatedSize() const
{
    return m_uiMaxSize;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::GetGrowBy() const
{
    return m_uiGrowBy;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    // If the number of slots gets smaller, the elements in the unwanted
    // slots must be zeroed in case class T has side effects that must occur.
    // For example, if T is a smart pointer class, then decrementing the ref
    // count must occur.
    unsigned int i;
    if (uiMaxSize < m_uiSize)
    {
        for (i = uiMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_uiESize--;
            }
        }

        m_uiSize = uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (uiMaxSize > 0)
    {
        // allocate a new array
        m_pBase = new T[m_uiMaxSize];
        assert(m_pBase);

        // copy old array to new array
        for (i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }
        // initialize new memory
        for (i = m_uiSize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = T(0);  
        }

        
    }
    else
    {
        m_pBase = 0;
    }

    // delete old array
    delete[] pSaveBase;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::SetGrowBy(unsigned int uiGrowBy)
{
    m_uiGrowBy = uiGrowBy;
}
//---------------------------------------------------------------------------
template <class T> inline
const T& NiTArray<T>::GetAt(unsigned int uiIndex) const
{
    return m_pBase[uiIndex];
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::SetAt(unsigned int uiIndex, const T& element)
{
    assert (uiIndex < m_uiMaxSize);
    if (uiIndex >= m_uiMaxSize)
    {
        return;
    }

    if (uiIndex >= m_uiSize)
    {
        m_uiSize = uiIndex+1;
        if (element != T(0))
        {
            m_uiESize++;
        }
    }
    else 
    {
        if (element != T(0))
        {
            if (m_pBase[uiIndex] == T(0))
            {
                m_uiESize++;
            }
        }
        else
        {
            if (m_pBase[uiIndex] != T(0))
            {
                m_uiESize--;
            }
        }
    }

    m_pBase[uiIndex] = element;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_uiMaxSize)
    {
        SetSize(uiIndex + m_uiGrowBy);
    }

    SetAt(uiIndex, element);
    return uiIndex;
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::Add(const T& element)
{
    return SetAtGrow(m_uiSize, element);
}
//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTArray<T>::AddFirstEmpty(const T& element)
{
    if (element == T(0))
    {
        return 0xffffffff;
    }

    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        if (m_pBase[i] == T(0))
        {
            // empty slot - add here
            m_pBase[i] = element;
            m_uiESize++;
            return i;
        }
    }

    // no empty slots - add at end
    return SetAtGrow(m_uiSize, element);
}
//---------------------------------------------------------------------------
template <class T> inline
T NiTArray<T>::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex >= m_uiSize)
    {
        return T(0);
    }
    
    T element = m_pBase[uiIndex];
    m_pBase[uiIndex] = T(0);

    if (element != T(0))
    {
        m_uiESize--;
    }

    if (uiIndex == m_uiSize - 1)
    {
        m_uiSize--;
    }

    return element;
}
//---------------------------------------------------------------------------
template <class T> inline
T NiTArray<T>::RemoveAtAndFill(unsigned int uiIndex)
{
    if (uiIndex >= m_uiSize)
    {
        return T(0);
    }
    
    m_uiSize--;
    T element = m_pBase[uiIndex];

    m_pBase[uiIndex] = m_pBase[m_uiSize];
    m_pBase[m_uiSize] = T(0);

    if (element != T(0))
    {
        m_uiESize--;
    }

    return element;
}
//---------------------------------------------------------------------------
template <class T> inline
T NiTArray<T>::RemoveEnd()
{
    if (m_uiSize == 0)
        return T(0);

    m_uiSize--;
    T element = m_pBase[m_uiSize];
    m_pBase[m_uiSize] = T(0);

    if (element != T(0))
    {
        m_uiESize--;
    }

    return element;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::RemoveAll()
{
    // The elements in the to-be-removed slots must be zeroed in case class
    // T has side effects that must occur.  For example, if T is a smart
    // pointer class, then decrementing the ref count must occur.
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        m_pBase[i] = T(0);
    }

    m_uiSize = 0;
    m_uiESize = 0;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::Compact()
{
    if (m_uiESize == m_uiSize)
    {
        return;
    }

    // move elements to contiguous memory at beginning of array
    if (m_uiESize)
    {
        for (unsigned int i = 0, j = 0; i < m_uiSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                if (m_pBase[j] != m_pBase[i])
                {
                    m_pBase[j] = m_pBase[i];
                }
                j++;
            }
        }
    }

    // downsize storage
    T* pSaveBase = m_pBase;
    m_uiSize = m_uiESize;
    m_uiMaxSize = m_uiSize;
    if (m_uiMaxSize > 0)
    {
        m_pBase = new T[m_uiMaxSize];
        assert(m_pBase);

        // copy old array to new array
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }
    }
    else
    {
        m_pBase = 0;
    }

    // delete old array
    delete[] pSaveBase;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTArray<T>::UpdateSize()
{
    while (m_uiSize > 0)
    {
        if (m_pBase[m_uiSize - 1] != T(0))
        {
            break;
        }

        m_uiSize--;
    }
}
//---------------------------------------------------------------------------
