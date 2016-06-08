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

#ifndef NIMATH_H
#define NIMATH_H

#include "NiMainLibType.h"
#include "NiRTLib.h"

NIMAIN_ENTRY extern const float NI_INFINITY;
NIMAIN_ENTRY extern const float NI_PI;
NIMAIN_ENTRY extern const float NI_HALF_PI;
NIMAIN_ENTRY extern const float NI_TWO_PI;

// 'float' wrappers for standard math functions
float NiAbs(float fValue);
float NiACos(float fValue);
float NiASin(float fValue);
float NiATan(float fValue);
float NiATan2(float fY, float fX);
float NiCos(float fRadians);
float NiExp(float fValue);
float NiFmod(float fX, float fY);
float NiLog(float fValue);
float NiPow(float fBase, float fExponent);
float NiSign(float fValue);
float NiSin(float fRadians);
void NiSinCos(float fRadians, float& fSin, float& fCos);
float NiSqr(float fValue);
float NiSqrt(float fValue);

//
float NiMin(float fA, float fB);
float NiMax(float fA, float fB);
int NiMin(int iA, int iB);
int NiMax(int iA, int iB);

// utility function
bool NiIsPowerOf2(unsigned int uiI);

// random number generation
void NiSrand(unsigned int uiSeed);
int NiRand();  // r in [0,RAND_MAX]
float NiSymmetricRandom();  // r in [-1,1]
float NiUnitRandom();  // r in [0,1]

// fast functions
unsigned int NiFastLog(unsigned int uiNum);
NIMAIN_ENTRY float NiFastATan2(float fY, float fX);
NIMAIN_ENTRY float NiCapelliATan2(float fY, float fX);

#include "NiMath.inl"

#endif // NIMATH_H
