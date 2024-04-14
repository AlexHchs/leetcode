#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool flag_m = false, flag_n = false;
    int m = matrix.size(), n = matrix[0].size();

    for(int i=0; i<m; i++){
        if(matrix[i][0] == 0){
            flag_m = true;
            break;
        }
    }
    for(int j=0; j<n; j++){
        if(matrix[0][j] == 0){
            flag_n = true;
            break;
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(flag_m){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }
    if(flag_n){
        for(int j=0; j<n; j++){
            matrix[0][j] = 0;
        }
    }
}

int main(){
    vector<vector<int>> input = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    cout << "Input: matrix = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    setZeroes(input);

    cout << "Output: [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}