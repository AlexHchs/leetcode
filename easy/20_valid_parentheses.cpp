#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    vector<char> stack;
    int count = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push_back(s[i]);
            count++;
        }
        else if(count == 0)
            return false;
        else if(s[i] == ')' && stack[stack.size()-1] != '(')
            return false;
        else if(s[i] == ']' && stack[stack.size()-1] != '[')
            return false;
        else if(s[i] == '}' && stack[stack.size()-1] != '{')
            return false;
        else{
            stack.pop_back();
            count--;
        }
    }

    if(stack.empty())
        return true;
    else
        return false;
}

int main(){
    string input = "()[]{}";
    bool result = false;

    cout << "Input: " << input << endl;

    result = isValid(input);
    
    cout << "Output: " << result << endl;
}