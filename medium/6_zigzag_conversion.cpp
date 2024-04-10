#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows){
    string result = "";

    if(numRows == 1)
        return s;
    
    for(int i=0; i<numRows; i++){
        if(i == 0 || i == numRows-1){
            int j = i;
            while(j < s.size()){
                result += s[j];
                j = j + (2 * numRows - 2);
            }
        }
        else{
            int j = i;
            bool change = false;
            while(j < s.size()){
                result += s[j];
                if(!change){
                    j = j + (2 * numRows - 2 - 2 * i);
                    change = true;
                }
                else{
                    j = j + 2 * i;
                    change = false;
                }
            }
        }
    }

    return result;
}

int main(){
    string input = "PAYPALISHIRING";
    string result;
    int numRows = 3;

    cout << "Input: s = " << input << ", numRows = " << numRows << endl;

    result = convert(input, numRows);

    cout << "Output: " << result << endl;
}