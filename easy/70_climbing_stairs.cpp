#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    vector<int> count = {1, 2};

    for(int i=3; i<=n; i++){
        int temp = count[1];
        count[1] = count[0] + count[1];
        count[0] = temp;
    }

    return count[1];
}

int main(){
    int input = 3;
    int result;

    cout << "Input: n = " << input << endl;

    result = climbStairs(input);

    cout << "Output: " << result << endl;

    return 0;
}