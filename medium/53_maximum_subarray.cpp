#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums){
    int current_max = nums[0], maxSum = nums[0];

    for(int i=1; i<nums.size(); i++){
        current_max = max(current_max+nums[i], nums[i]);
        maxSum = max(current_max, maxSum);
    }

    return maxSum;
}

int main(){
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    int result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = maxSubArray(input);

    cout << "Output: " << result << endl;

    return 0;
}