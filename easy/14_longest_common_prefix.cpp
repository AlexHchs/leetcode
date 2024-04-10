#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    sort(strs.begin(), strs.end());

    if(strs.size() == 1){
        return strs[0];
    }
    if(strs[0] == strs[strs.size()-1]){
        return strs[0];
    }

    for(int i=0; i<strs[0].length(); i++){
        if(strs[strs.size()-1][i] != strs[0][i])
            return strs[0].substr(0, i);
    }

    return strs[0];
}

int main(){
    vector<string> input = {"flower", "flow", "flight"};
    string result;

    cout << "Input: ";
    for(const auto word : input){
        cout << word << " ";
    }
    cout << endl;

    result = longestCommonPrefix(input);

    cout << "Output: " << result << endl;
}