#include <iostream>
using namespace std;

int main() {
    int n, m;
    // This calculates nCm
    cout <<"Enter the value of n and m : ";
    cin >> n >> m;
    if(n<0 || m < 0){
        cerr<<"Both should positive..."<<endl;
        return 1;
    }
    if(m > n){
        cerr<<"'m' should less than 'n'..."<<endl;
        return 1;
    }
    int nCr[m + 1] = {0};
    nCr[0] = 1;           // Base case: C(n, 0) = 1

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, m); j > 0; j--) {
            nCr[j] = nCr[j] + nCr[j - 1];
        }
    }

    cout << n << "C"<< m <<" : "<< nCr[m] << endl;

    return 0;
}
