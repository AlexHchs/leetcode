#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }

    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    long dvd = labs(dividend), dvs = labs(divisor), result = 0;

    while(dvd >= dvs){
        long temp = dvs, m = 1;

        while(temp << 1 <= dvd){
            temp <<= 1;                     // temp = temp << 1
            m <<= 1;
        }
        dvd -= temp;
        result += m;
    }

    return result * sign;
}

int main(){
    int dividend = 7, divisor = -3;
    int result;

    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;

    result = divide(dividend, divisor);

    cout << "Output: " << result << endl;

    return 0;
}