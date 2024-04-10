#include <bits/stdc++.h>
using namespace std;

void solve_combination(vector<vector<int>>& result, vector<int>& candidates, vector<int> temp, int target, int index){
    if(index == candidates.size()){
        if(target == 0)
            result.push_back(temp);
        return;
    }

    if(candidates[index] <= target){
        temp.push_back(candidates[index]);
        solve_combination(result, candidates, temp, target-candidates[index], index);
        temp.pop_back();
    }
    solve_combination(result, candidates, temp, target, index+1);
}
    
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;

    solve_combination(result, candidates, temp, target, 0);

    return result;
}

int main(){
    vector<vector<int>> result;
    vector<int> input = {2, 3, 6, 7};
    int target = 7;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", target = " << target << endl;

    result = combinationSum(input, target);

    cout << "Output: ";
    for(const auto line : result){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << endl;
    

    return 0;
}