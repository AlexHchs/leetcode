#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
    int result;
    int diff = INT_MAX;

    for(int i=0; i<nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == target){
                return target;
            }
            if(abs(nums[i] + nums[j] + nums[k]) < diff){
                diff = abs(nums[i] + nums[j] + nums[k]);
                result = nums[i] + nums[j] + nums[k];
            }
            else if(nums[i]+nums[j]+nums[k] > target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    
    return result;
}

int main(){
    vector<int> input = {-1, 2, 1, 4};
    int target = 1;
    int result;

    cout << "Input: ";
    for(const auto num : input)
        cout << num << " ";
    cout << ", target = " << target << endl;

    result = threeSumClosest(input, target);

    cout << "Output: " << result << endl;
}