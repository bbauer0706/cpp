#include <iostream>
#include <memory>  // For smart pointers
#include <vector>

using namespace std;

/*
Key Differences in Output:
Unique Pointer:

Ownership is transferred using std::move() frozm uniquePtr1 to uniquePtr2, and after the move, uniquePtr1 becomes nullptr. The object is destroyed when uniquePtr2 goes out of scope at the end of uniquePtrExample().
Shared Pointer:

Both sharedPtr1 and sharedPtr2 share ownership of the same object. The reference count is shown to be 2. The object is only destroyed when the last shared_ptr (either sharedPtr1 or sharedPtr2) goes out of scope.
Summary of Key Differences:
Ownership:

unique_ptr: Exclusive ownership (one owner only).
shared_ptr: Shared ownership (multiple owners possible).
Memory Management:

unique_ptr: No reference counting, lightweight.
shared_ptr: Reference counting, heavier due to atomic operations.
Use Case:

unique_ptr: When you want a single owner, and you want the resource to be deleted as soon as the owner goes out of scope.
shared_ptr: When multiple owners need to share the resource, and you want it deleted when the last owner goes out of scope.
In practice:

Use unique_ptr when the ownership of an object is clear and exclusive.
Use shared_ptr when multiple parts of your program need to share ownership of an object.
*/

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
