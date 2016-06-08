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

#ifndef NIOPTTRISHAPE_H
#define NIOPTTRISHAPE_H

#include <NiTriShape.h>
#include "NiOptGeometry.h"

class NIOPTIMIZATION_ENTRY NiOptTriShape : public NiOptGeometry
{
public:
    NiOptTriShape(unsigned int uiVertices, NiOptVertex* pkVertex,
        unsigned int uiNumBones, void** ppvBones,
        void *pvRootParent, NiTransform* pkInitXforms,
        NiTransform &kRootParentToSkin, unsigned int uiTriListLength,
        unsigned int* puiTriList, bool bAllowLargeTriList, bool bMakeTwoSided);

    ~NiOptTriShape();

    void ConvertTo(NiTriShape*& pkShape);

protected:
    // vertex reduction
    virtual void RemoveDegenerateVertices();

    // triangle reduction
    void RemoveDegenerateTriangles();

    // Gamebryo object construction
    void CreateNiTriShape(NiTriShape*& pkShape);
    void IdentifySharedNormals(NiTriShape* pkShape);

    // for two sided materials
    void MakeTwoSided();

    unsigned int m_uiTriListLength;
    unsigned int* m_puiTriList;
    bool m_bAllowLargeTriList;
};

#endif  // #ifndef NIOPTTRISHAPE_H
