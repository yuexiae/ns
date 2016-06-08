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

#ifndef NIBLENDINTERPOLATOR_H
#define NIBLENDINTERPOLATOR_H

#include <NiInterpolator.h>
#include <NiTArray.h>

class NIANIMATION_ENTRY NiBlendInterpolator : public NiInterpolator
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiBlendInterpolator);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

    NiDeclareFlags(unsigned char);
public:
    virtual ~NiBlendInterpolator();

    static const unsigned char INVALID_INDEX;
    static const float INVALID_TIME;

    unsigned char GetArraySize() const;
    static unsigned char GetArrayGrowBy();
    static void SetArrayGrowBy(unsigned char ucArrayGrowBy);

    NiInterpolator* GetInterpolator(unsigned char ucIndex = 0) const;
    void SetInterpolator(NiInterpolator* pkInterpolator,
        unsigned char ucIndex = 0);

    float GetWeight(unsigned char ucIndex = 0) const;
    void SetWeight(float fWeight, unsigned char ucIndex = 0);

    char GetPriority(unsigned char ucIndex = 0) const;
    void SetPriority(char cPriority, unsigned char ucIndex = 0);

    float GetEaseSpinner(unsigned char ucIndex = 0) const;
    void SetEaseSpinner(float fEaseSpinner, unsigned char ucIndex = 0);

    float GetTime(unsigned char ucIndex = 0) const;
    void SetTime(float fTime, unsigned char ucIndex = 0);

    bool GetOnlyUseHighestWeight() const;
    void SetOnlyUseHighestWeight(bool bOnlyUseHighestWeight);

    virtual unsigned char AddInterpInfo(NiInterpolator* pkInterpolator,
        float fWeight, char cPriority = 0, float fEaseSpinner = 1.0f);
    virtual NiInterpolatorPtr RemoveInterpInfo(unsigned char ucIndex);

    float GetWeightThreshold() const;
    void SetWeightThreshold(float fWeightThreshold);

    // For use in reducing the memory footprint of an interpolator 
    virtual void Collapse();

    // *** begin NDL internal use only ***
    bool GetManagerControlled() const;
    void SetManagerControlled(bool bManagerControlled);
    void ComputeNormalizedWeights();
    float GetNormalizedWeight(unsigned char ucIndex = 0) const;
    unsigned char GetHighestWeightedIndex() const;
    virtual void ProcessClone(NiCloningProcess& kCloning);
    virtual void GuaranteeTimeRange(float fStartTime, 
        float fEndTime);
    // *** end NDL internal use only ***

protected:
    NiBlendInterpolator(bool bManagerControlled, float fWeightThreshold,
        unsigned char ucArraySize);

    // For cloning and streaming only.
    NiBlendInterpolator();

    // Virtual function overrides from base class.
    
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const = 0;

    virtual bool ReallocateArrays();
    
    void ComputeNormalizedWeightsFor2();
    void ClearWeightSums();

    struct InterpArrayItem
    {
        InterpArrayItem();

        void ClearValues();

        void LoadBinary(NiStream& kStream);
        void SaveBinary(NiStream& kStream);
        void RegisterStreamables(NiStream& kStream);
        bool IsEqual(InterpArrayItem& kDest);

        NiInterpolatorPtr m_spInterpolator;
        float m_fWeight;
        float m_fNormalizedWeight;
        char m_cPriority;
        float m_fEaseSpinner;
        float m_fUpdateTime;
    };

    // flags
    enum
    {
        MANAGER_CONTROLLED_MASK         = 0X0001,
        ONLY_USE_HIGHEST_WEIGHT_MASK    = 0X0002,
        COMPUTE_NORMALIZED_WEIGHTS_MASK = 0x0004
    };

    bool GetComputeNormalizedWeights() const;
    void SetComputeNormalizedWeights(bool bComputeNormalizedWeights);

    bool GetSingleUpdateTime(float& fTime);
    bool GetUpdateTimeForItem(float& fTime, InterpArrayItem& kItem);

    static unsigned char ms_ucArrayGrowBy;

    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;

    InterpArrayItem* m_pkInterpArray;
    NiInterpolator* m_pkSingleInterpolator;

    float m_fWeightThreshold;
    float m_fSingleTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fHighEaseSpinner;
};

NiSmartPointer(NiBlendInterpolator);

#include "NiBlendInterpolator.inl"

#endif  // #ifndef NIBLENDINTERPOLATOR_H
