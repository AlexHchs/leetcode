#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int i = 0;
    vector<vector<int>> result;

    while(i < intervals.size() && intervals[i][1] < newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }

    while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
        newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
        i++;
    }
    result.push_back(newInterval);

    while(i < intervals.size()){
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main(){
    vector<int> newInterval = {4,8};
    vector<vector<int>> input = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> result;

    cout << "Input: intervals = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "], new interval = [";
    for(const auto x : newInterval){
        cout << x << " ";
    }
    cout << "]" << endl;

    result = insert(input, newInterval);

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