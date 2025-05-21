#include<iostream>
using namespace std;

int horner(int a[], int n, int X0){
    int result = 0;

    for(int i = n; i > 0; --i){
        result = (result + a[i])*X0;
    }

    result += a[0];
    return result;
}

int main(){
    int a[] = {9, 0, 1, 2}; // ax3 + bx2 + cx + d
    int n = 3; 
    int X0 = 2; // X = 2;
 
    int mul = horner(a, n, X0);

    cout<<"multiplied value : "<<mul;

    return 0;
}