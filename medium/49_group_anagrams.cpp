#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    for(const auto x : strs){
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }

    for(const auto x : mp){
        result.push_back(x.second);
    }

    return result;
}

int main(){
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result;

    cout << "Input: strs = ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = groupAnagrams(input);

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