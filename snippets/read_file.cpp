/*
Explanation:
Functions for reading and writing text files:
readFileLineByLine: Reads and prints each line of the file.
readFileCharacterByCharacter: Reads and prints the file character by character.
writeToFile: Writes multiple lines of text to a file.
appendToFile: Appends data to the existing file.
Binary file operations:
writeBinaryFile: Writes binary data (an integer in this case) to a file using ios::binary.
readBinaryFile: Reads binary data (an integer) from a binary file.
How to Use:
Provide a valid file path in the filename and binaryFilename variables.
This program demonstrates several file operations, from reading text and binary files to appending and writing data.
The program writes and reads data from both text and binary files, and it shows how to handle file I/O operations in a variety of ways.
You can modify filename and binaryFilename to match the files you are working with. Let me know if you need further adjustments!
*/

#include <iostream>
#include <fstream>
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
        // Print each line from the file
        cout << line << endl;
    }
    
    file.close();  // Close the file when done
}

// Function to read a file character by character
void readFileCharacterByCharacter(const string& filename) {
    ifstream file(filename);  // Open the file for reading
    
    if (!file.is_open()) {
        cout << "Could not open the file for reading!" << endl;
        return;
    }
    
    char ch;
    while (file.get(ch)) {  // Read one character at a time
        cout << ch;  // Print the character
    }
    
    file.close();  // Close the file when done
}

// Function to write to a text file
void writeToFile(const string& filename) {
    ofstream file(filename);  // Open the file for writing
    
    if (!file.is_open()) {
        cout << "Could not open the file for writing!" << endl;
        return;
    }
    
    // Write some text to the file
    file << "Hello, this is a test file!" << endl;
    file << "We are writing multiple lines of text." << endl;
    
    file.close();  // Close the file when done
    cout << "Data written to file successfully!" << endl;
}

// Function to append data to a file
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);  // Open the file in append mode
    
    if (!file.is_open()) {
        cout << "Could not open the file for appending!" << endl;
        return;
    }
    
    // Append some text to the file
    file << "This text is appended to the file." << endl;
    file << "We are appending a second line." << endl;
    
    file.close();  // Close the file when done
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

int main() {
    string filename = "read_file_example.txt";  // Text file for reading and writing
    string binaryFilename = "read_file_example";  // Binary file for reading and writing

    // Read the file line by line
    cout << "Reading file line by line:" << endl;
    readFileLineByLine(filename);
    cout << endl;

    // Read the file character by character
    cout << "Reading file character by character:" << endl;
    readFileCharacterByCharacter(filename);
    cout << endl;

    // Write some data to a file
    cout << "Writing to a text file:" << endl;
    writeToFile(filename);
    cout << endl;

    // Append data to a file
    cout << "Appending to the text file:" << endl;
    appendToFile(filename);
    cout << endl;

    // Write binary data to a file
    cout << "Writing binary data to file:" << endl;
    writeBinaryFile(binaryFilename);
    cout << endl;

    // Read binary data from a file
    cout << "Reading binary data from file:" << endl;
    readBinaryFile(binaryFilename);

    return 0;
}
