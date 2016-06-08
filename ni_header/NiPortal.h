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

#ifndef NIPORTAL_H
#define NIPORTAL_H

#include "NiPortalLibType.h"

#include "NiAVObject.h"
#include "NiPlane.h"
#include "NiTPointerList.h"
#include "NiStream.h"

#include "NiRoom.h"
#include "NiRoomGroup.h"
#include "NiPortalSDM.h"
static NiPortalSDM NiPortalSDMObject;

class NiFrustum;

class NIPORTAL_ENTRY NiPortal : public NiAVObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareFlags(unsigned short);

public:
    // construction - points are COPIED by object
    NiPortal(unsigned short usVertices, const NiPoint3* pkVertex,
        NiAVObject* pkAdjoiner = 0, bool bActive = true);

    virtual ~NiPortal();

    // member access
    void SetAdjoiner(NiAVObject* pkAdjoiner);
    NiAVObject* GetAdjoiner() const;
    void SetActive(bool bActive);
    bool GetActive() const;

    unsigned short GetVertexCount() const;

    NiPoint3* GetVertices();
    const NiPoint3* GetVertices() const;

    // transforms
    virtual void ApplyTransform(const NiMatrix3& kMat, const NiPoint3& kTrn,
        bool bOnLeft);

    // bounds
    void SetModelBound(const NiBound& kBound);
    const NiBound& GetModelBound() const;
    NiBound& GetModelBound();
    
    // display
    virtual void Display(NiCamera* pkCamera);

protected:
    NiPortal();

    // updates
    virtual void UpdateWorldData(); 
    virtual void UpdateWorldBound();

    bool ComputePortalFrustum(NiCamera& kCamera, NiFrustum& kFrustum);

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 8
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        // switch to turn portal on/off
        ACTIVE_MASK = 0x0001,

        // flag to indicate if portal is part of current visitation path
        MARKED_MASK = 0x0002
    };

    bool GetMarked() const;
    void SetMarked(bool bMarked);

    // model points
    unsigned short m_usVertices;
    NiPoint3* m_pkModelVertex;

    // portal adjoiner _not_ refcounted (to avoid refcount cycles)
    NiAVObject* m_pkAdjoiner;

    NiBound m_kModelBound;

    NiPoint3* m_pkWorldVertex;
};

NiSmartPointer(NiPortal);

typedef NiTPointerList<NiPortalPtr> NiPortalList;

//---------------------------------------------------------------------------
inline void NiPortal::SetAdjoiner(NiAVObject* pkAdjoiner)
{ 
    m_pkAdjoiner = pkAdjoiner; 
}
//---------------------------------------------------------------------------
inline NiAVObject* NiPortal::GetAdjoiner() const
{ 
    return m_pkAdjoiner; 
}
//---------------------------------------------------------------------------
inline void NiPortal::SetActive(bool bActive) 
{ 
    SetBit(bActive, ACTIVE_MASK);
}
//---------------------------------------------------------------------------
inline bool NiPortal::GetActive() const
{ 
    return GetBit(ACTIVE_MASK); 
}
//---------------------------------------------------------------------------
inline void NiPortal::SetMarked(bool bMarked) 
{ 
    SetBit(bMarked, MARKED_MASK);
}
//---------------------------------------------------------------------------
inline bool NiPortal::GetMarked() const
{ 
    return GetBit(MARKED_MASK); 
}
//---------------------------------------------------------------------------
inline unsigned short NiPortal::GetVertexCount() const
{
    return m_usVertices;
}
//---------------------------------------------------------------------------
inline NiPoint3* NiPortal::GetVertices()
{
    return m_pkModelVertex;
}
//---------------------------------------------------------------------------
inline const NiPoint3* NiPortal::GetVertices() const
{
    return m_pkModelVertex;
}
//---------------------------------------------------------------------------
inline void NiPortal::SetModelBound(const NiBound& kBound)
{
    m_kModelBound = kBound;
}
//---------------------------------------------------------------------------
inline const NiBound& NiPortal::GetModelBound() const
{
    return m_kModelBound;
}
//---------------------------------------------------------------------------
inline NiBound& NiPortal::GetModelBound()
{
    return m_kModelBound;
}
//---------------------------------------------------------------------------
#endif

