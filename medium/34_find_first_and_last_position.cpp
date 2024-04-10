#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target){
    vector<int> result = {-1, -1};
    int left = 0, right = nums.size() - 1;
    bool find = false;

    if(nums.size() == 0){
        return result;
    }

    while(left <= right){
        int mid = (left + right) / 2;

        if(nums[mid] == target){
            find = true;
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(find == true){
        result[0] = left;
    }

    left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;

        if(nums[mid] == target){
            find == true;
            left = mid + 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(find == true){
        result[1] = right;
    }

    return result;
}

int main(){
    vector<int> input = {5, 7, 7, 8, 8, 10};
    vector<int> result;
    int target = 10;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", target = " << target << endl;

    result = searchRange(input, target);

    cout << "Output: ";
    for(const auto x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}