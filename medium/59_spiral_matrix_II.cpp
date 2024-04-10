#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    bool terminate = false;
    int row = n, column = n;
    int i = 0, j = 0, count = 0, number = 1;
    string direct = "right";
    vector<vector<int>> result(n, vector<int>(n, 0));
        
    while(!terminate){
        if(direct == "right"){
            for(count=0; count<column; count++, j++){
                result[i][j] = number++;
            }
            direct = "down";
            row--;
            j--;
            i++;
        }
        else if(direct == "down"){
            for(count=0; count<row; count++, i++){
                result[i][j] = number++;
            }
            direct = "left";
            column--;
            i--;
            j--;
        }
        else if(direct == "left"){
            for(count=0; count<column; count++, j--){
                result[i][j] = number++;
            }
            direct = "up";
            row--;
            j++;
            i--;
        }
        else if(direct == "up"){
            for(count=0; count<row; count++, i--){
                result[i][j] = number++;
            }
            direct = "right";
            column--;
            i++;
            j++;
        }

        if(number > n*n){
            terminate = true;
        }
    }

    return result;    
}

int main(){
    int input = 2;
    vector<vector<int>> result;

    cout << "Input: n = " << input << endl;

    result = generateMatrix(input);

    cout << "Output: [";
    for(const auto line : result){
        cout << "[";
        for(const auto x : line){
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}