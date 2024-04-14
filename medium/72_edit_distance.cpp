#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size()+1, n = word2.size()+1;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for(int i=0; i<m; i++){
        dp[i][0] = i;
    }
    for(int j=0; j<n; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                dp[i][j]++;
            }
        }
    }

    return dp[m-1][n-1];
}

int main(){
    int result;
    vector<string> input = {"horse", "ros"};

    cout << "Input: word1 = " << input[0] << ", word2 = " << input[1] << endl;

    result = minDistance(input[0], input[1]);

    cout << "Output: " << result << endl;

    return 0;
}