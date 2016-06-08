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

#ifndef NIPARTICLESDATA_H
#define NIPARTICLESDATA_H

#include "NiGeometryData.h"
#include "NiQuaternion.h"

class NIMAIN_ENTRY NiParticlesData : public NiGeometryData
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiParticlesData(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiQuaternion* pkRots);

    NiParticlesData();

    virtual ~NiParticlesData();

    // particle attributes
    float* GetRadii();
    const float* GetRadii() const;
    float* GetSizes();
    const float* GetSizes() const;
    NiQuaternion* GetRotations();
    const NiQuaternion* GetRotations() const;

    virtual void SetActiveVertexCount(unsigned short usActive);
    virtual unsigned short GetActiveVertexCount() const;

    // reallocation support
    void ReplaceRadii(float* pfRadii);
    void ReplaceSizes(float* pfSizes);
    void ReplaceRotations(NiQuaternion* pkRotations);

    virtual void RemoveParticle(unsigned short usParticle);

    // *** begin NDL internal use only ***

    // For temporarily using data only.  This call is like Replace(), 
    // but does not delete any pointers.  Be careful to call this only 
    // on objects created by the default (empty) constructor to prevent 
    // memory leaks.  These pointers will be owned (and deleted upon 
    // destruction) by this object so use this call carefully.
    void SetRadiiData(float* pfRadii);
    void SetSizesData(float* pfSizes);
    void SetRotationsData(NiQuaternion* pkRotations);

    // updates
    virtual void CalculateNormals();

#ifndef T3D_NO_NIF_CONVERSION
    // We now create an NiParticlesData object when in the old system, we
    // would have created an NiRotatingParticlesData object
    // Because the NiRotatingParticlesData added an optional array of 
    // rotations, we need to flag the new NiParticlesData object inside a
    // new creation function, so that inside of NiParticlesData::LoadBinary,
    // we can look for the optional array of quaternions.
    static NiObject* CreateOldRotatingParticlesObject();
    bool m_bIsOldRotatingParticlesObject;
#endif

    // *** end NDL internal use only ***

protected:
    float* m_pfRadii;
    unsigned short m_usActive;
    float* m_pfSizes;
    NiQuaternion* m_pkRotations;
};

typedef NiPointer<NiParticlesData> NiParticlesDataPtr;

#include "NiParticlesData.inl"

#endif // NIPARTICLESDATA_H
