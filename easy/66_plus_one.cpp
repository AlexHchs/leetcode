#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    for(int i=n-1; i>=0; i--){
        int temp = digits[i] + carry;
        digits[i] = temp % 10;
        carry = temp / 10;
    }

    if(carry > 0){
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main(){
    vector<int> input = {9};
    vector<int> result;

    cout << "Input: digits = [";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << "]" << endl;

    result = plusOne(input);

    cout << "Output: [";
    for(const auto x : result){
        cout << x << " ";
    }
    cout << "]" << endl;
    
    return 0;
}