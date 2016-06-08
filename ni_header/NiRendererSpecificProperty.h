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

#ifndef NIRENDERERSPECIFICPROPERTY_H
#define NIRENDERERSPECIFICPROPERTY_H

#include "NiProperty.h"

NiSmartPointer(NiRendererSpecificProperty);

class NIMAIN_ENTRY NiRendererSpecificProperty : public NiProperty
{
    NiDeclareRTTI;
    NiDeclareClone(NiRendererSpecificProperty);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiRendererSpecificProperty();
    ~NiRendererSpecificProperty();

    class NIMAIN_ENTRY RendererData
    {
    public:
        virtual ~RendererData();
        virtual unsigned int GetRendererTypeID() const = 0;

        virtual RendererData* CreateClone(
            NiCloningProcess& kCloning) const = 0;
    protected:
    };

    // Currently, only one renderer data object per property at a time
    // This is equivalent to saying that there can be only one type of
    // renderer at a time
    const RendererData* GetRendererData(unsigned int uiRendererTypeID) const;
    RendererData* GetRendererData(unsigned int uiRendererTypeID);

    // Do not share the data passed into this - the property "owns" this
    // data and will delete it if a new data item is set
    void SetRendererData(RendererData* pkData);

    bool IsEqualFast(const NiRendererSpecificProperty& kProp) const;

    virtual int Type () const;
    static int GetType ();
    static NiRendererSpecificProperty *GetDefault ();

    // *** begin NDL internal use only ***

    static void _SDMInit();
    static void _SDMShutdown();

    // *** end NDL internal use only ***

protected:
    RendererData* m_pkRendererData;

    static NiRendererSpecificPropertyPtr ms_spDefault;
};

typedef NiPointer<NiRendererSpecificProperty> NiRendererSpecificPropertyPtr;

#include "NiRendererSpecificProperty.inl"

#endif

