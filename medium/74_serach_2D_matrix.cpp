#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = n - 1;
    int index = 0;

    for(int i=0; i<m; i++){
        if(matrix[i][0] <= target && matrix[i][n-1] >= target){
            index = i;
            break;
        }
    }

    while(low <= high){
        int mid = (low + high) / 2;

        if(matrix[index][mid] == target){
            return true;
        }
        else if(matrix[index][mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return false;
}

int main(){
    bool result = false;
    int target = 3;
    vector<vector<int>> input = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    cout << "Input: matrix = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "], target = " << target << endl;

    result = searchMatrix(input, target);

    cout << "Output: " << ((result == true) ? "true" : "false") << endl;

    return 0;
}