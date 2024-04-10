#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    /* ----------------------------------------------------
        Math method path permutation: binomial coefficient
    ---------------------------------------------------- */
    long result = 1;
        
    for(int i=m+n-2, j=1; i>=max(m, n); i--, j++){
        result = (result * i) / j;
    }

    return result;

    /* ----------------------
        Dynamic programming
    ----------------------- */
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main(){
    int m = 3, n = 7;
    int result;

    cout << "Input: m = " << m << ", n = " << n << endl;

    result = uniquePaths(m, n);

    cout << "Output: " << result << endl;

    return 0;
}