#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<bool> track = {false, false};
    vector<vector<int>> dp(m, vector<int>(n, 1));

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
        return 0;
    }

    for(int i=0; i<n; i++){
        if(track[0] || obstacleGrid[0][i]){
            dp[0][i] = 0;
            track[0] = true;
        }
    }

    for(int i=0; i<m; i++){
        if(track[1] || obstacleGrid[i][0]){
            dp[i][0] = 0;
            track[1] = true;
        }
    }
        
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if((obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1) || obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }
            else if(obstacleGrid[i-1][j] == 1){
                dp[i][j] = dp[i][j-1];
            }
            else if(obstacleGrid[i][j-1] == 1){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main(){
    int result;
    vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};

    cout << "Input: obstacleGrid = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    result = uniquePathsWithObstacles(input);

    cout << "Output: " << result << endl;

    return 0;
}