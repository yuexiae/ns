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

#ifndef NISCREENGEOMETRYDATA_H
#define NISCREENGEOMETRYDATA_H

#include "NiTriShapeData.h"

#include "NiTPool.h"
#include "NiTArray.h"

class NIMAIN_ENTRY NiScreenGeometryData : public NiTriShapeData
{
public:
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // ScreenElement subclass
    class NIMAIN_ENTRY ScreenElement
    {
    public:
        void SetScreenElement(unsigned int uiNumVerts, short* psHorz, 
            short* psVert, NiColorA* pkColor, NiPoint2* pkTexture, 
            unsigned short usNumTextureSets);
        void SetScreenElement(unsigned int uiNumVerts, NiPoint2* pkVertex,
            NiColorA* pkColor, NiPoint2* pkTexture, 
            unsigned short usNumTextureSets);

        void SetScreenElementRect(float fLeft, float fTop, float fWidth, 
            float fHeight, NiColorA* pkColor, NiPoint2* pkTexture, 
            unsigned short usNumTextureSets);

        unsigned short GetVertexCount() const;
        const NiPoint2* GetVertices() const;
        const NiPoint2* GetVertex(unsigned int uiIndex) const;
        void SetVertex(unsigned int uiIndex, const NiPoint2& kVertex);

        const NiColorA* GetColors() const;
        const NiColorA* GetColor(unsigned int uiIndex) const;
        void SetColor(unsigned int uiIndex, const NiColorA& kColor);

        unsigned short GetTextureSets() const;
        const NiPoint2* GetTextures() const;
        const NiPoint2* GetTextureSet(unsigned short usSet) const;
        void AppendTextureSet(NiPoint2* pkSet);

        const NiPoint2* GetTextureCoord(unsigned short usSet, 
            unsigned int uiIndex) const;
        void SetTextureCoord(unsigned short usSet, unsigned int uiIndex, 
            const NiPoint2& kTexCoord);

    protected:
        ScreenElement();
        virtual ~ScreenElement();

        unsigned short m_usNumVerts;
        unsigned short m_usNumTexCoordSets;

        NiPoint2* m_pkVerts;
        NiColorA* m_pkColors;
        NiPoint2* m_pkTexCoords;

        friend class NiTPoolContainer<ScreenElement>;
    };    
    
    NiScreenGeometryData();

    virtual ~NiScreenGeometryData();
    virtual unsigned short GetActiveVertexCount() const;

    unsigned int AddScreenElement(unsigned int uiNumVerts, NiPoint2* pkVertex,
        NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);
    unsigned int AddScreenElement(unsigned int uiNumVerts, short* psHorz, 
        short* psVert, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);

    unsigned int AddScreenElementRect(float fLeft, float fTop, float fWidth, 
        float fHeight, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);

    unsigned int GetNumScreenElements() const;
    unsigned int GetScreenElementArraySize() const;
    ScreenElement* GetScreenElement(unsigned int uiIndex) const;
    void SetScreenElement(unsigned int uiIndex, ScreenElement* pkElement);
    bool RemoveScreenElement(unsigned int uiIndex);
    void RemoveAllScreenElements();

    bool GetPixelAccurate() const;
    void SetPixelAccurate(bool bAccurate);

    bool GetUnorderedElements() const;
    void SetUnorderedElements(bool bUnordered);

    void UpdateGeometryData();

    // *** begin NDL internal use only ***

    static void _SDMInit();
    static void _SDMShutdown();

    // updates
    virtual void CalculateNormals();

    // *** end NDL internal use only ***

protected:
    bool m_bPixelAccurate;
    bool m_bUnorderedElements;
    unsigned int m_usActiveVerts;

    NiTArray<ScreenElement*> m_kScreenElements;

    static NiTPool<ScreenElement>* ms_pkScreenElementPool;
};

NiSmartPointer(NiScreenGeometryData);

#include "NiScreenGeometryData.inl"

#endif //NISCREENGEOMETRYDATA_H
