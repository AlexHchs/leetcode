#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    int result = 0;
    
    while(x != 0){
        if(result < INT_MIN/10 || result > INT_MAX/10)
            return 0;
        result = result * 10 + (x % 10);
        x /= 10;
    }

    return result;
}

int main(){
    int input = -123;
    int result;

    cout << "Input: " << input << endl;

    result = reverse(input);

    cout << "Output: " << result << endl;
}