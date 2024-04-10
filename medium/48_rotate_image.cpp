#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int temp;
    int length = matrix.size() - 1;

    for(int i=0; i<=length; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int i=0; i<=length; i++){
        for(int j=0; j<=length-i; j++){
            swap(matrix[i][j], matrix[length-j][length-i]);
        }
    }
}

int main(){
    vector<vector<int>> input = {{5,1,9,11},
                                 {2,4,8,10},
                                 {13,3,6,7},
                                 {15,14,12,16}};

    cout << "Input: matrix = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    rotate(input);

    cout << "Output: ";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << endl;    

    return 0;
}