#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int locate = 0, ptr = 0;

    while(ptr != nums.size()){
        if(nums[ptr] != val){
            nums[locate] = nums[ptr];
            ptr++;
            locate++;
        }
        else{
            ptr++;
        }
    }

    return locate;
}

int main(){
    vector<int> input = {0, 1, 2, 2, 3, 0, 4, 2};
    int target = 2;
    int result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", val = " << target << endl;

    result = removeElement(input, target);

    cout << "Output: ";
    for(int i=0; i<result; i++){
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}