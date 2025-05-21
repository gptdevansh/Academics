#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string removeDuplicate(const string &str) {
    unordered_map<char, int> umap;
    string result;

    // Traverse through the string
    for (char c : str) {
        if (umap[c] < 1) { // Check if the character has appeared before
            umap[c]++;
            result += c;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "\nEnter the String: ";
    cin >> input;

    cout << "String after removing duplicates: " << removeDuplicate(input) << endl;

    return 0;
}
