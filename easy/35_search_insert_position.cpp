#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int end, vector<int>& nums, int target){
    int mid = (start + end) / 2;

    if(start > end)
        return start;

    if(nums[mid] == target){
        return mid;
    }
    else if(nums[mid] < target)
        return binarySearch(mid+1, end, nums, target);
    else
        return binarySearch(start, mid-1, nums, target);
}

int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int result;

    result = binarySearch(start, end, nums, target);

    return result;
}

int main(){
    vector<int> input = {1, 3, 5, 6};
    int target = 7;
    int result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", target = " << target << endl;

    result = searchInsert(input, target);

    cout << "Output: " << result << endl;

    return 0;
}