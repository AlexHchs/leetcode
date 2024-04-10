#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>& nums, int target){
    int nums_length = nums.size();
    int left = 0, right = nums_length - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(nums[mid] == target){
            return mid;
        }
        
        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> input = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    int result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", target = " << target << endl;

    result = Search(input, target);

    cout << "Output: " << result;

    return 0;
}