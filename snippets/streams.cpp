#include <iostream>
#include <fstream>
#include <sstream>  // For stringstream
#include <string>
using namespace std;

// Function to read a text file line by line
void readFileLineByLine(const string& filename) {
    ifstream file(filename);  // Open the file for reading
    
    if (!file.is_open()) {
        cout << "Could not open the file for reading!" << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

// Function to write to a text file
void writeToFile(const string& filename) {
    ofstream file(filename);  // Open the file for writing
    
    if (!file.is_open()) {
        cout << "Could not open the file for writing!" << endl;
        return;
    }
    
    file << "Hello, this is a test file!" << endl;
    file << "We are writing multiple lines of text." << endl;
    
    file.close();
    cout << "Data written to file successfully!" << endl;
}

// Function to append data to a file
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);  // Open the file in append mode
    
    if (!file.is_open()) {
        cout << "Could not open the file for appending!" << endl;
        return;
    }
    
    file << "This text is appended to the file." << endl;
    file << "We are appending a second line." << endl;
    
    file.close();
    cout << "Data appended to file successfully!" << endl;
}

// Function to write binary data to a file
void writeBinaryFile(const string& filename) {
    ofstream file(filename, ios::binary);  // Open the file in binary mode
    
    if (!file.is_open()) {
        cout << "Could not open the file for writing!" << endl;
        return;
    }

    int data = 123456789;  // Some data to write
    file.write(reinterpret_cast<char*>(&data), sizeof(data));  // Write binary data
    
    file.close();
    cout << "Binary data written to file successfully!" << endl;
}

// Function to read binary data from a file
void readBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);  // Open the file in binary mode
    
    if (!file.is_open()) {
        cout << "Could not open the file for reading!" << endl;
        return;
    }
    
    int data;
    file.read(reinterpret_cast<char*>(&data), sizeof(data));  // Read binary data
    
    cout << "Data read from binary file: " << data << endl;
    
    file.close();
}

// Function to demonstrate stringstream usage for reading
void readFromStringstream() {
    stringstream ss;  // Create a stringstream object
    ss.str("This is a test stringstream example.");  // Initialize with some text
    
    string word;
    while (ss >> word) {  // Read word by word
        cout << word << endl;
    }
}

// Function to demonstrate stringstream usage for writing
void writeToStringstream() {
    stringstream ss;
    ss << "This is a stringstream test for writing.";
    ss << " We are writing data to a stringstream object.";

    // Convert the stringstream contents to a string and print
    cout << "Stringstream contents: " << ss.str() << endl;
}

// Function to demonstrate istringstream for reading from a string
void readFromIstringstream() {
    string text = "100 200 300 400";
    istringstream ss(text);  // Create an input stringstream initialized with text

    int num;
    while (ss >> num) {  // Extract numbers from the string
        cout << "Number: " << num << endl;
    }
}

// Function to demonstrate ostringstream for writing to a string
void writeToOstringstream() {
    ostringstream ss;
    ss << "Writing numbers to stringstream: ";
    for (int i = 1; i <= 5; ++i) {
        ss << i << " ";
    }

    // Get the contents of the ostringstream
    cout << "Ostringstream contents: " << ss.str() << endl;
}

int main() {
    string filename = "read_file_example.txt";  // File for reading and writing
    string binaryFilename = "read_file_example.dat";  // Binary file for reading and writing
    
    // File stream examples
    cout << "Reading file line by line:" << endl;
    readFileLineByLine(filename);
    cout << endl;
    
    cout << "Writing to a text file:" << endl;
    writeToFile(filename);
    cout << endl;

    cout << "Appending to the text file:" << endl;
    appendToFile(filename);
    cout << endl;

    // Binary file operations
    cout << "Writing binary data to file:" << endl;
    writeBinaryFile(binaryFilename);
    cout << endl;

    cout << "Reading binary data from file:" << endl;
    readBinaryFile(binaryFilename);
    cout << endl;

    // String stream examples
    cout << "Reading from a stringstream:" << endl;
    readFromStringstream();
    cout << endl;

    cout << "Writing to a stringstream:" << endl;
    writeToStringstream();
    cout << endl;

    // Istringstream (input from string) and Ostringstream (output to string)
    cout << "Reading from an istringstream:" << endl;
    readFromIstringstream();
    cout << endl;

    cout << "Writing to an ostringstream:" << endl;
    writeToOstringstream();
    
    return 0;
}
