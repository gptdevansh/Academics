#include<iostream>
using namespace std;

long long decimalToBinary(int d){
    if(d < 1){
        cerr<<" Must be positive integer "<<endl;
        exit(1);
    }
    long long b = 0, p = 1;

    while(d > 0){
        b += p*(d % 2);
        p *= 10;
        d >>= 1; 
    }

    return b;
}

int main(){

    int n = 11054;
    long long b = decimalToBinary(n);
    cout<<"Binary of "<<n<<" : "<< b <<endl;

    return 0;

}
