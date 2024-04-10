#include <bits/stdc++.h>
using namespace std;

void permutation(int index, int n, string &digits, vector<string> &dict, string &temp, vector<string> &result){
    if(index == n){
        result.push_back(temp);
        return;
    }

    string letter = dict[digits[index] - '0'];

    for(int i=0; i<letter.size(); i++){
        temp += letter[i];
        permutation(index+1, n, digits, dict, temp, result);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    int n = digits.size();
    string temp = "";
    vector<string> result;
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if(n == 0)
        return result;

    permutation(0, n, digits, dict, temp, result);

    return result;
}

int main(){
    string input = "23";
    vector<string> result;

    cout << "Input: " << input << endl;

    result = letterCombinations(input);
    
    cout << "Output: ";
    for(const auto x : result){
        cout << x << " ";
    }
    cout << endl;
}