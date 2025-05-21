#include<iostream>
using namespace std;

int gcd(int n,int m){
    if(m%n == 0){
        return n;
    }else{
        return gcd(m%n, n);
    }
}
int main(){

    int n = 6;
    int m = 4;

    cout<<" GCD value of "<<n<<", "<<m<<" : "<<gcd(n, m);

    return 0;
}