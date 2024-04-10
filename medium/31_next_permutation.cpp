#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    // next_permutation(nums.begin(), nums.end());
    /* ----------------------------------------- */

    int index = -1, n = nums.size();
    
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    for(int i=n-1; i>=index && index!=-1; i--){
        if(nums[i] > nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1, nums.end());
}

int main(){
    vector<int> input = {1, 3, 2};

    cout << "Input: nums = ";
    for(auto x : input){
        cout << x << " ";
    }
    cout << endl;

    nextPermutation(input);

    cout << "Output: ";
    for(auto x : input){
        cout << x << " ";
    }
    cout << endl;
}