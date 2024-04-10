#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> umap; 
    for(int i=0; i<nums.size(); i++){
        int diff = target - nums[i];
        // Find the diff element whether in unordered map
        if(umap.find(diff) != umap.end()){
            result.push_back(umap[diff]);
            result.push_back(i);
            return result;
        }
        // If not, push the element into the unordered map
        umap[nums[i]] = i;
    }
    return result;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "Input: nums = ";
    for(const auto& n:nums)
        cout << n << " ";
    cout << ", Target = " << target << endl;

    cout << "Result = ";
    for(const auto& n:twoSum(nums, target))
        cout << n << " ";
    
    return 0;
}