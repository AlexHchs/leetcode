#include <bits/stdc++.h>
using namespace std;

void permutation(set<vector<int>>& permute, vector<int>& nums, int index){
    int nums_length = nums.size() - 1;

    if(index == nums_length){
        permute.insert(nums);
        return;
    }

    permutation(permute, nums, index+1);
    for(int i=index+1; i<=nums_length; i++){
        swap(nums[index], nums[i]);
        permutation(permute, nums, index+1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    set<vector<int>> permute;
        
    permutation(permute, nums, 0);
    for(const auto triplets : permute){
        result.push_back(triplets);
    }

    return result;
}

int main(){
    vector<int> input = {1, 1, 3};
    vector<vector<int>> result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = permuteUnique(input);

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