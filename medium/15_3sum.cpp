#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> ans;

    for(int i=0; i<nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }

    for(const auto triplets : ans)
        result.push_back(triplets);

    return result;
}

int main(){
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;

    cout << "Input: ";
    for(const auto x : input)
        cout << x << " ";
    cout << endl;

    result = threesum(input);

    cout << "Output: ";
    for(const auto x : result){
        cout << "[";
        for(const auto y : x){
            cout << y << " ";
        }
        cout << "] ";
    }
    cout << endl;
}