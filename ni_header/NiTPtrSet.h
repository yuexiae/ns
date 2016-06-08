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

#ifndef NITPTRSET_H
#define NITPTRSET_H

#include <NiTSet.h>

// This template class implements an unordered set. It is safe for smart
// pointer use.
template <class T> class NiTPtrSet : public NiTSet<T>
{
public:
    NiTPtrSet(unsigned int uiInitialSize = 1);
    ~NiTPtrSet();

    void RemoveAt(unsigned int uiIndex);
    void OrderedRemoveAt(unsigned int uiIndex); // Preserve order.
    void RemoveAll();

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    NiTPtrSet(const NiTPtrSet&);
    NiTPtrSet& operator=(const NiTPtrSet&);
};

//---------------------------------------------------------------------------
template <class T> inline
NiTPtrSet<T>::NiTPtrSet(unsigned int uiInitialSize) : NiTSet<T>(uiInitialSize)
{
}
//---------------------------------------------------------------------------
template <class T> inline
NiTPtrSet<T>::~NiTPtrSet()
{
    RemoveAll();
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPtrSet<T>::RemoveAt(unsigned int uiIndex)
{
    assert(uiIndex < m_uiUsed);

    m_pBase[uiIndex] = m_pBase[--m_uiUsed];
    m_pBase[m_uiUsed] = 0;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPtrSet<T>::OrderedRemoveAt(unsigned int uiIndex)
{
    assert(uiIndex < m_uiUsed);

    for (unsigned int ui = uiIndex; ui < m_uiUsed - 1; ui++)
    {
        m_pBase[ui] = m_pBase[ui + 1];
    }
    m_uiUsed--;
    m_pBase[m_uiUsed] = 0;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTPtrSet<T>::RemoveAll()
{
    for (unsigned int ui = 0; ui < m_uiAlloced; ui++)
    {
        m_pBase[ui] = 0;
    }
    m_uiUsed = 0;
}
//---------------------------------------------------------------------------

#endif // #ifndef NITPTRSET_H
