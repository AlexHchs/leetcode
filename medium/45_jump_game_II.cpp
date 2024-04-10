#include <bits/stdc++.h>
using namespace std;

int solve_jump(vector<int>& nums, int index, int jump){
    int destination = nums.size() - 1;
    int longest_path = 0, next_path = 0;
    
    jump++;
    if(index >= destination || index+nums[index] >= destination){
        return jump;
    }

    for(int i=1; i<=nums[index]; i++){
        if(i+nums[index+i] > longest_path){
            longest_path = i+nums[index+i];
            next_path = i;
        }
    }

    return solve_jump(nums, index+next_path, jump);
}

int jump(vector<int>& nums) {
    int result;

    if(nums.size() == 1){
        return 0;
    }

    result = solve_jump(nums, 0, 0);
    
    return result;
}

int main(){
    vector<int> input = {2, 3, 0, 1, 4};
    int result;

    cout << "Input: ";
    for(auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = jump(input);

    cout << "Output: " << result << endl;

    return 0;
}