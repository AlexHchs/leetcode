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
        �H�W�d�ҥi�ಣ�ͤ@�Ӱ��Dpow(10, 2) = 99,
        �]��pow function�ĥμƭȹG�񪺤覡�^��double��,
        �]���|�y���^�Ǽƭ�99.9999�ƭȺI�_��99.
    */

    cout << "---------- Example part2 (result double type) ----------" << endl;
    cout << "Input: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    result_double = pow(x, y);

    cout << "Output: " << endl;
    cout << "x^y = " << result_double << endl;

    /*
        �H�W�d�ұN�^�ǭȥ�double���˧Y�i�ѨM.
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