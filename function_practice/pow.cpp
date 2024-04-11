#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 10, b = 2;
    int result_int;
    double x = 10.0, y = 2.0;
    double result_double;
    double result;

    cout << "---------- Example part1 (result int type) ----------" << endl;
    cout << "Input: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    result_int = pow(a, b);

    cout << "Output: " << endl;
    cout << "a^b = " << result_int << endl;

    /*
        以上範例可能產生一個問題pow(10, 2) = 99,
        因為pow function採用數值逼近的方式回傳double值,
        因此會造成回傳數值99.9999數值截斷為99.
    */

    cout << "---------- Example part2 (result double type) ----------" << endl;
    cout << "Input: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    result_double = pow(x, y);

    cout << "Output: " << endl;
    cout << "x^y = " << result_double << endl;

    /*
        以上範例將回傳值用double盛裝即可解決.
    */

    cout << "---------- Enter in part ----------" << endl;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    result = pow(x, y);

    cout << "Output: " << endl;
    cout << "x^y = " << result << endl;

    return 0;
}