#include <iostream>
using namespace std;

/*
Key Concepts:
Generic Template Class:

Pair<T> is a class template that can work with any data type (int, double, etc.).
The member functions of the class are defined in terms of the template type T, making the class flexible and reusable.
Template Specialization:

template <> class Pair<char> is a specialization of the template class Pair for the char type. This version has a customized display() method for char pairs.
Specializing a template class allows you to provide specific functionality for certain types while keeping the general functionality for other types.
Instantiation:

When we instantiate Pair<int>, Pair<double>, or Pair<char>, the appropriate version of the template class is used.
Summary:
Template classes in C++ allow you to define classes that can operate on any data type.
Template specialization allows you to define a specific behavior for certain types, which overrides the generic implementation for those types.
This approach helps create generic and reusable code, while still allowing custom behavior for specific cases when needed.
*/

// Template class definition
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T a, T b) : first(a), second(b) {}

    // Method to display the pair
    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

// Template specialization for char type
template <>
class Pair<char> {
private:
    char first;
    char second;

public:
    Pair(char a, char b) : first(a), second(b) {}

    // Specialized display method for char type
    void display() {
        cout << "Specialized for char: First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    // Using the generic template for integers
    Pair<int> intPair(1, 2);
    intPair.display();  // Displays: First: 1, Second: 2

    // Using the generic template for doubles
    Pair<double> doublePair(3.14, 2.71);
    doublePair.display();  // Displays: First: 3.14, Second: 2.71

    // Using the specialized template for char
    Pair<char> charPair('A', 'B');
    charPair.display();  // Displays: Specialized for char: First: A, Second: B

    return 0;
}
