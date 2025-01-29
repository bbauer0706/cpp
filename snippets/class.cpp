#include <iostream>
#include <string>
#include <array>

// Base class
class Base {
public:
    // Data members
    int intValue;
    double doubleValue;

    // Default constructor
    Base() : intValue(0), doubleValue(0.0) {
        std::cout << "Base constructor called\n";
    }

    // Parameterized constructor
    Base(int intVal, double doubleVal) : intValue(intVal), doubleValue(doubleVal) {
        std::cout << "Base parameterized constructor called\n";
    }

    // Destructor
    virtual ~Base() {
        std::cout << "Base destructor called\n";
    }

    // Member functions
    virtual void display() const {
        std::cout << "intValue: " << intValue << ", doubleValue: " << doubleValue << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Additional data member
    std::string stringValue;

    // Default constructor
    Derived() : Base(), stringValue("") {
        std::cout << "Derived constructor called\n";
    }

    // Parameterized constructor
    Derived(int intVal, double doubleVal, const std::string& strVal)
        : Base(intVal, doubleVal), stringValue(strVal) {
        std::cout << "Derived parameterized constructor called\n";
    }

    // Destructor
    ~Derived() {
        std::cout << "Derived destructor called\n";
    }

    // Member function to display all values
    void display() const override {
        Base::display(); // Calling base class display
        std::cout << "stringValue: " << stringValue << std::endl;
    }
};

int main() {
    // Creating an object of Derived class using the parameterized constructor
    Derived d(10, 20.5, "Hello, World!");
    d.display(); // Display the values of the object

    return 0;
}
