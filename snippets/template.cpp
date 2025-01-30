#include <iostream>
using namespace std;

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
