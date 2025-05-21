#include <iostream>
#include <string>

using namespace std;

// Function to find all valid shifts where the pattern matches the text
void naivePatternMatching(string &text, string &pattern) {
    int n = text.length();    // Length of the text
    int m = pattern.length(); // Length of the pattern

    cout<<endl;
    for (int shift = 0; shift <= n - m; shift++) {
        bool match = true;

        // Check if the pattern matches at this shift
        for (int i = 0; i < m; i++) {
            if (text[shift + i] != pattern[i]) {
                match = false;
                break;
            }
        }

        // If a match is found, print the shift
        if (match) {
            cout << "Pattern found at shift " << shift << endl;
        }
    }
}

int main() {
    string text, pattern;

    // Input the text and pattern
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Call the function
    naivePatternMatching(text, pattern);

    return 0;
}
