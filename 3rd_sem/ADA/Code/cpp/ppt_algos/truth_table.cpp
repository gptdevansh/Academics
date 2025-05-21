#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void truth_table(int &n) {
    vector<bool> a(n, false);  // Create a Boolean array initialized to False

    for (int i = 0; i < pow(2, n); ++i) {
        int m = i, j = n;

        // Reset the array a[] to False for each iteration
        fill(a.begin(), a.end(), false);

        // Binary conversion of i into a[]
        while (m != 0) {
            if (m & 1) {
                a[j - 1] = true;  // Set True if last bit of m is 1
            } else {
                a[j - 1] = false; // Set False if last bit of m is 0
            }
            m >>= 1;  // Right shift m by 1 bit
            --j;      // Move to the next position in a[]
        }

        // Print the current row of the truth table
        for (int k = 0; k < n; ++k) {
            cout << (a[k] ? 'T' : 'F') << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 2;  // You can modify n to any value
    cout << "Truth table for " << n << " Boolean variables:" << endl;
    truth_table(n);
    return 0;
}
