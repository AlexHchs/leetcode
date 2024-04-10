#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = {0}, column[9][9] = {0}, block[9][9] = {0};

    for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[i].size(); ++j){
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1, k = i/3*3 + j/3;
                if(row[i][num] || column[j][num] || block[k][num])
                    return false;
                row[i][num] = column[j][num] = block[k][num] = 1;
            }
        }
    }
    
    return true;
}

int main(){
    vector<vector<char>> input = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'}, 
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    bool result = false;

    cout << "Input: board = " << endl;
    for(const auto line : input){
        cout << "{";
        for(const auto c : line){
            cout << c << " ";
        }
        cout << "}" << endl;
    }

    result = isValidSudoku(input);

    if(result == 1){
        cout << "Output: true" << endl;
    }
    else{
        cout << "Output: false" << endl;
    }

    return 0;
}