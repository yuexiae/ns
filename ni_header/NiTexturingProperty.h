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

#ifndef NITEXTURINGPROPERTY_H
#define NITEXTURINGPROPERTY_H

#include "NiProperty.h"
#include "NiTArray.h"
#include "NiTexture.h"
#include "NiTextureTransform.h"

NiSmartPointer(NiTexturingProperty);

class NIMAIN_ENTRY NiTexturingProperty : public NiProperty
{
    NiDeclareRTTI;
    NiDeclareClone(NiTexturingProperty);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiTexturingProperty();
    ~NiTexturingProperty();

    // creates a texturing property and attaches a base texture
    // created from the given filename
    NiTexturingProperty(const char* pcTextureName);
    
    // creates a texturing property and attaches a base texture
    // created from the given raw data
    NiTexturingProperty(NiPixelData* pkPixelData);

    enum FilterMode
    {
        FILTER_NEAREST,
        FILTER_BILERP,
        FILTER_TRILERP,
        FILTER_NEAREST_MIPNEAREST,
        FILTER_NEAREST_MIPLERP,
        FILTER_BILERP_MIPNEAREST,
        FILTER_MAX_MODES
    };

    enum ClampMode
    { 
        CLAMP_S_CLAMP_T,
        CLAMP_S_WRAP_T,
        WRAP_S_CLAMP_T,
        WRAP_S_WRAP_T,
        CLAMP_MAX_MODES
    };

    enum ApplyMode
    { 
        // see table below for apply mode equations
        APPLY_REPLACE,
        APPLY_DECAL,
        APPLY_MODULATE,
        // APPLY_HILIGHT & APPLY_HILIGHT2 are PS2 only modes
        // See GS manual for details on the equations used on this platform
        APPLY_HILIGHT,
        APPLY_HILIGHT2,
        APPLY_MAX_MODES
    };

    class NIMAIN_ENTRY Map
    {
    public:
        Map();
        Map(NiTexture* pkTexture, unsigned int uiIndex,
            ClampMode eClampMode = WRAP_S_WRAP_T, 
            FilterMode eFilterMode = FILTER_BILERP,
            NiTextureTransform* pkTextureTransform = NULL);
        Map(const Map& kObj);

        virtual ~Map();

        bool operator==(const Map& kObj) const;
        bool operator!=(const Map& kObj) const;

        // image access functions
        NiTexture* GetTexture() const;
        void SetTexture(NiTexture* pkTexture);

        // clamp mode access functions
        ClampMode GetClampMode() const;
        void SetClampMode(ClampMode eClampMode);

        // filter mode access functions
        FilterMode GetFilterMode() const;
        void SetFilterMode(FilterMode eFilterMode);

        // PS2 ONLY: mip-map LOD selection parameters
        void SetL(short sL);
        short GetL() const;
        void SetK(short sK);
        short GetK() const;

        unsigned int GetTextureIndex() const;
        void SetTextureIndex(unsigned int uiIndex);

        NiTextureTransform* GetTextureTransform();
        const NiTextureTransform* GetTextureTransform() const;
        void SetTextureTransform(NiTextureTransform* pkTrextureTransform);

        // *** begin NDL internal use only ***

        bool IsEqual(Map* pObject);
        virtual void LoadBinary(NiStream& stream);
        virtual void SaveBinary(NiStream& stream);

        // *** end NDL internal use only ***
    protected:
        NiTexturePtr m_spTexture;
        ClampMode m_eClamp;
        FilterMode m_eFilter;
        unsigned int m_uiTexCoord;
        short m_sL;
        short m_sK;
        NiTextureTransform* m_pkTextureTransform;

#ifdef PS2
    public:
        bool GetSmartMip() const;
        void SetSmartMip(bool bSmartMip);
    protected:
        bool m_bSmartMip;
#endif
    };

    class NIMAIN_ENTRY BumpMap : public Map
    {
    public:
        BumpMap();
        BumpMap(NiTexture* pkTexture, unsigned int uiIndex,
            ClampMode eClampMode = WRAP_S_WRAP_T, 
            FilterMode eFilterMode = FILTER_BILERP,
            float fLumaScale = 1.0f, float fLumaOffset = 0.0f,
            float fBumpMat00 = 0.5f, float fBumpMat01 = 0.0f,  
            float fBumpMat10 = 0.0f, float fBumpMat11 = 0.5f);

        float GetLumaScale() const;
        void SetLumaScale(float fVal);
        float GetLumaOffset() const;
        void SetLumaOffset(float fVal);
        float GetBumpMat00() const;
        void SetBumpMat00(float fVal);
        float GetBumpMat01() const;
        void SetBumpMat01(float fVal);
        float GetBumpMat10() const;
        void SetBumpMat10(float fVal);
        float GetBumpMat11() const;
        void SetBumpMat11(float fVal);

        virtual ~BumpMap();

        bool operator==(const BumpMap& kObj) const;
        bool operator!=(const BumpMap& kObj) const;

        // *** begin NDL internal use only ***

        bool IsEqual(BumpMap* pkObject);
        virtual void LoadBinary(NiStream& kStream);
        virtual void SaveBinary(NiStream& kStream);

        // *** end NDL internal use only ***
    protected:
        float m_fLumaScale;
        float m_fLumaOffset;

        float m_fBumpMat00;
        float m_fBumpMat01;
        float m_fBumpMat10;
        float m_fBumpMat11;
    };

    class NIMAIN_ENTRY ShaderMap : public Map
    {
    public:
        ShaderMap();
        ShaderMap(NiTexture* pkTexture, unsigned int uiIndex,
            ClampMode eClampMode = WRAP_S_WRAP_T, 
            FilterMode eFilterMode = FILTER_BILERP,
            unsigned int uiID = 0);

        unsigned int GetID() const;
        void SetID(unsigned int uiID);

        virtual ~ShaderMap();

        bool operator==(const ShaderMap& kObj) const;
        bool operator!=(const ShaderMap& kObj) const;

        // *** begin NDL internal use only ***

        bool IsEqual(ShaderMap* pkObject);
        virtual void LoadBinary(NiStream& kStream);
        virtual void SaveBinary(NiStream& kStream);

        // *** end NDL internal use only ***
    protected:
        unsigned int m_uiID;
    };


    // attach / detach access functions
    const Map* GetBaseMap() const;
    Map* GetBaseMap();
    void SetBaseMap(Map* pkMap);

    const Map* GetDarkMap() const;
    Map* GetDarkMap();
    void SetDarkMap(Map* pkMap);

    const Map* GetDetailMap() const;
    Map* GetDetailMap();
    void SetDetailMap(Map* pkMap);

    const Map* GetGlossMap() const;
    Map* GetGlossMap();
    void SetGlossMap(Map* pkMap);

    const Map* GetGlowMap() const;
    Map* GetGlowMap();
    void SetGlowMap(Map* pkMap);

    const BumpMap* GetBumpMap() const;
    BumpMap* GetBumpMap();
    void SetBumpMap(BumpMap* pkMap);

    const Map* GetDecalMap(unsigned int uiIndex) const;
    Map* GetDecalMap(unsigned int uiIndex);
    void SetDecalMap(unsigned int uiIndex, Map* pkMap);
    unsigned int GetDecalArrayCount() const;
    unsigned int GetDecalMapCount() const;

    const ShaderMap* GetShaderMap(unsigned int uiIndex) const;
    ShaderMap* GetShaderMap(unsigned int uiIndex);
    void SetShaderMap(unsigned int uiIndex, ShaderMap* pkMap);
    unsigned int GetShaderArrayCount() const;
    unsigned int GetShaderMapCount() const;

    // apply modes
    ApplyMode GetApplyMode() const;
    void SetApplyMode(ApplyMode eApplymode);

    bool IsEqualFast(const NiTexturingProperty& kProp) const;

    virtual int Type() const;
    static int GetType();
    static NiTexturingProperty* GetDefault();

    bool IsMultiTexture() const; 

    // Easy access to base map
    NiTexture* GetBaseTexture() const;
    void SetBaseTexture(NiTexture* pkTexture);
    ClampMode GetBaseClampMode() const;
    void SetBaseClampMode(ClampMode eMode);
    FilterMode GetBaseFilterMode() const;
    void SetBaseFilterMode(FilterMode eMode);
    short GetBaseL() const;   
    void SetBaseL(short sL);   
    short GetBaseK() const;   
    void SetBaseK(short sK);   
    unsigned int GetBaseTextureIndex() const;
    void SetBaseTextureIndex(unsigned int uiIndex);
    NiTextureTransform* GetBaseTextureTransform() const;
    void SetBaseTextureTransform(NiTextureTransform* pkTransform);

    // *** begin NDL internal use only ***

    const NiTArray<Map*>& GetMaps() const;
    void SetMap(unsigned int uiIndex, Map* pkMap);
    static void _SDMInit();
    static void _SDMShutdown();

    // streaming support
    static char* GetViewerString(const char* pcPrefix, ClampMode eMode);
    static char* GetViewerString(const char* pcPrefix, FilterMode eMode);
    static char* GetViewerString(const char* pcPrefix, ApplyMode eMode);

    enum 
    {
        BASE_INDEX,
        DARK_INDEX,
        DETAIL_INDEX,
        GLOSS_INDEX,
        GLOW_INDEX,
        BUMP_INDEX,
        DECAL_BASE
    };

    // *** end NDL internal use only ***

protected:
    void SetMultiTexture(Map* pkMap);

    ApplyMode m_eApply;
    bool m_bMultiTexture;

    NiTArray<Map*> m_kMaps;
    unsigned int m_uiDecals;

    NiTArray<ShaderMap*>* m_pkShaderMaps;

    static NiTexturingPropertyPtr ms_spDefault;
};

NiSmartPointer(NiTexturingProperty);

#include "NiTexturingProperty.inl"

#endif // NITEXTURINGPROPERTY_H

