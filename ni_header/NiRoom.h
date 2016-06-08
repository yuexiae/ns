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

#ifndef NIROOM_H
#define NIROOM_H

#include "NiNode.h"
#include "NiPortalLibType.h"
#include "NiStream.h"

NiSmartPointer(NiPortal);
typedef NiTPointerList<NiPortalPtr> NiPortalList;


typedef NiTPointerList<NiAVObjectPtr> NiAVObjectList;

class NIPORTAL_ENTRY  NiRoom : public NiNode
{
    NiDeclareRTTI;
    NiDeclareStream;
public:
    // construction
    NiRoom();
    ~NiRoom();

    class Wall
    {
    public:
        NiPlane m_kModelPlane;
        NiPlane m_kWorldPlane;
    };

    // walls
    NiTArray<Wall*>& GetWallArray();

    // portals
    const NiPortalList& GetOutgoingPortalList() const;
    void AttachOutgoingPortal(NiPortal* pkPortal);
    NiPortalPtr DetachOutgoingPortal(NiPortal* pkPortal);

    const NiPortalList& GetIncomingPortalList() const;
    void AttachIncomingPortal(NiPortal* pkPortal);
    NiPortalPtr DetachIncomingPortal(NiPortal* pkPortal);

    // fixtures
    const NiAVObjectList& GetFixtureList() const;
    void AttachFixture(NiAVObject* pkFixture);
    NiAVObjectPtr DetachFixture(NiAVObject* pkFixture);

    bool ContainsPoint(const NiPoint3& kPoint) const;

    unsigned int GetLastRenderedTimestamp() const;

    // display
    virtual void Display(NiCamera* pkCamera);

    virtual void ApplyTransform (const NiMatrix3& kMat, const NiPoint3& kTrn,
        bool bOnLeft);

    static unsigned int GetCurrentTimestamp();
    static void SetCurrentTimestamp(unsigned int uiTimestamp);

#ifndef T3D_NO_NIF_CONVERSION
    static NiObject* CreateOldWallObject();
    virtual void PostLinkObject(NiStream& kStream);
    NiAVObjectList m_kOldWalls;
#endif

protected:
    void UpdateChildArray();

    // update
    virtual void UpdateWorldData();

    // arrays of contained objects
    NiTArray<Wall*> m_kWalls;
    NiPortalList m_kInPortal;
    NiTArray<bool> m_kInPortalActive;
    NiPortalList m_kOutPortal;
    NiAVObjectList m_kFixture;

    unsigned int m_uiLastRenderedTimestamp;

    bool m_bRenderLock;

    static unsigned int ms_uiCurrentTimestamp;
};

typedef NiPointer<NiRoom> NiRoomPtr;
typedef NiTPointerList<NiRoomPtr> NiRoomList;

//---------------------------------------------------------------------------
inline NiTArray<NiRoom::Wall*>& NiRoom::GetWallArray()
{
    return m_kWalls;
}
//---------------------------------------------------------------------------
inline const NiPortalList& NiRoom::GetOutgoingPortalList() const
{
    return m_kOutPortal;
}
//---------------------------------------------------------------------------
inline const NiPortalList& NiRoom::GetIncomingPortalList() const
{
    return m_kInPortal;
}
//---------------------------------------------------------------------------
inline const NiAVObjectList& NiRoom::GetFixtureList() const
{
    return m_kFixture;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Timestamp functions
//---------------------------------------------------------------------------
inline unsigned int NiRoom::GetCurrentTimestamp()
{
    return ms_uiCurrentTimestamp;
}
//---------------------------------------------------------------------------
inline void NiRoom::SetCurrentTimestamp(unsigned int uiTimestamp)
{
    ms_uiCurrentTimestamp = uiTimestamp;
}
//---------------------------------------------------------------------------
inline unsigned int NiRoom::GetLastRenderedTimestamp() const
{
    return m_uiLastRenderedTimestamp;
}
//---------------------------------------------------------------------------

#endif

