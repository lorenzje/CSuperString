#pragma once
#define _CRT_SECURE_NO_WARNINGS
// --------------------------------------------------------------------------------
// Name: CSuperString
// Abstract: Final Solution for CSuperstring
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <iostream>
using namespace std;



// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------
class CSuperString
{
    // --------------------------------------------------------------------------------
    // Properties
    // --------------------------------------------------------------------------------
private:
    char* m_pstrSuperString;  // Pointer to dynamically allocated string

public:
    // --------------------------------------------------------------------------------
    // Constructors
    // --------------------------------------------------------------------------------
    CSuperString();    // Default constructor
    CSuperString(const char* pstrStringToCopy); 
    CSuperString(const bool blnBooleanToCopy);  
    CSuperString(const char chrLetterToCopy);   
    CSuperString(const short shtShortToCopy);   
    CSuperString(const int intIntegerToCopy);   
    CSuperString(const long lngLongToCopy);     // Constructor to initialize with a long integer
    CSuperString(const float sngFloatToCopy);   // Constructor to initialize with a float
    CSuperString(const double dblDoubleToCopy); // Constructor to initialize with a double
    CSuperString(const CSuperString& ssStringToCopy); // Copy constructor



    // --------------------------------------------------------------------------------
    // Destructor
    // --------------------------------------------------------------------------------
    virtual ~CSuperString();



    // --------------------------------------------------------------------------------
    // Assignment Operators
    // --------------------------------------------------------------------------------
    void operator=(const char* pstrStringToCopy);
    void operator=(const char chrLetterToCopy);
    void operator=(const CSuperString& ssStringToCopy);



    // --------------------------------------------------------------------------------
    // Concatenate Operator
    // --------------------------------------------------------------------------------
    void operator+=(const char* pstrStringToAppend);
    void operator+=(const char chrCharacterToAppend);
    void operator+=(const CSuperString& ssStringToAppend);



    // --------------------------------------------------------------------------------
    // Friend Functions for Concatenation
    // --------------------------------------------------------------------------------
    friend CSuperString operator+(const CSuperString& ssLeft, const CSuperString& ssRight);
    friend CSuperString operator+(const char* pstrLeftSide, const CSuperString& ssRightString);
    friend CSuperString operator+(const CSuperString& ssLeftString, const char* pstrRightSide);



    // --------------------------------------------------------------------------------
    // Methods
    // --------------------------------------------------------------------------------
    long Length() const;
    long FindFirstIndexOf(const char chrLetterToFind) const;
    long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex) const;
    long FindLastIndexOf(const char chrLetterToFind) const;

    long FindFirstIndexOf(const char* pstrSubStringToFind) const;
    long FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex) const;
    long FindLastIndexOf(const char* pstrSubStringToFind) const;

    const char* ToUpperCase();
    const char* ToLowerCase();
    const char* TrimLeft();
    const char* TrimRight();
    const char* Trim();
    const char* Reverse();

    const char* Left(long lngCharactersToCopy);
    const char* Right(long lngCharactersToCopy);
    const char* Substring(long lngStart, long lngSubStringLength);

    const char* Replace(char chrLetterToFind, char chrReplace);
    const char* Replace(const char* pstrFind, const char* pstrReplace);
    const char* Insert(char chrLetterToInsert, long lngIndex);
    const char* Insert(const char* pstrSubString, long lngIndex);



    // --------------------------------------------------------------------------------
    // Subscript Operator
    // --------------------------------------------------------------------------------
    char& operator[](long lngIndex);
    const char& operator[](long lngIndex) const;



    // --------------------------------------------------------------------------------
    // Conversion Methods
    // --------------------------------------------------------------------------------
    const char* ToString() const;
    bool ToBoolean() const;
    short ToShort() const;
    int ToInteger() const;
    long ToLong() const;
    float ToFloat() const;
    double ToDouble() const;



    // --------------------------------------------------------------------------------
    // Stream Operators
    // --------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& osOut, const CSuperString& ssOutput);
    friend istream& operator>>(istream& isIn, CSuperString& ssInput);
};
