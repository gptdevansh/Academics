#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > sub_arrays(const vector<int> &nums );

void displayVector(const std::vector<int>& vec);

int main(){
    vector< int > nums{1 , 2 , 3, 4};
    vector< vector<int> > arrays = sub_arrays( nums );
    for(auto& vec : arrays){
        displayVector(vec);
    }

    return 0;
}

vector< vector<int> > sub_arrays(const vector<int> &nums ){
    
    int n = nums.size(), sub_arrays_no = 1<<n;
    vector< vector<int> > ans;
    
    for(int num = 0; num < sub_arrays_no; ++num){
        vector<int>sub_array;
        
        for(int j = 0; j < n; ++j){
            if(num&(1<<j)){
                sub_array.push_back(nums[j]);
            }
        }
        
        ans.push_back(sub_array);
    }
    return ans;
    
}

void displayVector(const std::vector<int>& vec) {
    for (int element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}