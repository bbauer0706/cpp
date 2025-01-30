#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // For std::sort
using namespace std;

void demonstrateVector() {
    // Create a vector of integers
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Print original vector
    cout << "Original vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    
    // Adding elements to the vector
    vec.push_back(60);  // Adds 60 at the end of the vector
    vec.push_back(70);  // Adds 70 at the end of the vector
    
    // Removing the last element using pop_back
    vec.pop_back();  // Removes the last element (70)
    
    cout << "Vector after adding and removing elements: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Sorting the vector
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void demonstrateUnorderedMap() {
    // Create an unordered_map where the key is a string and the value is an integer
    unordered_map<string, int> ageMap;
    
    // Adding elements to the unordered_map
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 35;
    
    // Printing the elements of the unordered_map
    cout << "Unordered map: " << endl;
    for (const auto& pair : ageMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Checking if a key exists
    if (ageMap.find("Alice") != ageMap.end()) {
        cout << "Alice's age is " << ageMap["Alice"] << endl;
    }
    
    // Modifying a value
    ageMap["Bob"] = 32;  // Bob's age is updated
    
    // Removing an element by key
    ageMap.erase("Charlie");
    
    cout << "Updated unordered map after modification and removal: " << endl;
    for (const auto& pair : ageMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    // Demonstrating vector operations
    demonstrateVector();
    
    // Demonstrating unordered_map operations
    demonstrateUnorderedMap();
    
    return 0;
}