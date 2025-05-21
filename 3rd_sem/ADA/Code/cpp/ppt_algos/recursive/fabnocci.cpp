#include<iostream>
using namespace std;

int fabonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    }else{
        return fabonacci(n-1)+fabonacci(n-2);
    }
}
int main(){

    int n = 6;

    cout<<n<<" Element of fabonacci : "<<fabonacci(n);

    return 0;
}