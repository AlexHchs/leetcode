#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    for(int i=1; i<n; i++){
        grid[i][0] += grid[i-1][0];
    }

    for(int j=1; j<m; j++){
        grid[0][j] += grid[0][j-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            grid[i][j] += (grid[i-1][j] <= grid[i][j-1]) ? grid[i-1][j] : grid[i][j-1];
        }
    }

    return grid[n-1][m-1];
}

int main(){
    int result;
    vector<vector<int>> input = {{1,3,1},{1,5,1},{4,2,1}};

    cout << "Input: grid = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    result = minPathSum(input);

    cout << "Output: " << result << endl;

    return 0;
}