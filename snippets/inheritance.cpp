#include <iostream>
using namespace std;

// Abstract Base Class (Java-like Interface)
class _BASE_ {
public:
    // Pure virtual function to make the class abstract (Java Interface-like)
    virtual void show() = 0; // pure virtual function, must be overridden in derived classes
    virtual void details() = 0; // Another pure virtual function
    virtual ~_BASE_() {} // Virtual destructor for proper cleanup in derived classes
};

// Derived class inheriting from _BASE_
class _DERIVED_ : public _BASE_ {
public:
    // Overriding the pure virtual functions from _BASE_
    void show() override {
        cout << "This is the Derived Class showing base behavior." << endl;
    }

    void details() override {
        cout << "Derived class contains specific details." << endl;
    }

    // Additional functionality specific to _DERIVED_
    void derivedMethod() {
        cout << "Derived class specific method." << endl;
    }
};

// Another Class to demonstrate Multi-Inheritance
class _ANOTHER_ {
public:
    void additionalFeature() {
        cout << "This is an additional feature from another class." << endl;
    }
};

// Multi-Inheritance example (inheriting from both _DERIVED_ and _ANOTHER_)
class _MULTI_DERIVED_ : public _DERIVED_, public _ANOTHER_ {
public:
    void multiShow() {
        cout << "Multi-Derived class showing combined features:" << endl;
        show();          // Inherited from _DERIVED_
        details();       // Inherited from _DERIVED_
        additionalFeature(); // Inherited from _ANOTHER_
    }
};

int main() {
    // Using the _DERIVED_ class
    _DERIVED_ derivedObj;
    derivedObj.show();
    derivedObj.details();
    derivedObj.derivedMethod();

    // Using the _MULTI_DERIVED_ class
    _MULTI_DERIVED_ multiDerivedObj;
    multiDerivedObj.multiShow();

    return 0;
}
