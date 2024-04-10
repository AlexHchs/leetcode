#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> umap;
    int head = 0, result = 0;

    for(int i=0; i<s.size(); i++){
        // If s[i] nerver appear or it's locate is in front of the head
        if(umap.count(s[i]) == 0 || umap[s[i]] < head){
            umap[s[i]] = i;
            result = (result > i-head+1) ? result : i-head+1;
        }
        else{
            head = umap[s[i]] + 1;
            umap[s[i]] = i;
        }
    }

    return result;
}

int main(){
    string input = "abcabcbb";

    cout << "Input: " << input << endl;
    cout << "Output: " << lengthOfLongestSubstring(input) << endl;
}