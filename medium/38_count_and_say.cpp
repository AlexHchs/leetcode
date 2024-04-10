#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n){
    int i = 0, j = 0;
    string result;

    if(n == 1){
        return "1";
    }

    string str = countAndSay(n-1);

    while(i < str.size()){
        j = i + 1;

        while(j<str.size() && str[i]==str[j]){
            j++;
        }

        string temp = to_string(j-i);

        result += temp + str[i];
        i = j;
    }

    return result;
}

int main(){
    int input = 8;
    string result;

    cout << "Input: " << input << endl;

    result = countAndSay(input);

    cout << "Output: " << result << endl;

    return 0;
}