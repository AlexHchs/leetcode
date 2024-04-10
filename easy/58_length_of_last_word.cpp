#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int result = 0;
    int point = s.find_last_not_of(' ');

    while(s[point] != ' '){
        result++;
        if(point == 0){
            break;
        }
        else{
            point--;
        }
    }

    return result;
}

int main(){
    string input = "   fly me   to   the moon  ";
    int result;

    cout << "Input: " << input << endl;

    result = lengthOfLastWord(input);

    cout << "Output: " << result;

    return 0;
}