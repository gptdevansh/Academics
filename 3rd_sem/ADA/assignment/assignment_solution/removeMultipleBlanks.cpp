#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to remove extra spaces from a string
string removeExtraSpaces(const string &input) {
    string result = "";
    bool spaceFound = false;

    for (char c : input) {
        if (c != ' ') {
            result += c;  // Add non-space character
            spaceFound = false;
        } else if (!spaceFound) {
            result += ' ';  // Add one space if it's the first space
            spaceFound = true;
        }
    }

    return result;
}

int main() {
    string filePath = "input.txt";  // File name

    // Open the file for reading
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    string fileContent = "";

    // Read the file line by line
    while (getline(inFile, line)) {
        fileContent += line + "\n";  // Append each line to the content
    }

    inFile.close();  // Close the input file after reading

    // Remove extra spaces from the entire content
    string cleanedContent = removeExtraSpaces(fileContent);

    // Open the file again to overwrite it with the cleaned content
    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << cleanedContent;  // Write the cleaned content to the file

    outFile.close();  // Close the output file
    cout << "File processed successfully!" << endl;

    return 0;
}
