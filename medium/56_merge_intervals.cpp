#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int intervals_length = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    for(const auto interval : intervals){
        if(result.empty() || result.back()[1] < interval[0]){
            result.push_back(interval);
        }
        else{
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }

    return result;
}

int main(){
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result;

    cout << "Input: intervals = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    result = merge(input);

    cout << "Output: [";
    for(const auto line : result){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}