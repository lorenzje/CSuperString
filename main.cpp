// --------------------------------------------------------------------------------
// Name: Main
// Abstract : Main Method which tests CSuperstring class 
// --------------------------------------------------------------------------------

#include "CSuperString.h"
#include <iostream>

int main()
{
    //Constructors
    // ---------------------------------------------------------------------------------------------------
    // Testing the default constructor
    printf_s("default constructor\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strString1;
    std::cout << "Default constructor: " << strString1.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    // Testing the parameterized constructor
    printf_s("Parameterized constructor\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strString2("i love c programming!");
    std::cout << "Parameterized constructor: " << strString2.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Testing the copy constructor
    printf_s("copy constructor\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strString3 = strString2;
    std::cout << "Copy constructor: " << strString3.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //concatenation operator
    // ---------------------------------------------------------------------------------------------------
    //Testing concatenation operator
    printf_s("concatenation\n");
    printf_s("-----------------------------------------------------------------\n");
    strString2 += " (just kidding)";
    std::cout << "After concatenation: " << strString2.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");



    //Methods
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //To Upper Case 
    printf_s("ToUpperCase\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "ToUpperCase: " << strString2.ToUpperCase() << std::endl;
    printf_s("\n");
    printf_s("\n");

    //To Lower Case 
    printf_s("ToLowerCase\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "ToLowerCase: " << strString2.ToLowerCase() << std::endl;
    printf_s("\n");
    printf_s("\n");

    //Trim 
    printf_s("Trim\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strString4("   i love star track   ");
    std::cout << "Before Trim: '" << strString4.ToString() << "'" << std::endl;
    std::cout << "After Trim: '" << strString4.Trim() << "'" << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Trim Left 
    printf_s("TrimLeft\n");
    printf_s("-----------------------------------------------------------------\n");
    strString4 = "   i love star track   ";
    std::cout << "Before TrimLeft: '" << strString4.ToString() << "'" << std::endl;
    std::cout << "After TrimLeft: '" << strString4.TrimLeft() << "'" << std::endl;
    printf_s("\n");
    printf_s("\n");


    // Trim Right method
    printf_s("TrimRight\n");
    printf_s("-----------------------------------------------------------------\n");
    strString4 = "   i love star track   ";
    std::cout << "Before TrimRight: '" << strString4.ToString() << "'" << std::endl;
    std::cout << "After TrimRight: '" << strString4.TrimRight() << "'" << std::endl;
    printf_s("\n");
    printf_s("\n");


    // Reverse method
    printf_s("Reverse\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "Before Reverse: " << strString3.ToString() << std::endl;
    std::cout << "After Reverse: " << strString3.Reverse() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Replace character
    printf_s("Replace character)\n");
    printf_s("-----------------------------------------------------------------\n");
    strString3 = "I miss visual basic! :(";
    std::cout << "Before Replace (char): " << strString3.ToString() << std::endl;
    std::cout << "After Replace (char): " << strString3.Replace(' ', '_') << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Replace substring
    printf_s("Replace substring\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "Before Replace (substring): " << strString3.ToString() << std::endl;
    std::cout << "After Replace (substring): " << strString3.Replace("miss", "love") << std::endl;
    printf_s("\n");
    printf_s("\n");



    //find First Index of character
    printf_s("FindFirstIndexOf character\n");
    printf_s("-----------------------------------------------------------------\n");
    long index = strString3.FindFirstIndexOf('!');
    std::cout << "First index of '!': " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    //find First Index of character with start index
    printf_s("FindFirstIndexOf character with start index\n");
    printf_s("-----------------------------------------------------------------\n");
    index = strString3.FindFirstIndexOf('S', 5);
    std::cout << "First index of 'S' after index 5: " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    // Find Last Index of  character
    printf_s("Find Last Index of character\n");
    printf_s("-----------------------------------------------------------------\n");
    index = strString3.FindLastIndexOf('!');
    std::cout << "Last index of '!': " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    //FindFirstIndexOf substring
    printf_s("Find First Index Of substring\n");
    printf_s("-----------------------------------------------------------------\n");
    index = strString3.FindFirstIndexOf("Super");
    std::cout << "First index of 'Super': " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Find first Index of substring with start index
    printf_s("Testing FindFirstIndexOf substring with start index\n");
    printf_s("-----------------------------------------------------------------\n");
    index = strString3.FindFirstIndexOf("Java", 5);
    std::cout << "First index of 'Java' after index 5: " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Find Last Index of substring
    printf_s("Testing FindLastIndexOf substring\n");
    printf_s("-----------------------------------------------------------------\n");
    index = strString3.FindLastIndexOf("Super");
    std::cout << "Last index of 'Super': " << index << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Insert character
    printf_s("Insert character\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "Before Insert (char): " << strString3.ToString() << std::endl;
    std::cout << "After Insert (char): " << strString3.Insert('!', 0) << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Insert substring
    printf_s("Insert substring\n");
    printf_s("-----------------------------------------------------------------\n");
    std::cout << "Before Insert (substring): " << strString3.ToString() << std::endl;
    std::cout << "After Insert (substring): " << strString3.Insert(" Super", 6) << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Left method
    printf_s("Left method\n");
    printf_s("-----------------------------------------------------------------\n");
    const char* left = strString3.Left(5);
    std::cout << "Left 5 characters: " << left << std::endl;
    delete[] left;
    printf_s("\n");
    printf_s("\n");


    //Right method
    printf_s("Right method\n");
    printf_s("-----------------------------------------------------------------\n");
    const char* right = strString3.Right(5);
    std::cout << "Right 5 characters: " << right << std::endl;
    delete[] right;
    printf_s("\n");
    printf_s("\n");


    //Substring 
    printf_s("Substring\n");
    printf_s("-----------------------------------------------------------------\n");
    const char* substr = strString3.Substring(2, 5);
    std::cout << "Substring from index 2, length 5: " << substr << std::endl;
    delete[] substr;
    printf_s("\n");
    printf_s("\n");



    //Operators
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing assignment operator (char*)
    printf_s("char* assignment operator\n");
    printf_s("-----------------------------------------------------------------\n");
    strString3 = "New String";
    std::cout << "After assignment (char*): " << strString3.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Testing assignment operator (char)
    printf_s("char assignment operator\n");
    printf_s("-----------------------------------------------------------------\n");
    strString3 = 'A';
    std::cout << "After assignment (char): " << strString3.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Testing assignment operator (CSuperString)
    printf_s("Testing assignment operator CSuperString)\n");
    printf_s("-----------------------------------------------------------------\n");
    strString3 = strString2;
    std::cout << "After assignment (CSuperString): " << strString3.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Testing subscript operator (non-const)
    printf_s("Testing subscript operator (non-const)\n");
    printf_s("-----------------------------------------------------------------\n");
    strString3[0] = 'H';
    std::cout << "After subscript operator (non-const): " << strString3.ToString() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //Testing subscript operator (const)
    printf_s("Testing subscript operator (const)\n");
    printf_s("-----------------------------------------------------------------\n");
    const CSuperString strConst("Constant String");
    std::cout << "Subscript operator (const): " << strConst[0] << std::endl;
    printf_s("\n");
    printf_s("\n");



    //Conversions
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //To Boolean
    printf_s("To Boolean\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strBoolTrue("true");
    std::cout << "ToBoolean: " << strBoolTrue.ToBoolean() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //To Integer
    printf_s("To Integer\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strInt("123");
    std::cout << "To Integer: " << strInt.ToInteger() << std::endl;
    printf_s("\n");
    printf_s("\n");


    //To Float
    printf_s("To Float\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strFloat("123.45");
    std::cout << "ToFloat: " << strFloat.ToFloat() << std::endl;
    printf_s("\n");
    printf_s("\n");



    //stream operators
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf_s("stream operators\n");
    printf_s("-----------------------------------------------------------------\n");
    CSuperString strInput;
    std::cout << "Enter a string: ";
    std::cin >> strInput;
    std::cout << "Correct Answer: " << strInput << std::endl;
    printf_s("Congrats! You Passed!");
    printf_s("\n");
    printf_s("\n");

    system("pause");

    return 0;
}
