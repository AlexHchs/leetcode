#include <bits/stdc++.h>
using namespace std;

void permutation(int left, int right, string temp, vector<string> &result){
    if(left == 0 && right == 0){
        result.push_back(temp);
        return;
    }

    if(left == right){
        string temp1 = temp;
        temp1.push_back('(');
        permutation(left-1, right, temp1, result);
    }
    else if(left == 0){
        string temp1 = temp;
        temp1.push_back(')');
        permutation(left, right-1, temp1, result);
    }
    else if(right == 0){
        string temp1 = temp;
        temp1.push_back('(');
        permutation(left-1, right, temp1, result);
    }
    else{
        string temp1 = temp, temp2 = temp;
        temp1.push_back('(');
        temp2.push_back(')');
        permutation(left-1, right, temp1, result);
        permutation(left, right-1, temp2, result);
    }
}

vector<string> generateParenthesis(int n){
    int left = n, right = n;
    string temp = "";
    vector<string> result;

    permutation(left, right, temp, result);

    return result;
}

int main(){
    int input = 4;
    vector<string> result;

    cout << "Input: " << input << endl;

    result = generateParenthesis(input);

    cout << "Output: ";
    for(const auto x : result){
        cout << x << " ";
    }
    cout << endl;
}