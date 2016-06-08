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

#ifndef NIROOMGROUP_H
#define NIROOMGROUP_H

#include "NiRoom.h"
#include "NiStream.h"

class NIPORTAL_ENTRY NiRoomGroup : public NiNode
{
    NiDeclareRTTI;
    NiDeclareStream;
public:
    // construction
    NiRoomGroup();
    virtual ~NiRoomGroup();

    // shell of group, to be viewed from outside
    NiAVObjectPtr GetShell() const;
    void AttachShell(NiAVObject* pkShell);
    NiAVObjectPtr DetachShell();

    // rooms, to be viewed from inside
    const NiRoomList& GetRoomList() const;
    void AttachRoom(NiRoom* pkRoom);
    NiRoomPtr DetachRoom(NiRoom* pkRoom);

    // display
    virtual void Display(NiCamera* pkCamera);

    // Given kPoint should be in World space
    NiRoomPtr WhichRoom(const NiPoint3& kPoint) const;

    // As above, but starts search at the given room
    // The given room is _assumed_ to be in the room group
    NiRoomPtr WhichRoom(const NiPoint3& kPoint, NiRoom* pkLastRoom) const;

    // The "current" room from the last frame drawn
    NiRoomPtr GetLastRoom() const;

    // Allows the application to set a "hint" of which
    // room contains the viewer
    void SetLastRoom(NiRoom* pkLastRoom);

protected:
    void UpdateChildArray();

    // contained objects
    NiAVObjectPtr m_spShell;
    NiRoomList m_kRooms;

    NiRoomPtr m_spLastRoom;
};

typedef NiPointer<NiRoomGroup> NiRoomGroupPtr;

//---------------------------------------------------------------------------
inline NiRoomGroup::~NiRoomGroup()
{
    m_kRooms.RemoveAll();
}
//---------------------------------------------------------------------------
inline NiRoomGroup::NiRoomGroup()
{ 
    /* */
}
//---------------------------------------------------------------------------
inline NiAVObjectPtr NiRoomGroup::GetShell() const
{
    return m_spShell;
}
//---------------------------------------------------------------------------
inline const NiRoomList &NiRoomGroup::GetRoomList() const
{
    return m_kRooms;
}
//---------------------------------------------------------------------------
inline NiRoomPtr NiRoomGroup::GetLastRoom() const 
{ 
    return m_spLastRoom; 
}
//---------------------------------------------------------------------------
inline void NiRoomGroup::SetLastRoom(NiRoom* pkLastRoom)
{
    m_spLastRoom = pkLastRoom;
}
//---------------------------------------------------------------------------

#endif

