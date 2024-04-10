#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x){
    if(x < 0)
        return false;
    
    long long reverse_x = 0;
    long long temp = x;

    while(temp != 0){
        reverse_x = reverse_x * 10 + (temp % 10);
        temp /= 10;
    }

    return (reverse_x == x);
}

int main(){
    int input = 121;
    bool result;

    cout << "Input: " << input << endl;

    result = isPalindrome(input);

    cout << "Output: " << result << endl;
}