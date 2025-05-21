#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
void selectionSort(vector<int> &a){
    int n = a.size();

    for(int i = 0; i < n-1; ++i){
        int j = i;

        for(int k = i+1; k < n; ++k){
            if(a[j] > a[k]){
                j = k;
            }
        }

        if(j!=i){
            swap(a[j], a[i]);
        }
    }
}

void print(const vector<int> &a);

int main(){
    vector<int> a{2, 9, 4, 8, 5, 1, 3};

    print(a);

    selectionSort(a);
    
    print(a);

    return 0;
}

void print(const vector<int> &a){
    int n = a.size();
    for(int k = 0; k < n; ++k) {
            cout << a[k] << " ";
        }
        cout << endl;
}