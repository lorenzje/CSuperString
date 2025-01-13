
# CSuperString Class

## Overview

The `CSuperString` class is a custom string handling utility implemented in C++ that extends the capabilities of standard strings. It provides a variety of constructors, operators, and methods for flexible string manipulation.

---

## Features

### Constructors
- Default constructor initializes to an empty string.
- Copy constructors from various types:
  - C-style strings (`const char*`)
  - Boolean (`true` or `false`)
  - Single characters
  - Numeric types (short, int, long, float, double)
  - Another `CSuperString` object

### Operators
- Assignment operators for strings, characters, and `CSuperString` objects.
- Concatenation operators (`+=`) for appending strings and characters.
- Subscript operators for character access with bounds checking.
- Stream operators (`<<` and `>>`) for easy input and output.

### String Manipulation Methods
- **Length:** Returns the length of the string.
- **FindFirstIndexOf:** Finds the first occurrence of a character or substring.
- **FindLastIndexOf:** Finds the last occurrence of a character or substring.
- **ToUpperCase/ToLowerCase:** Converts the string to uppercase or lowercase.
- **TrimLeft/TrimRight/Trim:** Removes whitespace from the sides of the string.
- **Reverse:** Reverses the string.
- **Left/Right:** Extracts substrings from the left or right.
- **Substring:** Extracts a substring from a specified index.
- **Replace:** Replaces characters or substrings.
- **Insert:** Inserts characters or substrings at a specified index.

### Conversion Methods
- Converts the string to various types, including:
  - Boolean (`ToBoolean`)
  - Numeric types: short, int, long, float, double

---

## Usage

### Example

```cpp
#include "CSuperString.h"
#include <iostream>

int main() {
    CSuperString str1("Hello");
    CSuperString str2("World");
    
    // Concatenation
    str1 += " ";
    str1 += str2;
    std::cout << str1 << std::endl; // Output: Hello World

    // Finding substrings
    long index = str1.FindFirstIndexOf("World");
    std::cout << "Index of 'World': " << index << std::endl;

    // Uppercase conversion
    str1.ToUpperCase();
    std::cout << str1 << std::endl; // Output: HELLO WORLD

    return 0;
}
```

---

## Prerequisites
- A C++ compiler supporting the C++11 standard or later.
- Include the `CSuperString.h` header file and ensure the `CSuperString.cpp` implementation file is available.

---

## File Details
- **Header File:** `CSuperString.h`
- **Implementation File:** `CSuperString.cpp`

---

## License
This class implementation is intended for educational purposes and is not suited for production use without thorough testing and optimization.
