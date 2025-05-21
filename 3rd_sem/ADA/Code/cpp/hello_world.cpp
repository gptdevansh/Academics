#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int *arr = new int[5];
    fill_n(arr, 5, 0);
    std::cout<<arr[0];
    return 0;
}
