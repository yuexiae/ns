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

#ifndef NISYSTEMTIMELOCK_H
#define NISYSTEMTIMELOCK_H

void ReadNDLDevLock(char* pResult);
void NormalizeExpireTime(unsigned long& ulTime);
void DialogBoxExit(const char* pText, const char* pCaption);
bool CheckForTimeReset(unsigned int uiDecExpire);

#endif // NISYSTEMTIMELOCK_H
