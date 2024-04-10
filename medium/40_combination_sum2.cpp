#include <bits/stdc++.h>
using namespace std;

void solve_combination(vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates, int target, int index){
    if(target == 0){
        result.push_back(temp);
        return;
    }

    int i = index;

    while(index < candidates.size() && target - candidates[index] >= 0){
        if(index > i && candidates[index] == candidates[index-1]){
            index++;
            continue;
        }

        temp.push_back(candidates[index]);
        solve_combination(result, temp, candidates, target-candidates[index], index+1);
        temp.pop_back();
        index++;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());
    
    solve_combination(result, temp, candidates, target, 0);

    return result;
}

int main(){
    vector<vector<int>> result;
    vector<int> input = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    cout << "Input: nums = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << ", target = " << target << endl;

    result = combinationSum2(input, target);

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