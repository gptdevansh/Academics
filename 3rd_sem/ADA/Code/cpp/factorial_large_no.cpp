#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int* Fact(int num);
int digit_in_fact(int num);
void print_arr(const int arr[], int n);

int main(){
    
    cout<<": To find factorial : "<<endl<<"Enter a no.: ";
    int num, d;
    cin>>num;

    d = digit_in_fact(num);
    int *arr = new int[d];

    arr = Fact(num);
    cout<<"Factorial of "<<num<<" : ";
    print_arr(arr, d);

    delete[] arr; 
    return 0;

}

int* Fact(int num){
    if( num < 0 ){
        cout<<"Number should greater than 0 : Fact. of negative no. does't exist. "<<endl;
        exit(1); // exit whole program
    }

    int d = digit_in_fact(num);
    int *arr = new int[d];

    // set all element 0  
    fill_n(arr, d, 0);
    // at once position set 1
    arr[d-1] = 1;

    for(int i = 2; i <= num; ++i){

        int carry = 0;

        for(int j = d-1; j >= 0; --j){

            int mul = arr[j]*i + carry;
            arr[j] = mul%10;
            carry = mul/10;
        }
    }
    return arr;
}


int digit_in_fact(int num){
    if( num < 0 )return 0;

    double digits = 0.0;

    //  log10(2) + log10(3)  ...  log10(n-1) + log10(n).
    for(int i = 2; i <= num; ++i){
        digits += log10(i);
    }
    return floor(digits) + 1;
}

void print_arr(const int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout<<arr[i];
    }cout<<endl;
}