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
inline void NiSleep(unsigned int uiMilliseconds)
{
    Sleep(uiMilliseconds);
}
//---------------------------------------------------------------------------
#ifndef NDEBUG
inline void NiWriteToStdErr(char* pText)
{
    fputs(pText, stderr);
}
//---------------------------------------------------------------------------
#ifndef REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG
inline void NiOutputDebugString(const char* pcOut)
{
    OutputDebugStringA(pcOut);
}
#endif // #ifndef REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG
#endif
//---------------------------------------------------------------------------
