
#include<iostream>
#include<algorithm>

using namespace std;

void bubble_portion_sort(int *list, int n);
void print_arr(const int list[], int n);
void insert_arr(int *list,int n);
bool is_even(int num);
bool is_odd(int num);

int main(){

    // 2, 1, 8, 4, 5, 3
    // cout<<"Enter size of list : ";
    int n = 6;  
    // cin>>n;
    int *list = new int[n];
    list[0] = 2, 
    list[1] = 1, 
    list[2] = 8, 
    list[3] = 4,
    list[4] = 5, 
    list[5] = 3;
    cout<<endl;
    print_arr(list, n);

    bubble_portion_sort(list, n);
    print_arr(list, n);

    delete[] list;
    return 0;
    
}

// First even no. in decreasing order and odd no. are in increasing order :-
void bubble_portion_sort(int *list, int n){
    if(n == 1)return;

    for(int i = 0; i < n - 1; ++i){
        bool is_sort = false;
        for(int j = 0; j < n - i - 1; ++j){
            if( ((is_even(list[j]) && is_even(list[j+1])) && (list[j] < list[j+1])) ||
                ((is_odd(list[j]) && is_odd(list[j+1])) && (list[j] > list[j+1])) ||
                ((is_odd(list[j]) && is_even(list[j+1])) && (list[j] < list[j+1])) ){
                    swap(list[j], list[j+1]);
                    is_sort = true;
            }
        }
        if(!is_sort)break;
    }
}

void insert_arr(int *list,int n){
    cout<<"Enter "<<n<<" no. : "<<endl;
    for(int i = 0; i < n; ++i){
        cin>>list[i];
    }    

}

void print_arr(const int list[], int n){
    cout<<"Elements : "<<endl;
    for(int i = 0; i < n; ++i){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

bool is_even(int num){
    return num%2 == 0;
}

bool is_odd(int num){
    return num%2 != 0;
}