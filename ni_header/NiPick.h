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

#ifndef NIPICK_H
#define NIPICK_H

#include "NiCollisionLibType.h"
#include <NiColor.h>
#include <NiNode.h>
#include <NiPoint3.h>
#include <NiPoint2.h>
#include <NiTArray.h>

class NiAVObject;

class NICOLLISION_ENTRY NiPick
{
public:
    // construction and destruction
    NiPick ();
    ~NiPick ();

    // pick type (default = FIND_ALL)
    typedef enum { FIND_ALL, FIND_FIRST } PickType;
    void SetPickType (PickType eType);
    PickType GetPickType () const;

    // sort type (default = SORT)
    typedef enum { SORT, NO_SORT } SortType;
    void SetSortType (SortType eType);
    SortType GetSortType () const;

    // intersect type (default = TRIANGLE_INTERSECT)
    typedef enum { BOUND_INTERSECT, TRIANGLE_INTERSECT } IntersectType;
    void SetIntersectType (IntersectType eType);
    IntersectType GetIntersectType () const;

    // intersection point space (default = MODEL_COORDINATES)
    typedef enum { MODEL_COORDINATES, WORLD_COORDINATES } CoordinateType;
    void SetCoordinateType (CoordinateType eType);
    CoordinateType GetCoordinateType () const;

    // set/get doublesided mode (default = true)
    void SetFrontOnly (bool bFrontOnly);
    bool GetFrontOnly () const;

    // stop the pick if 'app culled' flag is ste
    void SetObserveAppCullFlag (bool bObserveAppCullFlag);
    bool GetObserveAppCullFlag () const;

    // for application to add/remove objects
    void SetTarget (NiAVObject* pObject);
    void RemoveTarget ();

    // attribute return types (default = false for all)
    void SetReturnTexture (bool bReturnTexture);
    bool GetReturnTexture () const;
    void SetReturnNormal (bool bReturnNormal);
    bool GetReturnNormal () const;
    void SetReturnSmoothNormal (bool bReturnSmoothNormal);
    bool GetReturnSmoothNormal () const;
    void SetReturnColor (bool bReturnColor);
    bool GetReturnColor () const;

    // pick operation
    bool PickObjects (const NiPoint3 &origin, const NiPoint3 &dir,
        bool bAppend = false);

    class NICOLLISION_ENTRY Record
    {
    public:
        Record (NiAVObject* pObject);

        NiAVObject* GetAVObject ();

        NiNode* GetParent ();

        void SetIntersection (const NiPoint3& intersect);
        const NiPoint3& GetIntersection () const;

        void SetDistance (float fDistance);
        float GetDistance () const;

        void SetTriangleIndex (unsigned short usIndex);
        unsigned short GetTriangleIndex () const;

        void SetVertexIndices (unsigned short usIndex0,
            unsigned short usIndex1, unsigned short usIndex2);
        void GetVertexIndices (unsigned short& usIndex0,
            unsigned short& usIndex1, unsigned short& usIndex2) const;

        void SetTexture (const NiPoint2& texture);
        const NiPoint2& GetTexture () const;

        void SetNormal (const NiPoint3& normal);
        const NiPoint3& GetNormal () const;

        void SetColor (const NiColorA& color);
        const NiColorA& GetColor () const;

        // *** begin NDL internal use only ***

        // NiAlphaSorter uses this function
        void SetProxyParent (NiNode* pProxyParent);

        // *** end NDL internal use only ***

    protected:
        // The picked object.
        NiAVObjectPtr m_spObject;

        // Support for picking in NiAlphaSorter.  The picked NiTriShapes have
        // been removed from the scene graph, so their parent information is
        // no longer available.  This member stores the original parent of
        // the NiTriShape before it was replaced by an NiAlphaProxy.
        NiNodePtr m_spProxyParent;

        // Coordinate space in which the intersection point lives is
        // determined by m_eCoordinateType (MODEL_COORDINATES or
        // WORLD_COORDINATES), default is MODEL_COORDINATES.
        NiPoint3 m_intersect;

        // A true distance only when the initial ray has unit-length
        // direction vector.  Provides ordering along the ray, anyway.
        float m_fDistance;

        // surface attributes at the intersection point
        unsigned short m_usTriangleIndex;
        unsigned short m_usVertexIndex[3];
        NiPoint2 m_texture;
        NiPoint3 m_normal;
        NiColorA m_color;
    };

    // pick results array
    typedef NiTArray<Record*> Results;
    Results& GetResults ();

    // *** begin NDL internal use only ***

    void Add (Record* pNewRecord);
    unsigned int GetSize ();
    
    // NiAlphaSorter uses this function
    Record* GetLastAddedRecord ();

    // *** end NDL internal use only ***

protected:
    // picking parameters
    PickType m_ePickType;
    SortType m_eSortType;
    IntersectType m_eIntersectType;
    CoordinateType m_eCoordinateType;
    bool m_bFrontOnly;
    bool m_bObserveAppCullFlag;
    NiAVObjectPtr m_spRoot;

    // pick results array
    Results m_pickResults;
    Record* m_pLastAddedRecord;

    // attribute return information
    bool m_bReturnTexture;
    bool m_bReturnNormal;  // true = return normal
    bool m_bReturnSmoothNormal;  // true = return interpolated vertex normals
                                 // false = return facet plane normal
    bool m_bReturnColor;

    void ClearResultsArray ();
};

#include "NiPick.inl"

#endif


