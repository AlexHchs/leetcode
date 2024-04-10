#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x == 0 || x == 1){
        return x;
    }
    int low = 1, high = x;
    int result;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid  == x / mid){
            return mid;
        }
        else if (mid > x / mid) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return high;
}

int main(){
    int input = 8;
    int result;

    cout << "Input: x = " << input << endl;

    result = mySqrt(input);

    cout << "Ouput: " << result << endl;

    return 0;
}