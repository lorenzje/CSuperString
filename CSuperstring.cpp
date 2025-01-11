#define _CRT_SECURE_NO_WARNINGS
// --------------------------------------------------------------------------------
// Name: CSuperString.cpp
// Abstract: CSuperString Class
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CSuperString.h"
#include <cstring>
#include <stdexcept>

// --------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------
CSuperString::CSuperString() : m_pstrSuperString(nullptr)
{
    // Initialize with an empty string
    m_pstrSuperString = new char[1];
    m_pstrSuperString[0] = '\0';
}



CSuperString::CSuperString(const char* pstrStringToCopy)
{
    if (pstrStringToCopy)
    {
        m_pstrSuperString = new char[strlen(pstrStringToCopy) + 1];
        strcpy(m_pstrSuperString, pstrStringToCopy);
    }
    else
    {
        m_pstrSuperString = new char[1];
        m_pstrSuperString[0] = '\0';
    }
}



CSuperString::CSuperString(const bool blnBooleanToCopy)
{
    m_pstrSuperString = new char[blnBooleanToCopy ? 5 : 6];
    strcpy(m_pstrSuperString, blnBooleanToCopy ? "true" : "false");
}



CSuperString::CSuperString(const char chrLetterToCopy)
{
    m_pstrSuperString = new char[2];
    m_pstrSuperString[0] = chrLetterToCopy;
    m_pstrSuperString[1] = '\0';
}



CSuperString::CSuperString(const short shtShortToCopy)
{
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%d", shtShortToCopy);
    m_pstrSuperString = new char[strlen(buffer) + 1];
    strcpy(m_pstrSuperString, buffer);
}



CSuperString::CSuperString(const int intIntegerToCopy)
{
    char chrBuffer[20];
    snprintf(chrBuffer, sizeof(chrBuffer), "%d", intIntegerToCopy);
    m_pstrSuperString = new char[strlen(chrBuffer) + 1];
    strcpy(m_pstrSuperString, chrBuffer);
}



CSuperString::CSuperString(const long lngLongToCopy)
{
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%ld", lngLongToCopy);
    m_pstrSuperString = new char[strlen(buffer) + 1];
    strcpy(m_pstrSuperString, buffer);
}



CSuperString::CSuperString(const float sngFloatToCopy)
{
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "%f", sngFloatToCopy);
    m_pstrSuperString = new char[strlen(buffer) + 1];
    strcpy(m_pstrSuperString, buffer);
}



CSuperString::CSuperString(const double dblDoubleToCopy)
{
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "%lf", dblDoubleToCopy);
    m_pstrSuperString = new char[strlen(buffer) + 1];
    strcpy(m_pstrSuperString, buffer);
}



CSuperString::CSuperString(const CSuperString& ssStringToCopy)
{
    m_pstrSuperString = new char[strlen(ssStringToCopy.m_pstrSuperString) + 1];
    strcpy(m_pstrSuperString, ssStringToCopy.m_pstrSuperString);
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Destructor
// --------------------------------------------------------------------------------
CSuperString::~CSuperString()
{
    delete[] m_pstrSuperString;
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Assignment Operators
// --------------------------------------------------------------------------------
void CSuperString::operator=(const char* pstrStringToCopy)
{
    if (m_pstrSuperString != pstrStringToCopy)
    {
        delete[] m_pstrSuperString;
        if (pstrStringToCopy)
        {
            m_pstrSuperString = new char[strlen(pstrStringToCopy) + 1];
            strcpy(m_pstrSuperString, pstrStringToCopy);
        }
        else
        {
            m_pstrSuperString = new char[1];
            m_pstrSuperString[0] = '\0';
        }
    }
}



void CSuperString::operator=(const char chrLetterToCopy)
{
    if (m_pstrSuperString[0] != chrLetterToCopy || m_pstrSuperString[1] != '\0')
    {
        delete[] m_pstrSuperString;
        m_pstrSuperString = new char[2];
        m_pstrSuperString[0] = chrLetterToCopy;
        m_pstrSuperString[1] = '\0';
    }
}



void CSuperString::operator=(const CSuperString& ssStringToCopy)
{
    if (this != &ssStringToCopy)
    {
        delete[] m_pstrSuperString;
        m_pstrSuperString = new char[strlen(ssStringToCopy.m_pstrSuperString) + 1];
        strcpy(m_pstrSuperString, ssStringToCopy.m_pstrSuperString);
    }
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Concatenate Operators
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const char* pstrStringToAppend)
{
    if (pstrStringToAppend)
    {
        char* newStr = new char[strlen(m_pstrSuperString) + strlen(pstrStringToAppend) + 1];
        strcpy(newStr, m_pstrSuperString);
        strcat(newStr, pstrStringToAppend);
        delete[] m_pstrSuperString;
        m_pstrSuperString = newStr;
    }
}



void CSuperString::operator+=(const char chrCharacterToAppend)
{
    char* newStr = new char[strlen(m_pstrSuperString) + 2];
    strcpy(newStr, m_pstrSuperString);
    newStr[strlen(m_pstrSuperString)] = chrCharacterToAppend;
    newStr[strlen(m_pstrSuperString) + 1] = '\0';
    delete[] m_pstrSuperString;
    m_pstrSuperString = newStr;
}



void CSuperString::operator+=(const CSuperString& ssStringToAppend)
{
    *this += ssStringToAppend.m_pstrSuperString;
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Friend Functions for Concatenation
// --------------------------------------------------------------------------------
CSuperString operator+(const CSuperString& ssLeft, const CSuperString& ssRight)
{
    CSuperString result = ssLeft;
    result += ssRight.m_pstrSuperString;
    return result;
}



CSuperString operator+(const char* pstrLeftSide, const CSuperString& ssRightString)
{
    CSuperString result = pstrLeftSide;
    result += ssRightString.m_pstrSuperString;
    return result;
}



CSuperString operator+(const CSuperString& ssLeftString, const char* pstrRightSide)
{
    CSuperString result = ssLeftString;
    result += pstrRightSide;
    return result;
}


// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Methods
// --------------------------------------------------------------------------------


//Name     : Length
//Abstract : Counts the number of characters in lngLength 
//---------------------------------------------------------------------------------
long CSuperString::Length() const
{
    //Declare Variables
    long lngLength = 0;


    //Calculate length 
    lngLength = (long)strlen(m_pstrSuperString);


    return lngLength;
}



// Name     : FindFirstIndexOf
// Abstract : Finds the first occurrence of a character in the string and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    long lngIndex = -1;


    //Find first occurrence 
    chrFound = strchr(m_pstrSuperString, chrLetterToFind);


    //calculate index
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : FindFirstIndexOf
// Abstract : Finds the first occurrence of a character in the string, starting from a given index, and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    long lngIndex = -1;


    //Valid start index
    if (lngStartIndex < 0 || lngStartIndex >= Length())
        throw out_of_range("Start index out of range.");


    //Find first occurrence of character from start index
    chrFound = strchr(m_pstrSuperString + lngStartIndex, chrLetterToFind);


    //Calculate index
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : FindLastIndexOf
// Abstract : Finds the last occurrence of a character in the string and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    long lngIndex = -1;


    //Find last occurrence and index
    chrFound = strrchr(m_pstrSuperString, chrLetterToFind);
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : FindFirstIndexOf
// Abstract : Finds the first occurrence of a substring in the string and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    long lngIndex = -1;


    //Find first occurrence of substring
    chrFound = strstr(m_pstrSuperString, pstrSubStringToFind);


    //calculate index
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : FindFirstIndexOf
// Abstract : Finds the first occurrence of a substring in the string, starting from a given index, and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    long lngIndex = -1;


    //Valid start
    if (lngStartIndex < 0 || lngStartIndex >= Length())
    {
        throw out_of_range("Start index out of range.");
    }


    //Find first occurrence of substring
    chrFound = strstr(m_pstrSuperString + lngStartIndex, pstrSubStringToFind);


    //calculate the index
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : FindLastIndexOf
// Abstract : Finds the last occurrence of a substring in the string and returns its index.
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind) const
{
    //Declare Variables
    const char* chrFound = nullptr;
    const char* chrTemp = nullptr;
    long lngIndex = -1;


    //Find first occurrence 
    chrTemp = strstr(m_pstrSuperString, pstrSubStringToFind);


    //find last occurrence
    while (chrTemp != nullptr)
    {
        chrFound = chrTemp;
        chrTemp = strstr(chrTemp + 1, pstrSubStringToFind);
    }


    //calculate index
    if (chrFound)
    {
        lngIndex = chrFound - m_pstrSuperString;
    }


    return lngIndex;
}



// Name     : ToUpperCase
// Abstract : Converts all characters in the string to uppercase.
// --------------------------------------------------------------------------------
const char* CSuperString::ToUpperCase()
{
    //Declare Variables
    char* strUpperCase = nullptr;
    long lngIndex = 0;


    //set variable
    strUpperCase = m_pstrSuperString;


    //convert to upper
    for (lngIndex = 0; lngIndex < Length(); ++lngIndex)
    {
        m_pstrSuperString[lngIndex] = toupper(m_pstrSuperString[lngIndex]);
    }


    return strUpperCase;
}



// Name     : ToLowerCase
// Abstract : Converts all characters in the string to lowercase.
// --------------------------------------------------------------------------------
const char* CSuperString::ToLowerCase()
{
    //Declare Variables
    char* strLowerCase = nullptr;
    long lngIndex = 0;


    //Set Variables
    strLowerCase = m_pstrSuperString;


    //Convert to Lower
    for (lngIndex = 0; lngIndex < Length(); ++lngIndex)
    {
        m_pstrSuperString[lngIndex] = tolower(m_pstrSuperString[lngIndex]);
    }


    return strLowerCase;
}



// Name     : TrimLeft
// Abstract : Trims whitespace characters from the left side of the string.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimLeft()
{
    //Declare Variables
    char* strTrimmedLeft = nullptr;
    long lngStart = 0;


    //Set Variable
    strTrimmedLeft = m_pstrSuperString;


    //Find first character
    while (isspace(m_pstrSuperString[lngStart]))
    {
        ++lngStart;
    }


    //trim
    if (lngStart > 0)
    {
        char* strNew = nullptr;
        strNew = new char[Length() - lngStart + 1];
        strcpy(strNew, m_pstrSuperString + lngStart);
        delete[] m_pstrSuperString;
        m_pstrSuperString = strNew;
        strTrimmedLeft = m_pstrSuperString;
    }


    return strTrimmedLeft;
}



// Name     : TrimRight
// Abstract : Trims whitespace characters from the right side of the string.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimRight()
{
    //Declare Variables
    char* strTrimmedRight = nullptr;
    long lngEnd = 0;


    //Set Variables
    strTrimmedRight = m_pstrSuperString;
    lngEnd = Length() - 1;


    //Find last Character
    while (lngEnd >= 0 && isspace(m_pstrSuperString[lngEnd]))
    {
        --lngEnd;
    }


    //trim
    m_pstrSuperString[lngEnd + 1] = '\0';


    return strTrimmedRight;
}



// Name     : Trim
// Abstract : removes spaces from both sides of the string
// --------------------------------------------------------------------------------
const char* CSuperString::Trim()
{
    //Declare Variables
    char* strTrimmed = nullptr;


    //Set Variables
    strTrimmed = m_pstrSuperString;


    //Trim 
    TrimLeft();
    TrimRight();


    return strTrimmed;
}



// Name     : Reverse
// Abstract : Reverses the order of characters in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Reverse()
{
    //Declare Variables
    char* strReversed = nullptr;
    long lngLength = 0;
    long lngIndex = 0;


    //set variables
    strReversed = m_pstrSuperString;
    lngLength = Length();


    //for loop which reverses the string
    for (lngIndex = 0; lngIndex < lngLength / 2; ++lngIndex)
    {
        swap(m_pstrSuperString[lngIndex], m_pstrSuperString[lngLength - lngIndex - 1]);
    }


    return strReversed;
}



// Name     : Left
// Abstract : Copies a substring from the left side of the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Left(long lngCharactersToCopy)
{
    //Valid # of characters
    if (lngCharactersToCopy < 0 || lngCharactersToCopy > Length())
    {
        throw out_of_range("Number of characters to copy out of range");
    }
        


    //Create New String
    char* chrNewString = new char[lngCharactersToCopy + 1];
    strncpy(chrNewString, m_pstrSuperString, lngCharactersToCopy);
    chrNewString[lngCharactersToCopy] = '\0';


    return chrNewString;
}



// Name     : Right
// Abstract : Copies a substring from the right side of the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy)
{
    //Declare Variables
    long lngLength = 0;
    char* chrNewString = nullptr;


    //Get Length
    lngLength = Length();


    //Valid Range
    if (lngCharactersToCopy < 0 || lngCharactersToCopy > lngLength)
    {
        throw out_of_range("Number of characters to copy out of range");
    }



    //New String
    chrNewString = new char[lngCharactersToCopy + 1];
    strncpy(chrNewString, m_pstrSuperString + (lngLength - lngCharactersToCopy), lngCharactersToCopy);
    chrNewString[lngCharactersToCopy] = '\0';


    return chrNewString;
}



// Name     : Substring
// Abstract : Extracts a substring from the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength)
{
    //Declare Variables
    char* chrNewString = nullptr;


    //Validate Range
    if (lngStart < 0 || lngStart >= Length() || lngSubStringLength < 0 || lngStart + lngSubStringLength > Length())
    {
        throw out_of_range("Substring range out of range");
    }


    //Create New String
    chrNewString = new char[lngSubStringLength + 1];
    strncpy(chrNewString, m_pstrSuperString + lngStart, lngSubStringLength);
    chrNewString[lngSubStringLength] = '\0';


    return chrNewString;
}



// Name     : Replace
// Abstract : Replaces all occurrences of a character in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
    //Declare Variables
    long lngIndex = 0;


    //Replace
    for (lngIndex = 0; lngIndex < Length(); ++lngIndex)
    {
        if (m_pstrSuperString[lngIndex] == chrLetterToFind)
        {
            m_pstrSuperString[lngIndex] = chrReplace;
        }
    }


    return m_pstrSuperString;
}



// Name     : Replace
// Abstract : Replaces all occurrences of a substring with another substring.
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
    //Declare Variables
    long lngFind = 0;
    long lngReplace = 0;
    long lngNewSize = 0;
    const char* chrTemp = nullptr;
    char* chrNewStr = nullptr;
    char* chrCurrent = nullptr;
    const char* chrsrc = nullptr;


    //Set Variables
    lngFind = strlen(pstrFind);
    lngReplace = strlen(pstrReplace);
    lngNewSize = Length();
    chrTemp = strstr(m_pstrSuperString, pstrFind);


    //Calculate Size
    while (chrTemp != nullptr)
    {
        lngNewSize = lngNewSize - lngFind + lngReplace;
        chrTemp = strstr(chrTemp + lngFind, pstrFind);
    }


    //New String
    chrNewStr = new char[lngNewSize + 1];
    chrCurrent = chrNewStr;
    chrsrc = m_pstrSuperString;
    chrTemp = strstr(chrsrc, pstrFind);


    //Replace
    while (chrTemp != nullptr)
    {
        long lenBefore = 0;
        lenBefore = chrTemp - chrsrc;
        strncpy(chrCurrent, chrsrc, lenBefore);
        chrCurrent += lenBefore;
        strcpy(chrCurrent, pstrReplace);
        chrCurrent += lngReplace;
        chrsrc = chrTemp + lngFind;
        chrTemp = strstr(chrsrc, pstrFind);
    }


    //Copy Remainder
    strcpy(chrCurrent, chrsrc);


    //Replace
    delete[] m_pstrSuperString;
    m_pstrSuperString = chrNewStr;


    return m_pstrSuperString;
}



// Name     : Insert
// Abstract : Inserts a character at a specified index in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(char chrLetterToInsert, long lngIndex)
{
    //Declare Variables
    char* chrNewStr = nullptr;


    //Valid Index
    if (lngIndex < 0 || lngIndex > Length())
    {
        throw out_of_range("Index out of range.");
    }



    //Insert
    chrNewStr = new char[Length() + 2];
        strncpy(chrNewStr, m_pstrSuperString, lngIndex);
    chrNewStr[lngIndex] = chrLetterToInsert;
        strcpy(chrNewStr + lngIndex + 1, m_pstrSuperString + lngIndex);


    //Replace
    delete[] m_pstrSuperString;
    m_pstrSuperString = chrNewStr;


    return m_pstrSuperString;
}



// Name     : Insert
// Abstract : Inserts a substring at a specified index in the string.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex)
{
    //Declare Variables
    long lngInsertLength = 0;
    char* newStr = nullptr;


    //Valid Index
    if (lngIndex < 0 || lngIndex > Length())
    {
        throw out_of_range("Index out of range.");
    }



    //Substring Length
    lngInsertLength = strlen(pstrSubString);
    newStr = new char[Length() + lngInsertLength + 1];


    //Insert
    strncpy(newStr, m_pstrSuperString, lngIndex);
    strcpy(newStr + lngIndex, pstrSubString);
    strcpy(newStr + lngIndex + lngInsertLength, m_pstrSuperString + lngIndex);


    //Replace
    delete[] m_pstrSuperString;
    m_pstrSuperString = newStr;


    return m_pstrSuperString;
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Subscript Operators
// --------------------------------------------------------------------------------


// Name     : char%
// Abstract : operator
// --------------------------------------------------------------------------------
char& CSuperString::operator[](long lngIndex)
{
    if (lngIndex < 0 || lngIndex >= Length())
    {
        throw out_of_range("Index out of range.");
    }


    return m_pstrSuperString[lngIndex];
}


// Name     : const char%
// Abstract : operator
// --------------------------------------------------------------------------------
const char& CSuperString::operator[](long lngIndex) const
{
    if (lngIndex < 0 || lngIndex >= Length())
    {
        throw out_of_range("Index out of range.");
    }

    return m_pstrSuperString[lngIndex];
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Conversion Methods
// --------------------------------------------------------------------------------

// Name     : ToString
// Abstract : Converts SuperString To String
// --------------------------------------------------------------------------------
const char* CSuperString::ToString() const
{
    return m_pstrSuperString;
}



// Name     : ToBoolean
// Abstract : Converts SuperString To Boolean
// --------------------------------------------------------------------------------
bool CSuperString::ToBoolean() const
{
    return strcmp(m_pstrSuperString, "true") == 0;
}



// Name     : ToShort
// Abstract : Converts SuperString To Short
// --------------------------------------------------------------------------------
short CSuperString::ToShort() const
{
    return static_cast<short>(atoi(m_pstrSuperString));
}



// Name     : ToInteger
// Abstract : Converts SuperString To Integer
// --------------------------------------------------------------------------------
int CSuperString::ToInteger() const
{
    return atoi(m_pstrSuperString);
}



// Name     : ToLong
// Abstract : Converts SuperString To Long
// --------------------------------------------------------------------------------
long CSuperString::ToLong() const
{
    return atol(m_pstrSuperString);
}



// Name     : ToFloat
// Abstract : Converts SuperString To Float
// --------------------------------------------------------------------------------
float CSuperString::ToFloat() const
{
    return static_cast<float>(atof(m_pstrSuperString));
}



// Name     : ToDouble
// Abstract : Converts SuperString To Double
// --------------------------------------------------------------------------------
double CSuperString::ToDouble() const
{
    return atof(m_pstrSuperString);
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Stream Operators
// --------------------------------------------------------------------------------
ostream& operator<<(ostream& osOut, const CSuperString& ssOutput)
{
    osOut << ssOutput.m_pstrSuperString;
    return osOut;
}



istream& operator>>(istream& isIn, CSuperString& ssInput)
{
    char buffer[1024];
    isIn >> buffer;
    ssInput = buffer;
    return isIn;
}