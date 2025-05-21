#include <iostream>
#include <climits>
using namespace std;


// Function to print the optimal multiplication path
void path(int i, int j, int **p) {
    if (i == j) {
        cout << "A" << i;  // If i == j, it's just one matrix
        return;
    }
    int k = p[i][j];  // The optimal split point
    cout << "(";
    path(i, k, p);  // Recursively print the left subchain
    path(k + 1, j, p);  // Recursively print the right subchain
    cout << ")";
}

// Function to calculate the minimum number of multiplications
int multiply(int arr[], int n) {
    // Dynamically allocate 2D arrays for storing the results
    int **mat = new int*[n+1];
    int **p = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        mat[i] = new int[n+1]();
        p[i] = new int[n+1]();
    }

    // Matrix chain multiplication dynamic programming solution
    for (int d = 1; d < n; d++) {  // d is the chain length
        for (int i = 1; i <= n - d; i++) {  // i is the start index
            int j = i + d;  // j is the end index

            mat[i][j] = INT_MAX;  // Set the initial value to infinity

            // Check every possible split point k to find the minimum number of multiplications
            for (int k = i; k < j; k++) {
                int q = mat[i][k] + mat[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < mat[i][j]) {
                    mat[i][j] = q;
                    p[i][j] = k;
                }
            }
        }
    }

    // Printing the optimal multiplication order
    cout << "Optimal multiplication order: ";
    path(1, n, p);
    cout << endl;

    // Return the minimum number of scalar multiplications required
    int result = mat[1][n];

    // Free dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        delete[] mat[i];
        delete[] p[i];
    }
    delete[] mat;
    delete[] p;

    return result;
}



int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n + 1];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];  // Matrix dimensions should be entered
    }

    cout << "Minimum number of multiplications required: " << multiply(arr, n) << endl;
    return 0;
}
