#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int ptr = 1, locate = 1, temp = nums[0];

    while(ptr < nums.size()){
        if(nums[ptr] == temp)
            ptr++;
        else{
            temp = nums[ptr];
            nums[locate] = temp;
            ptr++;
            locate++;
        }
    }

    return locate;
}

int main(){
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result;

    cout << "Input: ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = removeDuplicates(input);

    cout << "Output: ";
    for(int i=0; i<result; i++){
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}