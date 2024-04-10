#include <bits/stdc++.h>
using namespace std;

bool solve_dp(vector<vector<bool>> &dp, int i, int j, string s){
    if(i == j)
        return dp[i][j] = true;
    if(j-i == 1){
        if(s[i] == s[j])
            return dp[i][j] = true;
        else
            return dp[i][j] = false;
    }
    if(s[i]==s[j] && dp[i+1][j-1]==true)
        return dp[i][j] = true;
    else
        return dp[i][j] = false;
}

string longestPalindrome(string s){
    int str_length = s.size();
    int max_length = 0, index_start = 0;
    vector<vector<bool>> dp(str_length, vector<bool>(str_length, false));

    for(int n=0; n<str_length; n++){
        for(int i=0, j=n; i<str_length; i++, j++){
            solve_dp(dp, i, j, s);
            if(dp[i][j]){
                if(j-i+1 > max_length){
                    index_start = i;
                    max_length = j-i+1;
                }
            }
        }
    }

    return s.substr(index_start, max_length);
}


int main(){
    string input = "babad";
    string result;

    cout << "Input: " << input << endl;
    
    result = longestPalindrome(input);

    cout << "Output: " << result << endl;
}