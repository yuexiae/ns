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
#ifndef NIPSX2CBDATA_H
#define NIPSX2CBDATA_H

#include "NiStandardSharedDataLibType.h"

//---------------------------------------------------------------------------
class NISTANDARDSHAREDDATA_ENTRY NiPSX2CBData
{
    //  PUBLIC for simple, quick access.
public:
    int m_iProtocol;
    int m_iType;
    int m_iCode;
    int m_iResult;
    int m_iError;
    unsigned long m_ulData;
    int m_iDataSize;
    void* m_pvData;

    inline NiPSX2CBData( );
    inline NiPSX2CBData( int iProtocol, int iType, int iCode, 
               int iResult, int iError, unsigned long ulData, 
               int iDataSize, void* pvData );
    inline void Empty( );
};

//---------------------------------------------------------------------------
//  LnK Adjustment Classe
//  THIS MUST CORRESPOND TO WHAT THE PSX2MaxViewer EXPECTS
//  IT WILL BE IN Samples\PSX2MaxViewer\PSX2MaxViewer.cpp file
//  Using a shared header file would be a bit of a pain right now.
class NISTANDARDSHAREDDATA_ENTRY NiPSX2LnKValues
{
    //  PUBLIC for simple, quick access.
public:
    short m_sL;
    short m_sK;

    NiPSX2LnKValues( )
    {
        m_sL = 0;
        m_sK = 0;
    };
    NiPSX2LnKValues( short sL, short sK )
    {
        m_sL = sL;
        m_sK = sK;
    };

    short GetL( )           {   return m_sL;    };
    short GetK( )           {   return m_sK;    };
    void SetL( short sVal ) {   m_sL = sVal;    };
    void SetK( short sVal ) {   m_sK = sVal;    };
};
        
class NISTANDARDSHAREDDATA_ENTRY NiPSX2ReadBackData
{
    //  PUBLIC for simple, quick access.
public:
    char m_szMtrlName[128];
    NiPSX2LnKValues m_Base;
    NiPSX2LnKValues m_Dark;
    NiPSX2LnKValues m_Detail;
    NiPSX2LnKValues m_Gloss;
    NiPSX2LnKValues m_Glow;
    NiPSX2LnKValues m_Decal[3];
    unsigned short m_usDecalCount;

    NiPSX2ReadBackData( );

    inline char* GetMaterialName( );
    inline NiPSX2LnKValues* GetBaseLnK( );
    inline short GetBaseL( );
    inline short GetBaseK( );
    inline NiPSX2LnKValues* GetDarkLnK( );
    inline short GetDarkL( );
    inline short GetDarkK( );
    inline NiPSX2LnKValues* GetDetailLnK( );
    inline short GetDetailL( );
    inline short GetDetailK( );
    inline NiPSX2LnKValues* GetGlossLnK( );
    inline short GetGlossL( );
    inline short GetGlossK( );
    inline NiPSX2LnKValues* GetGlowLnK( );
    inline short GetGlowL( );
    inline short GetGlowK( );
    inline NiPSX2LnKValues* GetDecalLnK( unsigned int uiIndex );
    inline short GetDecalL( unsigned int uiIndex );
    inline short GetDecalK( unsigned int uiIndex );
    inline unsigned short GetDecalCount( );

    inline void SetMaterialName( char* pszName );
    inline void SetBaseLnK( short sL, short sK );
    inline void SetDarkLnK( short sL, short sK );
    inline void SetDetailLnK( short sL, short sK );
    inline void SetGlossLnK( short sL, short sK );
    inline void SetGlowLnK( short sL, short sK );
    inline void SetDecalLnK( unsigned int uiIndex, short sL, short sK );
    inline void SetDecalCount( unsigned short usCount );
};

//---------------------------------------------------------------------------
#include "NiPSX2CBData.inl"

//---------------------------------------------------------------------------
#endif  //#ifndef NIPSX2CBDATA_H