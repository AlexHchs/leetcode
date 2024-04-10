#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    double result;

    if(n == 0 || x == 1){
        return 1.0;
    }
    else if(n == 1){
        return x;
    }
    else if(n == INT_MIN){
        return myPow(x * x, n/2);
    }
    else if(n > 0){
        result = myPow(x*x, n/2);
        if(n%2 == 1){
            result *= x;
        }
        return result;
    }
    else{
        n *= -1;
        result = 1 / myPow(x, n);
        return result;
    }
}

int main(){
    int n = 3;
    double x = 2.1;
    double result;

    cout << "Input: x = " << x << ", n = " << n << endl;

    result = myPow(x, n);

    cout << "Output: " << result << endl;
    
    return 0;
}