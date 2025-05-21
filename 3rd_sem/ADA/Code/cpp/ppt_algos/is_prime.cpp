#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(const int &n){
    if( n < 2 ){
        return false;
    }
    int m = sqrt(n);

    for(int i = 2; i <= m; ++i ){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 79;

    if(is_prime(n)){
        cout<<n<<" is a prime no."<<endl;
    }else{
        cout<<n<<" is not a prime no."<<endl;
    }

    return 0;
}