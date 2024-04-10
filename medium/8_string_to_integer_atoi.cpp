#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s){
    bool negative = false;
    int str_length = s.size();
    int ptr = 0;
    double result = 0;

    while(s[ptr] == ' ')
        ptr++;
    
    if(s[ptr] == '-'){
        negative = true;
        ptr++;
    }
    else if(s[ptr] == '+'){
        ptr++;
    }

    while(ptr<str_length && s[ptr] >= '0' && s[ptr] <= '9'){
        result = result * 10 + (s[ptr] - '0');
        ptr++;
    }
    
    result = negative ? -result : result;
    result = (result > INT_MAX) ? INT_MAX : result;
    result = (result < INT_MIN) ? INT_MIN : result;

    return result;
}

int main(){
    string input = "   -42";
    int result;

    cout << "Input: " << input << endl;

    result = myAtoi(input);

    cout << "Output: " << result << endl;
}