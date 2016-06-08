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
//  NiTQueue inline functions

//---------------------------------------------------------------------------
template <class T> inline
NiTQueue<T>::NiTQueue(unsigned int uiInitialSize)
{
    assert(uiInitialSize > 0);

    m_pBase = new T[uiInitialSize];
    assert(m_pBase != NULL);
    m_uiAlloced = uiInitialSize;
    m_uiHead = UINT_MAX;
    m_uiTail = 0;
}

//---------------------------------------------------------------------------
template <class T> inline
NiTQueue<T>::~NiTQueue()
{
    while (!IsEmpty())
        Remove();
    delete[] m_pBase;
}

//---------------------------------------------------------------------------
template <class T> inline
bool NiTQueue<T>::IsEmpty() const
{
    return (m_uiHead == UINT_MAX);
}

//---------------------------------------------------------------------------
template <class T> inline
bool NiTQueue<T>::IsFull() const
{
    return (m_uiHead == m_uiTail);
}

//---------------------------------------------------------------------------
template <class T> inline
T NiTQueue<T>::Head() const
{
    assert(!IsEmpty());
    return m_pBase[m_uiHead];
}

//---------------------------------------------------------------------------
template <class T> inline
T NiTQueue<T>::Remove()
{
    if (IsEmpty())
        return 0;

    T element;
    element = m_pBase[m_uiHead];
    m_pBase[m_uiHead] = 0;
    if (++m_uiHead == m_uiAlloced)
    {
        m_uiHead = 0;
    }
    if (m_uiHead == m_uiTail)
    {
        m_uiHead = UINT_MAX;
        m_uiTail = 0;
    }
    return element;
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTQueue<T>::Add(T element)
{
    if (IsEmpty())
    {
        m_pBase[m_uiHead = 0] = element;
        m_uiTail = 1;
    }
    else
    {
        if (IsFull())
        {
            Realloc(2 * m_uiAlloced);
        }

        m_pBase[m_uiTail++] = element;
    }

    if (m_uiTail == m_uiAlloced)
    {
        m_uiTail = 0;
    }
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTQueue<T>::AddUnique(T element)
{
    unsigned int i;

    if (!IsEmpty())
    {
        if (m_uiHead >= m_uiTail)
        {
            for (i = m_uiHead; i < m_uiAlloced; i++)
            {
                if (m_pBase[i] == element)
                    return;
            }

            for (i = 0; i < m_uiTail; i++)
            {
                if (m_pBase[i] == element)
                    return;
            }
        }
        else
        {
            for (i = m_uiHead; i < m_uiTail; i++)
            {
                if (m_pBase[i] == element)
                    return;
            }
        }
    }

    Add(element);
}

//---------------------------------------------------------------------------
template <class T> inline
unsigned int NiTQueue<T>::GetSize() const
{
    if (IsEmpty())
    {
        return 0;
    }
    else if (m_uiHead >= m_uiTail)
    {
        return m_uiAlloced - m_uiHead + m_uiTail;
    }
    else
    {
        return m_uiTail - m_uiHead;
    }
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTQueue<T>::Realloc()
{
    Realloc(GetSize());
}

//---------------------------------------------------------------------------
template <class T> inline
void NiTQueue<T>::Realloc(unsigned int uiNewSize)
{
    T *pNewBase;
    unsigned int i, j;

    assert(uiNewSize >= GetSize());

    pNewBase = new T[uiNewSize];
    assert(pNewBase != NULL);

    j = 0;
    if (m_uiHead >= m_uiTail)
    {
        for (i = m_uiHead; i < m_uiAlloced; i++)
        {
            pNewBase[j++] = m_pBase[i];
        }
        
        for (i = 0; i < m_uiTail; i++)
        {
            pNewBase[j++] = m_pBase[i];
        }
    }
    else
    {
        for (i = m_uiHead; i < m_uiTail; i++)
        {
            pNewBase[j++] = m_pBase[i];
        }
    }

    assert(j == GetSize());

    m_uiHead = 0;
    m_uiTail = j;
    m_uiAlloced = uiNewSize;
    delete[] m_pBase;
    m_pBase = pNewBase;
}
