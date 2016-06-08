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
//  NiColor inline functions

//---------------------------------------------------------------------------
inline NiColor::NiColor (float fR, float fG, float fB)
{
    r = fR;
    g = fG;
    b = fB;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator= (float fScalar)
{
    r = fScalar;
    g = fScalar;
    b = fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline bool NiColor::operator== (const NiColor& c) const
{
    return (r == c.r && g == c.g && b == c.b);
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator+ (const NiColor& c) const
{
    NiColor result = *this;
    result.r += c.r;
    result.g += c.g;
    result.b += c.b;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator- (const NiColor& c) const
{
    NiColor result = *this;
    result.r -= c.r;
    result.g -= c.g;
    result.b -= c.b;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator* (float fScalar) const
{
    NiColor result = *this;
    result.r *= fScalar;
    result.g *= fScalar;
    result.b *= fScalar;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator* (const NiColor &c) const
{
    NiColor result = *this;
    result.r *= c.r;
    result.g *= c.g;
    result.b *= c.b;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator/ (float fScalar) const
{
    NiColor result = *this;
    result.r /= fScalar;
    result.g /= fScalar;
    result.b /= fScalar;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator/ (const NiColor &c) const
{
    NiColor result = *this;
    result.r /= c.r;
    result.g /= c.g;
    result.b /= c.b;
    return result;
}
//---------------------------------------------------------------------------
inline NiColor NiColor::operator- () const
{
    return NiColor(-r,-g,-b);
}
//---------------------------------------------------------------------------
inline NiColor operator* (float fScalar, const NiColor& c)
{
    return c*fScalar;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator+= (const NiColor& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator-= (const NiColor& c)
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator*= (float fScalar)
{
    r *= fScalar;
    g *= fScalar;
    b *= fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator*= (const NiColor &c)
{
    r *= c.r;
    g *= c.g;
    b *= c.b;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator/= (float fScalar)
{
    r /= fScalar;
    g /= fScalar;
    b /= fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColor& NiColor::operator/= (const NiColor &c)
{
    r /= c.r;
    g /= c.g;
    b /= c.b;
    return *this;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline NiColorA::NiColorA (float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator= (float fScalar)
{
    r = fScalar;
    g = fScalar;
    b = fScalar;
    a = fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline bool NiColorA::operator== (const NiColorA& c) const
{
    return (r == c.r && g == c.g && b == c.b && a == c.a);
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator+ (const NiColorA& c) const
{
    NiColorA result = *this;
    result.r += c.r;
    result.g += c.g;
    result.b += c.b;
    result.a += c.a;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator- (const NiColorA& c) const
{
    NiColorA result = *this;
    result.r -= c.r;
    result.g -= c.g;
    result.b -= c.b;
    result.a -= c.a;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator* (float fScalar) const
{
    NiColorA result = *this;
    result.r *= fScalar;
    result.g *= fScalar;
    result.b *= fScalar;
    result.a *= fScalar;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator* (const NiColorA &c) const
{
    NiColorA result = *this;
    result.r *= c.r;
    result.g *= c.g;
    result.b *= c.b;
    result.a *= c.a;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator/ (float fScalar) const
{
    NiColorA result = *this;
    result.r /= fScalar;
    result.g /= fScalar;
    result.b /= fScalar;
    result.a /= fScalar;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator/ (const NiColorA &c) const
{
    NiColorA result = *this;
    result.r /= c.r;
    result.g /= c.g;
    result.b /= c.b;
    result.a /= c.a;
    return result;
}
//---------------------------------------------------------------------------
inline NiColorA NiColorA::operator- () const
{
    return NiColorA(-r,-g,-b,-a);
}
//---------------------------------------------------------------------------
inline NiColorA operator* (float fScalar, const NiColorA& c)
{
    return c*fScalar;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator+= (const NiColorA& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    a += c.a;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator-= (const NiColorA& c)
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    a -= c.a;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator*= (float fScalar)
{
    r *= fScalar;
    g *= fScalar;
    b *= fScalar;
    a *= fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator*= (const NiColorA &c)
{
    r *= c.r;
    g *= c.g;
    b *= c.b;
    a *= c.a;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator/= (float fScalar)
{
    r /= fScalar;
    g /= fScalar;
    b /= fScalar;
    a /= fScalar;
    return *this;
}
//---------------------------------------------------------------------------
inline NiColorA& NiColorA::operator/= (const NiColorA &c)
{
    r /= c.r;
    g /= c.g;
    b /= c.b;
    a /= c.a;
    return *this;
}
//---------------------------------------------------------------------------
