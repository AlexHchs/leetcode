#include <bits/stdc++.h>
using namespace std;

void solve_canJump(vector<int>& nums, int index, bool& result){
    int destination = nums.size() - 1;
    int longest_path = 0, next_path = 0;

    if(index >= destination || index+nums[index] >= destination){
        result = true;
        return;
    }
    if(nums[index] == 0){
        return;
    }

    for(int i=1; i<=nums[index]; i++){
        if(i+nums[index+i] > longest_path){
            longest_path = i+nums[index+i];
            next_path = i;
        }
    }

    solve_canJump(nums, index+next_path, result);
}

bool canJump(vector<int>& nums) {
    bool result = false;

    solve_canJump(nums, 0, result);

    return result;
}

int main(){
    vector<int> input = {2,2,1,0,4};
    bool result;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = canJump(input);

    cout << "Output: " << ((result == 0) ? "false" : "true") << endl;

    return 0;
}