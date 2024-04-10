#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    bool terminate = false;
    int row = matrix.size(), column = matrix[0].size();
    int i = 0, j = 0, count = 0, total_element = row * column;
    string direct = "right";
    vector<int> result;
        
    while(!terminate){
        if(direct == "right"){
            for(count=0; count<column; count++, j++){
                result.push_back(matrix[i][j]);
            }
            direct = "down";
            row--;
            j--;
            i++;
        }
        else if(direct == "down"){
            for(count=0; count<row; count++, i++){
                result.push_back(matrix[i][j]);
            }
            direct = "left";
            column--;
            i--;
            j--;
        }
        else if(direct == "left"){
            for(count=0; count<column; count++, j--){
                result.push_back(matrix[i][j]);
            }
            direct = "up";
            row--;
            j++;
            i--;
        }
        else if(direct == "up"){
            for(count=0; count<row; count++, i--){
                result.push_back(matrix[i][j]);
            }
            direct = "right";
            column--;
            i++;
            j++;
        }

        if(result.size() == total_element){
            terminate = true;
        }
    }

    return result;
}

int main(){
    vector<vector<int>> input = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result;

    cout << "Input: matrix = [";
    for(const auto line : input){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    result = spiralOrder(input);

    cout << "Output: ";
    for(const auto x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}