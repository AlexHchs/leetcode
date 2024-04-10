#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string result;

    while(i >= 0 || j >= 0 || carry){
        if(i >= 0){
            carry += a[i] - '0';
            i--;
        }
        if(j >= 0){
            carry += b[j] - '0';
            j--;
        }
        result += carry % 2 + '0';
        carry /= 2;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(){
    string a = "1010", b = "11011";
    string result;

    cout << "Input: a = " << a << ", b = " << b << endl;

    result = addBinary(a, b);

    cout << "Output: " << result << endl;

    return 0;
}