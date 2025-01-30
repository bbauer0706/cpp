#include <iostream>
#include <functional> 

using namespace std;

void applyFunction(int x, const function<int(int)>& func) {
    cout << "Result: " << func(x) << endl;
}

int add_function(int a, int b) {
    return a + b;
}

// A function that accepts a function pointer as a parameter
void executeFunction(int x, int y, int (*func)(int, int)) {
    cout << "Result: " << func(x, y) << endl;
}

// A function that returns a lambda
function<int(int)> getMultiplier(int multiplier) {
    return [multiplier](int x) -> int { return x * multiplier; };
}

int main() {

    // Simple lambda that adds two numbers
    auto add = [](int a, int b) -> int { return a + b; };
    
    // Call the lambda
    cout << "Sum: " << add(5, 3) << endl;
    
    int a = 5, b = 3;
    
    // Capture a and b by value
    auto add_capture = [a, b]() -> int { return a + b; };
    
    // Capture by reference and modify variables
    auto modifyAndPrint = [&a, &b]() {
        a += 10;
        b += 5;
        cout << "Modified values: a = " << a << ", b = " << b << endl;
    };
    
    // Call the lambda expressions
    cout << "Sum: " << add_capture() << endl;
    modifyAndPrint();

    int multiplier = 3;

    // Pass a lambda as a parameter
    applyFunction(5, [multiplier](int n) -> int { return n * multiplier; });

    // Pass another lambda as a parameter
    applyFunction(10, [](int n) -> int { return n + 100; });

    int (*addPtr)(int, int) = add;  // Declare a function pointer and assign it to 'add'

    // Call executeFunction using the function pointer
    executeFunction(5, 10, addPtr);

    // Get a lambda that multiplies by 5
    auto multiplier_from_function = getMultiplier(5);

    // Use the returned lambda
    cout << "Multiplying 10 by 5: " << multiplier_from_function(10) << endl;

    return 0;
}
 