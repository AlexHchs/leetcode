#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int index = 0;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] > nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}

int main(){
    vector<int> input = {2,0,2,1,1,0};

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    sortColors(input);

    cout << "Output: ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}