#include<iostream>
using namespace std;

unsigned int fact(int n){
    if(n < 3){
        return n;
    }else{
        return n*fact(n-1);
    }
}
int main(){

    int n = -2;

    cout<<" Fact value of "<<n<<" : "<<fact(n);

    return 0;
}