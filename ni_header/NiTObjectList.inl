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
NiTObjectList<T>::~NiTObjectList()
{
    // RemoveAll is called from here because it depends on virtual functions
    // implemented in NiTAllocatorMap.  It will also be called in the 
    // parent destructor, but the map will already be empty.
    RemoveAll();
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::AddNewHead()
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();
    
    AddNodeHead(pkNode);

    return &pkNode->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::AddNewTail()
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    AddNodeTail(pkNode);

    return &pkNode->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::InsertNewBefore(NiTListIterator kPos, 
    NiTListIterator& kNewIterator)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    kNewIterator = AddNodeBefore(kPos,pkNode);

    return &pkNode->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::InsertNewAfter(NiTListIterator kPos, 
    NiTListIterator& kNewIterator)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    kNewIterator = AddNodeAfter(kPos,pkNode);

    return &pkNode->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::InsertNewBefore(NiTListIterator kPos)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();

    AddNodeBefore(kPos,pkNode);

    return &pkNode->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::InsertNewAfter(NiTListIterator kPos)
{
    NiTListItem<T>* pkNode;
    pkNode = (NiTListItem<T>*) NewItem();
    
    AddNodeAfter(kPos,pkNode);

    return &pkNode->m_element;
}//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::GetHead() const
{
    return m_pkHead ? &m_pkHead->m_element : NULL;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::GetTail() const
{
    return m_pkTail ? &m_pkTail->m_element : NULL;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::GetNext(NiTListIterator& kPos) const 
{
    if (kPos == 0)
        return NULL;

    T* pkElement = &((NiTListItem<T>*) kPos)->m_element;
    kPos = ((NiTListItem<T>*) kPos)->m_pkNext;
    return pkElement;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::GetPrev(NiTListIterator& kPos) const
{
    if (kPos == 0)
        return NULL;

    T* pkElement = &((NiTListItem<T>*) kPos)->m_element;
    kPos = ((NiTListItem<T>*) kPos)->m_pkPrev;
    return pkElement;
}
//---------------------------------------------------------------------------
template <class T> inline
T* NiTObjectList<T>::Get(NiTListIterator kPos) const
{
    if (!kPos)
        return NULL;
    
    return &((NiTListItem<T>*) kPos)->m_element;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTObjectList<T>::RemoveHead()
{
    assert(m_pkHead);

    NiTListItem<T>* pkNode = m_pkHead;

    m_pkHead = m_pkHead->m_pkNext;
    
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    
    DeleteItem(pkNode);

    m_kAllocator.m_uiCount--;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTObjectList<T>::RemoveTail()
{
    assert(m_pkTail);
    
    NiTListItem<T>* pkNode = m_pkTail;

    m_pkTail = m_pkTail->m_pkPrev;
    
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    
    DeleteItem(pkNode);

    m_kAllocator.m_uiCount--;
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTObjectList<T>::RemovePos(NiTListIterator& kPos)
{
    NiTListItem<T>* pkNode = (NiTListItem<T>*) kPos;

    assert(pkNode);

    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext; // kPos points to new head
        RemoveHead();
        
    }
    else if (pkNode == m_pkTail)
    {
        kPos = 0; // kPos has walked off end of list
        RemoveTail();
    }
    else
    {
        NiTListItem<T>* pkPrev = pkNode->m_pkPrev;
        NiTListItem<T>* pkNext = pkNode->m_pkNext;

        kPos = pkNext;
    
        if (pkPrev)
            pkPrev->m_pkNext = pkNext;
        if (pkNext)
            pkNext->m_pkPrev = pkPrev;
        
        DeleteItem(pkNode);
    
        m_kAllocator.m_uiCount--;
    }
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTObjectList<T>::Remove(const T* element)
{
    NiTListIterator kPos = FindPos(element);
    if (kPos)
        RemovePos(kPos);
}
//---------------------------------------------------------------------------
template <class T> inline
NiTListIterator NiTObjectList<T>::FindPos(const T* element, 
    NiTListIterator kStart) const
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
template <class T> inline
NiTListItem<T>* NiTObjectList<T>::NewItem()
{
    return (NiTListItem<T>*)m_kAllocator.Allocate();
}
//---------------------------------------------------------------------------
template <class T> inline
void NiTObjectList<T>::DeleteItem(NiTListItem<T>* pkItem)
{
    m_kAllocator.Deallocate(pkItem);
}
//---------------------------------------------------------------------------
