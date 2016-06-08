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

#ifndef NISTRING_H
#define NISTRING_H

#include "NiPluginToolkitLibType.h"
#include <NiRefObject.h>
#include <NiSmartPointer.h>
#include <stdio.h>

class NiPoint3;
class NiColor;
class NiColorA;

extern NIPLUGINTOOLKIT_ENTRY const unsigned int INVALID_INDEX;

/// A class that implements a smart character string. It is reference counted
/// in order to allow it to be shared by multiple NiString objects.
class NIPLUGINTOOLKIT_ENTRY NiStringBuffer : public NiRefObject
{
public:
    /// Construct a string buffer from a character string
    NiStringBuffer(const char* pcString);

    /// Construct a string buffer from a single character
    NiStringBuffer(char ch);

    /// Construct a string buffer with an empty string, but a built-in buffer size 
    /// of uiBuffSize. GetBestBufferSize is called on uiBuffSize to keep small
    /// data blocks about the same size
    NiStringBuffer(unsigned int uiBuffSize);

    /// Construct a string buffer with an input string, but a built-in buffer size 
    /// of uiBuffSize. GetBestBufferSize is called on uiBuffSize to keep small
    /// data blocks about the same size
    NiStringBuffer(unsigned int uiBuffSize, const char* pcString);

    /// Copy constructor
    NiStringBuffer(NiStringBuffer& kBuffer);

    /// Destructor
    ~NiStringBuffer();

    /// Calculate the length of m_pcString
    void CalcLength();

    /// Internal string buffer
    char* m_pcString;

    /// Amount of memory allocated to the buffer. 
    unsigned int m_uiBuffSize;

    /// Internal string length
    unsigned int m_uiStrLength;

    /// The ID of the thread who created and owns this string.
    unsigned long m_ulThreadOwner;
    
    /// Asserts if the current thread attempting access is not the owning thread
    void ThreadSafetyCheck();

    /// Used to determine the best allocation size of a string buffer
    static unsigned int GetBestBufferSize(unsigned int uiReqSize);
};

NiSmartPointer(NiStringBuffer);

/// A class that implements a smart character string.
class NIPLUGINTOOLKIT_ENTRY NiString
{
public:
    /// Construct an NiString using the input buffer size.
    NiString(int iBuffLength = 256);

    /// Construct an NiString from a single char
    NiString(char ch);

    /// Construct an NiString from an input string. The input string is copied
    /// into an internal NiStringBuffer
    NiString(const char* pcStr);

    /// Copy constructor. The internal string buffer's refcount is incremented, it is
    /// NOT copied
    NiString(const NiString& kString);

    /// Construct an NiString from a string buffer
    NiString(NiStringBuffer* pkBuffer);

    /// Destroys an NiString. The refcount of the internal string buffer is
    ///  decremented. If the refcount is now zero, the string buffer is deleted.
    ~NiString();

    /// Gets the length of the string
    unsigned int Length() const;
    
    /// Tests whether a NiString object contains no characters.
    bool IsEmpty() const;

    /// Forces a string to have 0 length. 
    void Empty(); 
    
    /// Returns the character at a given position. 
    char GetAt(unsigned int ui) const;
    
    /// Sets a character at a given position
    void SetAt(unsigned int ui, char c);
    
    /// This method compares pNiString lexicographically to the current
    /// string and returns a value indicating their relationship.
    int Compare(const char* pNiString) const;

    /// This method lexicographically compares lowercase versions of the current string and pNiString
    /// and returns a value indicating their relationship.
    int CompareNoCase(const char* pNiString) const;

    /// Does this string exactly equal the input string?
    bool Equals(const char* pcStr) const ;

    /// Does this string exactly equal the input string ignoring case?
    bool EqualsNoCase(const char* pcStr) const;

    /// Get a separate copy of a substring from uiBegin up to uiEnd
    NiString GetSubstring(unsigned int uiBegin, unsigned int uiEnd) const;

    /// Get a separate copy of a substring from uiBegin up to the first character
    /// found in pcDelimiters
    NiString GetSubstring(unsigned int uiBegin, const char* pcDelimeters) const;
    
    /// Find a character within this string and return its index
    unsigned int Find(char c, unsigned int uiStart = 0) const;

    /// Find a substring within this string and return its index
    unsigned int Find(const char* pcStr, unsigned int uiStart = 0) const;

    /// Find a character within this string, starting from the end and working 
    /// backwards, and return its index
    unsigned int FindReverse(char c) const;

    /// Find a character within this string from the set of characters in pcStr 
    /// and return its index 
    unsigned int FindOneOf(const char* pcStr, unsigned int uiStart = 0) const;

    /// Extracts the middle part of a string 
    NiString Mid(unsigned int uiBegin, unsigned int nCount = INVALID_INDEX) const;

    /// Extracts the left part of a string 
    NiString Left( unsigned int nCount ) const;

    /// Extracts the right part of a string
    NiString Right( unsigned int nCount ) const;

    /// Replace all exact matches of pcWhatToReplace in this string with
    /// pcReplaceWith
    void Replace(const char* pcWhatToReplace , const char* pcReplaceWith);

    /// Format the String buffer according to the standard printf string
    void Format(const char* pcFormatString ...);

    /// Convert the string to uppercase internally
    void ToUpper();
    /// Convert the string to lowercase internally
    void ToLower();
    /// Reverse the string internally
    void Reverse();

    /// Trim this character from the beginning of the string
    void TrimLeft(char c = ' ');
    /// Trim this character from the end of the string
    void TrimRight(char c = ' ');

    /// Get the char* buffer used by this string. Do NOT delete this buffer.
    /// Store in a smart pointer to ensure you're reference is taken into
    /// account.
    NiStringBufferPtr GetBuffer();

    /// Add the char* to the end of this string, growing the buffer as necessary.
    void Concatenate(const char* pcStr);

    /// Add the char to the end of this string, growing the buffer as necessary.
    void Concatenate(char ch);

    /// Convert the string into a boolean. True if successful, false if not.
    bool ToBool(bool& b);
    /// Convert the string into a float. True if successful, false if not.
    bool ToFloat(float& f);
    /// Convert the string into an int. True if successful, false if not.
    bool ToInt(int& i);
    /// Convert the string into an NiPoint3. True if successful, false if not.
    bool ToPoint3(NiPoint3& kPoint);
    /// Convert the string into an NiColor. True if successful, false if not.
    bool ToRGB(NiColor& kColor);
    /// Convert the string into an NiColorA. True if successful, false if not.
    bool ToRGBA(NiColorA& kColor);

    /// Returns the NiString representation of this object.
    static NiString FromBool(bool b);
    /// Returns the NiString representation of this object.
    static NiString FromFloat(float f);
    /// Returns the NiString representation of this object.
    static NiString FromInt(int i);
    /// Returns the NiString representation of this object.
    static NiString FromPoint3(NiPoint3& kPt);
    /// Returns the NiString representation of this object.
    static NiString FromRGB(NiColor& kColor);
    /// Returns the NiString representation of this object.
    static NiString FromRGBA(NiColorA& kColor);
    /// Returns the NiString representation of this object.

    /// return pointer to const string
    operator const char*() const;

    //char operator[](int nIndex) const;

    // overloaded assignment

    /// Ref-counted copy from another NiString
    NiString& operator=(NiString& stringSrc);
    /// copy string content from ANSI string (converts to char*)
    NiString& operator=(char* lpsz);
    /// copy string content from char*
    NiString& operator=(const char* psz);
    /// set string content to single character
    NiString& operator=(char ch);

    /// concatenate from another NiString
    NiString& operator+=(NiString& string);

    /// Concatenate a single character
    NiString& operator+=(char ch);
    /// Concatenate a char array
    NiString& operator+=(char* lpsz);
    /// Concatenate a const char*
    NiString& operator+=(const char* pcString);

    /// Create a new string that is the composite of String 1 and String 2
    friend NiString  NIPLUGINTOOLKIT_ENTRY operator+(const NiString& string1,
            const NiString& string2);

    /// Create a new string that is the composite of String 1 and a character
    friend NiString  NIPLUGINTOOLKIT_ENTRY operator+(const NiString& string, char ch);
    
    /// Create a new string that is the composite of a character and String 2
    friend NiString  NIPLUGINTOOLKIT_ENTRY operator+(char ch, const NiString& string);
    
    /// Create a new string that is the composite of String 1 and a char*
    friend NiString  NIPLUGINTOOLKIT_ENTRY operator+(const NiString& string, char* lpsz);

    /// Create a new string that is the composite of a char* and String 2
    friend NiString  NIPLUGINTOOLKIT_ENTRY operator+(char* lpsz, const NiString& string);

    /// create a character array that is not managed by this NiString
    char* MakeExternalCopy();


protected:
    /// Used to allow quick string checking for debugging, this is NOT 
    /// the internal buffer.
    const char* m_pcStr; 

    /// The internal string buffer
    NiStringBufferPtr m_spBuffer;

    /// Called before any operation that changes the string buffer.
    /// If this string is the only one holding on the the buffer, a copy
    /// is not made. Otherwise, a copy is made.
    void CopyOnWrite(bool bForceCopy = false);

    /// Internal implementation of vformat
    NiStringBufferPtr vformat(const char *fmt, va_list argPtr);

    /// Used internally to set the string buffer 
    void SetBuffer(NiStringBuffer* pkBuffer);
};

/// Do these two strings exactly match?
bool  NIPLUGINTOOLKIT_ENTRY operator==(const NiString& s1, const NiString& s2);
/// Do these two strings exactly match?
bool  NIPLUGINTOOLKIT_ENTRY operator==(const NiString& s1, const char* s2);
/// Do these two strings exactly match?
bool  NIPLUGINTOOLKIT_ENTRY operator==(const char* s1, const NiString& s2);
/// Do these two strings not match?
bool  NIPLUGINTOOLKIT_ENTRY operator!=(const NiString& s1, const NiString& s2);
/// Do these two strings not match?
bool  NIPLUGINTOOLKIT_ENTRY operator!=(const NiString& s1, const char* s2);
/// Do these two strings not match?
bool  NIPLUGINTOOLKIT_ENTRY operator!=(const char* s1, const NiString& s2);
/// Is s1 less than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<(const NiString& s1, const NiString& s2);
/// Is s1 less than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<(const NiString& s1, const char* s2);
/// Is s1 less than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<(const char* s1, const NiString& s2);
/// Is s1 greater than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>(const NiString& s1, const NiString& s2);
/// Is s1 greater than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>(const NiString& s1, const char* s2);
/// Is s1 greater than s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>(const char* s1, const NiString& s2);
/// Is s1 less than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<=(const NiString& s1, const NiString& s2);
/// Is s1 less than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<=(const NiString& s1, const char* s2);
/// Is s1 less than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator<=(const char* s1, const NiString& s2);
/// Is s1 greater than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>=(const NiString& s1, const NiString& s2);
/// Is s1 greater than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>=(const NiString& s1, const char* s2);
/// Is s1 greater than or equal to s2?
bool  NIPLUGINTOOLKIT_ENTRY operator>=(const char* s1, const NiString& s2);

bool NIPLUGINTOOLKIT_ENTRY IsTrue(NiString strStr);

#endif  // #ifndef NISTRING_H
