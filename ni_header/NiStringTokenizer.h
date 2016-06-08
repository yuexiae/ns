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

#ifndef NISTRINGTOKENIZER_H
#define NISTRINGTOKENIZER_H

#include "NiPluginToolkitLibType.h"
#include "NiString.h"

/// A class designed to take an existing NiString and break it into
/// tokens based on an NiString of delimiters.
class NIPLUGINTOOLKIT_ENTRY NiStringTokenizer
{
    public:
        /// Create a NiStringTokenizer for the string pcSource
        NiStringTokenizer(const char* pcSource);

        /// Get the next token from m_strSource, 
        /// using the delimiter string strDelimiters
        NiString GetNextToken(const char* pcDelimiters);

        /// Query if we've reached the end of the string
        bool IsEmpty();

        /// Consume chars, returns the number consumed
        unsigned int Consume(const char* pcChars);

        /// Consume unNumChars worth of chars, returns the number consumed
        unsigned int Consume(unsigned int uiNumChars);

        /// Peek at the next chars
        const char* Peek();

    protected:
        /// The source NiString
        NiString m_strSource;

        /// The current index
        unsigned int m_uiSourceIndex;
};
#endif