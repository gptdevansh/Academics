#include <iostream>
using namespace std;

void truthTable(int n) {
    int combinations = 1 << n;

    // Print header
    cout<<endl;
    for (int j = 1; j <= n; j++) {
        cout << "X" << j << "_     ";
    }cout << endl<<endl;

    // Generate truth table
    for (int i = 0; i < combinations; i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << ((i >> j) & 1) << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int variables;
    cout << "Enter number of variables: ";
    cin >> variables;

    truthTable(variables);

    return 0;
}
