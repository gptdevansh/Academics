#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;  // 2D array to hold matrix data
    int size = 0;    // Size of the matrix (n x n)

public:
    // Constructor to initialize matrix of given size
    Matrix(int n) {
        size = n;
        data = new int*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new int[size];
            // Initialize matrix elements to 0
            for (int j = 0; j < size; j++) {
                data[i][j] = 0;
            }
        }
    }
    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Function to input matrix values
    void input() {
        cout << "Enter the matrix elements : ";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Function to output matrix values
    void output() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix operator-(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication (Base case for 2x2)
    Matrix operator*(const Matrix& other) const {
        Matrix result(size);
        if (size == 2) {
            result.data[0][0] = data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0];
            result.data[0][1] = data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1];
            result.data[1][0] = data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0];
            result.data[1][1] = data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1];
        }
        return result;
    }

    // Strassen's Algorithm
    Matrix strassenMultiply(const Matrix& other) const {
        if (size == 2) {
            return (*this) * other;  // Base case for 2x2 matrices
        }

        int halfSize = size / 2;

        Matrix A11(halfSize), A12(halfSize), A21(halfSize), A22(halfSize);
        Matrix B11(halfSize), B12(halfSize), B21(halfSize), B22(halfSize);

        // Divide the matrices into submatrices
        for (int i = 0; i < halfSize; i++) {
            for (int j = 0; j < halfSize; j++) {
                A11.data[i][j] = data[i][j];
                A12.data[i][j] = data[i][j + halfSize];
                A21.data[i][j] = data[i + halfSize][j];
                A22.data[i][j] = data[i + halfSize][j + halfSize];

                B11.data[i][j] = other.data[i][j];
                B12.data[i][j] = other.data[i][j + halfSize];
                B21.data[i][j] = other.data[i + halfSize][j];
                B22.data[i][j] = other.data[i + halfSize][j + halfSize];
            }
        }

        // Compute P1 to P7
        Matrix P1 = (A11 + A12).strassenMultiply(B22 - B12);
        Matrix P2 = (A11 + A12).strassenMultiply(B11);
        Matrix P3 = (A21 + A22).strassenMultiply(B11);
        Matrix P4 = A22.strassenMultiply(B21 - B11);
        Matrix P5 = (A11 + A22).strassenMultiply(B11 + B22);
        Matrix P6 = (A12 - A22).strassenMultiply(B21 + B22);
        Matrix P7 = (A11 - A21).strassenMultiply(B11 + B12);

        // Combine results into a single matrix
        Matrix C(size);
        Matrix temp(halfSize), temp2(halfSize);

        // Calculate each block of the resultant matrix C
        temp = P5 + P4 - P2 + P6;
        for (int i = 0; i < halfSize; i++) {
            for (int j = 0; j < halfSize; j++) {
                C.data[i][j] = temp.data[i][j];  // Top-left block
            }
        }

        temp = P1 + P2;
        for (int i = 0; i < halfSize; i++) {
            for (int j = 0; j < halfSize; j++) {
                C.data[i][j + halfSize] = temp.data[i][j];  // Top-right block
            }
        }

        temp = P3 + P4;
        for (int i = 0; i < halfSize; i++) {
            for (int j = 0; j < halfSize; j++) {
                C.data[i + halfSize][j] = temp.data[i][j];  // Bottom-left block
            }
        }

        temp = P1 + P5 - P3 - P7;
        for (int i = 0; i < halfSize; i++) {
            for (int j = 0; j < halfSize; j++) {
                C.data[i + halfSize][j + halfSize] = temp.data[i][j];  // Bottom-right block
            }
        }

        return C;
    }


};

bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n = 0; // Matrix size (must be 2^k)
    cout<<"Enter size of matrices : ";
    cin>>n;
    if (!isPowerOfTwo(n)) {
            cerr<<"Size of matrix must be a power of 2.";
            exit(1);
        }
    Matrix A(n), B(n);

    cout << "Matrix A:" << endl;
    A.input();
    cout << "Matrix B:" << endl;
    B.input();

    // Strassen's multiplication
    Matrix C = A.strassenMultiply(B);

    cout << "Resultant Matrix C (A * B):" << endl;
    C.output();

    return 0;
}
