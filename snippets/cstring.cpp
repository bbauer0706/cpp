#include <iostream>
#include <cstring> // For C-style string functions
using namespace std;

void manipulateCString() {
    // Declare a C-style string (character array)
    char str[] = "Hello, World!";
    
    cout << "Original string: " << str << endl;
    
    // Manipulate individual characters (single byte manipulation)
    str[7] = 'w';  // Change the character at index 7 from 'W' to 'w'
    str[13] = '\0'; // Ensure null-termination after modification
    
    cout << "Modified string: " << str << endl;
    
    // Find the length of the string using strlen (from <cstring>)
    size_t len = strlen(str);
    cout << "Length of modified string: " << len << endl;
    
    // Iterate over the string and print individual characters (byte manipulation)
    cout << "Individual characters in the string: ";
    for (size_t i = 0; i < len; ++i) {
        cout << str[i] << " ";
    }
    cout << endl;
}

void cStringFunctions() {
    // Declare two C-style strings
    char str1[] = "Hello, ";
    char str2[] = "World!";
    
    // Concatenate two strings using strcat
    char result[50];  // Ensure the result can hold the concatenated string
    strcpy(result, str1);  // Copy str1 into result
    strcat(result, str2);  // Concatenate str2 onto the result
    
    cout << "Concatenated string: " << result << endl;
    
    // Copy one string to another using strcpy
    char strCopy[50];
    strcpy(strCopy, str1);
    cout << "Copied string: " << strCopy << endl;
    
    // Compare two strings using strcmp
    int cmpResult = strcmp(str1, str2);
    if (cmpResult == 0) {
        cout << "The strings are equal." << endl;
    } else if (cmpResult < 0) {
        cout << "str1 is lexicographically less than str2." << endl;
    } else {
        cout << "str1 is lexicographically greater than str2." << endl;
    }
}

void pointerToCString() {
    // Using a pointer to a C-style string (string literal, read-only)
    char *str = "Hello, World!"; // This is a pointer to a string literal
    
    // Print the original string
    cout << "Original string using pointer: " << str << endl;
    
    // Accessing individual characters via pointer
    cout << "First character using pointer: " << *str << endl;  // H
    cout << "Third character using pointer: " << *(str + 2) << endl;  // l
    
    // Pointer arithmetic to navigate the string
    char *p = str;
    cout << "Pointer arithmetic: " << *(p + 7) << endl;  // 'W' from "World!"
    
    // Modifying characters using pointer (note: this is not safe for string literals)
    // Uncommenting this line will cause undefined behavior
    // p[0] = 'h'; // Invalid: Cannot modify string literal
    
    // Safe modification: Use a character array (mutable)
    char mutableStr[] = "Hello, World!";
    mutableStr[0] = 'h';  // This works because it's an array, not a literal
    cout << "Modified string using pointer on array: " << mutableStr << endl;
}

int main() {
    // Manipulate a C-string and manipulate individual characters (bytes)
    manipulateCString();
    
    // Demonstrate basic C-string functions (concatenation, copying, comparison)
    cStringFunctions();
    
    // Demonstrate pointer to a C-string (pointer arithmetic and manipulation)
    pointerToCString();
    
    return 0;
}
