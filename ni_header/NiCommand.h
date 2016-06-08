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

#ifndef NICOMMAND_H
#define NICOMMAND_H

class NiCommand
{
public:
    NiCommand(int iArgc, char** ppcArgv);
    NiCommand(char* pcCmdline);
    ~NiCommand();
    int ExcessArguments();  // return values is index of first excess argument

    // set bounds for numerical arguments
    // if bounds required, they must be set for each argument
    NiCommand& Min(float fValue);
    NiCommand& Max(float fValue);
    NiCommand& Inf(float fValue);
    NiCommand& Sup(float fValue);

    // return value of the following methods is the option index within the
    // argument array

    // Use the boolean methods for options which take no argument, for
    // example in
    //           myprogram -debug -x 10 -y 20 filename
    // the option -debug has no argument.

    int Boolean(char* pcName);  // returns existence of option
    int Boolean(char* pcName, bool& bValue);
    int Integer(char* pcName, int& iValue);
    int Float(char* pcName, float& fValue);
    int String(char* pcName, char* pcValue);
    int Filename(char* pcName);

    // last error reporting
    const char* GetLastError() { return m_pcLastError; }

protected:
    // constructor support
    void Initialize();

    // command line information
    int m_iArgc;       // number of arguments
    char** m_ppcArgv;    // argument list(array of strings)
    char* m_pcCmdline;  // argument list(single string)
    bool* m_pbUsed;  // keeps track of arguments already processed

    // parameters for bounds checking
    float m_fSmall;   // lower bound for numerical argument(min or inf)
    float m_fLarge;   // upper bound for numerical argument(max or sup)
    bool m_bMinSet;    // if true, compare:  small <= arg
    bool m_bMaxSet;    // if true, compare:  arg <= large
    bool m_bInfSet;    // if true, compare:  small < arg
    bool m_bSupSet;    // if true, compare:  arg < large

    // last error strings
    char* m_pcLastError;
    static char ms_acOptionNotFound[];
    static char ms_acArgumentRequired[];
    static char ms_acArgumentOutOfRange[];
    static char ms_acFilenameNotFound[];
};

#endif

