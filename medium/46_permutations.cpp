#include <bits/stdc++.h>
using namespace std;

void permutation(vector<vector<int>>& result, vector<int>& nums, int index){
    int nums_length = nums.size() - 1;

    if(index == nums_length){
        result.push_back(nums);
        return;
    }

    permutation(result, nums, index+1);
    for(int i=index+1; i<=nums_length; i++){
        swap(nums[index], nums[i]);
        permutation(result, nums, index+1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
        
    permutation(result, nums, 0);

    return result;
}

int main(){
    vector<int> input = {1, 2, 3};
    vector<vector<int>> result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = permute(input);

    cout << "Output: [" << endl;
    for(const auto line : result){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    return 0;
}