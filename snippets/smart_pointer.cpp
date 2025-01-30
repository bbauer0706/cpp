#include <iostream>
#include <memory>  // For smart pointers
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass(int val) : value(val) {
        cout << "MyClass constructor called for value: " << value << endl;
    }

    ~MyClass() {
        cout << "MyClass destructor called for value: " << value << endl;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }

private:
    int value;
};

// Function to demonstrate unique_ptr
void uniquePointerDemo() {
    cout << "\n--- Unique Pointer Demo ---\n";

    // Creating a unique_ptr to manage a dynamically allocated object
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>(10);
    
    // Using the object
    uniquePtr->display();
    
    // No need to manually delete the object, it's automatically deleted when the unique_ptr goes out of scope
    // This happens at the end of this function when uniquePtr goes out of scope
}

// Function to demonstrate shared_ptr
void sharedPointerDemo() {
    cout << "\n--- Shared Pointer Demo ---\n";

    // Creating a shared_ptr to manage a dynamically allocated object
    shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>(20);

    // Creating another shared_ptr that shares ownership of the same object
    shared_ptr<MyClass> sharedPtr2 = sharedPtr1;

    // Using the object
    sharedPtr1->display();
    sharedPtr2->display();

    // The object is destroyed when the last shared_ptr goes out of scope
    // In this case, it will be destroyed when the sharedPtr2 goes out of scope
}

int main() {
    // Demonstrating unique_ptr
    uniquePointerDemo();

    // Demonstrating shared_ptr
    sharedPointerDemo();

    return 0;
}
