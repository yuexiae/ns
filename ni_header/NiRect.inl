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
//  NiRect inline functions

//---------------------------------------------------------------------------
template <class T>
inline void NiRect<T>::LoadBinary (NiStream& stream)
{
    NiStreamLoadBinary(stream,m_left);
    NiStreamLoadBinary(stream,m_right);
    NiStreamLoadBinary(stream,m_top);
    NiStreamLoadBinary(stream,m_bottom);
}
//---------------------------------------------------------------------------
template <class T>
inline void NiRect<T>::SaveBinary (NiStream& stream)
{
    NiStreamSaveBinary(stream,m_left);
    NiStreamSaveBinary(stream,m_right);
    NiStreamSaveBinary(stream,m_top);
    NiStreamSaveBinary(stream,m_bottom);
}
//---------------------------------------------------------------------------
template <class T>
inline char* NiRect<T>::GetViewerString (const char* pPrefix) const
{
    char* pString = new char[strlen(pPrefix)+64];

    sprintf(pString,"%s = (L=%g,R=%g,T=%g,B=%g)",pPrefix, (float)m_left,
        (float)m_right, (float)m_top, (float)m_bottom);

    return pString;
}
//---------------------------------------------------------------------------
