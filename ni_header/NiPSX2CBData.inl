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
//  NiPSX2CBData Inline Functions
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline NiPSX2CBData::NiPSX2CBData( )
{
    m_iProtocol = 0;
    m_iType = 0;
    m_iCode = 0;
    m_iResult = 0;
    m_iError = 0;
    m_ulData = 0;
    m_iDataSize = 0;
    m_pvData = 0;
}
//---------------------------------------------------------------------------
inline NiPSX2CBData::NiPSX2CBData( int iProtocol, int iType, 
           int iCode, int iResult, int iError, unsigned long ulData, 
           int iDataSize,void* pvData )
{
    m_iProtocol = iProtocol;
    m_iType = iType;
    m_iCode = iCode;
    m_iResult = iResult;
    m_iError = iError;
    m_ulData = ulData;
    m_iDataSize = iDataSize;
    m_pvData = pvData;
}
//---------------------------------------------------------------------------
inline void NiPSX2CBData::Empty( )
{
    m_iProtocol = 0;
    m_iType = 0;
    m_iCode = 0;
    m_iResult = 0;
    m_iError = 0;
    m_ulData = 0;
    m_iDataSize = 0;
    m_pvData = 0;
}

//---------------------------------------------------------------------------
inline NiPSX2ReadBackData::NiPSX2ReadBackData( )
{
    strcpy( m_szMtrlName, "" );
    m_Base.SetL( 0 );
    m_Base.SetK( 0 );
    m_Dark.SetL( 0 );
    m_Dark.SetK( 0 );
    m_Detail.SetL( 0 );
    m_Detail.SetK( 0 );
    m_Gloss.SetL( 0 );
    m_Gloss.SetK( 0 );
    m_Glow.SetL( 0 );
    m_Glow.SetK( 0 );
    m_Decal[0].SetL( 0 );
    m_Decal[0].SetK( 0 );
    m_Decal[1].SetL( 0 );
    m_Decal[1].SetK( 0 );
    m_Decal[2].SetL( 0 );
    m_Decal[2].SetK( 0 );
    m_usDecalCount = 0;
}
//---------------------------------------------------------------------------
inline char* NiPSX2ReadBackData::GetMaterialName( )
{   
    return m_szMtrlName;    
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetBaseLnK()   
{   
    return &m_Base;
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetBaseL( )
{   
    return m_Base.GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetBaseK( )
{   
    return m_Base.GetK( );
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetDarkLnK()   
{   
    return &m_Dark;         
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDarkL( )
{   
    return m_Dark.GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDarkK( )
{   
    return m_Dark.GetK( );
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetDetailLnK() 
{   
    return &m_Detail;       
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDetailL( )
{   
    return m_Detail.GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDetailK( )
{   
    return m_Detail.GetK( );
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetGlossLnK()  
{   
    return &m_Gloss;        
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetGlossL( )
{   
    return m_Gloss.GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetGlossK( )
{   
    return m_Gloss.GetK( );
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetGlowLnK()   
{   
    return &m_Glow;         
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetGlowL( )
{   
    return m_Glow.GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetGlowK( )
{   
    return m_Glow.GetK( );
}
//---------------------------------------------------------------------------
inline NiPSX2LnKValues* NiPSX2ReadBackData::GetDecalLnK( unsigned int uiIndex )  
{   
    return &(m_Decal[uiIndex]);
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDecalL( unsigned int uiIndex )
{   
    return m_Decal[uiIndex].GetL( );
}
//---------------------------------------------------------------------------
inline short NiPSX2ReadBackData::GetDecalK( unsigned int uiIndex )
{   
    return m_Decal[uiIndex].GetK( );
}
//---------------------------------------------------------------------------
inline unsigned short NiPSX2ReadBackData::GetDecalCount()  
{   
    return m_usDecalCount;  
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetMaterialName( char* pszName )
{
    if ( pszName )
        strncpy( m_szMtrlName, pszName, 128 );
    else
        strcpy( m_szMtrlName, "" );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetBaseLnK( short sL, short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetDarkLnK( short sL, short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetDetailLnK( short sL, short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetGlossLnK( short sL, short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetGlowLnK( short sL, short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetDecalLnK( unsigned int uiIndex, short sL, 
                short sK )
{
    m_Base.SetL( sL );
    m_Base.SetK( sK );
}
//---------------------------------------------------------------------------
inline void NiPSX2ReadBackData::SetDecalCount( unsigned short usCount )
{
    m_usDecalCount = usCount;
}
//---------------------------------------------------------------------------

