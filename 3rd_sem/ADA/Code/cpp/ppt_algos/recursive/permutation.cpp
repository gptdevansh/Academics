#include<iostream>
#include<algorithm>
using namespace std;

void perm(int a[],int k,int n){
    if(k == n){
        for(int i = 0; i < n; ++i){
            cout<<a[i]<<" ";
        }cout<<endl;
    }else{
        for(int i = k; i < n; ++i){
            swap(a[i], a[k]);
            perm(a, k+1, n);
            swap(a[i], a[k]);
        }
    }
}
int main(){
    int a[] = {1, 2, 3, 4};
    int k = 0;
    int n = 4;

    perm(a, k, n);


    return 0;
}