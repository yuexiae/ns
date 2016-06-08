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
template <class TheAllocator, class T> inline
NiTPointerListBase<TheAllocator,T>::~NiTPointerListBase() 
{
    // RemoveAll is called from here because it depends on virtual functions
    // implemented in the derived class.
    // It will also be called in the parent destructor, 
    // but the map will already be empty.
    RemoveAll();
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
NiTListItem<T>* NiTPointerListBase<TheAllocator,T>::NewItem()
{
    return (NiTListItem<T>*)m_kAllocator.Allocate();
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
void NiTPointerListBase<TheAllocator,T>::DeleteItem(NiTListItem<T>* pkItem)
{
    pkItem->m_element = 0;
    m_kAllocator.Deallocate(pkItem);
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
const T& NiTPointerListBase<TheAllocator,T>::GetHead() const
{
    return m_pkHead->m_element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
const T& NiTPointerListBase<TheAllocator,T>::GetTail() const
{
    return m_pkTail->m_element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
const T& NiTPointerListBase<TheAllocator,T>::GetNext(NiTListIterator& kPos)
    const
{
    assert (kPos != 0);

    const T& element= ((NiTListItem<T>*) kPos)->m_element;

    kPos = ((NiTListItem<T>*) kPos)->m_pkNext;
    return element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
const T& NiTPointerListBase<TheAllocator,T>::GetPrev(NiTListIterator& kPos)
    const
{
    assert(kPos != 0);

    const T& element= ((NiTListItem<T>*) kPos)->m_element;
    kPos = ((NiTListItem<T>*) kPos)->m_pkPrev;

    return element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
const T& NiTPointerListBase<TheAllocator,T>::Get(NiTListIterator kPos) const
{
    assert(kPos != 0);
    return ((NiTListItem<T>*) kPos)->m_element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
T NiTPointerListBase<TheAllocator,T>::RemoveHead()
{
    assert(m_pkHead);

    NiTListItem<T>* pkNode = m_pkHead;

    m_pkHead = m_pkHead->m_pkNext;
    
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    
    T element = pkNode->m_element;
    
    DeleteItem(pkNode);

    m_kAllocator.m_uiCount--;

    return element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
T NiTPointerListBase<TheAllocator,T>::RemoveTail()
{
    assert(m_pkTail);
    
    NiTListItem<T>* pkNode = m_pkTail;

    m_pkTail = m_pkTail->m_pkPrev;
    
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    
    T element = pkNode->m_element;
    
    DeleteItem(pkNode);

    m_kAllocator.m_uiCount--;
    
    return element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
T NiTPointerListBase<TheAllocator,T>::RemovePos(NiTListIterator& kPos)
{
    NiTListItem<T>* pkNode = (NiTListItem<T>*) kPos;

    assert(pkNode);

    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext; // kPos points to new head
        return RemoveHead();
    }
    if (pkNode == m_pkTail)
    {
        kPos = 0; // kPos has walked off end of list
        return RemoveTail();
    }

    NiTListItem<T>* pkPrev = pkNode->m_pkPrev;
    NiTListItem<T>* pkNext = pkNode->m_pkNext;

    kPos = pkNext;
    
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    
    T element = pkNode->m_element;
    
    DeleteItem(pkNode);
    
    m_kAllocator.m_uiCount--;
    
    return element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
NiTListIterator NiTPointerListBase<TheAllocator,T>::
    InsertAfter(NiTListIterator kPos, const T& element)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    pkNode->m_element = element;

    return AddNodeAfter(kPos,pkNode);
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
NiTListIterator NiTPointerListBase<TheAllocator,T>::
    InsertBefore(NiTListIterator kPos, const T& element)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    pkNode->m_element = element;

    return AddNodeBefore(kPos,pkNode);
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
void NiTPointerListBase<TheAllocator,T>::AddHead(const T& element)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    pkNode->m_element = element;
    
    AddNodeHead(pkNode);
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
void NiTPointerListBase<TheAllocator,T>::AddTail(const T& element)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    pkNode->m_element = element;

    AddNodeTail(pkNode);
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
T NiTPointerListBase<TheAllocator,T>::Remove(const T& element)
{
    NiTListIterator kPos = FindPos(element);

    return kPos ? RemovePos(kPos) : element;
}
//---------------------------------------------------------------------------
template <class TheAllocator, class T> inline
NiTListIterator NiTPointerListBase<TheAllocator,T>::
    FindPos(const T& element, NiTListIterator kStart) const
{
    if (kStart == 0)
        kStart = GetHeadPos();
    
    while (kStart)
    {
        NiTListIterator kPos = kStart;
        if (element == GetNext(kStart))
            return kPos;
    }
    return 0;
}
//---------------------------------------------------------------------------
