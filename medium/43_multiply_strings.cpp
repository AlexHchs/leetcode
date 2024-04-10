#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    string result(num1.size()+num2.size(), '0');

    for(int i=num1.size()-1; i>=0; --i){
        int carry = 0;
        for(int j=num2.size()-1; j>=0; --j){
            int temp = (result[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            result[i+j+1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }

    size_t start_position = result.find_first_not_of("0");
    if(string::npos != start_position){
        return result.substr(start_position);
    }

    return "0";
}

int main(){
    string input1 = "123", input2 = "456";
    string result;

    cout << "Input: num1 = " << input1 << ", num2 = " << input2 << endl;

    result = multiply(input1, input2);

    cout << "Output: " << result << endl;
     
    return 0;
}