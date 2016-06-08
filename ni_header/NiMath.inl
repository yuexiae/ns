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

//---------------------------------------------------------------------------
inline float NiAbs (float fValue)
{
    return float(fabs(fValue));
}
//---------------------------------------------------------------------------
inline float NiACos (float fValue)
{
    if ( -1.0f < fValue )
    {
        if ( fValue < 1.0f )
            return float(acos(fValue));
        else
            return 0.0f;
    }
    else
    {
        return NI_PI;
    }
}
//---------------------------------------------------------------------------
inline float NiASin (float fValue)
{
    if ( -1.0f < fValue )
    {
        if ( fValue < 1.0f )
            return float(asin(fValue));
        else
            return NI_HALF_PI;
    }
    else
    {
        return -NI_HALF_PI;
    }
}
//---------------------------------------------------------------------------
inline float NiATan (float fValue)
{
    return float(atan(fValue));
}
//---------------------------------------------------------------------------
inline float NiATan2 (float fY, float fX)
{
    return float(atan2(fY,fX));
}
//---------------------------------------------------------------------------
inline float NiCos (float fRadians)
{
    return float(cos(fRadians));
}
//---------------------------------------------------------------------------
inline float NiExp (float fValue)
{
    return float(exp(fValue));
}
//---------------------------------------------------------------------------
inline float NiFmod (float fX, float fY)
{
    return float(fmod(fX,fY));
}
//---------------------------------------------------------------------------
inline float NiLog (float fValue)
{
    return float(log(fValue));
}
//---------------------------------------------------------------------------
inline float NiPow (float fBase, float fExponent)
{
    return float(pow(fBase,fExponent));
}
//---------------------------------------------------------------------------
inline float NiSign (float fValue)
{
    return ( fValue > 0.0f ? +1.0f : ( fValue < 0.0f ? -1.0f : 0.0f ) );
}
//---------------------------------------------------------------------------
inline float NiSin (float fRadians)
{
    return float(sin(fRadians));
}
//---------------------------------------------------------------------------
inline void NiSinCos (float fRadians, float& fSin, float& fCos)
{
    float s, c;
    __asm fld fRadians
    __asm fsincos
    __asm fstp c
    __asm fstp s

    fSin = s;
    fCos = c;
}
//---------------------------------------------------------------------------
inline float NiSqr (float fValue)
{
    return fValue*fValue;
}
//---------------------------------------------------------------------------
inline float NiSqrt (float fValue)
{
    return float(sqrt(fValue));
}
//---------------------------------------------------------------------------
inline float NiMin(float fA, float fB)
{
    return (fA < fB) ? fA : fB;
}
//---------------------------------------------------------------------------
inline float NiMax(float fA, float fB)
{
    return (fA > fB) ? fA : fB;
}
//---------------------------------------------------------------------------
inline int NiMin(int iA, int iB)
{
    return (iA < iB) ? iA : iB;
}
//---------------------------------------------------------------------------
inline int NiMax(int iA, int iB)
{
    return (iA > iB) ? iA : iB;
}
//---------------------------------------------------------------------------
inline bool NiIsPowerOf2(unsigned int uiI)
{
    if (!uiI)
        return false;

    return (uiI & (uiI - 1)) == 0;
}
//---------------------------------------------------------------------------
inline void NiSrand (unsigned int uiSeed)
{
    srand(uiSeed);
}
//---------------------------------------------------------------------------
inline int NiRand ()
{
    return rand();
}
//---------------------------------------------------------------------------
inline float NiUnitRandom ()
{
    return float(NiRand())/float(RAND_MAX);
}
//---------------------------------------------------------------------------
inline float NiSymmetricRandom ()
{
    return -1.0f + 2.0f*float(NiRand())/float(RAND_MAX);
}
//---------------------------------------------------------------------------
inline unsigned int NiFastLog (unsigned int uiNum)
{
    unsigned int uiLog = 0;
    unsigned int uiTemp = uiNum >> 1;
    while ( uiTemp & 0xffffffff )
    {
        uiTemp >>= 1;
        uiLog++;
    }

    return uiLog;
}
//---------------------------------------------------------------------------
